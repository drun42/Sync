/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:33:36 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype
void	*ft_memcpy(void *dest, const void *src, size_t n);

int main(void)
{
//man: copies n bytes from src to dest, the areas must NOT overlap, returns dest
//expected is produced by libc memcpy on ref, actual by ft_memcpy on dest
size_t	x;
size_t	n;

x = 10;
n = 5;

char	src [x];
char	dest [x];
char	ref [x];
void	*ret;


void clear(void)
{
	memset(src, 7, x);
	memset(dest, 0, x);
	memset(ref, 0, x);
}


void bytes_print(char *b)
{
	for (size_t i = 0; i < x; i++)
	{
		printf("%d", b[i]);
	}
	printf("%s\n", "");
}


void compare(void)
{
	printf("%s", "expected : ");
	bytes_print(ref);
	printf("%s", "actual   : ");
	bytes_print(dest);
}


	//memory state
	clear();
	printf("%s\n", "Memory state (src = 7, dest = 0):");
	printf("src      : ");
	bytes_print(src);
	compare();
	printf("%s\n"," ");

	//base case
	printf("%s\n", "Base Case, memcpy(dest, src, 5):");
	memcpy(ref, src, n);
	ft_memcpy(dest, src, n);
	compare();
	printf("%s\n"," ");

	//n = 0 : dest must stay untouched
	clear();
	printf("%s\n", "n = 0 Case:");
	memcpy(ref, src, 0);
	ft_memcpy(dest, src, 0);
	compare();
	printf("%s\n"," ");

	//bytes, not a string : a '\0' inside src does not stop the copy
	clear();
	src[3] = 0;
	printf("%s\n", "Byte iteration check (copies past '\\0'):");
	memcpy(ref, src, n);
	ft_memcpy(dest, src, n);
	compare();
	printf("%s\n"," ");

	//return value
	clear();
	printf("%s\n", "Return Value Case:");
	ret = ft_memcpy(dest, src, n);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ret == (void *)dest);
	printf("%s\n"," ");

}
