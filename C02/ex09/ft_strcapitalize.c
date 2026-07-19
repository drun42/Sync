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
	while (*str)
	{
		if (*(str - 1) == 32 && *str >= 'a' && *str <= 'z')
			*str -= 32;
		if (*(str -1) == (*str >= '\0' && *str <= ' '))
			if ((*str >= 'A' && *str <= 'Z'))
				*str += 32;
		str++;
	}
	return (str);
}
/*
int main (void)
{
	char src[] = "hi, how are you? 42words forty-two; fifty+and+one";
	char *str = &src[0];
	printf("%s", ft_strcapitalize(str));

*/