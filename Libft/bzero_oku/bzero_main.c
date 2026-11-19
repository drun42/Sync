/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : bzero returns NOTHING, same as in your libft.h
void	ft_bzero(void *s, size_t n);

int main(void)
{
//man: writes n zero bytes to the area pointed to by s
//expected is produced by libc bzero on ref, actual by ft_bzero on buf
size_t	n;
char	buf [10];
char	ref [10];

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
	memset(buf, 7, 10);
	memset(ref, 7, 10);
	printf("%s\n", "Memory state (buf filled with 7):");
	printf("%s", "expected : ");
	bytes_print(ref);
	printf("%s", "actual   : ");
	bytes_print(buf);
	printf("%s\n"," ");

	//base case
	printf("%s\n", "Base Case, bzero(buf, 3):");
	bzero(ref, n);
	ft_bzero(buf, n);
	printf("%s", "expected : ");
	bytes_print(ref);
	printf("%s", "actual   : ");
	bytes_print(buf);
	printf("%s\n"," ");

}
