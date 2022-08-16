CC = gcc
PLATFORM := $(shell uname)
CFLAGS = -Wall -Werror -Wextra -std=c11
TFLAGS = `pkg-config --cflags --libs check` -lc -lm -lgcov --coverage
SRC = s21_*.c
OBJ = s21_*.o
TESTS_SRC = tests/*.c

ifeq ($(PLATFORM), Linux)
OPEN = xdg-open 
else
OPEN = open
endif

all: clean s21_math.a test gcov_report

s21_math.a: $(OBJ) s21_math.h
	echo $(OBJ)
	gcc $(CFLAGS) -c $(SRC)
	ar rcs $@ $(OBJ)
	ranlib $@

test: s21_math.a
	$(CC) $(TESTS_SRC) -o test_check $(CFLAGS) $(TFLAGS) s21_math.a
	./test_check

gcov_report: test
	lcov -t "gcov_report" -o test.info -c -d .
	genhtml -o gcov_report test.info
	$(OPEN) ./gcov_report/index.html

style_check:
	cppcheck *.c *.h
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py *.c *.h
	rm -f ./CPPLINT.cfg

miniverter:
	cd ../materials/build; sudo sh ./run.sh; cd ../../src

clean:
	rm -f test_check
	rm -f *.info
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.a
	rm -fr gcov_report