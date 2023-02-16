CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: s21_grep

s21_cat: 
	$(CC) -o s21_grep $(CFLAGS) s21_grep.c

clean:
	rm -rf *.o

check:
	cp ../../materials/linters/.clang-format ../../src/.clang-format
	clang-format -i *.c
	clang-format -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	python3 cpplint.py *.c *.h
test:
		$(CC) -o ./s21_grep $(CFLAGS) s21_grep.c
		sh ./test_func_grep.sh

	
git:
	git add *.c *.txt
	git add Makefile
	git commit -m "add from make"
	git push --set-upstream origin develop


