/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:19:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/02 08:28:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	init_algo(t_algo *algo, t_list **a, int size, int chunksize)
{
	algo->ret = 0;
	algo->sort = sort_list(a, size);
	algo->chunk_size = chunksize;
	algo->chunk_nb = size / algo->chunk_size;
	algo->current = 1;
}

void	apply_rotates(t_list **a, t_list **b, t_algo *algo)
{
	while (algo->rr-- > 0)
		rr(a, b, algo->display);
	while (algo->ra-- > 0)
		ra(a, algo->display);
	while (algo->rb-- > 0)
		rb(b, algo->display);
	while (algo->rrr-- > 0)
		rrr(a, b, algo->display);
	while (algo->rra-- > 0)
		rra(a, algo->display);
	while (algo->rrb-- > 0)
		rrb(b, algo->display);
	pb(a, b, algo->display);
}

void	init_loop(t_algo *algo)
{
	algo->ra = 0;
	algo->rb = 0;
	algo->rra = 0;
	algo->rrb = 0;
	algo->rr = 0;
	algo->rrr = 0;
}

int		algo(t_list **a, t_list **b, t_size *mysize, int display)
{
	t_algo	algo;

	init_algo(&algo, a, mysize->size, mysize->chunksize);
	algo.display = display;
	if (mysize->size > 5)
	{
		while (*a != NULL)
		{
			init_loop(&algo);
			algo.a_len = list_len(a);
			algo.b_len = list_len(b);
			find_hold(a, &algo);
			/*if (algo.display == SHOW)
			{
				print_list(a, b);
				printf("h_first : %d\n", algo.h_first);
				printf("algo->first_hold : %d\n", algo.first_pos);
			}*/
			if ((*b) && (*b)->next)
				get_values(b, &algo);
			else
				ft_rooftop(a, &algo);
			algo.ret += 1 + algo.ra + algo.rb + algo.rra
			+ algo.rrb + algo.rr + algo.rrr;
			apply_rotates(a, b, &algo);
			//if (algo.display == SHOW)
			//	print_list(a, b);
		}
		algo.ret += swap_to_a(a, b, &algo);
	}
	free(algo.sort);
	return (algo.ret);
}
