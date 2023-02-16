CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: s21_cat

s21_cat: 
	$(CC) -o s21_cat $(CFLAGS) s21_cat.c

clean:
	rm -rf *.o

check:
	cp ../../materials/linters/.clang-format ../../src/.clang-format
	clang-format -i *.c
	clang-format -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	python3 cpplint.py *.c *.h

test:
	$(CC) -o ./test_cat/s21_cat $(CFLAGS) s21_cat.c
	sh ./test_cat/test_func_cat.sh
	$(CC) -o s21_cat $(CFLAGS) s21_cat.c
	sh ./test_cat/test_leak_cat.sh

	
git:
	git add *.c *.h
	git add Makefile
	git commit -m "add from make"
	git push --set-upstream origin develop

