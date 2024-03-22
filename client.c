#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;
	int	count;

	count = 1;
	sign = 0;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			count = count * -1;
		sign++;
		if (sign > 1)
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + nptr[i++] - '0';
	return (result * count);
}

void	char_to_bit(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}

int	main(int ac, char **av)
{
	char *str;
	int	i;
	int	pid;

	if (ft_atoi(av[1]) <= 0)
		write(1, "ERROR: Wrong pid. Please try again.\n", 35);
	if (ac == 3)
	{
		str = av[2];
		i = 0;
		pid = ft_atoi(av[1]);
		while (str[i] != '\0')
		{
			char_to_bit(pid, str[i]);
			i++;
		}
		char_to_bit(pid, '\n');
		return (0);
	}
	write(1, "ERROR: Too much args. Please try again.", 38);
}
