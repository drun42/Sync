/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:37:30 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t n = 5;
void	*ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
//man: copies n bytes from src to dest, areas MAY OVERLAP, returns dest
size_t	x;
x = 10;

char	src [x];
char	dest [x];
char	buf [11];
void	*ret;

char *srcc;

srcc = (char*)src;


void clear(char *d, char *s,  size_t x)
{
	memset(d, 0, x);
	memset(s, 7, x);
	printf("%s\n", "src and dest cleared");

}



void src_dest_print(char *d, char *s, size_t x)
{
	//printing both buffers as bytes
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



void buf_reset(char *b)
{
	memcpy(b, "0123456789", 11);
}



void buf_print(char *b)
{
	printf("buf : %s\n", b);
}


	//memory state
	printf("%s\n", "Memory state:");
	src_dest_print(dest, src, x);
	clear(dest, src, x);
	src_dest_print(dest, src, x);
	printf("%s\n"," ");

	//base case, no overlap
	printf("%s\n", "Base Case (no overlap):");
	ft_memmove(dest, src, n);
	printf("%s\n", "memmove used");
	src_dest_print(dest, src,  x);
	clear(dest, src, x);
	printf("%s\n"," ");

	//n = 0
	printf("%s\n", "n = 0 Case:");
	ft_memmove(dest, src, 0);
	src_dest_print(dest, src, x);
	clear(dest, src, x);
	printf("%s\n"," ");

	//return value
	printf("%s\n", "Return Value Case:");
	ret = ft_memmove(dest, src, n);
	printf("ret == dest : %d\n", ret == (void *)dest);
	clear(dest, src, x);
	printf("%s\n"," ");

	//bytes, not a string
	printf("%s\n", "Byte iteration check (copies past '\\0'):");
	srcc[2] = 0;
	ft_memmove(dest, src, n);
	printf("%s\n", "memmove used");
	src_dest_print(dest, src,  x);
	clear(dest, src, x);
	printf("%s\n"," ");

	//overlap, dest after src
	printf("%s\n", "Overlap Case, dest > src :");
	buf_reset(buf);
	buf_print(buf);
	ft_memmove(buf + 3, buf, n);
	buf_print(buf);
	printf("%s\n", "expected : 0120123489");
	printf("%s\n"," ");

	//overlap, dest before src
	printf("%s\n", "Overlap Case, dest < src :");
	buf_reset(buf);
	buf_print(buf);
	ft_memmove(buf, buf + 3, n);
	buf_print(buf);
	printf("%s\n", "expected : 3456756789");
	printf("%s\n"," ");

	//dest and src are the same
	printf("%s\n", "Overlap Case, dest == src :");
	buf_reset(buf);
	ft_memmove(buf, buf, n);
	buf_print(buf);
	printf("%s\n", "expected : 0123456789");
	printf("%s\n"," ");

}
