       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.17 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

void	ft_check_accuracy(t_format_list_el *lst, char *s, size_t *n)
{
	size_t len;

	if ((lst->modifiers.flags & FM_FLAG_ACCURACY) &&
		(size_t)lst->modifiers.accuracy > lst->str_size)
	{
		len = lst->modifiers.accuracy - lst->str_size;
		if (lst->modifiers.type[0] == 's')
			ft_fill_space(lst, s, n, len);
		else
			ft_fill_zero(s, n, len);
	}
}

void	ft_check_zero(t_format_list_el *lst, char *s, size_t *n, size_t len)
{
	if (lst->modifiers.flags & FM_FLAG_0)
	{
		ft_check_sign(lst, s, n);
		len = len - (*n);
		ft_fill_zero(s, n, len);
		ft_fill_param(lst, s, n);
	}
	else
	{
		ft_fill_space(lst, s, n, len);
		ft_check_accuracy(lst, s, n);
		ft_fill_param(lst, s, n);
	}
}

void	ft_check_minus(t_format_list_el *lst, char *s, size_t *n)
{
	size_t len;

	if (lst->str_size > 0)
		len = lst->modifiers.width -
		((lst->str_size > (size_t)lst->modifiers.accuracy)
			? lst->str_size : lst->modifiers.accuracy);
	else
		len = lst->modifiers.width;
	if ((lst->modifiers.flags & FM_FLAG_OCTOTHORPE) && len == 1
		&& lst->modifiers.type[0] != 'o')
		len += 1;
	if (lst->modifiers.flags & FM_FLAG_MINUS)
	{
		ft_check_sign(lst, s, n);
		len = len - (*n);
		ft_check_accuracy(lst, s, n);
		ft_fill_param(lst, s, n);
		ft_fill_space(lst, s, n, len);
	}
	else
		ft_check_zero(lst, s, n, len);
}

void	ft_check_sign(t_format_list_el *lst, char *s, size_t *n)
{
	if (lst->sign)
		s[(*n)++] = '-';
	else if (lst->modifiers.flags & FM_FLAG_PLUS)
		s[(*n)++] = '+';
	else if (lst->modifiers.flags & FM_FLAG_SPACE)
		s[(*n)++] = ' ';
	else if (lst->modifiers.flags & FM_FLAG_OCTOTHORPE)
	{
		ft_fill_octothorpe(lst, s, n);
	}
}

void	ft_check_flags(t_format_list_el *lst)
{
	if (lst->modifiers.type[0] == 'U')
		lst->modifiers.prefix = FM_PREFIX_L;
	if (((lst->modifiers.flags & FM_FLAG_ACCURACY
		|| lst->modifiers.flags & FM_FLAG_MINUS))
		&& lst->modifiers.type[0] != 'f' && lst->modifiers.type[0] != 'F')
		lst->modifiers.flags &= ~(int)FM_FLAG_0;
	if (lst->modifiers.flags & FM_FLAG_PLUS)
		lst->modifiers.flags &= ~(int)FM_FLAG_SPACE;
	if (lst->modifiers.type[0] == 'x' || lst->modifiers.type[0] == 'X' ||
		lst->modifiers.type[0] == 'o' || lst->modifiers.type[0] == 'c' ||
		lst->modifiers.type[0] == 's' || lst->modifiers.type[0] == 'p' ||
		lst->modifiers.type[0] == 'u' || lst->modifiers.type[0] == 'n' ||
		lst->modifiers.type[0] == '%' || lst->modifiers.type[0] == 'b')
	{
		lst->modifiers.flags &= ~(int)FM_FLAG_SPACE;
		lst->modifiers.flags &= ~(int)FM_FLAG_PLUS;
	}
	if (lst->modifiers.type[0] != 'x' && lst->modifiers.type[0] != 'X' &&
		lst->modifiers.type[0] != 'o' && lst->modifiers.type[0] != 'b' &&
		lst->modifiers.type[0] != 'f' && lst->modifiers.type[0] != 'F')
		lst->modifiers.flags &= ~(int)FM_FLAG_OCTOTHORPE;
	if (lst->modifiers.type[0] == 'c' || lst->modifiers.type[0] == '%')
		lst->modifiers.flags &= ~(int)FM_FLAG_ACCURACY;
	if (lst->modifiers.type[0] == 'p')
		lst->modifiers.flags |= FM_FLAG_OCTOTHORPE;
}
