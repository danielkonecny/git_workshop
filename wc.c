#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	if(argc != 3) {
		fprintf(stderr, "ERROR: Number of parameters should be 2, not %d!\n", argc-1);
		return -1;
	}

	FILE *file = fopen(argv[2], "r");
	if(file == NULL) {
		fprintf(stderr, "ERROR: File %s not found!\n", argv[2]);
		return -2;
	}

	if (strcmp("-c", argv[1]) == 0 || strcmp("-w", argv[1]) == 0) {
		unsigned int counter = 0;
		int character;
		while((character = fgetc(file)) != EOF) {
			if(strcmp("-w", argv[1]) == 0 && isspace(character)) {
			counter++;	
			}
			else{
				if(strcmp("-c", argv[1]) == 0) {
				counter++;
				}	
			}
		} 
		printf("Count is: %d\n", counter);
	}
	return 0;
}