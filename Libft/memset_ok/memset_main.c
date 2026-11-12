#include <stdio.h>
void	*ft_memset(void *s, int c, size_t n);

int main(void)
{
//return xxxx, 777x
        int     c = 7;
        size_t  n = 3;
        char buf[10];
	for (int i = 0; i < 10 ; i++)
	{
		buf[i] = 0;
	}

        for (long unsigned int i = 0; i < n+1; i++)
        {
                printf("%d\n",buf[i]);
        }
        ft_memset(buf,c,n);
        for (long unsigned int i = 0; i < n+1; i++)
        {
                printf("%d\n", buf[i]);
        }
}
