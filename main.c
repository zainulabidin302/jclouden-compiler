#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

	char pgm[20];

	if (argc != 2) {

		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(0);
	}
	

	strcpy(pgm, argv[1]);

	

	return 0;
}
