       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"
#include "ft_advlongd.h"

static void		ft_printf_set_str_from_rapam_str(t_format_list_el *fm_list)
{
	if (fm_list->modifiers.prefix & FM_PREFIX_L && fm_list->param.s != NULL)
		ft_fm_wstr(fm_list);
	else
		ft_fm_str(fm_list);
}

static void		ft_printf_set_str_from_rapam_char(t_format_list_el *fm_list)
{
	if (fm_list->modifiers.prefix & FM_PREFIX_L)
		ft_fm_wchar(fm_list);
	else
		ft_fm_char(fm_list);
}

static void		ft_printf_set_str_from_rapam_di(t_format_list_el *fm_list)
{
	if ((fm_list->modifiers.prefix & FM_PREFIX_L)
		|| (fm_list->modifiers.prefix & FM_PREFIX_Z)
		|| (fm_list->modifiers.prefix & FM_PREFIX_T)
		|| (fm_list->modifiers.prefix & FM_PREFIX_J))
		ft_fm_ld(fm_list);
	else if (fm_list->modifiers.prefix & FM_PREFIX_LL)
		ft_fm_lld(fm_list);
	else if (fm_list->modifiers.prefix & FM_PREFIX_H)
		ft_fm_hd(fm_list);
	else if (fm_list->modifiers.prefix & FM_PREFIX_HH)
		ft_fm_hhd(fm_list);
	else
		ft_fm_int(fm_list);
}

static void		ft_printf_set_str_from_rapam_oux(t_format_list_el *fm_list)
{
	if ((fm_list->modifiers.prefix & FM_PREFIX_L)
		|| (fm_list->modifiers.prefix & FM_PREFIX_Z)
		|| (fm_list->modifiers.prefix & FM_PREFIX_T)
		|| (fm_list->modifiers.prefix & FM_PREFIX_J))
		ft_fm_lu(fm_list);
	else if (fm_list->modifiers.prefix & FM_PREFIX_LL)
		ft_fm_llu(fm_list);
	else if (fm_list->modifiers.prefix & FM_PREFIX_H)
		ft_fm_hu(fm_list);
	else if (fm_list->modifiers.prefix & FM_PREFIX_HH)
		ft_fm_hhu(fm_list);
	else
		ft_fm_uint(fm_list);
}

void			ft_printf_set_str_from_rapam(t_format_list_el *fm_list)
{
	if (fm_list->modifiers.type[0] == '%')
		ft_fm_percent(fm_list);
	if (fm_list->modifiers.type[0] == 'c')
		ft_printf_set_str_from_rapam_char(fm_list);
	else if (fm_list->modifiers.type[0] == 's')
		ft_printf_set_str_from_rapam_str(fm_list);
	else if (fm_list->modifiers.type[0] == 'd'
			|| fm_list->modifiers.type[0] == 'i')
		ft_printf_set_str_from_rapam_di(fm_list);
	else if (fm_list->modifiers.type[0] == 'o'
		|| fm_list->modifiers.type[0] == 'u'
		|| fm_list->modifiers.type[0] == 'U'
		|| fm_list->modifiers.type[0] == 'x'
		|| fm_list->modifiers.type[0] == 'X'
		|| fm_list->modifiers.type[0] == 'b')
		ft_printf_set_str_from_rapam_oux(fm_list);
	else if (fm_list->modifiers.type[0] == 'p')
		ft_fm_llu(fm_list);
	else if (fm_list->modifiers.type[0] == 'f'
		|| fm_list->modifiers.type[0] == 'F')
		ft_advld_get_str(fm_list);
}
