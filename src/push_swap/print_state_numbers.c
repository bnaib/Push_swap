       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static void		print_state_numbers_value_color(
	t_list_element **pp_element,
	size_t i,
	size_t list_len)
{
	char					color;
	t_stack_list_content	*p_content;
	char					*format;

	if (i >= list_len)
	{
		ft_printf("║             |             ");
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
		format = "║ {red}%11i | %11lu{eoc} ";
	else if (color == 1)
		format = "║ {yellow}%11i | %11lu{eoc} ";
	else
		format = "║ {green}%11i | %11lu{eoc} ";
	ft_printf(format, p_content->value, p_content->index);
	*pp_element = (*pp_element)->p_next;
}

static void		print_state_numbers_value(
	t_list_element **pp_element,
	size_t i,
	size_t list_len)
{
	t_stack_list_content	*p_content;

	if (i >= list_len)
	{
		ft_printf("║             |             ");
		return ;
	}
	p_content = (*pp_element)->p_content;
	ft_printf("║ %11i | %11lu ", p_content->value, p_content->index);
	*pp_element = (*pp_element)->p_next;
}

static void		print_state_numbers_values(
	t_global_variables *p_gv,
	void (*psnv)(t_list_element **, size_t, size_t))
{
	t_list_element			*p_list_elements[2];
	size_t					i;

	p_list_elements[0] = class_list_get_root(p_gv->p_stacks[0]);
	p_list_elements[1] = class_list_get_root(p_gv->p_stacks[1]);
	i = -1;
	ft_printf("╔═══════════════════════════╦═══════════════════════════╗\n");
	ft_printf("║      A      |    INDEX    ║      B      |    INDEX    ║\n");
	ft_printf("╟───────────────────────────╫───────────────────────────╢\n");
	while (++i < p_gv->p_stacks[0]->length || i < p_gv->p_stacks[1]->length)
	{
		if ((p_gv->flags & GV_FLAGS_PRINT_TOP) &&
			i >= (size_t)(p_gv->print_top_size))
			break ;
		psnv(&(p_list_elements[0]), i, p_gv->p_stacks[0]->length);
		psnv(&(p_list_elements[1]), i, p_gv->p_stacks[1]->length);
		ft_printf("║\n");
	}
	ft_printf("╚═══════════════════════════╩═══════════════════════════╝\n");
}

void			print_state_numbers(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_PRINT_COLOR)
		print_state_numbers_values(p_gv, print_state_numbers_value_color);
	else
		print_state_numbers_values(p_gv, print_state_numbers_value);
}
