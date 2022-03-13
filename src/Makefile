all: spiral

clean:
	rm -rf ../builds/*

cpplint:
	python3 ../cpplint.py --extensions=c *

spiral:
	gcc -Wall -Werror -Wextra 1_spiral.c -o ../builds/spiral

cut_it:
	gcc -Wall -Werror -Wextra 2_cut_it.c -o ../builds/cut_it
