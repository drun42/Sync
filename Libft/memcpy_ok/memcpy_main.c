/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:33:36 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/14 13:11:27 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

size_t n = 5;
void *ft_memcpy(void *dest, const void *src, size_t n);

int main(void)
{
//return
size_t	x;
x = 10; 
char	src [x];
char	dest [x];

char *srcc;

srcc = (char*)src;


void clear(char *d, char *s,  size_t x)
{
	memset(d, 0, x);
	memset(s, 7, x);
	printf("%s\n", "mem and dest cleared");

}



void src_dest_print(char *d, char *s, size_t x)
{
	//printing both strings
	printf("%s\n","src :");
        for (size_t i = 0; i < x; i++)
        {
                printf("%d",s[i]);
        }
	printf("%s\n"," ");
	printf("%s\n", "dest :");

       	for (size_t i = 0; i < x; i++)
        {
                printf("%d",d[i]);
        }
	printf("%s\n"," ");
}


	//memory state
	 printf("%s\n", "Memory tsate:");
	src_dest_print(dest, src, x);
	clear(dest, src, x);
	src_dest_print(dest, src, x);
	printf("%s\n"," ");

	//base case
	printf("%s\n", "Base Case:");
	ft_memcpy(dest, src, n);
	printf("%s\n", "memcpy used");
	src_dest_print(dest, src,  x);
	clear(dest, src, x);
	printf("%s\n"," ");

	//n = 0 
	printf("%s\n", "n = 0 Case:");
	ft_memcpy(dest, src, 0);
	src_dest_print(dest, src, x);
        clear(dest, src, x);
	printf("%s\n"," ");

	//string iteration check
	printf("%s\n", "String/byte iteration check :");
	srcc[3] = '\0';
	ft_memcpy(dest, src, n);
	printf("%s\n", "memcpy used");
	src_dest_print(dest, src,  x);
	clear(dest, src, x);
	printf("%s\n"," ");



}

