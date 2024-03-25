/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:56:39 by jlira             #+#    #+#             */
/*   Updated: 2024/03/25 11:58:47 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		process_id;
	char	*str;
	int		len;

	process_id = get_pid();
	write(STDOUT_FILENO, "MINITALK\n", 9);
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
