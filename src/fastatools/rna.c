/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** rna
*/

#include "../../include/fastatools.h"

void is_it_rna(int c)
{
	if (c == 97 || c == 103 || c == 99 || c == 110) {
		c -= 32;
		write(1, &c, 1);
	} else if (c == 65 || c == 71 || c == 67 || c == 78)
		write(1, &c ,1);
	else if (c == 116 || c == 84)
		write(1, "U", 1);
}

void rna(void)
{
	int c;
	int a = 0;

	while (1337) {
		c = getchar();
		if (c == EOF) {
			write(1, "\n", 1);
			break;
		}
		if (c == 62)
			a = print_until_eol(c, a);
		is_it_rna(c);
	}
}