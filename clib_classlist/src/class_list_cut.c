       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

void						class_list_cut_element(
	t_class_list *p_list,
	t_list_element *p_element)
{
	if (p_element == NULL)
		return ;
	p_list->length--;
	if (p_list->length == 0)
		p_list->p_element = NULL;
	else
	{
		if (p_element == p_list->p_element)
			p_list->p_element = p_list->p_element->p_next;
		p_element->p_next->p_last = p_element->p_last;
		p_element->p_last->p_next = p_element->p_next;
	}
	p_element->p_next = NULL;
	p_element->p_last = NULL;
}

t_list_element				*class_list_cut_root(
	t_class_list *p_list)
{
	t_list_element	*p_element;

	if ((p_element = class_list_get_root(p_list)) == NULL)
		return (NULL);
	class_list_cut_element(p_list, p_element);
	return (p_element);
}

t_list_element				*class_list_cut_end(
	t_class_list *p_list)
{
	t_list_element	*p_element;

	if ((p_element = class_list_get_end(p_list)) == NULL)
		return (NULL);
	class_list_cut_element(p_list, p_element);
	return (p_element);
}

t_list_element				*class_list_cut_element_from_start_index(
	t_class_list *p_list,
	size_t index)
{
	t_list_element	*p_element;

	if ((p_element =
		class_list_get_element_from_start_index(p_list, index)) == NULL)
		return (NULL);
	class_list_cut_element(p_list, p_element);
	return (p_element);
}

t_list_element				*class_list_cut_element_from_end_index(
	t_class_list *p_list,
	size_t index)
{
	t_list_element	*p_element;

	if ((p_element =
		class_list_get_element_from_end_index(p_list, index)) == NULL)
		return (NULL);
	class_list_cut_element(p_list, p_element);
	return (p_element);
}
