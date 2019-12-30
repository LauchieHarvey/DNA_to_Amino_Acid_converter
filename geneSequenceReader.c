#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	if (argc != 2)
	{
		printf("Please enter the sequence as a command line argument.\n");
		return 1;
	}
	char *DNA_sequence = malloc(strlen(argv[1]) * sizeof(char) + 1);
	strcpy(DNA_sequence, argv[1]);

	printf("%s \n", DNA_sequence);

	char *RNA_sequence = malloc(strlen(argv[1]) * sizeof(char) + 1);
	strcpy(RNA_sequence, DNA_sequence);


	int n = strlen(DNA_sequence);
	for (int i = 0; i < n; i++)
	{
		if (RNA_sequence[i] == 'T')
		{
			RNA_sequence[i] = 'U';
		}
	}
	printf("%s \n", RNA_sequence);

	free(DNA_sequence);
	free(RNA_sequence);
}

//print the DNA sequence, the RNA sequence below it, and the amino acids below that.