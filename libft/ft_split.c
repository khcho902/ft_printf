/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:18:33 by kycho             #+#    #+#             */
/*   Updated: 2020/03/05 00:51:26 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_num(char const *s, char c)
{
	size_t cnt;
	size_t idx;

	cnt = 0;
	idx = 0;
	
	while (s[idx] != '\0')
	{
		if (s[idx] != c)
		{
			cnt++;
			while (s[idx] != '\0' && s[idx] != c)
				idx++;
			idx--;
		}
		idx++;
	}
	return (cnt);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static int	memory_free(char **res, size_t n)
{
	size_t idx;

	idx = 0;
	while (idx < n)
	{
		free(res[idx]);
		idx++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	r_i;
	size_t	s_i;
	size_t	word_len;
	
	if (!(res = (char **)malloc(sizeof(char *) * (get_word_num(s, c) + 1))))
		return (NULL);
	r_i = 0;
	s_i = 0;
	while (s[s_i] != '\0')
	{
		if (s[s_i] != c)
		{
			word_len = get_word_len(&s[s_i], c);
			res[r_i] = (char *)malloc(sizeof(char)*(word_len + 1));
			if (res[r_i] == NULL && memory_free(res, r_i))
				return (0);
			ft_strlcpy(res[r_i], &s[s_i], word_len + 1);
			s_i += word_len - 1;
			r_i++;
		}
		s_i++;
	}
	res[r_i] = NULL;
	return (res);
}
