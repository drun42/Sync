/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/24 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =========================================================================
** LIBFT - annotated reference, all 43 functions of subject version 19.3.
**
** This file is DOCUMENTATION, not a submission file. It holds exactly the
** same code as the files in Libft_ok/, with the man page quotes, the
** reasoning and the traps written next to it. Reading order follows the
** subject: Part 1 libc, Part 2 additional, Part 3 linked list.
**
** It compiles as one translation unit, so the explanations cannot drift
** away from code that works:
**     cc -Wall -Wextra -Werror -c aft_libft.c -I../Libft_ok
**
** One exception is marked in place: ft_memmove is the version currently
** in Libft_ok and it still has the n == 0 bug.
** =========================================================================
*/

#include "libft.h"

/* ========================================================================== */
/* PART 1 - LIBC FUNCTIONS                                                   */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* ft_isalpha                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_isalpha : is this byte a letter ?
**
** man: isalpha() checks for an alphabetic character.
**
** SUBJECT: the return value must be exactly 1 when c belongs to the class
** and exactly 0 when it does not. libc is only required to return 'non
** zero', which is why a libc result cannot simply be forwarded.
**
** The parameter is an int and not a char because libc is specified that
** way: the caller passes the value of an unsigned char, or EOF.
**
** In ASCII the letters sit in two contiguous blocks, 'a' to 'z' and 'A' to
** 'Z', so two range checks answer the question. No lookup table is needed.
** Writing 'a' instead of 97 costs nothing and says what is meant.
**
** Everything else is not a letter: digits, space, punctuation, the control
** bytes below 32, and every byte above 126.
** =========================================================================
*/

int	ft_isalpha(int c)
{
	// the two letter blocks of the ASCII table, lower case and upper case
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	// reached only when no range matched, so c is not a letter
	return (0);
}

/* -------------------------------------------------------------------------- */
/* ft_isdigit                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_isdigit : is this byte a decimal digit ?
**
** man: isdigit() checks for a digit (0 through 9).
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** The test is on the CHARACTER '0' to '9', not on the numbers 0 to 9.
** The character '0' is the byte 48, so c == 0 is the terminating '\0' and
** is not a digit. Mixing '0' and 0 is the classic mistake here.
**
** The ten digits are contiguous in ASCII, so one range check is enough.
** =========================================================================
*/

int	ft_isdigit(int c)
{
	// '0' is the byte 48 and '9' is the byte 57, the ten digits are in a row
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* ft_isalnum                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_isalnum : is this byte a letter or a digit ?
**
** man: isalnum() checks for an alphanumeric character; it is equivalent to
** (isalpha(c) || isdigit(c)).
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** The two conditions of ft_isalpha and the one of ft_isdigit are repeated
** here on purpose, so this file compiles on its own and needs no prototype
** of another function of the library.
**
** The condition is split over two lines because it is long; the operator
** || starts the second line so the reader sees at once that it continues.
** =========================================================================
*/

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* -------------------------------------------------------------------------- */
/* ft_isascii                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_isascii : does this value fit in the 7-bit ASCII set ?
**
** man: isascii() checks whether c is a 7-bit unsigned char value that fits
** into the ASCII character set.
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** This one is not a character class like the others: it asks whether the
** VALUE is in the range 0 to 127. That is why the lower bound 0 matters
** and must be written: the parameter is a signed int, so a negative value
** can arrive and is not ASCII.
**
** 127 is the last 7-bit value (0111 1111). 128 and above need an eighth
** bit, so they are out, even though they are perfectly valid bytes.
** The terminating '\0' is value 0, so it IS ascii, and the answer is 1.
** =========================================================================
*/

int	ft_isascii(int c)
{
	// 0 to 127 is everything that fits in seven bits
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* ft_isprint                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_isprint : is this byte printable ?
**
** man: isprint() checks for any printable character including space.
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** The printable ASCII characters are one single block, from the space
** (32) to the tilde (126). Everything below 32 is a control character,
** '\n' and '\t' among them, so they are NOT printable even though they
** clearly do something on screen.
**
** 127 is DEL, a control character, so the upper bound is 126 and not 127.
** That off by one is what the tests look for.
** =========================================================================
*/

int	ft_isprint(int c)
{
	// 32 is ' ' and 126 is '~', 127 is DEL and is not printable
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* ft_strlen                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_strlen : how many bytes are there before the terminating '\0' ?
**
** man: strlen() calculates the length of the string pointed to by s,
** excluding the terminating null byte ('\0').
**
** The return type is size_t and not int. size_t is unsigned and is the
** type the whole string part of libc uses for sizes, so a length can
** never be negative. Returning an int would also mean converting it back
** at every call site.
**
** The parameter carries const because the string is only read. That is
** part of the man prototype and lets the caller pass a const char *.
**
** A string in C is not an object that knows its own size: it is a run of
** bytes that ENDS at the first '\0'. So the length can only be found by
** walking until that byte, which is what the loop does. The '\0' itself
** is not counted, because the loop stops ON it without adding 1.
**
** s[i] is the byte at offset i. As a condition it is read as 'is this
** byte different from 0', because in C any non zero value is true.
** =========================================================================
*/


size_t	ft_strlen(const char *s)
{
	// i is both the walking index and, at the end, the answer
	size_t	i;

	i = 0;
	// stops on the first '\0', which is false as a condition
	while (s[i])
	{
		i++;
	}
	// i now holds the number of bytes seen BEFORE the '\0'
	return (i);
}

/* -------------------------------------------------------------------------- */
/* ft_memset                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_memset : fill a block of memory with one byte.
**
** man: the memset() function fills the first n bytes of the memory area
** pointed to by s with the constant byte c.
** man: it returns a pointer to the memory area s.
**
** The parameter c is an int but only its low byte is used: man says
** "the constant byte c". So memset(buf, 300, n) writes the same byte as
** memset(buf, 44, n), because 300 and 44 share their low 8 bits.
** Casting to unsigned char on the way in is what throws the rest away.
**
** s is a void *, which cannot be indexed: the compiler does not know how
** wide one element is. A char * view of the same address can be, and a
** char is exactly one byte, which is the unit man counts in.
**
** n == 0 must write nothing. The loop condition i < n is false from the
** start, so that case needs no special branch.
**
** The return value is the SAME address that came in, not the end of the
** block. It exists only so calls can be chained.
** =========================================================================
*/

void	*ft_memset(void *s, int c, size_t n)
{
	// char * view, because void * cannot be indexed
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		// only the low byte of c is written, that is what the cast does
		a[i] = (unsigned char)c;
		i++;
	}
	// the address that came in, unchanged
	return (a);
}

/* -------------------------------------------------------------------------- */
/* ft_bzero                                                                  */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_bzero : write n zero bytes.
**
** man: the bzero() function erases the data in the n bytes of the memory
** starting at the location pointed to by s, by writing zeros (bytes
** containing '\0') to that area.
**
** bzero is memset with c fixed at 0, and it returns NOTHING: the return
** type is void. That is the whole difference, and it is the detail most
** often got wrong by copying memset.
**
** The byte written is the value 0. '\0' is the same value written as a
** character literal, so a[i] = 0 and a[i] = '\0' compile to the same
** store. It is NOT the character '0', which is 48.
**
** bzero is deprecated in favour of memset in the man page, but the
** subject asks for it anyway.
** =========================================================================
*/

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		// the byte 0, not the character '0' which would be 48
		a[i] = 0;
		i++;
	}
	// no return: the type is void
}

/* -------------------------------------------------------------------------- */
/* ft_memcpy                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_memcpy : copy n bytes from one block to another.
**
** man: the memcpy() function copies n bytes from memory area src to
** memory area dest. The memory areas must not overlap.
** man: it returns a pointer to dest.
**
** "Must not overlap" is the whole contract. memcpy is allowed to copy in
** any order it likes, so if the two blocks overlap the result is
** undefined. The function that handles overlap is memmove: that is why
** both exist, and it is the first question asked at defense.
**
** src is const void * and dest is void *: the direction of the copy is
** visible in the prototype. The const says this function promises not to
** write through src.
**
** Both are void *, so neither can be indexed. Two char * views give
** byte sized indexing, and bytes are the unit n counts in. The view on
** src keeps its const.
**
** No NULL check is in the prototype or in man: passing NULL with n > 0 is
** undefined behaviour, and the caller is responsible for it.
**
** n == 0 copies nothing, because i < n is false from the start.
** =========================================================================
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	// the view on src keeps const: this side is only read
	const char		*s;
	size_t			i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	// one byte at a time, front to back, overlap is not handled here
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* -------------------------------------------------------------------------- */
/* ft_memmove                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_memmove : copy n bytes, overlap allowed.
**
** man: the memmove() function copies n bytes from memory area src to
** memory area dest. The memory areas MAY overlap: the copy is performed
** as though the bytes in src were first copied into a temporary array
** that does not overlap src or dest, and the bytes were then copied from
** the temporary array to dest.
** man: it returns a pointer to dest.
**
** No temporary array is actually needed. Only the DIRECTION of the copy
** matters, and only when the two blocks overlap:
**
** - dest BEFORE src: copying front to back always reads a byte before
** anything has overwritten it.
** - dest AFTER src: front to back would overwrite bytes of src that have
** not been read yet, so the copy has to run back to front.
**
** That is why this function has two branches and memcpy has one.
**
** The trap in the backward branch is the index. It has to start at the
** LAST byte, and a size_t is unsigned: it cannot hold a negative value.
** Any expression that would go below zero wraps around to a huge number
** instead. n == 0 is exactly the case where that happens, and it is the
** case Moulinette tests.
**
** NOTE: the version below is the one currently in Libft_ok. It crashes on
** ft_memmove(dest, src, 0) when dest is after src. The marked line is
** where the wrap around happens. Not fixed on purpose: this one is yours.
** =========================================================================
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = (char *)dest;
	s = (char *)src;
	// man does not ask for this, and it only triggers when BOTH are NULL
	if (d == 0 && s == 0)
	{
		return (d);
	}
	else
	{
		// overlap case that needs the backward copy
		if (d > s)
		{
			// BUG: n == 0 makes this wrap to the largest size_t value
			i = n - 1;
			while (i != 0)
			{
				d[i] = s[i];
				i--;
			}
			// the loop above stops BEFORE index 0, so byte 0 is done here
			if (n != 0)
				d[0] = s[0];
		}
		else
		{
			// front to back is safe: dest is before src
			i = 0;
			while (i < n)
			{
				d[i] = s[i];
				i++;
			}
		}
		return (dest);
	}
}

/* -------------------------------------------------------------------------- */
/* ft_strlcpy                                                                */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_strlcat                                                                */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_toupper                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_toupper : turn one lower case letter into its upper case twin.
**
** man: toupper() converts the letter c to upper case, if possible.
** man: the value returned is that of the converted letter, or c if the
** conversion was not possible.
**
** 'if possible' is the whole contract: anything that is not a lower case
** letter must come back UNCHANGED. Returning 0, or returning c - 32 for
** every input, both break it.
**
** In ASCII 'a' is 97 and 'A' is 65, and the two blocks run in parallel,
** so the distance is always 32: 'a' - 'A' == 32. Subtracting 32 from a
** lower case letter therefore lands exactly on its upper case twin.
**
** The return type is int, like the parameter, because libc is specified
** that way. The value still fits in a char.
** =========================================================================
*/

int	ft_toupper(int c)
{
	// only a lower case letter is converted
	if (c >= 'a' && c <= 'z')
		// 32 is the constant distance between the two blocks, 'a' - 'A'
		return (c - 32);
	// everything else comes back untouched, that is the 'if possible' part
	return (c);
}

/* -------------------------------------------------------------------------- */
/* ft_tolower                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_tolower : turn one upper case letter into its lower case twin.
**
** man: tolower() converts the letter c to lower case, if possible.
** man: the value returned is that of the converted letter, or c if the
** conversion was not possible.
**
** Same contract as ft_toupper, mirrored: anything that is not an upper
** case letter must come back UNCHANGED.
**
** In ASCII the lower case block sits 32 above the upper case one, so
** adding 32 to an upper case letter lands on its lower case twin.
** =========================================================================
*/

int	ft_tolower(int c)
{
	// only an upper case letter is converted
	if (c >= 'A' && c <= 'Z')
		// the lower case block is 32 higher in the table
		return (c + 32);
	// everything else comes back untouched
	return (c);
}

/* -------------------------------------------------------------------------- */
/* ft_strchr                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_strchr : address of the FIRST c inside s, or NULL.
**
** man: the strchr() function returns a pointer to the first occurrence of
** the character c in the string s.
** man: the terminating null byte is considered part of the string, so if c
** is '\0' the function locates the terminator.
** man: returns NULL if the character is not found.
**
** Two details carry every test of this function.
**
** First, c arrives as an int but must be compared as a CHAR. The caller
** may pass any int, and libc is specified to convert it to char. So
** 'o' + 256 has to behave exactly like 'o': both have the same low byte.
** Casting c to char throws the higher bits away and gets that for free.
** Comparing s[i] == c without the cast makes 'o' + 256 miss.
**
** Second, the terminator is part of the string. The walking loop stops ON
** the '\0' without testing it, so that case is handled after the loop:
** if c was '\0', the address of that terminator is the answer.
**
** The return type is char * while the parameter is const char *. That is
** the man prototype, and it is why the cast on the way out is needed: the
** function hands back a writable pointer into a string it promised only to
** read. The cast is on the return value, NOT on the parameter type.
**
** (char *)s + i is the address of byte i: the start of the string plus an
** offset of i bytes, because a char is one byte wide.
** =========================================================================
*/


char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	// walk until the terminator, which this condition treats as false
	while (s[i])
	{
		// the cast to char is what makes 'o' + 256 match 'o'
		if (s[i] == (char)c)
			// address of byte i, not the byte itself
			return ((char *)s + i);
		i++;
	}
	// the loop ended on the '\0', which man counts as part of the string
	if ((char)c == '\0')
		return ((char *)s + i);
	// c is not in s at all
	return (NULL);
}

/* -------------------------------------------------------------------------- */
/* ft_strrchr                                                                */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_strncmp                                                                */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_memchr                                                                 */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_memcmp                                                                 */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_strnstr                                                                */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/* ft_atoi                                                                   */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_atoi : read an int out of the front of a string.
**
** man: the atoi() function converts the initial portion of the string
** pointed to by nptr to int.
** man: the behaviour is the same as strtol(nptr, NULL, 10) except that
** atoi() does not detect errors.
**
** So the grammar is the one of strtol: optional whitespace, then ONE
** optional sign, then decimal digits, and the conversion stops at the
** first character that does not fit. Nothing is an error: a string with
** no digits at all simply gives 0.
**
** Three places where versions usually differ from libc:
**
** 1. The whitespace set is the one of isspace, six characters: space plus
** '\t' '\n' '\v' '\f' '\r'. Those five are the values 9 to 13, in a row
** in the ASCII table, so '>= \t && <= \r' covers them. Skipping only
** space, '\t' and '\n' fails on the other three.
**
** 2. There is ONE sign at most. It is an if, not a while. '--5' and '+-5'
** are not numbers: the conversion stops on the second sign and the answer
** is 0. A loop over the signs would read '--5' as 5.
**
** 3. Whitespace is allowed only BEFORE the sign. '- 42' is 0, because
** after the '-' a space is not a digit, so the digit loop reads nothing.
**
** The accumulator n is a long and not an int. INT_MIN is -2147483648, and
** its digits build the positive value 2147483648, which does NOT fit in
** an int. Building it in a long and applying the sign afterwards keeps
** both limits exact. Input that does not fit in an int at all is
** undefined behaviour for atoi, so it is not handled here.
**
** The digits are turned into a value with n * 10 + (c - '0'). Subtracting
** '0' works because the ten digits are contiguous in ASCII: '7' - '0'
** is 7.
** =========================================================================
*/


int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	// long, so the digits of INT_MIN can be built before the sign is applied
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	// the full isspace set: ' ' plus the values 9 to 13, '\t' to '\r'
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	{
		i++;
	}
	// an if and not a while: at most ONE sign is accepted
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	// stops at the first byte that is not a digit, that is 'initial portion'
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		// '0' is 48 and the digits are contiguous, so c - '0' is its value
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	// apply the sign in long, then cut down to int
	return ((int)(sign * n));
}

/* -------------------------------------------------------------------------- */
/* ft_calloc                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_calloc : malloc, but the memory comes back zeroed.
**
** man: the calloc() function allocates memory for an array of nmemb
** elements of size bytes each and returns a pointer to the allocated
** memory. The memory is set to ZERO.
** man: if nmemb or size is 0, then calloc() returns either NULL, or a
** unique pointer value that can later be successfully passed to free().
**
** SUBJECT: that choice is removed, the subject requires the second
** behaviour: with nmemb or size at 0 the result must be a unique pointer
** that free() accepts, so returning NULL is wrong.
**
** Nothing special has to be written for that case: malloc(0) already
** returns such a pointer, both in glibc and on a mac. The product is 0,
** the zeroing loop does not run, and the pointer is handed back as it is.
**
** Two arguments instead of one is the whole interface difference with
** malloc: the total is nmemb * size bytes.
**
** malloc can fail, and then it returns NULL. That has to be tested BEFORE
** the zeroing loop, otherwise the loop writes through a NULL pointer and
** the program dies.
**
** The zeroing is done through a char * view, because the area is counted
** in bytes and void * cannot be indexed. 0 and '\0' are the same value
** here, the byte 0.
**
** Note that nmemb * size can overflow for huge arguments; man says NULL
** in that case. The subject does not ask for it, so it is left out.
** =========================================================================
*/


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*c;
	size_t	i;

	// one block of nmemb * size bytes, 0 bytes is a valid request
	p = malloc(nmemb * size);
	// test the failure FIRST, before anything is written
	if (p == NULL)
		return (NULL);
	// byte sized view of the block, void * cannot be indexed
	c = (char *)p;
	i = 0;
	// zero every byte, this is what calloc adds to malloc
	while (i < nmemb * size)
	{
		c[i] = 0;
		i++;
	}
	// the pointer the caller will later pass to free
	return (p);
}

/* -------------------------------------------------------------------------- */
/* ft_strdup                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_strdup : make a private copy of a string.
**
** man: the strdup() function returns a pointer to a new string which is a
** duplicate of the string s. Memory for the new string is obtained with
** malloc(3), and can be freed with free(3).
** man: it returns NULL if insufficient memory was available.
**
** The caller becomes the owner of the result and has to free it. That is
** the contract, and it is why this function belongs to the malloc group
** of the subject.
**
** The size to ask for is len + 1: len bytes of text plus one for the
** terminating '\0'. Asking for len is the classic off by one, and the
** write of the terminator then lands one byte outside the block.
**
** malloc can fail, and then NULL is returned without touching anything.
**
** The copy stops at the '\0' of the source, like every string function:
** bytes that sit behind it are not part of the string and are not copied.
** The terminator is written by hand after the loop, because the loop ends
** ON it without copying it.
**
** The result is a NEW block: writing into the copy must not change the
** original. That is what makes it different from returning s itself.
** =========================================================================
*/


char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	// length of the source, the '\0' is not counted
	len = 0;
	while (s[len])
	{
		len++;
	}
	// len + 1: the text plus room for the terminator
	p = (char *)malloc(len + 1);
	// allocation failed, man says return NULL
	if (p == NULL)
		return (NULL);
	i = 0;
	// copy the text only, the loop stops before the '\0'
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	// terminate the copy by hand, the loop did not copy the '\0'
	p[len] = '\0';
	return (p);
}

/* ========================================================================== */
/* PART 2 - ADDITIONAL FUNCTIONS                                             */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* ft_substr                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_substr : a fresh string cut out of s.
**
** subject: allocates (with malloc) and returns a substring from the string
** 's'. The substring starts at index 'start' and has a maximum length of
** 'len'. Returns NULL if the allocation fails.
**
** "MAXIMUM length" is the whole job. len is what the caller WANTS, not
** what it gets. Two things can make the answer shorter:
**
** 1. start is at or past the end of s. There is nothing to copy, and the
** result is an empty string "" - NOT NULL. A one byte allocation holding
** only '\0' is still a valid string the caller will free.
**
** 2. start is inside s but start + len runs past the end. Then only
** slen - start bytes exist, and that is the length.
**
** Both are handled by clamping len BEFORE the malloc, so the allocation
** is exactly as big as what will be written. Computing the size one way
** and the loop another way is how buffers get overrun.
**
** slen - start is safe only because the first branch already rejected
** start >= slen. size_t is unsigned: if start were larger, that
** subtraction would wrap to a huge number and malloc would be asked for
** it.
**
** start is an unsigned int and len is a size_t. That mix is in the
** subject prototype, not a mistake to clean up.
**
** The '\0' is written by hand: malloc does not zero its memory, and the
** copy loop stops at len.
** =========================================================================
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	// nothing to copy: the answer is an empty string, not NULL
	if (start >= slen)
		len = 0;
	// the tail of s is shorter than what was asked for
	else if (len > slen - start)
		len = slen - start;
	// allocate AFTER len is final, + 1 for the terminator
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		// read offset start + i, write offset i
		p[i] = s[start + i];
		i++;
	}
	// malloc does not zero anything, the terminator is written by hand
	p[i] = '\0';
	return (p);
}

/* -------------------------------------------------------------------------- */
/* ft_strjoin                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_strjoin : one new string holding s1 then s2.
**
** subject: allocates (with malloc) and returns a new string, which is the
** result of concatenating 's1' and 's2'. Returns NULL if the allocation
** fails.
**
** Neither input is touched: this is not strcat. Both are char const *,
** and the result is a third block of memory the caller owns and frees.
**
** The size is l1 + l2 + 1. The + 1 is the single terminator of the
** RESULT: the '\0' of s1 is not copied, it is overwritten by the first
** byte of s2. Allocating l1 + l2 only is the classic off by one here, and
** it writes one byte past the block.
**
** Two loops, each with its own fresh i, is the simple way. The second one
** writes at p[l1 + i]: index 0 of s2 lands right after the last byte of
** s1.
**
** Nothing checks whether s1 or s2 is NULL: the subject does not ask for
** it, and ft_strlen would dereference NULL anyway.
** =========================================================================
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	// + 1 for ONE terminator: the '\0' of s1 is not kept
	p = (char *)malloc(l1 + l2 + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		// offset l1 + i: s2 starts where s1 ended
		p[l1 + i] = s2[i];
		i++;
	}
	p[l1 + l2] = '\0';
	return (p);
}

/* -------------------------------------------------------------------------- */
/* ft_strtrim                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_strtrim : copy of s1 without the leading and trailing bytes that
** appear in set.
**
** subject: allocates (with malloc) and returns a copy of 's1' with
** characters from 'set' removed from the BEGINNING and the END.
**
** From the beginning and the end only. Bytes of set in the middle stay:
** trim(" a b ", " ") is "a b", not "ab".
**
** The work is finding two indices, then handing them to ft_substr, which
** already does the allocation and the copy. start is the first byte to
** keep, end is one PAST the last byte to keep, so the length is
** end - start. Keeping end exclusive is why no +1 or -1 appears in that
** subtraction.
**
** Three details:
**
** - the first loop tests s1[start] BEFORE calling ft_strchr. If s1 is
** made only of bytes from set, start walks to the terminator and stops
** there. Without that test ft_strchr(set, '\0') would be asked, and
** ft_strchr finds the terminator of set, so it answers "yes" and the walk
** would run off the end of s1.
**
** - the second loop tests end > start, so it can never walk back past
** what the first loop already accepted. That is also what makes the
** all trimmed case give "" instead of a wrapped size_t.
**
** - end - 1 is used because end is exclusive: the last byte currently
** kept sits one below it.
**
** set == "" trims nothing: ft_strchr("", c) is NULL for every c that is
** not '\0', so both loops stop immediately.
** =========================================================================
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	// s1[start] is tested FIRST: without it the terminator would match
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
	{
		start++;
	}
	// end is EXCLUSIVE: one past the last byte kept
	end = ft_strlen(s1);
	// end > start keeps this loop inside what the first one accepted
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
	{
		end--;
	}
	// ft_substr does the malloc, the copy and the terminator
	return (ft_substr(s1, start, end - start));
}

/* -------------------------------------------------------------------------- */
/* ft_split                                                                  */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_split : cut s on the byte c into an array of fresh strings.
**
** subject: allocates (with malloc) and returns an array of strings
** obtained by splitting 's' using the character 'c' as a delimiter. Each
** string in the returned array is allocated independently. The array of
** pointers itself is also allocated dynamically. The returned array must
** be NULL TERMINATED. Returns NULL if any allocation fails.
** subject: the returned structure will be released using free() on each
** string, then free() on the array itself.
**
** So the shape of the result is fixed: n pointers to n independent
** strings, plus one NULL slot at the end, which is how the caller knows
** where to stop. The array is therefore n + 1 pointers wide, and
** forgetting that + 1 is the classic crash here.
**
** Empty words do not exist. Runs of delimiters, and delimiters at the
** start or the end, produce nothing: split("  a  b  ", ' ') has 2 words.
** This is why the counting and the filling must use the SAME rule, and
** why both skip delimiters before looking at a word.
**
** The counting pass is separate because the size of the array has to be
** known before malloc is called. Walking the string twice is the price of
** not growing the array.
**
** The failure path is the part Moulinette looks at. If one ft_substr
** fails, everything already allocated has to be freed, or the function
** leaks. Here the failed slot is left NULL by fill_tab, so free_tab can
** stop at the first NULL and does not need a count.
**
** Norminette limits a function to 25 lines, which is the real reason this
** file has static helpers. They are static because nothing outside this
** file may call them, and they are not in libft.h.
** =========================================================================
*/

// how many words: the counting rule must match the filling rule exactly
static size_t	count_words(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		// skip a run of delimiters, however long
		while (s[i] == c)
			i++;
		// only count if something is actually there
		if (s[i])
			n++;
		// walk to the end of the word
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

// frees what was allocated so far, stops at the first NULL slot
static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// fills the array, 0 means an allocation failed
static int	fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		// measure the word first, ft_substr needs its length
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			tab[w] = ft_substr(s, i, len);
			// the failed slot stays NULL, free_tab stops there
			if (tab[w] == NULL)
				return (0);
			w++;
		}
		i += len;
	}
	// the NULL that terminates the array
	tab[w] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	// + 1 slot for the terminating NULL, sizeof a POINTER, not of a char
	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	if (fill_tab(tab, s, c) == 0)
	{
		// free everything already allocated before giving up
		free_tab(tab);
		return (NULL);
	}
	return (tab);
}

/* -------------------------------------------------------------------------- */
/* ft_itoa                                                                   */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_itoa : the decimal spelling of an int, as a fresh string.
**
** subject: allocates (with malloc) and returns a string representing the
** integer received as an argument. NEGATIVE NUMBERS MUST BE HANDLED.
** Returns NULL if the allocation fails.
**
** Three cases decide this function:
**
** 1. n == 0. Zero has one digit, but a loop of the shape
** "while (n > 0) take the last digit" never runs, so "0" has to be
** written explicitly. Returning "" here is the usual bug.
**
** 2. negative n. One extra byte for the '-', and the digits are those of
** the absolute value.
**
** 3. INT_MIN, which is -2147483648. Its absolute value, 2147483648, does
** NOT fit in an int: INT_MAX is 2147483647. So -n overflows, which is
** undefined behaviour, and the usual symptom is that INT_MIN comes back
** unchanged. Holding the value in a long, which is 64 bit here, makes the
** negation exact. That is the same reason ft_atoi accumulates in a long.
**
** The length is counted before the malloc, by dividing by 10 until one
** digit is left. num_len does that on the int WITHOUT negating it: the
** condition n <= -10 || n >= 10 means "more than one digit", whatever the
** sign, so INT_MIN is counted without ever overflowing. Integer division
** of a negative value truncates toward zero in C99, so -42 / 10 is -4.
**
** The digits come out of n % 10 in reverse order, last digit first. That
** is why the writing loop fills the buffer from the END backwards: len is
** decremented before each store, and the first store lands on the last
** digit position. The '-' sits at index 0, and the loop stops before
** reaching it.
**
** '0' + digit turns a value into its character: the ten digits are
** contiguous in ASCII.
** =========================================================================
*/

// counts the digits, plus one slot for the sign, without ever negating n
static size_t	num_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	// "more than one digit", works the same for both signs
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	// long, so that INT_MIN can be negated without overflow
	long	nb;

	nb = n;
	len = num_len(n);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	// zero produces no digits in the loop below, so it is written here
	if (nb == 0)
		p[0] = '0';
	// filled from the END: n % 10 gives the LAST digit first
	while (nb > 0)
	{
		len--;
		p[len] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (p);
}

/* -------------------------------------------------------------------------- */
/* ft_strmapi                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_strmapi : a new string, each byte passed through f.
**
** subject: applies the function f to each character of the string s,
** passing its INDEX as the first argument and the character itself as the
** second. A new string is created (with malloc) to store the results from
** the successive applications of f.
**
** char (*f)(unsigned int, char) reads from the inside out: f is a pointer
** to a function that takes an unsigned int and a char and RETURNS a char.
** The parentheses around *f are what make it a pointer to a function
** instead of a function returning a pointer.
**
** f is called as f(i, s[i]) - no dereference needed, the call syntax works
** directly on the pointer. What comes back is stored, so s itself is never
** modified: that is the difference with ft_striteri, which gets an address
** and modifies in place.
**
** The result has the same length as s, because f returns exactly one char
** per char. So the allocation is len + 1 and no counting is needed.
**
** The index is an unsigned int, not a size_t, because the subject fixes
** the type of f's first parameter. Mixing it with len, a size_t, in
** i < len is fine: both are unsigned.
** =========================================================================
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	size_t			len;
	// unsigned int, because that is the type f expects
	unsigned int	i;

	len = ft_strlen(s);
	// one char in, one char out, so the length is known in advance
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		// the return value is stored: s is not modified
		p[i] = f(i, s[i]);
		i++;
	}
	p[len] = '\0';
	return (p);
}

/* -------------------------------------------------------------------------- */
/* ft_striteri                                                               */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_striteri : apply f to every byte of s, in place.
**
** subject: applies the function 'f' to each character of the string
** passed as argument, passing its index as the first argument. Each
** character is passed BY ADDRESS to 'f' so it can be MODIFIED if
** necessary.
**
** Two things follow from "by address":
**
** - the second parameter of f is a char *, not a char, and the call site
** has to pass &s[i]. Passing s[i] would hand f a copy, and anything f
** wrote would be lost.
** - s is char *, without const, unlike almost every other string
** parameter in this library. The prototype itself says this function
** writes through it. A string literal must not be passed: those live in
** read only memory and writing there is a crash.
**
** Nothing is allocated and nothing is returned: the return type is void.
** The work happens inside the caller's own buffer.
**
** &s[i] is the address of byte i. s + i is the same address written
** differently.
** =========================================================================
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		// &s[i] : the ADDRESS, so f can write through it
		f(i, &s[i]);
		i++;
	}
}

/* -------------------------------------------------------------------------- */
/* ft_putchar_fd                                                             */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_putchar_fd : write one byte to a file descriptor.
**
** subject: outputs the character 'c' to the specified file descriptor.
**
** write is the only output call allowed in this project: no printf, no
** putchar. Its prototype is
** ssize_t write(int fd, const void *buf, size_t count);
** so it wants an ADDRESS and a byte count, never a value. &c is that
** address: c is a parameter, so it is a real object on the stack with an
** address of its own.
**
** A file descriptor is just a small int the kernel uses as a handle:
** 0 is standard input, 1 standard output, 2 standard error. The point of
** taking fd as a parameter is that the same function can write to a file
** or to a pipe without changing.
**
** write returns how many bytes it actually wrote, or -1 on error. These
** functions return void, so that answer is dropped: the subject does not
** ask for it.
** =========================================================================
*/

void	ft_putchar_fd(char c, int fd)
{
	// &c : write takes an address and a length, not a value
	write(fd, &c, 1);
}

/* -------------------------------------------------------------------------- */
/* ft_putstr_fd                                                              */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_putstr_fd : write a string to a file descriptor, without a newline.
**
** subject: outputs the string 's' to the specified file descriptor.
**
** write does not know what a string is: it writes a COUNT of bytes. So
** the length has to be measured first, and that is exactly what
** ft_strlen is for. One write call for the whole string is one system
** call; a loop of one byte writes would be as correct but slower.
**
** The '\0' is NOT written. It marks the end of the string in memory, it
** is not part of the text. Writing ft_strlen(s) + 1 bytes would send a
** stray zero byte down the descriptor.
**
** s is char * without const in the subject prototype, even though nothing
** is written through it.
** =========================================================================
*/

void	ft_putstr_fd(char *s, int fd)
{
	// the length WITHOUT the terminator: '\0' is not part of the text
	write(fd, s, ft_strlen(s));
}

/* -------------------------------------------------------------------------- */
/* ft_putendl_fd                                                             */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_putendl_fd : the string, then a newline.
**
** subject: outputs the string 's' to the specified file descriptor
** FOLLOWED BY A NEWLINE.
**
** Nothing new happens here: it is ft_putstr_fd plus one byte. Reusing the
** two functions already written is the point - the subject says functions
** from the earlier parts may be useful, and the library links as one
** archive, so a file may call anything declared in libft.h.
**
** '\n' is ONE byte, the value 10. It is not the two characters
** backslash and n: that is only how it is written in source. "\n" with
** double quotes would be a string of two bytes, 10 and 0.
** =========================================================================
*/

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	// '\n' is a single byte, value 10
	ft_putchar_fd('\n', fd);
}

/* -------------------------------------------------------------------------- */
/* ft_putnbr_fd                                                              */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_putnbr_fd : write an int in decimal.
**
** subject: outputs the integer 'n' to the specified file descriptor.
**
** This is ft_itoa without the malloc: same three traps.
**
** 1. INT_MIN. -2147483648 negated does not fit in an int, so the value is
** held in a long before the sign is dealt with. Try it with an int and
** INT_MIN prints as a wrong number.
**
** 2. the digit order. n % 10 gives the LAST digit, but the leftmost one
** has to be written first. The recursive call handles the higher digits
** BEFORE the current one is written: every call writes its digit on the
** way back out, so the order comes out right without a buffer.
**
** 3. zero. n == 0 skips the recursion, because 0 >= 10 is false, and the
** single digit is written by the last line.
**
** The recursion ends because nb / 10 shrinks toward 0 at every step, and
** the call is only made while nb >= 10.
**
** '0' + digit turns a value into its character.
** =========================================================================
*/

void	ft_putnbr_fd(int n, int fd)
{
	// long, so INT_MIN survives the negation below
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	// the higher digits go out FIRST, on the way down the recursion
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	// then this call writes its own digit on the way back out
	ft_putchar_fd('0' + nb % 10, fd);
}

/* ========================================================================== */
/* PART 3 - LINKED LIST                                                      */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* ft_lstnew                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** PART 3 - the linked list
**
** subject: add the following structure declaration to your libft.h file
**
** typedef struct s_list
** {
**     void            *content;
**     struct s_list   *next;
** }   t_list;
**
** content is a void *, so a node can hold anything: the list does not
** know and does not care what is in it. It stores the ADDRESS of the
** data, never a copy of it. Whoever created the data stays responsible
** for it, which is why ft_lstdelone and ft_lstclear are handed a 'del'
** function instead of calling free on content themselves.
**
** next is the address of the following node, or NULL in the last one.
** NULL is the end marker: every walk through a list is a while loop that
** stops on it. Inside the struct the type must be written
** struct s_list *, not t_list *, because the typedef does not exist yet
** at that point.
**
** Why some functions take t_list ** and others t_list *: a function that
** has to change WHICH node is the first one needs the address of the
** caller's pointer, not a copy of it. ft_lstadd_front, ft_lstadd_back and
** ft_lstclear change the head, so they take t_list **. The others only
** read the chain, so a t_list * is enough.
** =========================================================================
*/

/*
** =========================================================================
** ft_lstnew : one new node.
**
** subject: allocates (with malloc) and returns a new node. The 'content'
** member variable is initialized with the given parameter 'content'. The
** variable 'next' is initialized to NULL.
**
** The subject fixes both fields, and NULL for next is what makes the new
** node a valid one element list on its own.
**
** malloc does not zero its memory: without the explicit next = NULL, that
** field holds whatever was in the heap, and the first walk through the
** list follows it into nothing.
**
** sizeof(t_list) is the size of the STRUCT, two pointers, not the size of
** what content points at. Nothing is copied here: only the address
** passed in is stored.
** =========================================================================
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	// sizeof the STRUCT: two pointers, not the size of the content
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	// the address is stored, the data itself is not copied
	node->content = content;
	// malloc leaves garbage: NULL has to be written by hand
	node->next = NULL;
	return (node);
}

/* -------------------------------------------------------------------------- */
/* ft_lstadd_front                                                           */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstadd_front : put a node at the head of the list.
**
** subject: adds the node 'new' at the beginning of the list.
** parameters: lst - the ADDRESS OF A POINTER to the first node of a list.
**
** t_list **lst is the whole lesson of this function. The caller holds a
** pointer to the first node; after this call that pointer must point at
** the NEW first node. Changing the caller's pointer means receiving its
** address, so the parameter is a pointer to a pointer, and *lst is the
** caller's variable itself.
**
** With a t_list * parameter the assignment would only change this
** function's own copy and the caller would see nothing.
**
** Order matters: new->next has to be set to the OLD head before *lst is
** overwritten. Doing it the other way round loses the address of the rest
** of the list - nothing points at it any more, and it cannot be freed.
**
** An empty list is a *lst that is NULL, and it needs no special case:
** new->next becomes NULL and new is a one element list.
**
** 'new' is a legal identifier in C. It is only reserved in C++.
** =========================================================================
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	// the OLD head first: overwriting *lst before this loses the list
	new->next = *lst;
	// *lst is the caller's own pointer, that is why lst is a t_list **
	*lst = new;
}

/* -------------------------------------------------------------------------- */
/* ft_lstsize                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstsize : how many nodes.
**
** subject: counts the number of nodes in the list.
** subject prototype: unsigned int ft_lstsize(t_list *lst);
**
** WATCH THE RETURN TYPE. This subject (version 19.3) says unsigned int.
** The older subject and nearly every public tester use int. If the
** prototype in libft.h does not match the one in the subject, the
** function is wrong even when the counting is right.
**
** The walk is the pattern every lst function uses: start at lst, follow
** next, stop on NULL. lst is a local copy of the caller's pointer, so
** moving it along costs nothing and the caller's own pointer is
** untouched. That is why no t_list ** is needed here.
**
** An empty list is lst == NULL and gives 0 without a special case: the
** loop body never runs.
** =========================================================================
*/

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	n;

	n = 0;
	// NULL is the end marker of every list
	while (lst != NULL)
	{
		n++;
		// lst is a local copy, moving it does not touch the caller's
		lst = lst->next;
	}
	return (n);
}

/* -------------------------------------------------------------------------- */
/* ft_lstlast                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstlast : the last node.
**
** subject: returns the last node of the list.
**
** The last node is the one whose next is NULL - not NULL itself. So the
** loop condition is on lst->next, not on lst: stopping on lst == NULL
** would walk one node too far and return NULL every time.
**
** Because the test dereferences lst, the empty list has to be caught
** first: lst == NULL means there is no last node, and reading lst->next
** there is a crash. This is the one place where the usual
** "while (lst != NULL)" shape does not work.
** =========================================================================
*/

t_list	*ft_lstlast(t_list *lst)
{
	// lst->next below would dereference NULL, so this comes first
	if (lst == NULL)
		return (NULL);
	// the condition is on NEXT: the last node is the one whose next is NULL
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* -------------------------------------------------------------------------- */
/* ft_lstadd_back                                                            */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstadd_back : put a node at the end of the list.
**
** subject: adds the node 'new' at the end of the list.
** parameters: lst - the address of a pointer to the first node of a list.
**
** Two different situations, and that is why this one is longer than
** ft_lstadd_front:
**
** - the list is EMPTY (*lst == NULL). There is no last node to attach to,
** so the new node becomes the head, and the caller's pointer has to be
** changed. This is the case that needs the t_list **.
** - the list is not empty. The head does not move at all; only the next
** field of the current last node changes. ft_lstlast finds it.
**
** Mixing the two up is the usual bug: without the empty case,
** ft_lstlast(*lst) is called on NULL, or the head is overwritten on a
** list that already had nodes.
**
** new->next is already NULL if the node came from ft_lstnew, so nothing
** has to be set on the new node itself.
**
** Walking to the end on every call makes building a list of n nodes cost
** n * n steps. Fine for this project, worth knowing at defense.
** =========================================================================
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	// empty list: there is no last node, the new one becomes the head
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	// not empty: the head does not move, only the last node's next changes
	last = ft_lstlast(*lst);
	last->next = new;
}

/* -------------------------------------------------------------------------- */
/* ft_lstdelone                                                              */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstdelone : free one node and its content.
**
** subject: takes a node as parameter and frees its content using the
** function 'del'. Free the node itself but DOES NOT free the next node.
**
** Two separate allocations are involved, and they were made by different
** people: the content belongs to the caller, the node itself was made by
** ft_lstnew. So two steps, in this order:
**
** - del(lst->content): the list does not know what content is, so it
** cannot free it itself. The caller passes the function that knows how.
** For a simple malloc'd block that function is a wrapper around free; for
** a struct holding other pointers it is something larger.
** - free(lst): the node.
**
** The order cannot be swapped. After free(lst) the node is gone and
** reading lst->content is a use after free: the memory may still hold the
** old value, which is why this bug often "works" until it does not.
**
** "does NOT free the next node" is what separates this function from
** ft_lstclear. lst->next is simply ignored, which means the caller must
** have saved it or re-linked the list first, or the rest of the chain
** leaks.
** =========================================================================
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	// content FIRST: after free(lst) the field cannot be read any more
	del(lst->content);
	// the node itself
	free(lst);
	// next is deliberately untouched: that is ft_lstclear's job
}

/* -------------------------------------------------------------------------- */
/* ft_lstclear                                                               */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstclear : free the whole list.
**
** subject: deletes and frees the given node AND ALL ITS SUCCESSORS, using
** the function 'del' and free(). Finally, SET THE POINTER TO THE LIST TO
** NULL.
**
** The trap is the order of two operations that both want the same node.
** Each node has to be freed, but its next field is the only way to reach
** the rest of the list - and that field dies with the node. So the
** address of the next node is saved in a local variable BEFORE the
** current one is freed. Without that save, the loop reads a freed node to
** find its successor: use after free, and the rest of the list leaks.
**
** The per node work is exactly ft_lstdelone, so it is reused rather than
** repeated.
**
** *lst = NULL at the end is required by the subject, and it is why this
** function takes a t_list **. Every node is gone, so the caller's pointer
** is dangling; setting it to NULL leaves an empty list that can be used
** again, and makes a second ft_lstclear on it harmless.
** =========================================================================
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		// saved BEFORE the free: node->next dies with the node
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	// required by the subject: the caller's pointer would be dangling
	*lst = NULL;
}

/* -------------------------------------------------------------------------- */
/* ft_lstiter                                                                */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstiter : apply f to the content of every node.
**
** subject: iterates through the list 'lst' and applies the function 'f'
** to the CONTENT of each node.
**
** To the content, not to the node: the call is f(lst->content), so f
** never sees the list structure and cannot follow next or break the
** chain. Passing lst instead of lst->content is the usual mistake, and it
** compiles, because f takes a void * and any object pointer converts to
** that silently.
**
** void (*f)(void *) returns nothing, so f works IN PLACE, through the
** address it is given. Nothing is allocated and nothing is returned. The
** function that builds a new list instead is ft_lstmap.
**
** No t_list ** is needed: the chain is only read.
** =========================================================================
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		// the CONTENT, not the node: f must not see the list structure
		f(lst->content);
		lst = lst->next;
	}
}

/* -------------------------------------------------------------------------- */
/* ft_lstmap                                                                 */
/* -------------------------------------------------------------------------- */

/*
** =========================================================================
** ft_lstmap : a brand new list, each content passed through f.
**
** subject: iterates through the list 'lst', applies the function 'f' to
** each node's content, and creates a NEW LIST resulting of the successive
** applications of 'f'. The 'del' function is used to delete the content
** of a node if needed. Returns NULL if the allocation fails.
**
** Two lists exist at the end: the original, untouched, and the new one,
** which the caller owns. void *(*f)(void *) returns a void *, and that
** return value becomes the content of a new node - which is the
** difference with ft_lstiter, whose f returns nothing and works in place.
**
** The failure path is what this function is really about, and it is a
** favourite at defense. Two things can be lost when a malloc fails
** halfway through:
**
** 1. the nodes already built. ft_lstclear on the partial list frees them,
** which is why del is a parameter: the contents those nodes hold were
** produced by f and nobody else can free them.
** 2. the content that was JUST produced by the call to f, in the same
** step where ft_lstnew failed. It is allocated but no node holds it, so
** it is unreachable the moment the function returns. This is why f's
** result is kept in its own variable instead of being written straight
** into the ft_lstnew call: a value with a name can still be handed to
** del. The version that writes ft_lstnew(f(lst->content)) leaks exactly
** one content on failure, and that leak is real - it shows up under a
** malloc that is made to fail.
**
** ft_lstadd_back keeps the original order. It also walks to the end every
** time, so building n nodes costs n * n steps; ft_lstadd_front plus a
** reversal, or a kept tail pointer, would be linear.
** =========================================================================
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	// named, so it can still be freed if ft_lstnew fails below
	void	*content;

	if (f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (node == NULL)
		{
			// the content just produced: no node holds it yet
			del(content);
			// everything built so far
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		// add_back keeps the original order
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

