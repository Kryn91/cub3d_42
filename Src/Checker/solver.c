/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:24:21 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:24:21 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "stdlib.h"

void	stack_init(t_stack *stack, int capacity)
{
	stack->data = malloc(sizeof(t_point) * capacity);
	stack->size = 0;
	stack->capacity = capacity;
}

void	stack_push(t_stack *stack, int pos_x, int pos_y)
{
	stack->data[stack->size].x = pos_x;
	stack->data[stack->size].y = pos_y;
	stack->size++;
}

t_point	stack_pop(t_stack *stack)
{
	return (stack->data[--stack->size]);
}

int	stack_empty(t_stack *stack)
{
	return (stack->size == 0);
}
