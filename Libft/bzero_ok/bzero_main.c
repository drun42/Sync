#include <stdio.h>
void	*ft_bzero(void *s, size_t n);

int main(void)
{
//return xxxx, 777x
        int     c = 7;
        size_t  n = 3;
        char buf[10];
	for (int i = 0; i < 10 ; i++)
	{
		buf[i] = 7;
	}

        for (long unsigned int i = 0; i < n+1; i++)
        {
                printf("%d\n",buf[i]);
        }
        ft_bzero(buf,n);
        for (long unsigned int i = 0; i < n+1; i++)
        {
                printf("%d\n", buf[i]);
        }
}
