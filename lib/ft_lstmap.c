#include "libft.h"

static void	lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	if (!lst || !del)
		return;
	if (lst)
	{
		while (*lst)
		{
			current = *lst;
			*lst = (*lst)->next;
			del(current->content);
			free(current);
		}
		*lst = NULL;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	new_list = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}