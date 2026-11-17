/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strlcat : append a string to a buffer of a known size.
**
** man: strlcat() appends the NUL-terminated string src to the end of dst.
** man: it will append at most size - strlen(dst) - 1 bytes, then
** NUL-terminate, unless size is 0 or past the end of dst.
** man: it returns the total length of the string it TRIED to create, that
** is the initial length of dst plus the length of src.
**
** Like ft_strlcpy, size is the FULL size of the destination buffer, and
** the return value is the length that WOULD have been produced, so the
** caller detects truncation with 'return value >= size'.
**
** The case that breaks most versions is size SMALLER than the current
** length of dst. Then dst is not even a valid string inside its first
** size bytes, nothing may be appended, and man fixes the answer as
** size + strlen(src). This is why the first loop is capped by size: it
** stops at size instead of walking to a terminator that may be outside
** the window. When it stops because of that cap, dlen == size, and that
** is exactly the condition for the special return.
**
** size == 0 falls into the same branch: the first loop never runs, dlen
** is 0, so dlen == size and the answer is 0 + strlen(src), with nothing
** written. It also keeps size - dlen - 1 from wrapping around, which it
** would, size_t being unsigned.
**
** In the copy loop the destination index is dlen + i: the appended bytes
** start where dst already ended.
** =========================================================================
*/

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	// capped by size: never look for a '\0' outside the buffer window
	dlen = 0;
	while (dlen < size && dst[dlen])
	{
		dlen++;
	}
	// plain length of src, it is not bounded by anything
	slen = 0;
	while (src[slen])
	{
		slen++;
	}
	// no room at all, man fixes the answer and nothing is written
	if (dlen == size)
		return (size + slen);
	i = 0;
	// what is left is size - dlen bytes, minus one for the '\0'
	while (i < size - dlen - 1 && src[i])
	// append behind the existing content of dst
	{
		dst[dlen + i] = src[i];
		i++;
	}
	// the length it TRIED to create
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
