#include <unistd.h>

char *ft_strcpy(char *dest, const char *src, unsigned int n)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
/*
int main(void)
{
	char src[] = "pedik";
	char dest[50];
	write(1, (ft_strcpy(dest, src)), 6);
}


These functions copy non-null bytes from the string pointed to  by  src
       into  the  array pointed to by dst.  If the source has too few non-null
       bytes to fill the destination, the functions pad the  destination  with
       trailing  null  bytes.  If the destination buffer, limited by its size,
       isn't large enough to hold the copy, the resulting  character  sequence
       is truncated²
*/



