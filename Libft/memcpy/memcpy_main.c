/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:33:36 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/13 17:03:44 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
	int n = 5;
void *ft_memcpy(void *dest, const void *src, size_t n);

int main(void)
{
//return

char src [10];
	char dest [10];



void clean(void *dest, const void *src, size_t n)
{
	//erasing previous usage result
	int	i;
	
	i = 0;

	for (int i = 0; i < 10 ; i++)
	{
		src[i] = 7;
		dest[i] = 0;
	}
}

void src_dest_print(void *dest, const void *src, size_t n)
{
	//printing both strings
        for (int i = 0; i < n+1; i++)
        {
                printf("%d\n",src[i]);
        }
	printf("%ld\n",111111111111111111);

       	for (int i = 0; i < n+1; i++)
        {
                printf("%d\n",dest[i]);
        }
	printf("%ld\n",111111111111111111);
}

void dest_print(void *dest, size_t n)
{
	printf("d%\n","dest:");
        for (int i = 0; i < n+1; i++)
        {
                printf("%d\n",dest[i]);
        }
}



	//func basic usage
	ft_memcpy(dest,src,n)
	dest_print(dest,n)
}

