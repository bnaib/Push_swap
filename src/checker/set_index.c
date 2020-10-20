       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.17 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

static t_stack_list_content	*get_next_min_content(t_class_list *p_list)
{
	t_list_element			*p_element;
	t_stack_list_content	*p_content[2];
	size_t					i;

	p_element = class_list_get_root(p_list);
	p_content[1] = NULL;
	i = (size_t)-1;
	while (++i < p_list->length)
	{
		p_content[0] = p_element->p_content;
		if (p_content[0]->index == 0 &&
			(p_content[1] == NULL || p_content[1]->value > p_content[0]->value))
			p_content[1] = p_content[0];
		p_element = p_element->p_next;
	}
	return (p_content[1]);
}

size_t						set_index(t_class_list *p_list)
{
	size_t					index;
	t_stack_list_content	*p_content;

	index = 0;
	while ((p_content = get_next_min_content(p_list)) != NULL)
		p_content->index = ++index;
	return (index);
}
