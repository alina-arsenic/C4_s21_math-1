#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define S21_M_PI 3.14159265358979323846264338327950288   // pi
#define S21_M_PI_2     1.57079632673412561417   // pi/2
#define S21_M_PI_4     0.785398163397448309616  // pi/4

#define EPS 1e-17

static const double
S1  = -1.66666666666666324348e-01, /* 0xBFC55555, 0x55555549 */
S2  =  8.33333333332248946124e-03, /* 0x3F811111, 0x1110F8A6 */
S3  = -1.98412698298579493134e-04, /* 0xBF2A01A0, 0x19C161D5 */
S4  =  2.75573137070700676789e-06, /* 0x3EC71DE3, 0x57B1FE7D */
S5  = -2.50507602534068634195e-08, /* 0xBE5AE5E6, 0x8A2B9CEB */
S6  =  1.58969099521155010221e-10; /* 0x3DE5D93A, 0x5ACFD57C */

static const double
C1  =  4.16666666666666019037e-02, /* 0x3FA55555, 0x5555554C */
C2  = -1.38888888888741095749e-03, /* 0xBF56C16C, 0x16C15177 */
C3  =  2.48015872894767294178e-05, /* 0x3EFA01A0, 0x19CB1590 */
C4  = -2.75573143513906633035e-07, /* 0xBE927E4F, 0x809C52AD */
C5  =  2.08757232129817482790e-09, /* 0x3E21EE9E, 0xBDB4B1C4 */
C6  = -1.13596475577881948265e-11; /* 0xBDA8FAE9, 0xBE8838D4 */

static const double
pio4    = 0x1.921fb54442d18p-1,
pio2_2  = 6.07710050630396597660e-11, /* 0x3DD0B461, 0x1A600000 */
pio2_2t = 2.02226624879595063154e-21, /* 0x3BA3198A, 0x2E037073 */
pio2_3  = 2.02226624871116645580e-21, /* 0x3BA3198A, 0x2E000000 */
pio2_3t = 8.47842766036889956997e-32; /* 0x397B839A, 0x252049C1 */

static const int init_jk[] = {3,4,4,6}; /* initial value for jk */

/*
 * Table of constants for 2/pi, 396 Hex digits (476 decimal) of 2/pi
 *
 *              integer array, contains the (24*i)-th to (24*i+23)-th
 *              bit of 2/pi after binary point. The corresponding
 *              floating value is
 *
 *                      ipio2[i] * 2^(-24(i+1)).
 *
 * NB: This table must have at least (e0-3)/24 + jk terms.
 *     For quad precision (e0 <= 16360, jk = 6), this is 686.
 */
static const int32_t ipio2[] = {
0xA2F983, 0x6E4E44, 0x1529FC, 0x2757D1, 0xF534DD, 0xC0DB62,
0x95993C, 0x439041, 0xFE5163, 0xABDEBB, 0xC561B7, 0x246E3A,
0x424DD2, 0xE00649, 0x2EEA09, 0xD1921C, 0xFE1DEB, 0x1CB129,
0xA73EE8, 0x8235F5, 0x2EBB44, 0x84E99C, 0x7026B4, 0x5F7E41,
0x3991D6, 0x398353, 0x39F49C, 0x845F8B, 0xBDF928, 0x3B1FF8,
0x97FFDE, 0x05980F, 0xEF2F11, 0x8B5A0A, 0x6D1F6D, 0x367ECF,
0x27CB09, 0xB74F46, 0x3F669E, 0x5FEA2D, 0x7527BA, 0xC7EBE5,
0xF17B3D, 0x0739F7, 0x8A5292, 0xEA6BFB, 0x5FB11F, 0x8D5D08,
0x560330, 0x46FC7B, 0x6BABF0, 0xCFBC20, 0x9AF436, 0x1DA9E3,
0x91615E, 0xE61B08, 0x659985, 0x5F14A0, 0x68408D, 0xFFD880,
0x4D7327, 0x310606, 0x1556CA, 0x73A8C9, 0x60E27B, 0xC08C6B,
};

static const double PIo2[] = {
  1.57079625129699707031e+00, /* 0x3FF921FB, 0x40000000 */
  7.54978941586159635335e-08, /* 0x3E74442D, 0x00000000 */
  5.39030252995776476554e-15, /* 0x3CF84698, 0x80000000 */
  3.28200341580791294123e-22, /* 0x3B78CC51, 0x60000000 */
  1.27065575308067607349e-29, /* 0x39F01B83, 0x80000000 */
  1.22933308981111328932e-36, /* 0x387A2520, 0x40000000 */
  2.73370053816464559624e-44, /* 0x36E38222, 0x80000000 */
  2.16741683877804819444e-51, /* 0x3569F31D, 0x00000000 */
};

int __rem_pio2_large(double *x, double *y, int e0, int nx)
{
	int32_t jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	double z,fw,f[20],fq[20],q[20];

	/* initialize jk*/
	jk = init_jk[1];
	jp = jk;

	/* determine jx,jv,q0, note that 3>q0 */
	jx = nx-1;
	jv = (e0-3)/24;  if(jv<0) jv=0;
	q0 = e0-24*(jv+1);

	/* set up f[0] to f[jx+jk] where f[jx+jk] = ipio2[jv+jk] */
	j = jv-jx; m = jx+jk;
	for (i=0; i<=m; i++,j++)
		f[i] = j<0 ? 0.0 : (double)ipio2[j];

	/* compute q[0],q[1],...q[jk] */
	for (i=0; i<=jk; i++) {
		for (j=0,fw=0.0; j<=jx; j++)
			fw += x[j]*f[jx+i-j];
		q[i] = fw;
	}

	jz = jk;

	/* distill q[] into iq[] reversingly */
	for (i=0,j=jz,z=q[jz]; j>0; i++,j--) {
		fw    = (double)(int32_t)(0x1p-24*z);
		iq[i] = (int32_t)(z - 0x1p24*fw);
		z     = q[j-1]+fw;
	}

	/* compute n */
	z  = scalbn(z,q0);       /* actual value of z */
	z -= 8.0*floor(z*0.125); /* trim off integer >= 8 */
	n  = (int32_t)z;
	z -= (double)n;
	ih = 0;
	if (q0 > 0) {  /* need iq[jz-1] to determine n */
		i  = iq[jz-1]>>(24-q0); n += i;
		iq[jz-1] -= i<<(24-q0);
		ih = iq[jz-1]>>(23-q0);
	}
	else if (q0 == 0) ih = iq[jz-1]>>23;
	else if (z >= 0.5) ih = 2;

	if (ih > 0) {  /* q > 0.5 */
		n += 1; carry = 0;
		for (i=0; i<jz; i++) {  /* compute 1-q */
			j = iq[i];
			if (carry == 0) {
				if (j != 0) {
					carry = 1;
					iq[i] = 0x1000000 - j;
				}
			} else
				iq[i] = 0xffffff - j;
		}
		if (q0 > 0) {  /* rare case: chance is 1 in 12 */
			switch(q0) {
			case 1:
				iq[jz-1] &= 0x7fffff; break;
			case 2:
				iq[jz-1] &= 0x3fffff; break;
			}
		}
		if (ih == 2) {
			z = 1.0 - z;
			if (carry != 0)
				z -= scalbn(1.0,q0);
		}
	}

	//printf("jz = %d\n", jz);

	// chop off zero terms
	if (z == 0.0) {
		jz -= 1;
		q0 -= 24;
		while (iq[jz] == 0) {
			jz--;
			q0 -= 24;
		}
	} else { // break z into 24-bit if necessary
		z = scalbn(z,-q0);
		if (z >= 0x1p24) {
			fw = (double)(int32_t)(0x1p-24*z);
			iq[jz] = (int32_t)(z - 0x1p24*fw);
			jz += 1;
			q0 += 24;
			iq[jz] = (int32_t)fw;
		} else
			iq[jz] = (int32_t)z;
	}

	//printf("jz = %d\n", jz);

	/* convert integer "bit" chunk to floating-point value */
	fw = scalbn(1.0,q0);
	for (i=jz; i>=0; i--) {
		q[i] = fw*(double)iq[i];
		fw *= 0x1p-24;
	}

	/* compute PIo2[0,...,jp]*q[jz,...,0] */
	for(i=jz; i>=0; i--) {
		for (fw=0.0,k=0; k<=jp && k<=jz-i; k++)
			fw += PIo2[k]*q[i+k];
		fq[jz-i] = fw;
	}

	// compress fq[] into y[]
    fw = 0.0;
    for (i=jz; i>=0; i--)
        fw += fq[i];
    fw = (double)fw;
    y[0] = ih==0 ? fw : -fw;

	return n&7;
}

int binar(long int x) {
	int b, i = -1;
	while (x>0) {
		i += 1;
		b = x%2;
		printf("%d", b);
		x = x/2;
	}
	printf("\n");
	return i;
}

int large(double x, double *y) {

    union {double f; uint64_t i;} u = {x};
	double_t z,w,t,r,fn;
	double tx[3],ty[2];
	uint32_t ix;
	int sign, n, i;

	sign = (x < 0) ? -1 : 1;
    double ax = fabs(x);
	int tt = 0;
	while (fabs(x) - pow(2, tt) > 0) tt += 1;
	tt -= 24;  // tt = степень старшего бита -23 в записи двоичного представления x (double)

	/* set z = scalbn(|x|,-ilogb(x)+23) */
	u.f = x;
	u.i &= (uint64_t)-1>>12;
	u.i |= (uint64_t)(0x3ff + 23)<<52;
	z = u.f;
	for (i=0; i < 2; i++) {
		tx[i] = (double)(int32_t)z;
		z = (z-tx[i])*0x1p24;
	}
	tx[i] = z;
	n = __rem_pio2_large(tx,ty,tt,i+1);

	y[0] = sign*ty[0];
	return sign*n;
}

int medium(double x, double *y) {

    union {double f; uint64_t i;} u = {x};
	double_t z,w,t,r,fn;
	int sign, n, i;

	sign = (x < 0) ? 1 : 0;
    double ax = fabs(x);

    fn = round(x/(S21_M_PI_2));
    n = (int)fn;
    r = x - fn*S21_M_PI_2;
    w = 0;  // 1st round, good to 85 bits
    y[0] = x - fn*S21_M_PI_2;

    if (fabs(x) > S21_M_PI*1500) { // 2nd round, good to 118 bits
        t = r;
        w = fn*pio2_2;
        r = t - w;
        w = fn*pio2_2t - ((t-r)-w);
        y[0] = r - w;
    }
    return n;
}

double small(double x) {
    x = fmod(x, 2*S21_M_PI);
    long double result = 1;
    long double xx = x*x;
    long double fact = 2;
    long double fact_mul = 2;
    long double add = 1;
    int sign = -1;
    int i = 1;
    while (fabs(add) > EPS) {
        add = sign*(pow(xx, i))/(fact);
        result += add;
        sign *= -1;
        fact *= ++fact_mul;
        fact *= ++fact_mul;
        i++;
    }
    return (double)result;
}

double __s21_cos(double x)
{
	double hz,z,r,w;

	z  = x*x;
	w  = z*z;
	r  = z*(C1+z*(C2+z*C3)) + w*w*(C4+z*(C5+z*C6));
	hz = 0.5*z;
	w  = 1.0-hz;
	return w + (((1.0-w)-hz) + (z*r));
}

double __s21_sin(double x)
{
	double_t z,r,v,w;

	z = x*x;
	w = z*z;
	r = S2 + z*(S3 + z*S4) + z*w*(S5 + z*S6);
	v = z*x;
	return x - ((z*(- v*r)) - v*S1);
}

double s21_cos(double x)
{
	double y[2];
    unsigned n;
    double ax = fabs(x);

    if (!isnormal(x)) {  // x is inf or NaN
		y[0] = y[1] = x - x;
	} else if (ax <= 9*S21_M_PI_4) {
        return small(x);
    } else if (ax < pow(2, 20)*S21_M_PI_2) { 
        n = medium(x, y);
    } else {
        n = large(x, y);
    }

	//printf("n = %d, y[0] = %lf\n", n, y[0]);

	switch (n&3) {
	case 0: return  __s21_cos(y[0]);
	case 1: return -__s21_sin(y[0]);
	case 2: return -__s21_cos(y[0]);
	default:
		return  __s21_sin(y[0]);
	}
}

int main() {
    double xx = 0.1111111111111111;
    for (int i = 0; i < 17; i++) {
        printf("%24lf : %10lf %10lf\n", xx, s21_cos(xx), cos(xx));
        xx *= 10;
    }
    xx = 0.9999999999999999;
    for (int i = 0; i < 17; i++) {
        printf("%24lf : %10lf %10lf\n", xx, s21_cos(xx), cos(xx));
        xx *= 10;
    }
    xx = 0.1;
    for (int i = 0; i < 17; i++) {
        printf("%24lf : %10lf %10lf\n", xx, s21_cos(xx), cos(xx));
        xx *= 10;
    }
    return 0;
}
