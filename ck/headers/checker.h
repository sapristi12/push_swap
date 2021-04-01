/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:52:54 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/01 11:52:55 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../ps/headers/push_swap.h"

void	get_list_a(t_list **a, int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
long	long_atoi(char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);

#endif
