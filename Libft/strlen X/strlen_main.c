/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : size_t, const qualifier
size_t	ft_strlen(const char *s);

int main(void)
{
//man: counts the bytes before the terminating '\0', the '\0' itself is NOT counted
char	*tab [6];
char	embedded [8] = "abc\0def";
size_t	i;

tab[0] = "likun";
tab[1] = "";
tab[2] = " ";
tab[3] = "42 Nice\n";
tab[4] = "\0abc";
tab[5] = "0123456789012345678901234567890123456789";


	//base cases, compared against libc
	printf("%s\n", "Base Cases (ft vs libc):");
	i = 0;
	while (i < 6)
	{
		printf("[%s] ft : %zu  libc : %zu\n", tab[i], ft_strlen(tab[i]),
			strlen(tab[i]));
		i++;
	}
	printf("%s\n"," ");

	//stops at the first '\0', does not run to the end of the buffer
	printf("%s\n", "Embedded '\\0' Case:");
	printf("ft : %zu  libc : %zu  expected : 3\n", ft_strlen(embedded),
		strlen(embedded));
	printf("%s\n"," ");

	//return type is size_t, not int : no negative result exists
	printf("%s\n", "Return Type Case:");
	printf("ft_strlen(\"\") == 0 : %d\n", ft_strlen("") == 0);
	printf("%s\n"," ");

}
