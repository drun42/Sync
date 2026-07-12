#include <unistd.h>

char *ft_strcpy(char *dest, const char *src)
// char* function() = the return of teh fonction is a pointer to a char
// function(const char *src) = the function will not modify te content of src pointer
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
*/
