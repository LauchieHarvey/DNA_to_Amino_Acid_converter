#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DNA_to_RNA(int lengthOfSequence, char* DNA_sequence){
	char *RNA_sequence = malloc(strlen(DNA_sequence) * sizeof(char) + 1);
	strcpy(RNA_sequence, DNA_sequence);
	if (!RNA_sequence)
	{
		exit(1);
	}
	for (int i = 0; i < lengthOfSequence; i++)
	{
		if (RNA_sequence[i] == 'T')
		{
			RNA_sequence[i] = 'U';
		}
	}
	return RNA_sequence;
}

char *RNA_to_Amino_Acid(int lengthOfSequence, char * RNA_sequence){
	char *aminoAcidSequence = malloc(lengthOfSequence * sizeof(char) + 1);
	FILE *fp = fopen("aminoAcidSequence.txt", "w");
	strcpy(aminoAcidSequence, RNA_sequence);
	
	for (int i = 0; i < lengthOfSequence; i += 3)
	{
		if (aminoAcidSequence[i] == 'U')
		{
			if (aminoAcidSequence[i + 1] == 'U')
			{
				if (aminoAcidSequence[i + 2] == 'U' || aminoAcidSequence[i + 2] == 'C')
				{
					fprintf(fp, "Phe ");
				}
				else fprintf(fp, "Leu ");	
			}
			else if (aminoAcidSequence[i + 1] == 'C')
			{
				fprintf(fp, "Ser ");
			}		
			else if (aminoAcidSequence[i + 1] == 'A')
			{
				if (aminoAcidSequence[i + 2] == 'U' || aminoAcidSequence[i + 2] == 'C')
				{
					fprintf(fp, "Tyr ");
				}
				else fprintf(fp, "STOP");
			}
			else if (aminoAcidSequence[i + 1] == 'G')
			{
				if (aminoAcidSequence[i + 2] == 'U' || aminoAcidSequence[i + 2] == 'C')
				{
					fprintf(fp, "Cys ");
				}
				else if (aminoAcidSequence[i + 2] == 'A')
				{
					fprintf(fp, "STOP");
				}
				else if (aminoAcidSequence[i + 2] == 'G')
				{
					fprintf(fp, "Trp ");
				}
			}			
		}
	}

	fclose(fp);
	strcpy(aminoAcidSequence, "hello");
	return aminoAcidSequence;
}

int main(int argc, char* argv[]){
	int lengthOfSequence = strlen(argv[1]);
	if (argc != 2)
	{
		printf("Please enter the sequence as a command line argument.\n");
		return 1;
	}
	char *DNA_sequence = malloc(lengthOfSequence * sizeof(char) + 1);
	if (!DNA_sequence)
	{
		return 1;
	}
	strcpy(DNA_sequence, argv[1]);

	printf("DNA: %s \n", DNA_sequence);

	char *RNA_sequence = malloc(lengthOfSequence * sizeof(char) + 1);
	strcpy(RNA_sequence, DNA_to_RNA(lengthOfSequence, DNA_sequence));

	printf("RNA: %s \n", RNA_sequence);

	char *aminoAcidSequence = malloc(lengthOfSequence * sizeof(char) + 1); // If you want to add spaces between amino acids update this
	strcpy(aminoAcidSequence, RNA_to_Amino_Acid(lengthOfSequence, RNA_sequence));
	
	printf("Amino Acids: %s \n", aminoAcidSequence);
	free(DNA_sequence);
	free(RNA_sequence);
	free(aminoAcidSequence);
}