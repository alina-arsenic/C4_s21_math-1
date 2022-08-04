CFLAGS=-Wall -Werror -Wextra

all: clean s21_math.a #test gcov_report

s21_math.a:
	gcc -c *.c
	ar rcs s21_math.a *.o
	rm *.o
	ranlib s21_math.a

#test:
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
