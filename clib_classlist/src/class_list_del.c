       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

void				class_list_del_element(
	t_class_list *p_list,
	t_list_element **pp_element)
{
	p_list->free_list_content((*pp_element)->p_content);
	if ((*pp_element)->p_next != NULL && (*pp_element)->p_last != NULL)
		class_list_cut_element(p_list, *pp_element);
	free(*pp_element);
	*pp_element = NULL;
}

void				class_list_del_root(
	t_class_list *p_list)
{
	t_list_element	*p_element;

	if ((p_element = class_list_get_root(p_list)) == NULL)
		return ;
	class_list_del_element(p_list, &p_element);
}

void				class_list_del_end(
	t_class_list *p_list)
{
	t_list_element	*p_element;

	if ((p_element = class_list_get_end(p_list)) == NULL)
		return ;
	class_list_del_element(p_list, &p_element);
}

void				class_list_del_element_from_start_index(
	t_class_list *p_list,
	size_t index)
{
	t_list_element	*p_element;

	if ((p_element =
		class_list_get_element_from_start_index(p_list, index)) == NULL)
		return ;
	class_list_del_element(p_list, &p_element);
}

void				class_list_del_element_from_end_index(
	t_class_list *p_list,
	size_t index)
{
	t_list_element	*p_element;

	if ((p_element =
		class_list_get_element_from_end_index(p_list, index)) == NULL)
		return ;
	class_list_del_element(p_list, &p_element);
}
