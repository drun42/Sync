/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strncmp : compare at most n bytes of two strings.
**
** man: the strncmp() function compares only the first (at most) n bytes
** of s1 and s2.
** man: it returns an integer less than, equal to, or greater than zero if
** s1 is found, respectively, to be less than, to match, or be greater
** than s2.
** man: the comparison is done using UNSIGNED characters.
**
** Only the SIGN of the result is part of the contract. The usual choice,
** and what libc does, is to return the difference of the first two bytes
** that differ.
**
** 'unsigned characters' is the detail that breaks most versions. On x86 a
** plain char is SIGNED, so the byte 0200 (128) reads as -128. Comparing
** '\200' with '\001' as plain chars gives -128 - 1, a negative number,
** while the answer must be positive, because as unsigned bytes 128 > 1.
** Casting both sides to unsigned char fixes the sign of the result.
**
** Two things stop the walk: the n limit, tested by the loop itself, and a
** '\0' reached in BOTH strings at the same index. The second test can
** look at s1[i] alone: the code only gets there when s1[i] == s2[i], so a
** '\0' in one is a '\0' in the other, both strings ended together and
** they are equal. Reading past that point would leave the strings.
**
** n == 0 means nothing is compared, so the answer is 0 and neither string
** is ever read.
** =========================================================================
*/

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	// the n limit is the loop condition, so n == 0 reads nothing
	while (i < n)
	{
		// first difference decides, nothing after it is read
		if (s1[i] != s2[i])
			// the casts make the SIGN right for bytes above 127
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		// bytes are equal here, so a '\0' in s1 is a '\0' in s2 as well
		if (s1[i] == '\0')
			// both strings ended at the same place: equal
			return (0);
		i++;
	}
	// n bytes compared, no difference found
	return (0);
}
