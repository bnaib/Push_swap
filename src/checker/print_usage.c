       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

void	print_usage(t_global_variables *p_gv)
{
	if (!(p_gv->flags & GV_FLAGS_PRINT_HELP))
		return ;
	ft_printf("\
	\rUsage checker:\n\
	\r  -h        - Prints help info (not repeteble)                         \n\
	\r  -v or -l  - Prints states or line states                             \n\
	\r              (not repeteble)                                          \n\
	\r  -c        - Prints colored state                                     \n\
	\r              Uses only with -v or -l                                  \n\
	\r              (not repeteble)                                          \n\
	\r  -cls      - Makes cls before prints state                            \n\
	\r              Uses only with -v or -l                                  \n\
	\r              (not repeteble)                                          \n\
	\r  -p        - Waits after every prints state                           \n\
	\r              Uses only with -v or -l                                  \n\
	\r              (not repeteble)                                          \n\
	\r  -top[int] - Prints max [int](1 - 2147483647) lines in state          \n\
	\r              Uses only with -v or -l                                  \n\
	\r              (not repeteble)                                          \n\
	\r  [int]     - Adds [int](-2147483648 - +2147483647) to stack A         \n\
	\r              (repeteble but different values)                         \n\
	\r");
}
