/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** data
*/

#include "../../include/fastatools.h"

char **read_file(void)
{
	int i;
	int guard;
	char *temp = NULL;
	char **buffer = malloc(sizeof(char *) * 1000);
	size_t len = 0;

	for (i = 0; 1337; i++) {
		guard = getline(&temp, &len, stdin);
		if (guard == -1) {
			buffer[i] = NULL;
			break;
		}
		buffer[i] = strdup(temp);
	}
	return (buffer);
}

int print_until_eol(int c, int a)
{
	if (a != 0)
		write (1, "\n", 1);
	a++;
	write(1, &c, 1);
	while (c != 10) {
		c = getchar();
		write(1, &c, 1);
	}
	return (a);
}

char *format_string(char *str)
{
	int i;
	int j = 0;
	char *formated = malloc(sizeof(char) * (strlen(str) + 1));

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == 97 || str[i] == 116 || str[i] == 103
			|| str[i] == 99 || str[i] == 110) {
			formated[j] = str[i] - 32;
			j++;
		} else if (str[i] == 65 || str[i] == 84 || str[i] == 71
			|| str[i] == 67 || str[i] == 78) {
			formated[j] = str[i];
			j++;
		}
	}
	return (formated);
}

void clean_data(char **file)
{
	int i = 0;
	int j;

	for (i = 0; file[i] != NULL; i++)
		if (strchr(file[i], 62) == NULL) {
			j = i;
			while (file[i + 1] != NULL &&
				strchr(file[i + 1], 62) == NULL) {
				file[i + 1] =
					my_strcat_dup(file[i],
					strdup(file[i + 1]));
				file[i] = "\0";
				i++;
			}
			i = j;
			file[i] = format_string(file[i]);
		}
}