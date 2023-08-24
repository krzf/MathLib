FLAGS = -Wall -Wextra -Werror -pedantic -std=c11
CC = gcc
LFLAGS = -fprofile-arcs -ftest-coverage
SRC := $(wildcard funcs/*.c)
OBJ := $(patsubst funcs/*.c, %.o, $(SRC))



all: Mymath.a test gcov_report

gcov: gcov_report

#uild_obj: $(CC) $(FLAGS) $(LFLAGS) --coverage -c funcs/*.c

test: Mymath.a
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_abs.c -o checktestabs -lm -lcheck -L/usr/local/lib
	./checktestabs
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_exp.c -o checktestexp -lm -lcheck -L/usr/local/lib
	./checktestexp
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_log.c -o checktestlog -lm -lcheck -L/usr/local/lib
	./checktestlog
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_pow.c -o checktestpow -lm -lcheck -L/usr/local/lib
	./checktestpow
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_floor.c -o checktestfloor -lm -lcheck -L/usr/local/lib
	./checktestfloor
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_ceil.c -o checktestceil -lm -lcheck -L/usr/local/lib
	./checktestceil
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_fmod.c -o checktestfmod -lm -lcheck -L/usr/local/lib
	./checktestfmod
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_cos.c -o checktestcos -lm -lcheck -L/usr/local/lib
	./checktestcos
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_asin.c -o checktestasin -lm -lcheck -L/usr/local/lib
	./checktestasin
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_atan.c -o checktestatan -lm -lcheck -L/usr/local/lib
	./checktestatan
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_acos.c -o checktestacos -lm -lcheck -L/usr/local/lib
	./checktestacos
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_fabs.c -o checktestfabs -lm -lcheck -L/usr/local/lib
	./checktestfabs
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_sin.c -o checktestsin -lm -lcheck -L/usr/local/lib
	./checktestsin
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_sqrt.c -o checktestsqrt -lm -lcheck -L/usr/local/lib
	./checktestsqrt
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) --coverage testdelete/Mytest_tan.c -o checktesttan -lm -lcheck -L/usr/local/lib
	./checktesttan
	

Mymath.a: 
	gcc -Wall -Wextra -Werror funcs/*.c -c 
	ar rc libMymath.a *.o
	ranlib libMymath.a
	cp libMymath.a ./Mymath.a
	rm *.o

gcov_report: test
	gcov testdelete/*.c
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory coverage-html
	rm -rf *.gcda *.gcno




stylecheck:
	clang-format -style=Google -n ./*/*.c



clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf *.a_check
	rm -rf gcov
	rm -rf coverage
	rm -rf coverage-html
	rm -rf checktestpow          
	rm -rf checktestabs
	rm -rf checktestacos
	rm -rf checktestasin
	rm -rf checktestatan
	rm -rf checktestceil
	rm -rf checktestcos
	rm -rf checktestexp 
	rm -rf checktestfabs
	rm -rf checktestfloor
	rm -rf checktestfmod
	rm -rf checktestlog
	rm -rf checktesttan
	rm -rf checktestsqrt
	rm -rf checktestsin
	rm -rf ALL
rebuild:
	make clean
	make