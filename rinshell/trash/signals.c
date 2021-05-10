/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:55:02 by frariel           #+#    #+#             */
/*   Updated: 2021/03/17 20:59:31 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

// typedef void	(*sighandler_t)(int);

// sighandler_t signal

void	sig_handler(int signum)
{
	printf("Caught SIGINT\n");
}

int		main()
{
	signal(SIGINT, SIG_IGN);
	while (1)
		;
}
