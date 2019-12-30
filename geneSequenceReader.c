#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	char *fullSequence = malloc(strlen(argv[1]) * sizeof(char) + 1);

	strcpy(fullSequence, argv[1]);

	printf("%s \n", fullSequence);

	free(fullSequence);
}