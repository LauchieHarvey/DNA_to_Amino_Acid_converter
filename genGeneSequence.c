#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int random;

	int sequenceLength = atoi(argv[1]);

	printf("%d", sequenceLength);



	const char nucleotides[] = {'A', 'T', 'G', 'C'};
	/*

	for (int i = 0; i < sequenceLength; i++)
	{
		random = rand() % 4;
		char thisNucleotide = nucleotides[random];
		printf("%c", thisNucleotide);
	}
	*/
	printf("\n");
}