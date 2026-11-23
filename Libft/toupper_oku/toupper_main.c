/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/21 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

//man prototype : takes an int, returns an int
int	ft_toupper(int c);

int main(void)
{
//man: converts the letter c to upper case, if possible
//man: everything that is not a letter comes back unchanged
//expected is produced by libc toupper
int	tab [16];
int	i;
int	bad;

//letters that MUST change
tab[0] = 'a';
tab[1] = 'z';
tab[2] = 'g';
//letters already in the target case, MUST stay
tab[3] = 'A';
tab[4] = 'Z';
tab[5] = 'G';
//the four ASCII neighbours of the letter ranges, the off by one traps
tab[6] = '@';
tab[7] = '[';
tab[8] = '`';
tab[9] = '{';
//other non letters
tab[10] = '0';
tab[11] = '9';
tab[12] = ' ';
tab[13] = 0;
tab[14] = 127;
tab[15] = 255;


int vis(int c)
{
	if (isprint(c))
		return (c);
	return ('.');
}


void show(int c)
{
	printf("case %4d '%c'  |  expected %4d '%c'  |  actual %4d '%c'\n",
		c, vis(c),
		toupper(c), vis(toupper(c)),
		ft_toupper(c), vis(ft_toupper(c)));
}


	//base cases, every line shows the value AND the character it stands for
	printf("%s\n", "Base Cases:");
	i = 0;
	while (i < 16)
	{
		show(tab[i]);
		i++;
	}
	printf("%s\n"," ");

	//man: the argument must be representable as unsigned char, or equal to EOF
	printf("%s\n", "EOF Case, ft_toupper(-1):");
	show(-1);
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
