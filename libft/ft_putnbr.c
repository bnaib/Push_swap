       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	buf[10];
	int		i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		buf[0] = n % 10 * -1 + '0';
		n = n / 10 * -1;
		i++;
	}
	while (n)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (!i)
		write(1, "0", 1);
	while (i > 0)
	{
		i--;
		write(1, buf + i, 1);
	}
}
