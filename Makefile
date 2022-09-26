unhash : md5.c printer.c unhash.c
	gcc -o teste md5.c printer.c unhash.c -fopenmp