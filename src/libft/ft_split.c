/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:26:12 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:50:02 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function:		static void skip
**
** Description:		skips delimiters if flag is 1, skips letters and
** everything except delimiters if flag is 2
*/

static void			skip(char *s, char c, int *i, int flag)
{
	if (flag == 1)
		while (s[*i] == c && s[*i] != '\0')
			*i += 1;
	else if (flag == 2)
		while (s[*i] != c && s[*i] != '\0')
			*i += 1;
}

/*
** Function:		static int word_count
**
** Description:		counts the number of words
*/

static int			word_count(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		skip(s, c, &i, 1);
		if (s[i] != '\0')
			count++;
		skip(s, c, &i, 2);
	}
	return (count);
}

/*
** Function:		void search_word
**
** Description:		the function skips characters in searches for
** the word whose number is specified in the i argument
*/

void				search_word(char *s, char c, int *k, int i)
{
	int count_words;

	count_words = 0;
	skip(s, c, k, 1);
	while (count_words < i)
	{
		skip(s, c, k, 2);
		count_words++;
		skip(s, c, k, 1);
	}
}

/*
** Function:		static char *allocate_and_fill_elem
**
** Description:		the function counts the number of characters in a
** single word and allocates memory for it. Then fills in
*/

static char			*allocate_and_fill_elem(char *str, char *s, char c, int i)
{
	int k;
	int j;
	int count;

	k = 0;
	count = 0;
	search_word(s, c, &k, i);
	j = k;
	while (s[j] != c && s[j] != '\0')
	{
		count++;
		j++;
	}
	if (!(str = (char *)malloc((count * sizeof(char)) + 1)))
		exit_error("memory allocation failed", "ft_split");
	str[count] = '\0';
	j = 0;
	while (s[k] != c && s[k] != '\0')
		str[j++] = s[k++];
	return (str);
}

/*
** Function:		char **ft_split
**
** Description:		Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter.  The array must be
** ended by a NULL pointer.
*/

char				**ft_split(char const *s, char c)
{
	int		i;
	int		count_words;
	char	**arr;

	if (s == NULL)
		return (NULL);
	count_words = word_count((char *)s, c);
	if (!(arr = (char **)malloc((count_words + 1) * (sizeof(char *)))))
		exit_error("memory allocation failed", "ft_split");
	arr[count_words] = NULL;
	i = -1;
	while (++i < count_words)
	{
		if (!(arr[i] = allocate_and_fill_elem(arr[i], (char *)s, c, i)))
		{
			i = 0;
			while (i < count_words)
				free(arr[i++]);
			free(arr);
			return (NULL);
		}
	}
	return (arr);
}
