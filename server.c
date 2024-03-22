#include "minitalk.h"

void	bit_to_char(int sign)
{
	static int	bit;
	static char	chr;

	if (bit < 8)
	{
		if (sign == SIGUSR1)
			chr += (1 << (7 - bit));
		bit++;
	}
	if (bit == 8)
	{
		write(1, &chr, 1);
		chr = 0;
		bit = 0;
	}
}

int	main(void)
{
	write(STDOUT_FILENO, "MINITALK\n", 9);
	int		process_id = getpid();
	char	*str;
	int		len;
	write(STDOUT_FILENO, "PID: ", 5);
	str = ft_itoa(process_id);
	len = str_len(str);
	write(STDOUT_FILENO, str, len);
	write(STDOUT_FILENO, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, bit_to_char);
		signal(SIGUSR2, bit_to_char);
		pause();
	}
}
