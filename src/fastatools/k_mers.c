/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** k_mers
*/

#include "../../include/fastatools.h"

int get_kmers(int k, int l, char *str, char **kmer)
{
	int i = 0;
	int j = 0;
	int m = 0;

	for (i = 0; str[i] != 0; i++) {
		kmer[l] = malloc(sizeof(char) * (k + 1));
		for (j = i, m = 0; j < i + k; j++, m++)
			kmer[l][m] = str[j];
		kmer[l][m] = '\0';
		if (duplica_buster(kmer, l) != 0 && strlen(kmer[l]) ==
			(size_t)k && is_the_string_legal(kmer[l]) == 0) {
			l++;
		} else
			free(kmer[l]);
	}
	return (l);
}

static int comparison(void const *a, void const *b)
{
	const char *pa = *(const char **)a;
	const char *pb = *(const char **)b;

	return (strcmp(pa, pb));
}

void k_mers(int k)
{
	int i;
	int l = 0;
	char **data = read_file();
	char **kmer = malloc(sizeof(char *) * 1000);

	clean_data(data);
	for (i = 1; data[i] != NULL; i++) {
		if (data[i] != NULL && data[i][0] != '\0' && 
			strchr(data[i], 62) == NULL) {
			l = get_kmers(k,l, data[i], kmer);
		}
	}
	kmer[l] = NULL;
	qsort(kmer, l, sizeof(char*), comparison);
	for (i = 0; i < l; i++) {
		printf("%s\n", kmer[i]);
	}
	free_data(kmer);
	free_data(data);
}