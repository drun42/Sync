# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
/*   ft_strdup.c                                        :+:      :+:    :+:   */
#                                                     +:+ +:+         +:+      #
#    By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/19 17:03:27 by dshofer           #+#    #+#              #
/*   Updated: 2026/09/19 17:22:30 by dshofer          ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src);
{
	int	len;

	len = ft_strlen(*src);
	return len;
}


int main(void)
{
	char	str[] = "likun";

	printf("%d", ft_strdup(str));
}

