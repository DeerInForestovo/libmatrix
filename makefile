build:
	gcc -shared -fPIC -o libmatrix.so matrix.c

test:
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH
	gcc -o test -L. test.c -lmatrix
	./test

clear:
	rm libmatrix.so
	rm test