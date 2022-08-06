.PHONY: test

CFLAGS=-std=c11 -Wall -Werror -Wextra
CHECKFLAGS=`pkg-config --cflags --libs check`
FUNC_NAMES=s21_abs s21_acos s21_asin s21_atan s21_ceil s21_cos s21_exp s21_fabs \
s21_floor s21_fmod s21_log s21_pow s21_sin s21_sqrt s21_tan


all: clean s21_math.a test #gcov_report

s21_math.a: clean
	gcc $(CFLAGS) -c *.c
	ar rcs s21_math.a *.o
	rm *.o
	ranlib s21_math.a

test: s21_math.a
	rm -rf test/*.c
	for NAME in $(FUNC_NAMES); do \
		if [ -f "test/$${NAME}_test.check" ] ; then \
			checkmk test/$${NAME}_test.check > test/$${NAME}_test.c; \
			gcc test/$${NAME}_test.c -L. s21_math.a -o test/$${NAME}_test $(CHECKFLAGS) -lm; \
			echo \\n$${NAME}:; ./test/$${NAME}_test; \
		fi \
	done

#gcov_report:
#valgrind:

style_check:
	cppcheck *.c *.h
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py *.c *.h
	rm -f ./CPPLINT.cfg

miniverter:
	cd ../materials/build; sudo sh ./run.sh; cd ../../src

clean:
	rm -rf s21_math.a
	rm -rf test/*.c
	rm -rf test/*test
