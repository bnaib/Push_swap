       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

t_list_element					*class_list_copy_element(
	const t_class_list *p_list,
	t_list_element *p_element)
{
	if (p_element == NULL)
		return (NULL);
	return (class_list_create_element(p_list, p_element->p_content));
}

t_list_element					*class_list_copy_root(
	const t_class_list *p_list)
{
	t_list_element *p_element;

	if ((p_element = class_list_get_root(p_list)) == NULL)
		return (NULL);
	return (class_list_create_element(p_list, p_element->p_content));
}

t_list_element					*class_list_copy_end(
	const t_class_list *p_list)
{
	t_list_element *p_element;

	if ((p_element = class_list_get_end(p_list)) == NULL)
		return (NULL);
	return (class_list_create_element(p_list, p_element->p_content));
}

t_list_element					*class_list_copy_element_from_start_index(
	const t_class_list *p_list,
	size_t index)
{
	t_list_element *p_element;

	p_element = class_list_get_element_from_start_index(p_list, index);
	if (p_element == NULL)
		return (NULL);
	return (class_list_create_element(p_list, p_element->p_content));
}

t_list_element					*class_list_copy_element_from_end_index(
	const t_class_list *p_list,
	size_t index)
{
	t_list_element *p_element;

	p_element = class_list_get_element_from_end_index(p_list, index);
	if (p_element == NULL)
		return (NULL);
	return (class_list_create_element(p_list, p_element->p_content));
}
