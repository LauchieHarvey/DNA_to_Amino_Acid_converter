#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DNA_to_RNA(int lengthOfSequence, char* DNA_sequence){
	char *RNA_sequence = malloc(strlen(DNA_sequence) * sizeof(char) + 1);
	strcpy(RNA_sequence, DNA_sequence);
	if (!RNA_sequence) {exit(1);}

	for (int i = 0; i < lengthOfSequence; i++)
	{
		if(RNA_sequence[i] == 'T') {RNA_sequence[i] = 'U';}
	}
	return RNA_sequence;
}

char *returnAminoAcid(int firstNucleotideIndex, int secondNucletideIndex, int thirdNucleotideIndex){
	char *aminoAcidArray[4][4][4] = {
		{{"Phe", "Phe", "Leu", "Leu"}, {"Ser", "Ser", "Ser", "Ser"}, {"Tyr", "Tyr", "Stop", "Stop"}, {"Cys", "Cys", "Stop", "Trp"}},
		{{"Leu", "Leu", "Leu", "Leu"}, {"Pro", "Pro", "Pro", "Pro"}, {"His", "His", "Gln", "Gln"}, {"Arg", "Arg", "Arg", "Arg"}},
		{{"Ile", "Ile", "Ile", "Met"}, {"Thr", "Thr", "Thr", "Thr"}, {"Asn", "Asn", "Lys", "Lys"}, {"Ser", "Ser", "Arg", "Arg"}},
		{{"Val", "Val", "Val", "Val"}, {"Ala", "Ala", "Ala", "Ala"}, {"Asp", "Asp", "Glu", "Glu"}, {"Gly", "Gly", "Gly", "Gly"}},
	};

	return aminoAcidArray[firstNucleotideIndex][secondNucletideIndex][thirdNucleotideIndex];
}

int *RNA_to_RNA_integer_Sequence(int lengthOfSequence, char *RNA_sequence){
	int *RNA_integer_Sequence = malloc(lengthOfSequence * sizeof(int));
	if(!RNA_integer_Sequence) {exit(1);}

	for (int i = 0; i < lengthOfSequence; i++)
	{
		if (RNA_sequence[i] == 'U')
		{
			RNA_integer_Sequence[i] = 0;
		}else if (RNA_sequence[i] == 'C')
		{
			RNA_integer_Sequence[i] = 1;
		}else if (RNA_sequence[i] == 'A')
		{
			RNA_integer_Sequence[i] = 2;
		}else if (RNA_sequence[i] == 'G')
		{
			RNA_integer_Sequence[i] = 3;
		}
	}
	return RNA_integer_Sequence;
}

void RNA_to_Amino_Acid(int lengthOfSequence, char * RNA_sequence){
	FILE *fp = fopen("aminoAcidSequence.txt", "w");

	int *RNA_integer_Sequence = RNA_to_RNA_integer_Sequence(lengthOfSequence, RNA_sequence);

	for (int i = 0; i < lengthOfSequence; i += 3)
	{
		fprintf(fp, "%s ", returnAminoAcid(RNA_integer_Sequence[i], RNA_integer_Sequence[i + 1], RNA_integer_Sequence[i + 2]));
	}

	fclose(fp);
}

int main(int argc, char* argv[]){
	int lengthOfSequence = strlen(argv[1]);
	if (argc != 2)
	{
		printf("Please enter the sequence as a command line argument.\n");
		return 1;
	}
	char *DNA_sequence = malloc(lengthOfSequence * sizeof(char) + 1);
	if (!DNA_sequence) {return 1;}
	strcpy(DNA_sequence, argv[1]);

	printf("DNA: %s \n", DNA_sequence);

	char *RNA_sequence = malloc(lengthOfSequence * sizeof(char) + 1);
	strcpy(RNA_sequence, DNA_to_RNA(lengthOfSequence, DNA_sequence));

	printf("RNA: %s \n", RNA_sequence);

	//char *aminoAcidSequence = malloc(lengthOfSequence * sizeof(char) + 1); 
	//variable not needed as of now, will be needed if you read the file in future
	//	free(aminoAcidSequence); <-- add this in at the end also :)

	RNA_to_Amino_Acid(lengthOfSequence, RNA_sequence); // PRINTS TO THE .txt FILE!!!

	free(DNA_sequence);
	free(RNA_sequence);	
}