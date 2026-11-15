/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : const qualifiers, size_t n
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
//man: compares at most the first n bytes of s1 and s2
//man: the bytes are compared as UNSIGNED CHAR
//man: returns < 0, 0 or > 0 : only the SIGN has to match libc, not the value
char	*a [9];
char	*b [9];
size_t	len [9];
size_t	i;

//equal, n past the end
a[0] = "ABC";		b[0] = "ABC";		len[0] = 10;
//s1 < s2
a[1] = "ABC";		b[1] = "ABD";		len[1] = 10;
//s1 > s2
a[2] = "ABD";		b[2] = "ABC";		len[2] = 10;
//s1 is a prefix of s2 : stops at the '\0' of s1
a[3] = "ABC";		b[3] = "ABCD";		len[3] = 10;
//difference sits beyond n : must not be seen
a[4] = "ABC";		b[4] = "ABD";		len[4] = 2;
//n = 0 : nothing is compared at all
a[5] = "ABC";		b[5] = "XYZ";		len[5] = 0;
//empty against non empty
a[6] = "";		b[6] = "ABC";		len[6] = 3;
//byte > 127 : signed vs unsigned char changes the SIGN of the result
a[7] = "\200";		b[7] = "\001";		len[7] = 1;
a[8] = "\001";		b[8] = "\200";		len[8] = 1;


int sign(int v)
{
	if (v > 0)
		return (1);
	if (v < 0)
		return (-1);
	return (0);
}


	//every case against libc
	printf("%s\n", "Base Cases:");
	i = 0;
	while (i < 9)
	{
		printf("case     : [%s] [%s] n = %zu\n", a[i], b[i], len[i]);
		printf("expected : %d  (sign %d)\n", strncmp(a[i], b[i], len[i]),
			sign(strncmp(a[i], b[i], len[i])));
		printf("actual   : %d  (sign %d)\n", ft_strncmp(a[i], b[i], len[i]),
			sign(ft_strncmp(a[i], b[i], len[i])));
		i++;
	}
	printf("%s\n"," ");

	//the unsigned char rule, written out as a yes/no check
	printf("%s\n", "Unsigned char Case, ft(\"\\200\",\"\\001\",1) > 0:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ft_strncmp("\200", "\001", 1) > 0);
	printf("%s\n", "Unsigned char Case, ft(\"\\001\",\"\\200\",1) < 0:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ft_strncmp("\001", "\200", 1) < 0);
	printf("%s\n"," ");

	//does not read past a '\0' inside the buffers
	printf("%s\n", "Embedded '\\0' Case, ft(\"ab\\0cd\",\"ab\\0xy\",5):");
	printf("expected : %d\n", strncmp("ab\0cd", "ab\0xy", 5));
	printf("actual   : %d\n", ft_strncmp("ab\0cd", "ab\0xy", 5));
	printf("%s\n"," ");

}
