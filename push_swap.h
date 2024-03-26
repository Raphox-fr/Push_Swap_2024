/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:11 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/26 23:02:34 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

// Structure ----------------------
typedef struct s_stack
{
	int				data;
	int				negative_data;
	int				size_a;
	int				index;
	int				sign;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

// Sorting------------------------

int					sort_less_5(t_stack **stack_a, t_stack **stack_b);
int					do_sort_less_5(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack **stack_a);

// Annexe -----------------------
int					get_max(t_stack **stack);
long int			ft_atoi(char *str);
int					ft_strlen(char *str);
int					get_max_bits(t_stack **stack);
int					get_stack_size(t_stack **stack);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strjoin(int size, char **strs, char *sep);
int					get_min(t_stack **stack);

// Check args -------------------
int					check_base(int argc, char **str);
int					chck(char *str);

// Moves ------------------------
// i = 0 = Stack_a | i = 1 = Stack_b | i = -1 Print rien

void				swap(t_stack **stack_a_b, int i);
void				swap_swap(t_stack **stack_a, t_stack **stack_b);

void				push(t_stack **stack_a, t_stack **stack_b, int i);

void				rotate(t_stack **stack, int i);
void				rotate_rotate(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate(t_stack **stack_a_b, int i);
void				reverse_reverse_rotate(t_stack **stack_a,
						t_stack **stack_b);
t_stack				*get_stack_bottom(t_stack *stack);
int					ft_strlen(char *str);

// Initialization --------------

int					initialize_all(int argc, char **argv, t_stack *stack_a);

t_stack				*new_stack(int value);
size_t				count_words(char *s, char c);
char				**ft_split(char *s, char c);
int					get_words_count(char *str, char *charset);
t_stack				*add_to_end_linklist(t_stack *stack, char *data);
t_stack				*add_negative_to_end_linklist(t_stack *stack, char *value);
int					initializatiom_with_split(t_stack *stack_a, char *str);

// handle negative

int					count_negative(t_stack **stack_a);
void				push_negative(t_stack **stack_a, t_stack **stack_b);
void				negative_to_positive(t_stack **stack_a, t_stack **stack_b);
// void				push_negative_to_stack_b(t_stack **stack_a,
// 						t_stack **stack_b);
// void				turn_stack_b_to_negative(t_stack **stack_a,
// 						t_stack **stack_b);

// error -----------------------
void				free_stack(t_stack **stack);
void				free_array(size_t i, char **array);
void				exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
