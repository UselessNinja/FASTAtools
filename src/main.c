/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** main
*/

#include "../include/fastatools.h"

void help(void)
{
	printf("USAGE\n");
	printf("\t./FASTAtools option\n\n");
	printf("DESCRIPTION\n");
	printf("\toption 1: read FASTA from standard input, write the DNA ");
	printf("sequences to the standard output\n");
	printf("\toption 2: read FASTA from standard input, write the RNA ");
	printf("sequences to the standard output\n");
	printf("\toption 3: read FASTA from standard input, write the ");
	printf("reverse complement to the standard output\n");
	printf("\toption 4: read FASTA from standard input, write the k-mer ");
	printf("list to the standard output\n");
	printf("\toption 5: read FASTA from standard input, write the coding");
	printf(" sequences lsit to the standard output\n");
	printf("\toption 6: read FASTA from the standard input, write the ");
	printf("amino acids list to the standard output\n");
	printf("\toption 7: read FASTA from standard input containing ");
	printf("exactly 2 sequences, align them and write the result to the ");
	printf("standard output\n");
	printf("\tk: size of k-mers for option 4\n");
	exit(0);
}

int main(int ac, char **av)
{
	data_t data;

	if (ac < 2 || ac > 3)
		return (84);
	if (strcmp("-h", av[1]) == 0)
		help();
	if (av[1] == NULL || av[1][0] == '\0')
		return (84);
	data.option = my_getnumber(av[1]);
	if (data.option < 1 && data.option > 7)
		return (84);
	if (data.option == 4) {
		if (av[2] == NULL || av[2][0] == '\0')
			return (84);
		data.size_kmers = my_getnumber(av[2]);
		if (data.size_kmers < 1)
			return (84);
	}
	fastatools(&data);
	return (0);
}