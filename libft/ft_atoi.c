       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

static char		ft_check_over(long long li, char n, char minus)
{
	if (minus)
	{
		if (li == 922337203685477580 && n == '9')
			return (1);
	}
	else
	{
		if (li == 922337203685477580 && (n == '8' || n == '9'))
			return (1);
	}
	if (li > 922337203685477580 && n >= '0' && n <= '9')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long		ll;
	char			minus;
	int				i;
	char			co;

	ll = 0;
	i = 0;
	while (str[i] && ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
		i++;
	minus = str[i] == '-';
	if (minus || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ll = ll * 10 + (str[i] - '0');
		co = ft_check_over(ll, str[i + 1], minus);
		if (co)
			return (-1 * !minus);
		i++;
	}
	if (minus)
		ll *= -1;
	return ((int)ll);
}
