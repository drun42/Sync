/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:45:03 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/13 23:26:55 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{	
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i -1] == 32 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if(str[i - 1] >= 0 && str[i - 1] <= 32) && (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return(str);
}

int main (void)
{
	printf("%s", ft_strcapitalize("hi, how are you? 42words forty-two; fifty+and+one"));
}
