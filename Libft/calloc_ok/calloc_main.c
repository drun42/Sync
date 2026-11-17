/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//man prototype : two size_t, returns void *
void	*ft_calloc(size_t nmemb, size_t size);

int main(void)
{
//man: allocates memory for an array of nmemb elements of size bytes each
//man: the memory is set to ZERO, and is freed with free
//SUBJECT: if nmemb or size is 0, it must return a UNIQUE pointer that can
//SUBJECT: still be passed to free successfully, so NOT a plain NULL
//run it under valgrind too : valgrind --leak-check=full ./a.out
char	*p;
char	*q;
int	*ip;
size_t	i;
int	bad;

	//base case : 10 bytes, all of them zero
	printf("%s\n", "Base Case, ft_calloc(10, 1) not NULL:");
	p = ft_calloc(10, 1);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", p != NULL);
	printf("%s\n", "Base Case, number of non zero bytes out of 10:");
	bad = 0;
	i = 0;
	while (i < 10)
	{
		if (p[i] != 0)
			bad++;
		i++;
	}
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", bad);
	free(p);
	printf("%s\n", "p freed");
	printf("%s\n"," ");

	//the block really is nmemb * size bytes : write into all of it
	printf("%s\n", "Size Case, ft_calloc(5, sizeof(int)), 20 bytes zeroed:");
	ip = ft_calloc(5, sizeof(int));
	bad = 0;
	i = 0;
	while (i < 5)
	{
		if (ip[i] != 0)
			bad++;
		ip[i] = 42;
		i++;
	}
	printf("%s\n", "expected : 0");
	printf("actual   : %d\n", bad);
	printf("%s\n", "Size Case, last element readable after writing:");
	printf("%s\n", "expected : 42");
	printf("actual   : %d\n", ip[4]);
	free(ip);
	printf("%s\n", "ip freed");
	printf("%s\n"," ");

	//nmemb = 0, size = 0, both 0 : a unique freeable pointer each time
	printf("%s\n", "Zero Case, ft_calloc(0, 1) not NULL:");
	p = ft_calloc(0, 1);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", p != NULL);
	free(p);
	printf("%s\n", "Zero Case, ft_calloc(1, 0) not NULL:");
	p = ft_calloc(1, 0);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", p != NULL);
	free(p);
	printf("%s\n", "Zero Case, ft_calloc(0, 0) not NULL:");
	p = ft_calloc(0, 0);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", p != NULL);
	free(p);
	printf("%s\n", "all three freed without crashing");
	printf("%s\n"," ");

	//two separate calls must not hand out the same block
	printf("%s\n", "Unique Case, two calls give different pointers:");
	p = ft_calloc(4, 1);
	q = ft_calloc(4, 1);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", p != q);
	free(p);
	free(q);
	printf("%s\n", "both freed");
	printf("%s\n"," ");

}
