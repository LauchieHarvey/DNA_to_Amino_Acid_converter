#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int random;
	srand(time(NULL));
	if (argc != 2)
	{
		printf("Please enter the number of nucleotides as a command line argument. \n");
		return 1;
	}

	int sequenceLength = atoi(argv[1]);

	const char nucleotides[] = {'A', 'T', 'G', 'C'};

	for (int i = 0; i < sequenceLength; i++)
	{
		printf("%c", nucleotides[rand() % 4]);
	}
	printf("\n");
}
