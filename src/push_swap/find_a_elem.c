       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static void			find_a_elem_back(
	t_list_element **pp_element,
	t_stack_list_content *p_content[2],
	size_t index)
{
	p_content[1] = (*pp_element)->p_last->p_content;
	while (index < p_content[1]->index
		&& p_content[0]->index > p_content[1]->index)
	{
		(*pp_element) = (*pp_element)->p_last;
		p_content[0] = (*pp_element)->p_content;
		p_content[1] = (*pp_element)->p_last->p_content;
	}
}

static void			find_a_elem_foward(
	t_list_element **pp_element,
	t_stack_list_content *p_content[2],
	size_t index)
{
	p_content[1] = (*pp_element)->p_next->p_content;
	while (index > p_content[0]->index
		&& p_content[0]->index < p_content[1]->index)
	{
		(*pp_element) = (*pp_element)->p_next;
		p_content[0] = (*pp_element)->p_content;
		p_content[1] = (*pp_element)->p_next->p_content;
	}
	if (index > p_content[0]->index &&
		p_content[0]->index > p_content[1]->index)
	{
		(*pp_element) = (*pp_element)->p_next;
		p_content[0] = (*pp_element)->p_content;
		p_content[1] = (*pp_element)->p_next->p_content;
	}
}

t_list_element		*find_a_elem(
	t_global_variables *p_gv,
	t_list_element *p_index_el)
{
	t_list_element			*p_element;
	t_stack_list_content	*p_content[2];
	size_t					index;

	index = ((t_stack_list_content *)(p_index_el->p_content))->index;
	p_element = p_gv->p_start_norm;
	p_content[0] = p_element->p_content;
	if (index < p_content[0]->index)
		find_a_elem_back(&p_element, p_content, index);
	else
		find_a_elem_foward(&p_element, p_content, index);
	return (p_element);
}
