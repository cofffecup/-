all: spiral

clean:
	rm -rf ../builds/*

cpplint:
	python3 ../cpplint.py --extensions=c *

spiral:
	gcc -Wall -Werror -Wextra 1_spiral.c -o ../builds/spiral

cut_it:
	gcc -Wall -Werror -Wextra 2_cut_it.c -o ../builds/cut_it

test:
	gcc -Wall -Werror -Wextra test.c

simplex:
	gcc -Wall -Werror -Wextra 3_simplex/simplex.c -o ../builds/simplex

struct:
	gcc -Wall -Werror -Wextra 4_struct.c -o ../builds/struct

input:
	gcc -Wall -Werror -Wextra 5_dynamic_input -o ../builds/input
