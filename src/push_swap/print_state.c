       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

void		cls(t_global_variables *p_gv)
{
	int		i;

	if (p_gv->flags & GV_FLAGS_PRINT_CLS)
	{
		i = -1;
		while (++i < 10)
			write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 20);
	}
}

static void	read_wait(t_global_variables *p_gv)
{
	char buf[1];

	if (p_gv->flags & GV_FLAGS_PRINT_PAUSE)
	{
		ft_printf("\nPress enter for continue...\n");
		while (read(0, buf, 1) > 0 && buf[0] != '\n')
			buf[0] = '\0';
	}
}

void		print_state(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_PRINT_STATE)
		print_state_numbers(p_gv);
	if (p_gv->flags & GV_FLAGS_PRINT_LINES)
		print_state_lines(p_gv);
	read_wait(p_gv);
}
