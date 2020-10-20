       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

void							class_list_add_to_end(
	t_class_list *p_list,
	t_list_element *p_element)
{
	if (p_list->p_element == NULL)
	{
		p_element->p_next = p_element;
		p_element->p_last = p_element;
		p_list->p_element = p_element;
	}
	else
	{
		p_element->p_next = p_list->p_element;
		p_element->p_last = p_list->p_element->p_last;
		p_list->p_element->p_last->p_next = p_element;
		p_list->p_element->p_last = p_element;
	}
	p_list->length++;
}

void							class_list_add_to_start(
	t_class_list *p_list,
	t_list_element *p_element)
{
	class_list_add_to_end(p_list, p_element);
	p_list->p_element = p_list->p_element->p_last;
}
