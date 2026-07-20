/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:43:25 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/20 09:11:06 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strncat(char *dest, char *src, unsigned int nb);
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
    {
        i++;
    }
    while (j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return(dest);
}
