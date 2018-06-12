/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** requirement
*/

int is_nonalphanum(char c)
{
	if (c > 96 && c < 123)
		return (1);
	if ((c > 47 && c < 58) || (c > 64 && c < 91))
		return (2);
	return (0);
}

char *capitalize_the_next_word(char *str, int i)
{
	for (; str[i] != '\0'; i++) {
		if (is_nonalphanum(str[i]) == 1) {
			str[i] -= 32;
			break;
		}
		if (is_nonalphanum(str[i]) == 2)
			break;
	}
	return (str);
}

char *my_strcapitalize_synthesis(char *str)
{
	int i;

	if (is_nonalphanum(str[0]) == 1)
		str[0] -= 32;
	for (i = 0; str[i] != '\0'; i++) {
		if (is_nonalphanum(str[i]) == 0) {
			i++;
			str = capitalize_the_next_word(str, i);
		}
	}
	return (str);
}