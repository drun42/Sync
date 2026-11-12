/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:49:38 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/12 15:38:36 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int     main(void)
{ 

// 	strcmp -  67, -1, 1, 130
        char str1[] = "ABC";
        char str2[] = "AB";
        char *s1 = &str1[0];
        char *s2 = &str2[0];    
        printf("%d,\n", ft_strcmp(s1, s2));

        char str3[] = "ABC";
        char str4[] = "ABD";
        char *s3 = &str3[0];
        char *s4 = &str4[0];
        printf("%d,\n", ft_strcmp(s3, s4));

        char str5[] = "ABD";
        char str6[] = "ABC";
        char *s5 = &str5[0];
        char *s6 = &str6[0];    
        printf("%d,\n", ft_strcmp(s5, s6));

        char str7[] = "ABé";
        char str8[] = "ABA";
        //the return have to be 130
        char *s7 = &str7[0];
        char *s8 = &str8[0];
        printf("%d,\n", ft_strcmp(s7, s8));

}

