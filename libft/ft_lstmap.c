       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.12 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_lstmap_free_r(t_list **r)
{
	t_list	*n;

	while (*r)
	{
		n = (*r)->next;
		if ((*r)->content)
			free((*r)->content);
		free(*r);
		*r = n;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*r;
	t_list		**rp;

	if (!f)
		return (NULL);
	rp = &r;
	r = NULL;
	while (lst)
	{
		*rp = f(lst);
		if (!*rp)
		{
			ft_lstmap_free_r(&r);
			return (NULL);
		}
		lst = lst->next;
		rp = &((*rp)->next);
	}
	return (r);
}
