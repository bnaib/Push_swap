       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

t_list_element	*class_list_create_element(
	const t_class_list *p_list,
	const void *p_content)
{
	t_list_element	*p_element;

	if ((p_element = malloc(sizeof(*p_element))) == NULL)
		return (NULL);
	p_element->p_content = NULL;
	p_element->p_last = NULL;
	p_element->p_next = NULL;
	if (p_content == NULL)
		return (p_element);
	if ((p_element->p_content = p_list->copy_list_content(p_content)) == NULL)
	{
		free(p_element);
		return (NULL);
	}
	return (p_element);
}

t_list_element	*class_list_create_element_to_end(
	t_class_list *p_list,
	const void *p_content)
{
	t_list_element	*p_element;

	if ((p_element = class_list_create_element(p_list, p_content)) == NULL)
		return (NULL);
	class_list_add_to_end(p_list, p_element);
	return (p_element);
}

t_list_element	*class_list_create_element_to_start(
	t_class_list *p_list,
	const void *p_content)
{
	t_list_element	*p_element;

	if ((p_element = class_list_create_element(p_list, p_content)) == NULL)
		return (NULL);
	class_list_add_to_start(p_list, p_element);
	return (p_element);
}
