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
** advld_set_one_int(
**  t_advld *p_advld -	It is point to struct with int array
**						and start/end id in array.
**  int i -	Value to set first integer element of array (0 - 999999999):
**			If i < 0 then i = 0;
**			If i > 999999999 then i = 999999999;
** )
** This function set zero to all array elements
** and set one array element from second function parametr.
*/

void		ft_advld_set_one_int(t_advld *p_advld, int i)
{
	int		i1;

	if (i < 0)
		i = 0;
	if (i > 999999999)
		i = 999999999;
	i1 = -1;
	while (++i1 < ADVLD_ALL_PART)
		p_advld->val[i1] = 0;
	p_advld->val[ADVLD_INT_PART_LAST_ID] = i;
	p_advld->start_el_id = ADVLD_INT_PART_LAST_ID;
	p_advld->end_el_id = ADVLD_INT_PART_LAST_ID;
}

/*
** advld_mult_two(
**  t_advld *p_advld -	It is point to struct with int array
**						and start/end id in array.
** )
** This function set parameter to itself multiply by two.
** If result is biger t_advld - function go to segmentation fault.
*/

void		ft_advld_mult_two(t_advld *p_advld)
{
	int		i;

	if (p_advld->val[ADVLD_INT_PART_LAST_ID] == 0 &&
		p_advld->start_el_id == ADVLD_INT_PART_LAST_ID &&
		p_advld->end_el_id == ADVLD_INT_PART_LAST_ID)
		return ;
	i = p_advld->end_el_id + 1;
	while (--i >= p_advld->start_el_id)
		p_advld->val[i] <<= 1;
	i = p_advld->end_el_id + 1;
	while (--i >= p_advld->start_el_id)
	{
		if (p_advld->val[i] >= 1000000000)
		{
			p_advld->val[i] %= 1000000000;
			p_advld->val[i - 1]++;
		}
	}
	if (p_advld->val[p_advld->end_el_id] == 0)
		p_advld->end_el_id--;
	if (p_advld->val[i] > 0)
		p_advld->start_el_id--;
}

/*
** advld_mult_two(
**  t_advld *p_advld -	It is point to struct with int array
**						and start/end id in array.
** )
** This function set parameter to itself division by two.
** If result is biger t_advld - function go to segmentation fault.
*/

void		ft_advld_div_two(t_advld *p_advld)
{
	int		i;

	if (p_advld->val[ADVLD_INT_PART_LAST_ID] == 0 &&
		p_advld->start_el_id == ADVLD_INT_PART_LAST_ID &&
		p_advld->end_el_id == ADVLD_INT_PART_LAST_ID)
		return ;
	i = p_advld->start_el_id - 1;
	while (++i <= p_advld->end_el_id)
	{
		if (p_advld->val[i] & 1)
			p_advld->val[i + 1] += 1000000000;
	}
	if (p_advld->val[i - 1] & 1)
		p_advld->end_el_id++;
	i = p_advld->start_el_id;
	if ((p_advld->val[i] >>= 1) == 0)
		p_advld->start_el_id++;
	while (++i <= p_advld->end_el_id)
		p_advld->val[i] >>= 1;
}

/*
** ft_advld_get_two_in_degree(
**  t_advld *p_advld -	It is point to struct with int array
**						and start/end id in array.
**  int degree - degree value for two
** )
** This function set first parameter to two in degree of second parametr.
** If result is biger t_advld - function go to segmentation fault.
*/

void		ft_advld_get_two_in_degree(t_advld *p_advld, int degree)
{
	int		i;

	ft_advld_set_one_int(p_advld, 1);
	if (degree > 0)
	{
		i = -1;
		while (++i < degree)
			ft_advld_mult_two(p_advld);
	}
	else
	{
		i = 1;
		while (--i > degree)
			ft_advld_div_two(p_advld);
	}
}

/*
** ft_advld_add(
**  t_advld *p_advld_from -	It is point to struct with int array
**							and start/end id in array.
**  t_advld *p_advld_to - 	It is point to struct with int array
**							and start/end id in array.
** )
** This function add first parametr to second parametr.
** If result is biger t_advld - function go to segmentation fault.
*/

void		ft_advld_add(t_advld *p_advld_from, t_advld *p_advld_to)
{
	int		i;

	if (p_advld_from->start_el_id < p_advld_to->start_el_id)
		p_advld_to->start_el_id = p_advld_from->start_el_id;
	if (p_advld_from->end_el_id > p_advld_to->end_el_id)
		p_advld_to->end_el_id = p_advld_from->end_el_id;
	i = p_advld_to->start_el_id - 1;
	while (++i <= p_advld_to->end_el_id)
		p_advld_to->val[i] += p_advld_from->val[i];
	i = p_advld_to->end_el_id + 1;
	while (--i >= p_advld_to->start_el_id)
	{
		if (p_advld_to->val[i] >= 1000000000)
		{
			p_advld_to->val[i] %= 1000000000;
			p_advld_to->val[i - 1]++;
			if (i == p_advld_to->end_el_id && p_advld_to->val[i] == 0)
				p_advld_to->end_el_id--;
		}
	}
	if (p_advld_to->val[i] > 0)
		p_advld_to->start_el_id--;
	if (p_advld_to->val[p_advld_to->start_el_id] == 0 &&
		p_advld_to->start_el_id > p_advld_to->end_el_id)
		p_advld_to->end_el_id++;
}
