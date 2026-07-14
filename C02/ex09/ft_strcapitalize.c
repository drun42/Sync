/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:45:03 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/13 23:45:41 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
// passing as argument pointer to a string so litterally str[0]
{
	while(*str)
	// while str[i] != '\0'
	{
		if(*(str - 1) == 32 /* if str[i - 1] == space*/  && *str >= 'a' && *str <= 'z'/* and str[0] == a-z*/)

			*str -= 32;/* then str[i] a -> A*/
		if((*(str -1) == (*str >= '\0' && *str <= ' ')/* if str[i - 1] == non printable char*/ && (*str >= 'A' && *str <= 'Z')/* and str[i] == A - Z*/))
			*str += 32;/*then A = a*/
		str++;/* str[i] += 1*/
	}
	return(str);/*return pointer to the last character in string, in my example - e*/
}

int main (void)
{
	char src[] = "hi, how are you? 42words forty-two; fifty+and+one";
	char *str = &src[0];
	printf("%s", ft_strcapitalize(
