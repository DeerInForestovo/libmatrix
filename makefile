build:
	gcc -shared -fPIC -o libmatrix.so matrix.c
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH
	echo $$LD_LIBRARY_PATH

test:
	gcc -o test -L. test.c -lmatrix
	./test

clean:
	rm libmatrix.so
	rm test