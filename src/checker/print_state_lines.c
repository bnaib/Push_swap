       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

static void		print_state_lines_value_color(
	t_list_element **pp_element,
	size_t i,
	size_t list_len,
	size_t s)
{
	char					color;
	t_stack_list_content	*p_content;
	char					*format;

	if (i >= list_len)
	{
		ft_printf("║                           ");
		return ;
	}
	color = 0;
	p_content = (*pp_element)->p_content;
	if (i == 0 || p_content->value >
		((t_stack_list_content *)((*pp_element)->p_last->p_content))->value)
		color++;
	if (++i == list_len || p_content->value <
		((t_stack_list_content *)((*pp_element)->p_next->p_content))->value)
		color++;
	if (color == 0)
		format = "║\33[0;41m %*s\x1b[0m%*s";
	else if (color == 1)
		format = "║\33[0;43m %*s\x1b[0m%*s";
	else
		format = "║\33[0;42m %*s\x1b[0m%*s";
	ft_printf(format, s, "", 26 - s, "");
	*pp_element = (*pp_element)->p_next;
}

static void		print_state_lines_value(
	t_list_element **pp_element,
	size_t i,
	size_t list_len,
	size_t s)
{
	if (i >= list_len)
	{
		ft_printf("║                           ");
		return ;
	}
	ft_printf("║\33[0;47m %*s\x1b[0m%*s", s, "", 26 - s, "");
	*pp_element = (*pp_element)->p_next;
}

static void		print_state_lines_values(
	t_global_variables *p_gv,
	void (*pslv)(t_list_element **, size_t, size_t, size_t))
{
	t_list_element			*p_list_elements[2];
	size_t					i;
	size_t					s;

	p_list_elements[0] = class_list_get_root(p_gv->p_stacks[0]);
	p_list_elements[1] = class_list_get_root(p_gv->p_stacks[1]);
	i = -1;
	ft_printf("╔═══════════════════════════╦═══════════════════════════╗\n");
	ft_printf("║             A             ║             B             ║\n");
	ft_printf("╟───────────────────────────╫───────────────────────────╢\n");
	while (++i < p_gv->p_stacks[0]->length || i < p_gv->p_stacks[1]->length)
	{
		if ((p_gv->flags & GV_FLAGS_PRINT_TOP) &&
			i >= (size_t)(p_gv->print_top_size))
			break ;
		s = (p_list_elements[0] == NULL) ? 0 : ((t_stack_list_content *)
			(p_list_elements[0]->p_content))->index * 26 / p_gv->max_index;
		pslv(&(p_list_elements[0]), i, p_gv->p_stacks[0]->length, s);
		s = (p_list_elements[1] == NULL) ? 0 : ((t_stack_list_content *)
			(p_list_elements[1]->p_content))->index * 26 / p_gv->max_index;
		pslv(&(p_list_elements[1]), i, p_gv->p_stacks[1]->length, s);
		ft_printf("║\n");
	}
	ft_printf("╚═══════════════════════════╩═══════════════════════════╝\n");
}

void			print_state_lines(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_PRINT_COLOR)
		print_state_lines_values(p_gv, print_state_lines_value_color);
	else
		print_state_lines_values(p_gv, print_state_lines_value);
}
