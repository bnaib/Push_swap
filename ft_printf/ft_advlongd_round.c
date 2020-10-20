       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.08 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_advlongd.h"

static char	ft_advlongd_round_5(
			t_advld *advld_2arr,
			int *i)
{
	int		a[2];

	if (i[2] != 5 || i[1] < advld_2arr[0].end_el_id)
		return (0);
	a[0] = i[3];
	a[1] = i[1];
	while ((a[0] /= 10) > 0)
	{
		if ((advld_2arr[0].val[a[1]] / a[0] % 10) != 0)
			return (0);
	}
	if (i[0] == 0)
		a[1]--;
	if (advld_2arr[0].val[a[1]] / ((i[0] == 0) ? 1 : (i[3] * 10)) % 2)
		return (0);
	return (1);
}

void		ft_advlongd_round(
			t_format_list_el *fm_list,
			t_advld *advld_2arr)
{
	int		i[4];

	i[0] = (((fm_list->modifiers.flags & FM_FLAG_ACCURACY) &&
	(fm_list->modifiers.accuracy >= 0)) ? fm_list->modifiers.accuracy : 6);
	i[1] = ADVLD_INT_PART + i[0] / 9;
	i[0] %= 9;
	i[2] = -1;
	i[3] = 1;
	while (++i[2] < 8 - i[0])
		i[3] *= 10;
	if (i[1] > advld_2arr[0].end_el_id ||
		(i[2] = advld_2arr[0].val[i[1]] / i[3] % 10) < 5 ||
		ft_advlongd_round_5(advld_2arr, i))
		return ;
	ft_advld_set_one_int(&advld_2arr[1], 0);
	if (i[0] == 0)
		i[1]--;
	advld_2arr[1].val[i[1]] = (i[0] == 0) ? 1 : (i[3] * 10);
	advld_2arr[1].start_el_id = i[1];
	advld_2arr[1].end_el_id = i[1];
	ft_advld_add(&advld_2arr[1], &advld_2arr[0]);
}
