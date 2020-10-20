       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.16 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_advlongd.h"

/*
** ft_advld_malloc_val(
**  t_advld *advld_2arr -	It is array t_advld advld[2]
** )
** This function use malloc for advld[0].val and advld[1].val .
** advld[0].val - used for result operations;
** advld[1].val - it is help struct for operations;
** Return values:
** 0 - OK
** 1 - ERROR
*/

int			ft_advld_malloc_val(t_advld *advld_2arr)
{
	if (!(advld_2arr[0].val = malloc(sizeof(*(advld_2arr[0].val))
		* ADVLD_ALL_PART)))
		return (1);
	if (!(advld_2arr[1].val = malloc(sizeof(*(advld_2arr[1].val))
		* ADVLD_ALL_PART)))
	{
		free(advld_2arr[0].val);
		return (1);
	}
	return (0);
}

/*
** ft_advld_free_val(
**  t_advld *advld_2arr -	It is array t_advld advld[2]
** )
** This function use free for advld[0].val and advld[1].val.
** Used for free vals created with ft_advld_malloc_val();
*/

void		ft_advld_free_val(t_advld *advld_2arr)
{
	free(advld_2arr[0].val);
	advld_2arr[0].val = NULL;
	free(advld_2arr[1].val);
	advld_2arr[1].val = NULL;
}

/*
** ft_advld_free_val(
**	long double ld - long double value for convert to t_advld;
**  t_advld *p_advld -	It is point to array (t_advld advld[2];).
** )
** This function set value advld_2arr[0] for long double from ld.
*/

void		ft_advld_get_from_longdouble(long double ld, t_advld *advld_2arr)
{
	t_long_double			tld;
	int						i;
	unsigned long long int	ull;

	tld.val = ld;
	ft_advld_get_two_in_degree(&advld_2arr[1],
		tld.s.exponent - 16383 - (tld.s.exponent ? 63 : 62));
	ft_advld_set_one_int(&advld_2arr[0], 0);
	ull = tld.s.mantis;
	i = -1;
	while (++i < 64)
	{
		if (ull & 1)
			ft_advld_add(&advld_2arr[1], &advld_2arr[0]);
		ft_advld_mult_two(&advld_2arr[1]);
		ull >>= 1;
	}
}

void		ft_advld_set_itoa(
				char **str,
				int val,
				size_t *st,
				char first_el)
{
	int		i;
	char	c;

	i = 1000000000;
	while (*st > 0 && (i /= 10) > 0)
	{
		c = '0' + (char)(val / i % 10);
		if (first_el && c == '0' && i > 1)
			continue ;
		**str = c;
		(*str)++;
		(*st)--;
		first_el = 0;
	}
}
