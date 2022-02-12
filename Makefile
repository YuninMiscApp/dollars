
PHONY : all

TARGET_NAME ?= dollars


all: FORCE
	gcc -Wall -o dollars dollars.c
	gcc -Wall -o calc calc.c

clean: FORCE
	$(shell rm -f `ls *.c | sed 's/\(.*\)\.c/\1/g' | xargs `)


distclean: clean FORCE
	@echo "clean...."

PHONY += FORCE
FORCE:

