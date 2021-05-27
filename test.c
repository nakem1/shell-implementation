
#include "libft.h"

int			check_empty_token(char *str, char delim)
{
	int i;
	int j;
	int size_list;
	int	flag;

	i = 0;
	if ((i = ft_strindx(str, delim, i)) == -1)
		return (1);
	size_list = ft_strlen(str);
	flag = 0;
	while (str[i] != '\0')
	{
		j = i;
		if (j == 0 || j == size_list - 1)
			return (1);
		j--;
		while (str[j] != delim && j != -1)
		{
			if (str[j] != ' ')
				flag = 1;
			j--;
		}
		if (flag == 0)
			return (1);
		j = i;
		flag = 0;
		j++;
		while (str[j] != delim && j != size_list)
		{
				if (str[j] != ' ')
					flag = 1;
			j++;
		}
		if (flag == 0)
			return (1);
		i = ft_strindx(str + (i + 1), delim, i + 1);
	}
	if (flag == 0)
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	printf("%d\n", check_empty_token(argv[1], ';'));
	return (0);
}