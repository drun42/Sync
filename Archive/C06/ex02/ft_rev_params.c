/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 05:26:08 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/26 05:44:15 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char **argv) 
{
        int     i;
        int     j;

        j = argc - 1;
        if (argc == 0)
                return (0);
        while (j != 0)
        {
                i = 0;
                while (argv[j][i])
                {
                        write(1, &argv[j][i], 1);
                        i++;
                }
                write(1, "\n", 1);
                j--;
        }
} 
