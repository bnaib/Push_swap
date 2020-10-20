       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

t_error_code	check_sort_a(t_global_variables *p_gv)
{
	t_list_element			*p_element;
	t_stack_list_content	*p_content[2];
	size_t					i;

	p_element = class_list_get_root(p_gv->p_stacks[0]);
	i = 0;
	while (++i < p_gv->p_stacks[0]->length)
	{
		p_content[0] = p_element->p_content;
		p_element = p_element->p_next;
		p_content[1] = p_element->p_content;
		if (p_content[0]->value > p_content[1]->value)
			return (EC_KO);
	}
	return (EC_OK);
}

t_error_code	check_sort_b(t_global_variables *p_gv)
{
	t_list_element			*p_element;
	t_stack_list_content	*p_content[2];
	size_t					i;

	p_element = class_list_get_root(p_gv->p_stacks[1]);
	i = 0;
	while (++i < p_gv->p_stacks[1]->length)
	{
		p_content[0] = p_element->p_content;
		p_element = p_element->p_next;
		p_content[1] = p_element->p_content;
		if (p_content[0]->value < p_content[1]->value)
			return (EC_KO);
	}
	return (EC_OK);
}

t_error_code	check_sort_a_and_b(t_global_variables *p_gv)
{
	char	c;

	c = (check_sort_a(p_gv) == EC_OK);
	c &= (check_sort_b(p_gv) == EC_OK);
	return (c ? EC_OK : EC_KO);
}

t_error_code	check_sort(t_global_variables *p_gv)
{
	if (p_gv->p_stacks[1]->length != 0)
		return (EC_KO);
	return (check_sort_a(p_gv));
}
