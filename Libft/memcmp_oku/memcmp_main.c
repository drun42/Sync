/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : two const void *, size_t
int	ft_memcmp(const void *s1, const void *s2, size_t n);

int main(void)
{
//man: compares the first n bytes of the two memory areas s1 and s2
//man: the bytes are interpreted as UNSIGNED CHAR
//man: returns < 0, 0 or > 0 : only the SIGN has to match libc
//unlike strncmp, memcmp does NOT stop on a '\0'
//expected is produced by libc memcmp
char	a [6] = "ab\0cd";
char	b [6] = "ab\0ce";
char	hi [2] = "\200";
char	lo [2] = "\001";


int sign(int v)
{
	if (v > 0)
		return (1);
	if (v < 0)
		return (-1);
	return (0);
}


void both(char *s1, char *s2, size_t n)
{
	printf("expected : %d  (sign %d)\n", memcmp(s1, s2, n),
		sign(memcmp(s1, s2, n)));
	printf("actual   : %d  (sign %d)\n", ft_memcmp(s1, s2, n),
		sign(ft_memcmp(s1, s2, n)));
}


	//identical buffers
	printf("%s\n", "Base Case, memcmp(\"abc\", \"abc\", 3):");
	both("abc", "abc", 3);
	printf("%s\n"," ");

	//s1 < s2 and s2 > s1
	printf("%s\n", "Less Case, memcmp(\"abc\", \"abd\", 3):");
	both("abc", "abd", 3);
	printf("%s\n", "Greater Case, memcmp(\"abd\", \"abc\", 3):");
	both("abd", "abc", 3);
	printf("%s\n"," ");

	//difference sits beyond n
	printf("%s\n", "n Limit Case, memcmp(\"abc\", \"abd\", 2):");
	both("abc", "abd", 2);
	printf("%s\n"," ");

	//n = 0 : nothing is compared
	printf("%s\n", "n = 0 Case, memcmp(\"abc\", \"xyz\", 0):");
	both("abc", "xyz", 0);
	printf("%s\n"," ");

	//the '\0' does not stop memcmp : the difference is at index 4
	printf("%s\n", "Past '\\0' Case, \"ab\\0cd\" vs \"ab\\0ce\", n = 5:");
	both(a, b, 5);
	printf("%s\n"," ");

	//unsigned char : '\200' is the BIGGER byte
	printf("%s\n", "Unsigned char Case, \"\\200\" vs \"\\001\", n = 1:");
	both(hi, lo, 1);
	printf("%s\n"," ");

}
