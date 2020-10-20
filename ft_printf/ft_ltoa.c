       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.04 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static void		ft_fill_str_zero(t_format_list_el *lst, int *len)
{
	if (((lst->modifiers.flags & FM_FLAG_ACCURACY) &&
		lst->modifiers.accuracy == 0) && !(lst->modifiers.type[0] == 'o' &&
		lst->modifiers.flags & FM_FLAG_OCTOTHORPE))
		lst->str[(*len)] = ' ';
	else
		lst->str[(*len)++] = '0';
	if (lst->modifiers.type[0] != 'p')
		lst->modifiers.flags &= ~FM_FLAG_OCTOTHORPE;
}

static int		ft_check_radix(const char type)
{
	if (type == 'x' || type == 'X' || type == 'p')
		return (16);
	else if (type == 'o')
		return (8);
	else if (type == 'b')
		return (2);
	return (10);
}

static void		ft_fill_str_base(unsigned long long param,
					t_format_list_el *lst, int *num)
{
	int mod;

	if (param > 0)
	{
		mod = (param % lst->radix);
		param = (param / lst->radix);
		ft_fill_str_base(param, lst, num);
		if (lst->modifiers.type[0] == 'X')
			lst->str[(*num)++] = (mod < 10) ? mod + '0' : mod + 'A' - 10;
		else
			lst->str[(*num)++] = (mod < 10) ? mod + '0' : mod + 'a' - 10;
	}
}

void			ft_ltoa(unsigned long long param, t_format_list_el *lst)
{
	int size;
	int len;

	size = 64;
	len = 0;
	lst->radix = ft_check_radix(lst->modifiers.type[0]);
	if ((lst->str = (char *)malloc(sizeof(char) * size + 1)) == NULL)
	{
		ft_fm_list_free(&lst);
		exit(0);
	}
	if (param == 0)
		ft_fill_str_zero(lst, &len);
	else
		ft_fill_str_base(param, lst, &len);
	lst->str[len] = '\0';
}
