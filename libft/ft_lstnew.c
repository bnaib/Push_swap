       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*el;

	el = malloc(sizeof(*el));
	if (el)
	{
		if (content)
		{
			el->content = malloc(content_size);
			if (!(el->content))
			{
				free(el);
				return (NULL);
			}
			if (content_size)
				ft_memcpy(el->content, content, content_size);
			el->content_size = content_size;
		}
		else
		{
			el->content = NULL;
			el->content_size = 0;
		}
		el->next = NULL;
	}
	return (el);
}
