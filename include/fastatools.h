/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** fastatools
*/

#ifndef FASTATOOLS_H_
	#define FASTATOOLS_H_

#include <stdio.h>
#include "../lib/my/my.h"

typedef struct data_s {
	int option;
	int size_kmers;
} data_t;

/*
** FASTAtools
*/

void fastatools(data_t *data);

/*
** Tools 1 to 7
*/

void dna(void);
void rna(void);
void reversed_complement(void);
void k_mers(int k);

/*
** data_management and printing
*/

int print_until_eol(int c, int a);
char **read_file(void);
void clean_data(char **file);
int duplica_buster(char **kmer, int l);
int is_the_string_legal(char *str);
void free_data(char **data);

#endif /* !FASTATOOLS_H_ */
