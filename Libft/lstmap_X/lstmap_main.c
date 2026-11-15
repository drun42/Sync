/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_main.c                                     :+:      :+:    :+:   */
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

//subject prototype : f builds the new content, del frees it on failure
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//builds a NEW content out of the old one : the old one is left alone
void	*plus_one(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (n == NULL)
		return (NULL);
	*n = *(int *)content + 1;
	return (n);
}

//frees a content created by f
void	del(void *content)
{
	free(content);
}

int main(void)
{
//subject: iterates over lst, applies f to each content, and builds a NEW
//subject: list out of the results, allocated with malloc
//subject: returns NULL if any allocation fails, using del to clean up
//the ORIGINAL list must come out completely unchanged
//run it under valgrind : valgrind --leak-check=full ./a.out
int	v1;
int	v2;
int	v3;
t_list	a;
t_list	b;
t_list	c;
t_list	*new;
t_list	*tmp;
int	count;

v1 = 1;
v2 = 2;
v3 = 3;
a.content = &v1;
a.next = &b;
b.content = &v2;
b.next = &c;
c.content = &v3;
c.next = NULL;


void list_print(char *label, t_list *l)
{
	printf("%s : ", label);
	while (l)
	{
		printf("[%d]", *(int *)l->content);
		l = l->next;
	}
	printf("\n");
}


	//the new list holds the transformed contents
	printf("%s\n", "Base Case, ft_lstmap(&a, plus_one, del):");
	new = ft_lstmap(&a, plus_one, del);
	printf("%s\n", "expected : [2][3][4]");
	if (new == NULL)
		printf("%s\n", "actual   : NULL");
	else
		list_print("actual  ", new);
	printf("%s\n"," ");

	//the original list is untouched
	printf("%s\n", "Original Untouched Case, the old list:");
	printf("%s\n", "expected : [1][2][3]");
	list_print("actual  ", &a);
	printf("%s\n"," ");

	//the new nodes are new memory, not the old ones
	printf("%s\n", "New Memory Case, new != &a:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", new != &a);
	printf("%s\n", "New Memory Case, new->content != a.content:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", new->content != a.content);
	printf("%s\n"," ");

	//the new list must have the same number of nodes and end with NULL
	count = 0;
	tmp = new;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	printf("%s\n", "Size Case, nodes in the new list:");
	printf("%s\n", "expected : 3");
	printf("actual   : %d\n", count);
	printf("%s\n"," ");

	//clean the new list by hand : content with del, then the node
	while (new)
	{
		tmp = new->next;
		del(new->content);
		free(new);
		new = tmp;
	}
	printf("%s\n", "Cleanup Case, new list freed:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", new == NULL);
	printf("%s\n"," ");

	//an empty list maps to an empty list
	printf("%s\n", "Empty List Case, ft_lstmap(NULL, plus_one, del):");
	new = ft_lstmap(NULL, plus_one, del);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", new == NULL);
	printf("%s\n"," ");

}
