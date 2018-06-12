/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** misc
*/

#include "../../include/fastatools.h"

int duplica_buster(char **kmer, int l)
{
	int i;

	for (i = 0; i < l; i++)
		if (strcmp(kmer[i], kmer[l]) == 0)
			return (0);
	return (1);
}

int is_the_string_legal(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (is_alphanum(str[i]) != 0)
			return (1);
	return (0);
}

void free_data(char **data)
{
	int i;

	for (i = 0; data[i] != NULL; i++)
		free(data[i]);
	free(data);
}