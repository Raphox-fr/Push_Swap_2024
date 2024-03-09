/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:11 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/09 17:44:57 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

// Structure
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

// Annexe
int					ft_strlen(char *str);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
long int			ft_atoi(char *str);
void				args_to_int(int argc, char **argv);
void				exit_error(t_stack **stack_a, t_stack **stack_b);

// Check args
int					check_base(int argc, char **argv);
int					check_letters_in_args(char *str);

// Move
// i = 0 = Stack_a | i = 1 = Stack_b | i = -1 Print rien

void				swap_a_b(t_stack **stack_a_b, int i);
void				swap_swap_a_b(t_stack **stack_a, t_stack **stack_b);

void				push_a_b(t_stack **stack_a, t_stack **stack_b, int i);

void				rotate_a_b(t_stack **stack_a_b, int i);
void				rotate_rotate_a_b(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate_a_b(t_stack **stack_a_b, int i);
void				reverse_reverse_rotate_a_b(t_stack **stack_a,
						t_stack **stack_b);

// Initilization
t_stack				*new_stack(int value);
t_stack				*add_to_end_linklist(t_stack *stack, char *data);
char				**ft_split(char *str, char *charset);
int					initializatiom_with_split(t_stack *stack_a, int argc,
						char **argv);
int					get_words_count(char *str, char *charset);
int	initializatiom_basic(t_stack *stack_a, int argc, char **argv);

#endif
