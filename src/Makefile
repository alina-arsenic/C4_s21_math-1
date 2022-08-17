CC = gcc
PLATFORM := $(shell uname)
CFLAGS = -Wall -Werror -Wextra -std=c11
TFLAGS = `pkg-config --cflags --libs check` -lc -lm -lgcov --coverage
SRC = s21_*.c
OBJ = s21_*.o
TESTS_SRC = tests/*.c

SOURCES1=*.c

ifeq ($(PLATFORM), Linux)
OPEN = xdg-open 
else
OPEN = open
endif

all: clean s21_math.a test gcov_report

s21_math.a: $(OBJ) s21_math.h
	gcc $(CFLAGS) -c $(SRC)
	ar rcs $@ $(OBJ)
	ranlib $@
	rm -f *.o

test: s21_math.a
	$(CC) $(TESTS_SRC) $(SRC) -o ./tests/test_check $(CFLAGS) $(TFLAGS) s21_math.a
	./tests/test_check

gcov_report: test
	lcov -t "./tests/test_check" -o gcov.info -c -d .
	genhtml -o gcov_report gcov.info
	@rm -rf ./*.gc*
	$(OPEN) gcov_report/index.html

style_check:
	cppcheck *.c *.h
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py *.c *.h tests/*.c tests/*.h
	rm -f ./CPPLINT.cfg

miniverter:
	cd ../materials/build; sudo sh ./run.sh; cd ../../src

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=VALGR.txt ./tests/test_check

clean:
	rm -f ./tests/test_check
	rm -f *.info
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.a
	rm -fr gcov_report
