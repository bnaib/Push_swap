       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

t_list_element					*class_list_get_root(
	const t_class_list *p_list)
{
	return (p_list->p_element);
}

t_list_element					*class_list_get_end(
	const t_class_list *p_list)
{
	if (p_list->p_element == NULL)
		return (NULL);
	return (p_list->p_element->p_last);
}

t_list_element					*class_list_get_element_from_start_index(
	const t_class_list *p_list,
	size_t index)
{
	t_list_element	*p_element;
	size_t			i;

	if (index >= p_list->length)
		return (NULL);
	p_element = p_list->p_element;
	i = 0;
	while (i++ < index)
		p_element = p_element->p_next;
	return (p_element);
}

t_list_element					*class_list_get_element_from_end_index(
	const t_class_list *p_list,
	size_t index)
{
	t_list_element	*p_element;
	size_t			i;

	if (index >= p_list->length)
		return (NULL);
	p_element = p_list->p_element->p_last;
	i = 0;
	while (i++ < index)
		p_element = p_element->p_last;
	return (p_element);
}
