/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strlcpy : copy a string into a buffer of a known size.
**
** man: strlcpy() copies up to size - 1 characters from the NUL-terminated
** string src to dst, NUL-terminating the result.
** man: it returns the total length of the string it TRIED to create, that
** is the length of src.
**
** The return value is the surprise of this function. It is NOT the number
** of bytes copied: it is strlen(src), whatever happened. That is what lets
** the caller detect truncation with one test: if the return value is >=
** size, the copy did not fit.
**
** size is the FULL size of the destination buffer, terminator included.
** So at most size - 1 real characters are written, and the last slot is
** kept for the '\0'. That is where the - 1 in the loop condition comes
** from, and forgetting it writes one byte past the buffer.
**
** size == 0 is a separate case and must be handled BEFORE anything is
** written. There is no room at all, not even for a terminator, so dst is
** left exactly as it was. Note that size - 1 with size == 0 would wrap
** around to a huge number, because size_t is unsigned; the early return
** is what avoids that.
**
** src is only read, so it carries const. dst is written, so it does not.
** =========================================================================
*/

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	// len is the length of src, the value man asks us to return
	len = 0;
	while (src[len])
	{
		len++;
	}
	// no room for even a terminator: touch nothing, and avoid size - 1
	if (size == 0)
		return (len);
	i = 0;
	// size - 1 keeps the last slot free for the '\0'
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	// always terminate, whether the copy was complete or truncated
	dst[i] = '\0';
	// the length it TRIED to create, not the number of bytes written
	return (len);
}
