// by weaveryu
#include <math.h>
#include <stdio.h>

#define EPS 1e-16
#define S21_M_PI 3.14159265358979323846264338327950288
#define S21_M_PI_2   1.57079632679489661923132169163975144

/*long double s21_atan(double x)
{
    double a, ax, p, r, s, q, o;
    // argument reduction: 
    // arctan (-x) = -arctan(x); 
    // arctan (1/x) = 1/2 * pi - arctan (x), when x > 0

    ax = fabs(x);
    a = (ax > 1.0) ? 1.0/ax : ax;
    // evaluate minimax polynomial approximation 
    s = a * a; // a**2
    q = s * s; // a**4
    o = q * q; // a**8
    // use Estrin's scheme for low-order terms 
    p = fma (fma (fma (-0x1.53e1d2a25ff34p-16, s, 0x1.d3b63dbb65af4p-13), q,
                  fma (-0x1.312788dde0801p-10, s, 0x1.f9690c82492dbp-9)), o,
             fma (fma (-0x1.2cf5aabc7cef3p-7, s, 0x1.162b0b2a3bfcep-6), q, 
                  fma (-0x1.a7256feb6fc5cp-6, s, 0x1.171560ce4a483p-5)));
    // use Horner's scheme for high-order terms
    p = fma (fma (fma (fma (fma (fma (fma (fma (fma (fma (fma (fma (p, s,
        -0x1.4f44d841450e1p-5), s,
         0x1.7ee3d3f36bb94p-5), s, 
        -0x1.ad32ae04a9fd1p-5), s,  
         0x1.e17813d66954fp-5), s, 
        -0x1.11089ca9a5bcdp-4), s,  
         0x1.3b12b2db51738p-4), s,
        -0x1.745d022f8dc5cp-4), s,
         0x1.c71c709dfe927p-4), s,
        -0x1.2492491fa1744p-3), s,
         0x1.99999999840d2p-3), s,
        -0x1.555555555544cp-2) * s, a, a);
    // back substitution based on argument reduction
    r = (ax > 1.0) ? (S21_M_PI_2 - p) : p;

    printf("%.100lf\n", -0x1.53e1d2a25ff34p-16);

    return (long double)copysign (r, x);
}*/

long double s21_atan(double x) {
    double ax = fabs(x);  // arctan(-x) = -arctan(x)
    double a = a = (ax > 1.0) ? 1.0/ax : ax;  // arctan(1/x) = pi/2 - arctan(x) if x > 0
    
    long double k = fmod(a*a, S21_M_PI);
    long double temp = 0, pred = 1;
    double div = 3;
    while (fabs(pred-temp) > EPS) {
        pred = temp;
        temp += pow(k, (div-1)/2)*(k/(div+2)-(1/div));
        div += 4;
    }
    temp += 1;
    temp *= fmod(ax, S21_M_PI);

    long double result = (ax > 1.0) ? (S21_M_PI_2 - temp) : temp;
    return (long double)copysign(result, x);
}

int main() {
    double x;
    while (1) {
        scanf("%lf", &x);
        printf("%Lf %lf\n", s21_atan(x), atan(x));
    }
    return 0;
}
