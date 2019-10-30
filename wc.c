#include <stdio.h>
#include <string.h>
#include <ctype.h>

//tig - stromecek commitu v terminalu

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

	int c_opt = strcmp("-c", argv[1]) == 0;
	int w_opt = strcmp("-w", argv[1]) == 0;
	int l_opt = strcmp("-l", argv[1]) == 0;

	if(c_opt || w_opt || l_opt) {
		unsigned int counter = 0;
		int character;
		while((character = fgetc(file)) != EOF) {
			if(w_opt && isspace(character)) {
				counter++;	
			}
			else if(l_opt && character == '\n') {
				counter++;
			}
			else if(c_opt) {
				counter++;
			}	
		} 
		printf("Count is: %d\n", counter);
	}
	return 0;
}
