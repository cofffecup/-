all: spiral

clean:
	rm -rf builds/*

spiral:
	gcc -Wall -Werror -Wextra spiral.c -o builds/spiral

cpplint:
	python3 ../cpplint.py --extensions=c *