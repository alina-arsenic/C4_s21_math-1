
CC=gcc
GCOV=gcov
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c11
PROFILE_FLAGS=-fprofile-arcs -ftest-coverage
COV_FLAGS=--coverage -g -O1
GCONV_FLAGS=-r . --html --html-details -d
LDFLAGS=
DIR1=
SOURCES1=s21_math.c
SOURCES2=s21_math_tests.c
OBJECTS1=$(SOURCES1:.c=.o)
TOBJECTS=$(SOURCES2:.c=.o)
HEADERS1=$(SOURCES1:.c=.h)
HEADERS2=$(SOURCES2:.c=.h)
EXECUTABLE=$(SOURCES2:.c=)
LIBS=$(OBJECTS1:.o=.a)

UNAME=$(shell uname -s)
ifeq ($(UNAME), Darwin)
	TST_FLAGS=-lcheck -lm -lpthread
endif

ifeq ($(UNAME), Linux)
	TST_FLAGS=-lcheck -lm -lpthread -lrt -lsubunit
endif

ifeq ($(UNAME), FreeBSD)
	TST_FLAGS=-lcheck -lm -lpthread -lrt -lsubunit
endif



all: build

build: s21_math.a

rebuild: clean all

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS1) $(TOBJECTS)
	rm -f s21_math.a
	rm -rf ./tests/res*.t
	rm -f ./tests/RESULT_VALGRIND*
	rm -f *.gc??
	rm -f *.gcov
	rm -f ./tests/coverage*
	rm -rf report*


$(LIBS): $(OBJECTS1)
	ar rsv $@ $^
	rm -f $^

test: clean style_check $(TOBJECTS)
	$(CC) $(CFLAGS) $(TST_FLAGS) $(COV_FLAGS) -c $(SOURCES1) -o $(OBJECTS1)
	ar rsv $(LIBS) $(OBJECTS1)
	$(CC) $(CFLAGS)  $(TOBJECTS) -o $(EXECUTABLE) -L. $(LIBS) -lm $(PROFILE_FLAGS) $(TST_FLAGS)
	./s21_math_tests
	$(GCOV) $(SOURCES1) 
	rm -f *.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

gcov_report: clean test
	$(GCOV) -a -f $(SOURCES1:.c=.gcno) >> ./tests/coverage.txt
	geninfo $(SOURCES1:.c=.gcda) -b . -o ./tests/coverage1.info
	genhtml -o report ./tests/coverage1.info
	open report/index.html


valgrind: test 
#	CK_FORK='no leaks' '--atExit' '--' $(EXECUTABLE2) cc Makefile
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=./tests/RESULT_VALGRIND.txt ./$(EXECUTABLE) > ./tests/res1.t
	tail -n 1 ./tests/RESULT_VALGRIND.txt

debug: clean style_check $(SOURCES2)
	$(CC) $(CFLAGS) $(TST_FLAGS) $(COV_FLAGS) -c $(SOURCES1) -o $(OBJECTS1)
	ar rsv $(LIBS) $(OBJECTS1)
	$(CC) $(CFLAGS) $(COV_FLAGS) -c $(SOURCES2) -o $(TOBJECTS)
	$(CC) $(CFLAGS) $(COV_FLAGS) $(TOBJECTS) -o $(EXECUTABLE) -L. $(LIBS) -lm $(PROFILE_FLAGS) $(TST_FLAGS)

style_check:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	rm -f CPPLINT.cfg

git:
	git push
	git push mygitserver
