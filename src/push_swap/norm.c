       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.17 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

size_t	norm_equally(t_class_list *p_list, t_list_element *p_element)
{
	size_t					i;
	size_t					result;
	size_t					find_index;
	t_stack_list_content	*p_content;

	if (p_element == NULL)
		return (0);
	result = 0;
	p_content = p_element->p_content;
	p_content->norm_position = true;
	find_index = p_content->index + 1;
	p_element = p_element->p_next;
	i = 0;
	while (++i < p_list->length)
	{
		p_content = p_element->p_content;
		if ((p_content->norm_position = (p_content->index == find_index)))
		{
			result++;
			find_index++;
		}
		p_element = p_element->p_next;
	}
	return (result);
}

size_t	norm_more(t_class_list *p_list, t_list_element *p_element)
{
	size_t					i;
	size_t					result;
	size_t					last_index;
	t_stack_list_content	*p_content;

	if (p_element == NULL)
		return (0);
	result = 0;
	p_content = p_element->p_content;
	p_content->norm_position = true;
	last_index = p_content->index;
	p_element = p_element->p_next;
	i = 0;
	while (++i < p_list->length)
	{
		p_content = p_element->p_content;
		if ((p_content->norm_position = (p_content->index > last_index)))
		{
			result++;
			last_index = p_content->index;
		}
		p_element = p_element->p_next;
	}
	return (result);
}

void	set_norm(
	t_global_variables *p_gv,
	t_class_list *p_list,
	size_t (*norm)(t_class_list *, t_list_element *))
{
	size_t					i[3];
	t_list_element			*p_element;
	t_stack_list_content	*p_content[2];

	i[1] = 0;
	p_element = class_list_get_root(p_list);
	p_gv->p_start_norm = p_element;
	i[0] = (size_t)-1;
	while (++(i[0]) < p_list->length)
	{
		p_content[0] = p_element->p_content;
		p_content[1] = p_gv->p_start_norm->p_content;
		i[2] = norm(p_list, p_element);
		if (i[2] > i[1])
		{
			i[1] = i[2];
			p_gv->p_start_norm = p_element;
		}
		else if (i[2] == i[1] && p_content[0]->value < p_content[1]->value)
			p_gv->p_start_norm = p_element;
		p_element = p_element->p_next;
	}
	p_gv->norm_size = norm(p_list, p_gv->p_start_norm);
}
