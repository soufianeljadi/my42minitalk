/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:30:59 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/05 00:40:00 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define B16L "0123456789abcdef"
# define B16U "0123456789ABCDEF"
# define B10 "0123456789"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <signal.h>

//includes
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(const char *s);
int		ft_put_d(long long n, char *base);
int		ft_put_u(unsigned long long n, char *base);

//mandatory
void	check_bit(unsigned char tmp, int pid);
void	send_char(int pid, char c);
void	sig_handler(int signal, siginfo_t *info, void *s);

//bonus 
void	check_bit_bonus(unsigned char tmp, int pid);
void	send_char_bonus(int pid, char c);
void	sig_handler_bonus(int signal, siginfo_t *info, void *s);
void	received(int signal);

#endif
