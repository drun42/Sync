/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//the struct comes from the subject, it must match the one in your libft.h
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//subject prototype : del is applied to the CONTENT, not to the node
void	ft_lstdelone(t_list *lst, void (*del)(void *));

//counts how many times del was called, and frees the content
int	del_count = 0;

void	del(void *content)
{
	del_count++;
	free(content);
}

int main(void)
{
//subject: frees the content of the node with del, then frees the node itself
//subject: the NEXT node must NOT be freed
//del is called exactly ONCE, on the content only
//run it under valgrind : valgrind --leak-check=full ./a.out
int	*c1;
int	*c2;
t_list	*n1;
t_list	*n2;

c1 = malloc(sizeof(int));
c2 = malloc(sizeof(int));
*c1 = 1;
*c2 = 2;
n1 = malloc(sizeof(t_list));
n2 = malloc(sizeof(t_list));
n2->content = c2;
n2->next = NULL;
n1->content = c1;
n1->next = n2;

	//del must be called exactly once
	printf("%s\n", "Base Case, ft_lstdelone(n1, del), number of del calls:");
	ft_lstdelone(n1, del);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", del_count);
	printf("%s\n"," ");

	//the next node must still be alive and readable
	printf("%s\n", "Next Node Case, n2 still holds its content:");
	printf("%s\n", "expected : 2");
	printf("actual   : %d\n", *(int *)n2->content);
	printf("%s\n", "Next Node Case, n2->next == NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", n2->next == NULL);
	printf("%s\n"," ");

	//clean the rest by hand : ft_lstdelone did not touch it
	del(n2->content);
	free(n2);
	printf("%s\n", "Cleanup Case, total del calls after freeing n2 by hand:");
	printf("%s\n", "expected : 2");
	printf("actual   : %d\n", del_count);
	printf("%s\n"," ");

}
