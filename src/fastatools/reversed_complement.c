/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** reversed_complement
*/

#include "../../include/fastatools.h"

void reverse_and_edit(char *str)
{
	int len = strlen(str) - 1;
	int c;
	int i;
	char *dup = strdup(str);

	for (i = 0 ; len >= 0; len--) {
		c = dup[i];
		str[len] = c == 65 ? 84 : c == 84 ? 65 :
		c == 71 ? 67 : c == 67 ? 71 : c;
		i++;
	}
	printf("%s", str);
	free(dup);
}

void reversed_complement(void)
{
	int i = 0;
	int a = 0;
	char **file = read_file();

	clean_data(file);
	for (i = 0; file[i] != NULL; i++) {
		if (file[i][0] != '\0' && strchr(file[i], 62) != NULL) {
			if (a != 0)
				printf("\n");
			printf("%s", file[i]);
			a++;
		} else
			reverse_and_edit(file[i]);
	}
	printf("\n");
	free_data(file);
}