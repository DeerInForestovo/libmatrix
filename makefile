test:
	gcc -fPIC -c matrix.c -o matrix.o
	gcc -shared matrix.o -o libmatrix.so
	gcc -o test test.c -L. -lmatrix
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH
	./test

make:
	gcc -fPIC -c matrix.c -o matrix.o
	gcc -shared matrix.o -o libmatrix.so