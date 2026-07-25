#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    if (to_find[0] == '\0')
        return str;
    
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == to_find[0])
        {
            j = 0;
            while (to_find[j] != '\0' && str[i + j] == to_find[j])
                j++;
            if (to_find[j] == '\0')
                return &str[i];
        }
    }
    return 0;
}

int main(void)
{
    char haystack[] = "please help me";
    char *result;

    result = ft_strstr(haystack, "help");
    printf("search 'help' -> %s\n", result ? result : "(null)");

    result = ft_strstr(haystack, "please");
    printf("search 'please' -> %s\n", result ? result : "(null)");

    result = ft_strstr(haystack, "me");
    printf("search 'me' -> %s\n", result ? result : "(null)");

    result = ft_strstr(haystack, "xyz");
    printf("search 'xyz' -> %s\n", result ? result : "(null)");

    result = ft_strstr(haystack, "");
    printf("search '' -> %s\n", result ? result : "(null)");

    return 0;
}
