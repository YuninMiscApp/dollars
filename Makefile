
PHONY : all

TARGET_NAME ?= dollars


all: FORCE
	gcc -Wall -o $(TARGET_NAME) $(TARGET_NAME).c

clean: FORCE
	@rm -f $(TARGET_NAME)


distclean: clean FORCE


PHONY += FORCE
FORCE:


