#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DNA_to_RNA(int lengthOfSequence, char* DNA_sequence){
	char *RNA_sequence = malloc(strlen(DNA_sequence) * sizeof(char) + 1);
	if (!RNA_sequence) {exit(1);}
	strcpy(RNA_sequence, DNA_sequence);
	
	for (int i = 0; i < lengthOfSequence; i++)
	{
		if(RNA_sequence[i] == 'T') {RNA_sequence[i] = 'U';}
	}
	return RNA_sequence;
}

char *return_Amino_Acid(int first_Nucleotide_Index, int second_Nucletide_Index, int third_Nucleotide_Index){
	char *amino_Acid_Array[4][4][4] = {
		{{"Phe", "Phe", "Leu", "Leu"}, {"Ser", "Ser", "Ser", "Ser"}, {"Tyr", "Tyr", "Stop", "Stop"}, {"Cys", "Cys", "Stop", "Trp"}},
		{{"Leu", "Leu", "Leu", "Leu"}, {"Pro", "Pro", "Pro", "Pro"}, {"His", "His", "Gln", "Gln"}, {"Arg", "Arg", "Arg", "Arg"}},
		{{"Ile", "Ile", "Ile", "Met"}, {"Thr", "Thr", "Thr", "Thr"}, {"Asn", "Asn", "Lys", "Lys"}, {"Ser", "Ser", "Arg", "Arg"}},
		{{"Val", "Val", "Val", "Val"}, {"Ala", "Ala", "Ala", "Ala"}, {"Asp", "Asp", "Glu", "Glu"}, {"Gly", "Gly", "Gly", "Gly"}},
	};

	return amino_Acid_Array[first_Nucleotide_Index][second_Nucletide_Index][third_Nucleotide_Index];
}

int *RNA_to_RNA_integer_Sequence(int lengthOfSequence, char *RNA_sequence){
	int *RNA_integer_Sequence = malloc(lengthOfSequence * sizeof(int));
	if(!RNA_integer_Sequence) {exit(1);}

	//Each Nucleotide has been assigned an integer value. This allows for efficient sorting through a 3D array.
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
		}else{
			RNA_integer_Sequence[i] = -1;
		}
	}
	return RNA_integer_Sequence;
}

void RNA_to_Amino_Acid(int lengthOfSequence, char * RNA_sequence){
	// There is no variable storing the amino acid string. It just gets printed straight to the .txt file for now.
	FILE *fp = fopen("aminoAcidSequence.txt", "w");

	int *RNA_integer_Sequence = RNA_to_RNA_integer_Sequence(lengthOfSequence, RNA_sequence);

	for (int i = 0; i < lengthOfSequence; i += 3)
	{
		if(RNA_integer_Sequence[i])
		{
			fprintf(fp, "%s ", return_Amino_Acid(RNA_integer_Sequence[i], RNA_integer_Sequence[i + 1], RNA_integer_Sequence[i + 2]));
		}else 
		{
			fprintf(fp, "%s", "000"); //Indicated that a letter that isn't T, C, A or G was inputted.
		}
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
	if(!RNA_sequence) {return 1;}
	strcpy(RNA_sequence, DNAtoRNA(lengthOfSequence, DNA_sequence));

	printf("RNA: %s \n", RNA_sequence);

	RNA_to_Amino_Acid(lengthOfSequence, RNA_sequence); // converts to amino acid && prints amino acids to the .txt file

	free(DNA_sequence);
	free(RNA_sequence);	
}
