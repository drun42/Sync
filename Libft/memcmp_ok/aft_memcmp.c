/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_memcmp : compare the first n bytes of two memory areas.
**
** man: the memcmp() function compares the first n bytes (each interpreted
** as UNSIGNED CHAR) of the memory areas s1 and s2.
** man: it returns an integer less than, equal to, or greater than zero if
** the first n bytes of s1 are found, respectively, to be less than, to
** match, or be greater than the first n bytes of s2.
**
** The difference with ft_strncmp is what stops the comparison. strncmp
** works on strings and stops on a '\0'. memcmp works on raw memory: a
** '\0' is an ordinary byte and the comparison runs over it. Only n stops
** it. So "ab\0cd" and "ab\0ce" are EQUAL for strncmp with n = 5 and
** DIFFERENT for memcmp with n = 5.
**
** 'unsigned char' again decides the sign of the result: on x86 a plain
** char is signed, so the byte 0200 would read as -128 and the comparison
** would come out with the wrong sign.
**
** Only the sign of the return value is part of the contract; the usual
** choice is the difference of the first two bytes that differ.
**
** n == 0 compares nothing: the answer is 0 and neither area is read.
** =========================================================================
*/

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	// unsigned char * on both sides, as man requires
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	// only n stops this loop, a '\0' is just another byte
	while (i < n)
	{
		// first difference decides the answer
		if (p1[i] != p2[i])
			// both operands are unsigned bytes, so the sign is correct
			return (p1[i] - p2[i]);
		i++;
	}
	// n bytes compared and no difference found
	return (0);
}
