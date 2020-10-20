       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_advlongd.h"

static void	ft_advld_set_inf(t_format_list_el *fm_list, size_t st)
{
	size_t	i;

	i = -1;
	while (++i < fm_list->str_size)
		fm_list->str[i] = ' ';
	i = (!(fm_list->modifiers.flags & FM_FLAG_MINUS)) ?
		fm_list->str_size - st : 0;
	if (fm_list->param.llf.s.sign)
		fm_list->str[i++] = '-';
	else if (fm_list->modifiers.flags & FM_FLAG_PLUS)
		fm_list->str[i++] = '+';
	else if (fm_list->modifiers.flags & FM_FLAG_SPACE)
		i++;
	if (fm_list->modifiers.type[0] == 'f')
	{
		fm_list->str[i++] = 'i';
		fm_list->str[i++] = 'n';
		fm_list->str[i] = 'f';
	}
	else
	{
		fm_list->str[i++] = 'I';
		fm_list->str[i++] = 'N';
		fm_list->str[i] = 'F';
	}
}

static void	ft_advld_set_nan(t_format_list_el *fm_list, size_t st)
{
	size_t	i;

	i = -1;
	while (++i < fm_list->str_size)
		fm_list->str[i] = ' ';
	i = (!(fm_list->modifiers.flags & FM_FLAG_MINUS)) ?
		fm_list->str_size - st : 0;
	if (fm_list->modifiers.type[0] == 'f')
	{
		fm_list->str[i++] = 'n';
		fm_list->str[i++] = 'a';
		fm_list->str[i] = 'n';
	}
	else
	{
		fm_list->str[i++] = 'N';
		fm_list->str[i++] = 'A';
		fm_list->str[i] = 'N';
	}
}

char		ft_advld_check_infnan(t_format_list_el *fm_list)
{
	size_t	st;

	if (fm_list->param.llf.s.exponent != 0b111111111111111)
		return (0);
	st = 3 + (fm_list->param.llf.s.mantis << 1 == 0 &&
		((fm_list->modifiers.flags & FM_FLAG_PLUS) ||
		(fm_list->modifiers.flags & FM_FLAG_SPACE) ||
		fm_list->param.llf.s.sign));
	fm_list->str_size = ((fm_list->modifiers.flags & FM_FLAG_WIDTH) &&
		(st < (size_t)fm_list->modifiers.width)) ?
		fm_list->modifiers.width : st;
	if (!(fm_list->str = malloc(sizeof(*(fm_list->str)) * fm_list->str_size)))
		ft_printf_exit(&fm_list);
	if (fm_list->param.llf.s.mantis << 1 == 0)
		ft_advld_set_inf(fm_list, st);
	else
		ft_advld_set_nan(fm_list, st);
	return (1);
}
