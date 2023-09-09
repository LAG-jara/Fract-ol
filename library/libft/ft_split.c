/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:07:16 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/14 14:35:30 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s: The string to be split.
c: The delimiter character

The array of new strings resulting from the split.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer
*/

static int	ft_countw(char const *s, char c)
{
	int	w;
	int	nw;
	int	i;

	i = 0;
	nw = 1;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			nw = 1;
		else if (s[i] != c && nw == 1)
		{
			w++;
			nw = 0;
		}
		i++;
	}
	return (w);
}

static int	ft_countl(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] != c && s[i])
	{
		i++;
		l++;
	}
	return (l);
}

static int	ft_writter(const char *s, char *word, int i, int wl)
{
	int	k;

	k = 0;
	while (k < wl)
		word[k++] = s[i++];
	word[k] = 0;
	return (i);
}

static void	*ft_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**list;
	unsigned int	i;
	int				w;
	int				wl;

	i = 0;
	w = 0;
	list = (char **)malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (!list || !s)
		return (NULL);
	while ((char)s[i])
	{
		if ((char)s[i] == c)
			i++;
		else
		{
			wl = ft_countl(s, c, i);
			list[w] = (char *)malloc(sizeof(char) * (wl + 1));
			if (!list[w])
				return (ft_free(list));
			i = ft_writter(s, list[w++], i, wl);
		}
	}
	list[w] = NULL;
	return (list);
}
/*
int main()
{
	char **list;
	int i;
	
	i = -1;
	list = ft_split("      split       this for   me  !       ", ' ');
	while (list[++i])
	{
				printf("%d",getpid());
		printf("%s\n",list[i]);

		usleep(1000000000);
	}
}*/