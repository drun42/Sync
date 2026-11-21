/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strnstr : find a string inside another, without reading past len.
**
** man: the strnstr() function locates the first occurrence of the
** null-terminated string little in the string big, where not more than
** len characters are searched.
** man: characters that appear after a '\0' are not searched.
** man: if little is an empty string, big is returned.
** man: if little occurs nowhere in big, NULL is returned.
**
** strnstr is a BSD function: it is in the man pages on a mac, and glibc
** does not ship it at all, which is why Linux has nothing to compare
** against unless libbsd is installed.
**
** The empty needle is a special case and comes first: man says big is
** returned, whatever len is, even 0.
**
** Two loops: the outer one picks a starting position in big, the inner one
** compares the needle from there. The inner loop stops on three things, a
** '\0' in little (the needle is over), the len limit, and a mismatch.
**
** After the inner loop, little[j] == '\0' is the test for a FULL match:
** it means the needle ran out, so every one of its bytes matched. If the
** inner loop stopped on a mismatch or on len instead, little[j] is still a
** real character and the search continues one position further.
**
** The 'i + j < len' test is what makes the WHOLE needle fit in the window.
** Without it, a needle starting inside the first len bytes but ending
** outside would be reported as found: strnstr("Hello World", "World", 10)
** must be NULL, because 'World' ends at index 11.
** =========================================================================
*/

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	// man: an empty needle gives back big itself, len does not matter
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	// outer loop: every possible starting position inside the window
	while (big[i] && i < len)
	{
		j = 0;
		// inner loop: three stop conditions, needle over, len reached, mismatch
		while (little[j] && i + j < len && big[i + j] == little[j])
		{
			j++;
		}
		// the needle ran out, so all of its bytes matched
		if (little[j] == '\0')
			// address of the start of the match, not of its end
			return ((char *)big + i);
		i++;
	}
	// no starting position worked
	return (NULL);
}
