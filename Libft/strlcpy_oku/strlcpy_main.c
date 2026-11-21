/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : returns size_t, size is the FULL size of the dst buffer
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int main(void)
{
//man: copies up to size - 1 bytes and always terminates with '\0' if size > 0
//man: RETURNS strlen(src), the length it TRIED to create, not what it copied
//man: a return value >= size means the copy was truncated
//if size is 0, nothing is written at all, dst is not even terminated
//expected is produced by libc strlcpy on a reference buffer
char	dst [16];
char	ref [16];
char	*src;


void prep(void)
{
	memset(dst, 'X', 15);
	memset(ref, 'X', 15);
	dst[15] = '\0';
	ref[15] = '\0';
}


void both(char *s, size_t size)
{
	size_t	r;

	prep();
	r = strlcpy(ref, s, size);
	printf("expected : ret %zu  dst [%s]\n", r, ref);
	r = ft_strlcpy(dst, s, size);
	printf("actual   : ret %zu  dst [%s]\n", r, dst);
}


src = "hello";

	//plenty of room
	printf("%s\n", "Base Case, strlcpy(dst, \"hello\", 16):");
	both(src, 16);
	printf("%s\n"," ");

	//exact fit : 5 characters plus the terminator
	printf("%s\n", "Exact Fit Case, size = 6:");
	both(src, 6);
	printf("%s\n"," ");

	//truncation : only size - 1 characters fit, return is still strlen(src)
	printf("%s\n", "Truncation Case, size = 3:");
	both(src, 3);
	printf("%s\n"," ");

	//size = 1 : room for the terminator only
	printf("%s\n", "Size 1 Case:");
	both(src, 1);
	printf("%s\n"," ");

	//size = 0 : nothing is written, dst keeps its old content
	printf("%s\n", "Size 0 Case:");
	both(src, 0);
	printf("%s\n"," ");

	//empty src
	printf("%s\n", "Empty Src Case, strlcpy(dst, \"\", 16):");
	both("", 16);
	printf("%s\n"," ");

}
