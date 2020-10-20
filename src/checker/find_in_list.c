       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

char	find_in_list(t_class_list *p_list, int value)
{
	t_list_element			*p_list_element;
	t_stack_list_content	*p_content;
	size_t					i;

	p_list_element = class_list_get_root(p_list);
	i = -1;
	while (++i < p_list->length)
	{
		p_content = p_list_element->p_content;
		if (p_content->value == value)
			return (1);
		p_list_element = p_list_element->p_next;
	}
	return (0);
}
