/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_memmove : copy n bytes, even when the two areas overlap.
**
** man: the memmove() function copies n bytes from memory area src to
** memory area dest. The memory areas MAY OVERLAP.
** man: memmove() returns a pointer to dest.
**
** This is memcpy plus one problem. With memcpy the caller promises the
** areas do not overlap, so copying front to back is safe. Here they may
** overlap, and a front to back copy would overwrite bytes of src that
** have not been read yet.
**
** Example, buf = "0123456789", memmove(buf + 3, buf, 5). Copying forward
** writes '0' over buf[3], and buf[3] was still needed as a source byte,
** so the result becomes 0120120120 instead of 0120123489.
**
** The fix is the DIRECTION of the copy, not a temporary buffer:
**   dest > src  ->  copy backwards, from the last byte to the first
**   dest <= src ->  copy forwards, the classic memcpy loop
** In both cases a byte is read before anything can overwrite it.
**
** A temporary buffer would also work, but 'char tmp[n]' puts an array of
** a size chosen by the CALLER on the stack: a large n blows the stack, and
** n == 0 asks for a zero length array. The direction test costs nothing.
**
** void * cannot be indexed: the compiler does not know the size of what it
** points to. So both pointers are cast to char *, which steps one byte at
** a time, and n is a count of BYTES. src keeps const because it is only
** read, so its copy s is a const char *.
**
** n == 0 must not read or write anything: both loops simply never run,
** and dest comes back untouched. dest == src ends in the forward loop and
** copies every byte onto itself, which is harmless.
**
** The backward loop decrements BEFORE the assignment. i starts at n, so
** the first index used is n - 1, the last valid byte, and the loop ends
** after index 0. Writing 'while (i >= 0)' with a size_t would never end,
** because an unsigned type cannot go below zero.
** =========================================================================
*/

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	// the byte sized views of the two areas, void * cannot be indexed
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	// dest sits AFTER src, so a forward copy would eat its own source
	if (d > s)
	{
		// start one past the last byte and walk down
		i = n;
		while (i > 0)
		{
			// decrement first: the first index touched is n - 1
			i--;
			d[i] = s[i];
		}
		// the backward case is done, leave before the forward loop
		return (dest);
	}
	// dest <= src, or no overlap at all: the plain memcpy loop is safe
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	// man says the return value is dest, not the end of the copy
	return (dest);
}
