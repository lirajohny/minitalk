/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:56:57 by jlira             #+#    #+#             */
/*   Updated: 2024/03/25 11:57:01 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char	*ft_itoa(int n);
void	char_to_bit(int pid, char c);
void	bit_to_char(int sign);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		str_len(char *str);

#endif
