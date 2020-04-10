all: checkers
checkers:
	gcc -Wall -Wextra -Werror c.c -o checkers
clean:
	rm -f checkers
re: clean all