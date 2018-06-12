/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** fasta
*/

#include "../../include/fastatools.h"

void fastatools(data_t *data)
{
	if (data->option == 1) {
		dna();
		exit(0);
	}
	if (data->option == 2) {
		rna();
		exit(0);
	}
	if (data->option == 3) {
		reversed_complement();
		exit(0);
	}
	if (data->option == 4) {
		k_mers(data->size_kmers);
		exit(0);
	}
}