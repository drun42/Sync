/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strrchr : address of the LAST c inside s, or NULL.
**
** man: the strrchr() function returns a pointer to the last occurrence of
** the character c in the string s.
** man: the terminating null byte is considered part of the string.
** man: returns NULL if the character is not found.
**
** Same contract as ft_strchr, with the search running the other way, so
** the same two details apply: c is compared as a char, and the terminator
** counts as part of the string.
**
** The length is not known in advance, so the first loop walks to the
** terminator to find it. Then the second loop walks back down.
**
** The i++ between the two loops is the trick: after the first loop i is
** the index of the '\0'. Adding one puts i one PAST the end, so the
** backward loop, which decrements before it compares, starts exactly on
** the terminator. That is what makes ft_strrchr(s, '\0') return the
** address of the terminator instead of missing it.
**
** The loop condition is 'i > 0' with the decrement inside, because i is a
** size_t: unsigned. 'while (i >= 0)' would always be true and the loop
** would never end, then i would wrap around to a huge value and read far
** outside the string.
** =========================================================================
*/

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	// first pass: find the index of the terminator
	while (s[i])
	{
		i++;
	}
	// step one past it, so the backward loop starts ON the terminator
	i++;
	// unsigned index: test for 0 and decrement inside the loop
	while (i > 0)
	{
		i--;
		// first match found walking down IS the last one in the string
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	// walked all the way to index 0 without a match
	return (NULL);
}
