/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

//man prototype : takes an int, returns an int
int	ft_toupper(int c);

int main(void)
{
//man: converts the letter c to upper case, if possible
//man: a lower case letter becomes upper case, everything else comes back unchanged
//expected is produced by libc toupper
int	tab [16];
int	i;
int	bad;

tab[0] = 'a';
tab[1] = 'z';
tab[2] = 'A';
tab[3] = 'Z';
tab[4] = 'g';
tab[5] = 'G';
tab[6] = '0';
tab[7] = '9';
tab[8] = ' ';
tab[9] = '\n';
tab[10] = 0;
tab[11] = '+';
tab[12] = '~';
tab[13] = 127;
tab[14] = 128;
tab[15] = 255;


	//base cases, printed as value then as the character itself
	printf("%s\n", "Base Cases:");
	i = 0;
	while (i < 16)
	{
		printf("case     : %d\n", tab[i]);
		printf("expected : %d\n", toupper(tab[i]));
		printf("actual   : %d\n", ft_toupper(tab[i]));
		i++;
	}
	printf("%s\n"," ");

	//non letters must come back untouched, not zeroed
	printf("%s\n", "Unchanged Case, ft_toupper('5'):");
	printf("expected : %d\n", toupper('5'));
	printf("actual   : %d\n", ft_toupper('5'));
	printf("%s\n"," ");

	//whole unsigned char range at once
	printf("%s\n", "Full Range Case (0 to 255), number of mismatches:");
	bad = 0;
	i = 0;
	while (i < 256)
	{
		if (ft_toupper(i) != toupper(i))
			bad++;
		i++;
	}
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", bad);
	printf("%s\n"," ");

}
