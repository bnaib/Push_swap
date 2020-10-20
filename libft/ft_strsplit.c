       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.11 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	ft_strsplit_creater(char ***r, char const *s, char c)
{
	int		wc;

	if (!s || !r)
		return (1);
	wc = ft_strsplitwcount(s, c);
	wc++;
	*r = malloc(sizeof(**r) * wc);
	if (!*r)
		return (1);
	ft_bzero(*r, sizeof(**r) * wc);
	return (0);
}

static char		ft_strsplit_screater(char **r, char const *s, int ws)
{
	if (!r || !s)
		return (1);
	*r = malloc(sizeof(**r) * (ws + 1));
	if (!*r)
		return (1);
	ft_memcpy(*r, s, ws);
	(*r)[ws] = 0;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		wi;
	int		ws;

	if (ft_strsplit_creater(&r, s, c))
		return (NULL);
	wi = 0;
	while (*s)
	{
		ws = ft_strsplitwsize(s, c);
		if (ws)
		{
			if (ft_strsplit_screater(&(r[wi]), s, ws))
			{
				ft_arrfree((void ***)(&r));
				return (NULL);
			}
			s += ws;
			wi++;
		}
		else
			s++;
	}
	return (r);
}
