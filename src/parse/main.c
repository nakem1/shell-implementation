
#include <term.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

int		main(int argc, char **argv, char const **envp)
{
	char			str[2000];
	int				l;
	struct termios	term;
	
	tcgetattr(0, &term);

	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	while (strcmp(str, "\n"))
	{
		l = read(0, str, 100);
		write(1, str, l);
	}
	write(1, "\n", l);
	return (0);
}
