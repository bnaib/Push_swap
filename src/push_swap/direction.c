       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static void			estimate_direction(
	t_class_list *p_list,
	t_list_element *p_index_el,
	size_t *rx_size,
	size_t *rrx_size)
{
	t_list_element	*p_element;
	size_t			i;

	*rx_size = 0;
	p_element = class_list_get_root(p_list);
	i = (size_t)-1;
	while (++i < p_list->length && p_element != p_index_el)
	{
		(*rx_size)++;
		p_element = p_element->p_next;
	}
	*rrx_size = 0;
	p_element = class_list_get_root(p_list);
	i = (size_t)-1;
	while (++i < p_list->length && p_element != p_index_el)
	{
		(*rrx_size)++;
		p_element = p_element->p_last;
	}
}

static void			set_direction(
	t_global_variables *p_gv,
	size_t size,
	t_shift_info new_shift_info)
{
	if (!p_gv->shift_info.is_set || size < p_gv->shift_info.size)
	{
		p_gv->shift_info.a_elem = new_shift_info.a_elem;
		p_gv->shift_info.b_elem = new_shift_info.b_elem;
		p_gv->shift_info.a_direction = new_shift_info.a_direction;
		p_gv->shift_info.b_direction = new_shift_info.b_direction;
		p_gv->shift_info.size = size;
		p_gv->shift_info.is_set = true;
	}
}

static void			optimal_direction(
	t_global_variables *p_gv,
	t_list_element *b_elem)
{
	t_shift_info	new_shift_info;
	size_t			ras;
	size_t			rras;
	size_t			rbs;
	size_t			rrbs;

	new_shift_info.a_elem = find_a_elem(p_gv, b_elem);
	new_shift_info.b_elem = b_elem;
	estimate_direction(p_gv->p_stacks[0], new_shift_info.a_elem, &ras, &rras);
	estimate_direction(p_gv->p_stacks[1], b_elem, &rbs, &rrbs);
	new_shift_info.a_direction = R;
	new_shift_info.b_direction = R;
	set_direction(p_gv, ((ras > rbs) ? ras : rbs), new_shift_info);
	new_shift_info.a_direction = RR;
	set_direction(p_gv, rras + rbs, new_shift_info);
	new_shift_info.b_direction = RR;
	set_direction(p_gv, ((rras > rrbs) ? rras : rrbs), new_shift_info);
	new_shift_info.a_direction = R;
	set_direction(p_gv, ras + rrbs, new_shift_info);
}

void				opt_direction(t_global_variables *p_gv)
{
	t_list_element	*p_element;
	size_t			i;

	p_element = class_list_get_root(p_gv->p_stacks[1]);
	i = (size_t)-1;
	while (++i < p_gv->p_stacks[1]->length)
	{
		optimal_direction(p_gv, p_element);
		p_element = p_element->p_next;
	}
}
