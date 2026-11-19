/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype
void	*ft_memset(void *s, int c, size_t n);

int main(void)
{
//man: fills the first n bytes of s with the byte c, returns s
//expected is produced by libc memset on ref, actual by ft_memset on buf
int	c;
size_t	n;
char	buf [10];
char	ref [10];

c = 7;
n = 3;


void bytes_print(char *b)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", b[i]);
	}
	printf("%s\n", "");
}


	//memory state
	memset(buf, 0, 10);
	memset(ref, 0, 10);
	printf("%s\n", "Memory state (buf zeroed):");
	printf("%s", "expected : ");
	bytes_print(ref);
	printf("%s", "actual   : ");
	bytes_print(buf);
	printf("%s\n"," ");

	//base case
	printf("%s\n", "Base Case, memset(buf, 7, 3):");
	memset(ref, c, n);
	ft_memset(buf, c, n);
	printf("%s", "expected : ");
	bytes_print(ref);
	printf("%s", "actual   : ");
	bytes_print(buf);
	printf("%s\n"," ");

}
