/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 13:10:36 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/28 13:42:20 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

int	compute_disorder(t_stack *a)
{
	t_stack	*current;
	t_stack	*runner;
	long	mistakes;
	long	total_pairs;

	if (!a || !a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = a;
	while (current && current->next)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs++;
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((double) mistakes / (double) total_pairs);
}
