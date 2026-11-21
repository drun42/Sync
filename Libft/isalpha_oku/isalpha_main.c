/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

//subject prototype
int	ft_isalpha(int c);

int main(void)
{
//man: checks for an alphabetic character
//SUBJECT: the return value must be exactly 1 or 0, not just any non zero
//expected is produced by libc isalpha, forced to 1 or 0
int	tab [18];
int	i;
int	bad;

tab[0] = 'a';
tab[1] = 'z';
tab[2] = 'A';
tab[3] = 'Z';
tab[4] = 'g';
tab[5] = '0';
tab[6] = '9';
tab[7] = '5';
tab[8] = ' ';
tab[9] = '\t';
tab[10] = '\n';
tab[11] = 0;
tab[12] = '+';
tab[13] = '~';
tab[14] = 31;
tab[15] = 127;
tab[16] = 128;
tab[17] = 255;


	//base cases
	printf("%s\n", "Base Cases:");
	i = 0;
	while (i < 18)
	{
		printf("case     : %d '%c'\n", tab[i], isprint(tab[i]) ? tab[i] : '.');
		printf("expected : %d\n", isalpha(tab[i]) ? 1 : 0);
		printf("actual   : %d\n", ft_isalpha(tab[i]));
		i++;
	}
	printf("%s\n"," ");

	//whole unsigned char range at once, only the mismatch count is printed
	printf("%s\n", "Full Range Case (0 to 255), number of mismatches:");
	bad = 0;
	i = 0;
	while (i < 256)
	{
		if (ft_isalpha(i) != (isalpha(i) ? 1 : 0))
			bad++;
		i++;
	}
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", bad);
	printf("%s\n"," ");

	//the subject rule : nothing but 1 and 0 may come out
	printf("%s\n", "Return Value Case, values outside {0, 1}:");
	bad = 0;
	i = 0;
	while (i < 256)
	{
		if (ft_isalpha(i) != 0 && ft_isalpha(i) != 1)
			bad++;
		i++;
	}
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", bad);
	printf("%s\n"," ");

}
