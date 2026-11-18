/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_memchr : find a byte inside the first n bytes of a memory area.
**
** man: the memchr() function scans the initial n bytes of the memory area
** pointed to by s for the first instance of c. Both c and the bytes of the
** memory area pointed to by s are interpreted as UNSIGNED CHAR.
** man: it returns a pointer to the matching byte, or NULL if the character
** does not occur in the given memory area.
**
** This is the memory version of ft_strchr: it works on BYTES, not on a
** string. A '\0' is just another byte here and does not stop the scan;
** what stops it is n.
**
** void * cannot be indexed, so s is cast first. The cast is to
** unsigned char * and not to char *, because man says both sides of the
** comparison are unsigned: with a signed char the byte 0200 would read as
** a negative number and never match the value 128 passed in c.
**
** n == 0 means nothing may be read, not even the first byte: the loop
** never runs and the answer is NULL.
**
** The return type is void * while the parameter is const void *, so the
** const has to be cast away on the way out. That is the man prototype.
** =========================================================================
*/

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	// unsigned char * so the bytes compare the way man requires
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	// n is the only thing that stops the scan, a '\0' does not
	while (i < n)
	{
		// c is cut down to one unsigned byte before comparing
		if (p[i] == (unsigned char)c)
			// address of the matching byte, const cast away as the prototype asks
			return ((void *)(p + i));
		i++;
	}
	// the byte is not in those n bytes
	return (NULL);
}
