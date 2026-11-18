/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : void *, const void *, size_t
void	*ft_memchr(const void *s, int c, size_t n);

int main(void)
{
//man: scans the FIRST n bytes of s for the byte c
//man: c is interpreted as an UNSIGNED CHAR
//man: returns NULL if the byte is not found inside those n bytes
//memchr works on bytes, a '\0' does NOT stop it
//expected is produced by libc memchr
char	buf [12] = "hello world";
char	zeroed [6] = "ab\0cZ";


void show(char *label, char *base, void *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : offset %d\n", label, (int)((char *)p - base));
}


void both(char *base, int c, size_t n)
{
	show("expected", base, memchr(base, c, n));
	show("actual  ", base, ft_memchr(base, c, n));
}


	//first occurrence inside n bytes
	printf("%s\n", "Base Case, memchr(buf, 'o', 12):");
	both(buf, 'o', 12);
	printf("%s\n"," ");

	//byte is there, but behind the n limit
	printf("%s\n", "n Limit Case, memchr(buf, 'o', 4):");
	both(buf, 'o', 4);
	printf("%s\n"," ");

	//byte sits exactly on the last allowed index
	printf("%s\n", "n Limit Case, memchr(buf, 'o', 5):");
	both(buf, 'o', 5);
	printf("%s\n"," ");

	//not present
	printf("%s\n", "Not Found Case, 'z':");
	both(buf, 'z', 12);
	printf("%s\n"," ");

	//n = 0 : nothing is read, nothing is found
	printf("%s\n", "n = 0 Case:");
	both(buf, 'h', 0);
	printf("%s\n"," ");

	//c is taken as unsigned char : 'o' + 256 has the same low byte
	printf("%s\n", "Conversion Case, 'o' + 256:");
	both(buf, 'o' + 256, 12);
	printf("%s\n"," ");

	//a '\0' inside the buffer does not stop the scan
	printf("%s\n", "Past '\\0' Case, 'Z' in \"ab\\0cZ\":");
	both(zeroed, 'Z', 6);
	printf("%s\n", "Past '\\0' Case, '\\0' in \"ab\\0cZ\":");
	both(zeroed, '\0', 6);
	printf("%s\n"," ");

}
