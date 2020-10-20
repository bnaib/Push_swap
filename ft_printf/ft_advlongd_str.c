       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_advlongd.h"

static size_t	ft_advld_get_strlen(
					t_format_list_el *fm_list,
					t_advld *advld_2arr)
{
	int			i;
	size_t		st;

	i = advld_2arr[0].val[advld_2arr[0].start_el_id];
	st = 1;
	while ((i /= 10) > 0)
		st++;
	st += (ADVLD_INT_PART_LAST_ID - advld_2arr[0].start_el_id) * 9;
	st += (fm_list->modifiers.flags & FM_FLAG_PLUS) ||
		(fm_list->modifiers.flags & FM_FLAG_SPACE) ||
		fm_list->param.llf.s.sign;
	st += (fm_list->modifiers.flags & FM_FLAG_OCTOTHORPE) ||
		((fm_list->modifiers.flags & FM_FLAG_ACCURACY) &&
		(fm_list->modifiers.accuracy > 0)) ||
		!(fm_list->modifiers.flags & FM_FLAG_ACCURACY);
	st += ((fm_list->modifiers.flags & FM_FLAG_ACCURACY) &&
	(fm_list->modifiers.accuracy >= 0)) ? fm_list->modifiers.accuracy : 6;
	return (st);
}

static void		ft_advld_set_sign(
					t_format_list_el *fm_list,
					size_t *p_i)
{
	if (fm_list->param.llf.s.sign)
		fm_list->str[(*p_i)++] = '-';
	else if (fm_list->modifiers.flags & FM_FLAG_PLUS)
		fm_list->str[(*p_i)++] = '+';
	else if (fm_list->modifiers.flags & FM_FLAG_SPACE)
		fm_list->str[(*p_i)++] = ' ';
}

static void		ft_advld_set_left_width_and_sign(
					t_format_list_el *fm_list,
					size_t *p_i,
					size_t st)
{
	size_t	i_max;

	i_max = (fm_list->str_size > st) ? (fm_list->str_size - st) : 0;
	if (fm_list->modifiers.flags & FM_FLAG_0)
	{
		ft_advld_set_sign(fm_list, p_i);
		if (*p_i > 0)
			i_max++;
		(*p_i)--;
		while (++(*p_i) < i_max)
			fm_list->str[*p_i] = '0';
	}
	else
	{
		(*p_i)--;
		while (++(*p_i) < i_max)
			fm_list->str[*p_i] = ' ';
		ft_advld_set_sign(fm_list, p_i);
	}
}

static void		ft_advld_set_numeric(
					t_format_list_el *fm_list,
					size_t *p_i,
					size_t st,
					t_advld *advld_2arr)
{
	char	*str;
	int		i;

	st -= (fm_list->modifiers.flags & FM_FLAG_PLUS) ||
		(fm_list->modifiers.flags & FM_FLAG_SPACE) ||
		fm_list->param.llf.s.sign;
	str = &(fm_list->str[*p_i]);
	*p_i += st;
	i = (advld_2arr[0].start_el_id < ADVLD_INT_PART)
		? advld_2arr[0].start_el_id : ADVLD_INT_PART_LAST_ID;
	ft_advld_set_itoa(&str, advld_2arr[0].val[i], &st, 1);
	while (++i < ADVLD_INT_PART)
		ft_advld_set_itoa(&str, advld_2arr[0].val[i], &st, 0);
	if (st > 0 || (fm_list->modifiers.flags & FM_FLAG_OCTOTHORPE))
		*str = '.';
	if (st-- <= 0)
		return ;
	str++;
	ft_advld_set_itoa(&str, advld_2arr[0].val[i], &st, 0);
	while (++i <= advld_2arr[0].end_el_id)
		ft_advld_set_itoa(&str, advld_2arr[0].val[i], &st, 0);
	while (st-- > 0)
		*(str++) = '0';
}

void			ft_advld_get_str(t_format_list_el *fm_list)
{
	t_advld		advld[2];
	size_t		st;
	size_t		i;

	if (ft_advld_check_infnan(fm_list))
		return ;
	if (ft_advld_malloc_val(advld))
		ft_printf_exit(&fm_list);
	ft_advld_get_from_longdouble(fm_list->param.llf.val, advld);
	ft_advlongd_round(fm_list, advld);
	st = ft_advld_get_strlen(fm_list, advld);
	fm_list->str_size = ((fm_list->modifiers.flags & FM_FLAG_WIDTH) &&
		(st < (size_t)fm_list->modifiers.width)) ?
		fm_list->modifiers.width : st;
	if (!(fm_list->str = malloc(sizeof(*(fm_list->str)) * fm_list->str_size)))
		ft_printf_exit(&fm_list);
	i = 0;
	if (fm_list->modifiers.flags & FM_FLAG_MINUS)
		ft_advld_set_sign(fm_list, &i);
	else
		ft_advld_set_left_width_and_sign(fm_list, &i, st);
	ft_advld_set_numeric(fm_list, &i, st, advld);
	while (i < fm_list->str_size)
		fm_list->str[i++] = ' ';
	ft_advld_free_val(advld);
}
