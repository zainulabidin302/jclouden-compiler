#include "globals.h"
int main (int argc, char * argv[]) {

	char pgm[20];

	FILE * source;
	if (argc != 2) {

		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(0);
	}

	strcpy(pgm, argv[1]);

	if (strchr( pgm, '.') == NULL) {
		strcat(pgm, ".tny");
	}
	
	fprintf(stdout, "%s", pgm);

	source = fopen(pgm, "r");

	if (source == NULL) {
		fprintf(stderr, "File %s not found", pgm);
		exit(1);
	}

	

	

	fclose(source);

	return 0;
}
