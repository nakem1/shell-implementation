#include <term.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <libft.h>

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	init_term()

int		main(int argc, char **argv, char const **envp)
{
	char			str[2000];
	int				l;
	struct termios	term;
	char			*term_name;
	
	// if (!(str = ft_calloc(2000, sizeof(char))))
		// return (1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
	tputs(save_cursor, 1, ft_putchar);
	while (1)
	{
		l = read(0, str, 100);
		str[l] = 0;
		if (!strcmp(str, "\e[A"))
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "previous", 8);
		}
		else if (!strcmp(str, "\e[B"))
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, "next", 4);
		}
		else if (!strcmp(str, "\177"))// && !strcmp(str, "\177"))
		{
			// write(1, "rofl", 4);
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
		}
		else if (!ft_strcmp(str, "\4"))
			return (0);
		else
			write(1, str, l);
		} 
		// write(1, str, l);
	}
	write(1, "\n", l);
	return (0);
}

