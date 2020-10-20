       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

void	class_list_sort(
	t_class_list *p_list,
	int (*list_elements_cmp)(t_list_element *, t_list_element *),
	t_type_sort type_sort)
{
	size_t			i[2];
	t_list_element	*p_element[2];

	if (type_sort != ASC && type_sort != DESC)
		return ;
	i[0] = -1;
	while (++i[0] < p_list->length)
	{
		p_element[0] = class_list_get_root(p_list);
		p_element[1] = p_element[0]->p_next;
		i[1] = i[0];
		while (++i[1] < p_list->length)
		{
			if (type_sort == ASC &&
				list_elements_cmp(p_element[0], p_element[1]) > 0)
				p_element[0] = p_element[1];
			else if (type_sort == DESC &&
				list_elements_cmp(p_element[0], p_element[1]) < 0)
				p_element[0] = p_element[1];
			p_element[1] = p_element[1]->p_next;
		}
		class_list_cut_element(p_list, p_element[0]);
		class_list_add_to_end(p_list, p_element[0]);
	}
}
