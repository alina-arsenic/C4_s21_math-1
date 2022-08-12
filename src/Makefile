#Makefile
CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -g -std=c11
TEST_LIBS=-lcheck -lpthread -lrt -lm -lsubunit
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

all: test s21_math.a gcov_report

s21_math.a: s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

s21_math.o: s21_math.c s21_math.h
	$(CC) $(CFLAGS) -o s21_math.o s21_math.c

gcov_s21_math.a: gcov_s21_math.o
	ar rc gcov_s21_math.a gcov_s21_math.o
	ranlib gcov_s21_math.a

gcov_s21_math.o: s21_math.c s21_math.h
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o gcov_s21_math.o s21_math.c

test: s21_math.a unittests_s21_math.o
	$(CC) unittests_s21_math.o -o test $(TEST_LIBS) -L. s21_math.a -fsanitize=address

gcov_test: gcov_s21_math.a unittests_s21_math.o
	$(CC) unittests_s21_math.o $(GCOV_FLAGS) -o gcov_test $(TEST_LIBS) -L. gcov_s21_math.a -fsanitize=address

unittests_s21_math.o: unittests_s21_math.c
	$(CC) $(CFLAGS) -o unittests_s21_math.o unittests_s21_math.c  

gcov_report: gcov_test
	./gcov_test
	gcovr --html-details -o gcov_report.html

rebuild: clean all

style:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=VALGR_1.txt ./gcov_test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=VALGR_2.txt ./test

clean:
	rm -f *.o *.a *.gcda *.gcno *test *.html *.css *.txt
