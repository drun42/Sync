/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//man prototype : const qualifier
int	ft_atoi(const char *nptr);

int main(void)
{
//man: converts the INITIAL PORTION of the string to int
//man: behaves as strtol(nptr, NULL, 10), minus the error detection
//strtol: optional whitespace, then ONE optional sign, then digits, then stop
//out of range input is undefined behavior, so it is not tested here
//expected is produced by libc atoi
char	*tab [20];
size_t	i;

//plain digits
tab[0] = "42";
//leading whitespace, sign, trailing garbage
tab[1] = "  -523 4AAAgreghrsth";
tab[2] = "+42";
tab[3] = "-42";
//the full isspace set : space \t \n \v \f \r
tab[4] = " \t\n\v\f\r7";
//no digits at all
tab[5] = "";
tab[6] = "abc";
tab[7] = "a42";
//sign with nothing behind it
tab[8] = "+";
tab[9] = "-";
//more than one sign : conversion stops, nothing is read
tab[10] = "++5";
tab[11] = "--5";
tab[12] = "+-5";
tab[13] = "-+5";
//whitespace is allowed BEFORE the sign only
tab[14] = "- 42";
//digits then non digits
tab[15] = "42abc";
tab[16] = "0042";
tab[17] = "1 2";
//the two int limits
tab[18] = "2147483647";
tab[19] = "-2147483648";


	//base cases
	printf("%s\n", "Base Cases:");
	i = 0;
	while (i < 20)
	{
		printf("case     : [%s]\n", tab[i]);
		printf("expected : %d\n", atoi(tab[i]));
		printf("actual   : %d\n", ft_atoi(tab[i]));
		i++;
	}
	printf("%s\n"," ");

	//the whitespace set and the single sign rule are the two usual traps
	printf("%s\n", "Trap Case, \" \\t\\n\\v\\f\\r7\":");
	printf("%s\n", "expected : 7");
	printf("actual   : %d\n", ft_atoi(" \t\n\v\f\r7"));
	printf("%s\n", "Trap Case, \"+-5\":");
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", ft_atoi("+-5"));
	printf("%s\n", "Trap Case, \"--5\":");
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", ft_atoi("--5"));
	printf("%s\n", "Trap Case, \"- 42\":");
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", ft_atoi("- 42"));
	printf("%s\n"," ");

}
