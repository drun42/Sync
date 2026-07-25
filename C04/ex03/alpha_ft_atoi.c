/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_ft_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 02:39:31 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/25 11:01:02 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

	int             ft_atoi(char *str)
{
        int             sign;
        long    r;

        r = 0;
        sign = 1;
        while (*str == 32 || (*str >= 9 && *str <= 13))
                str++;
        if (*str == '-' || *str == '+')
        {
                if (*str == '-')
                        sign = -1;
                str++;
        }
        while (*str >= '0' && *str <= '9')
        {
                r = r * 10 + *str - '0';
                str++;
        }
        return (sign * (int)r);
}

int             main(void)
{
        char a[] = "    \n\n\v\f\r\t -5234AAAgreghrsth";//-5234
        printf("%d\n",ft_atoi(a));
}
