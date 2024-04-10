/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:11 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/10 20:56:32 by raphox           ###   ########.fr       */
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
	long int		data;
	long int		size_a;
	long int		index;
	long int		sign;
	long int		negative_data;

	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

// Sorting------------------------

int					sort_3_elements(t_stack **stack_a);
int					sort_4_elements(t_stack **stack_a, t_stack **stack_b);
int					sort_5_elements(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack **stack_a);

// get stack info --------------------------

int					get_max_position(t_stack **stack);
int					get_min_position(t_stack **stack);

// Annexe -----------------------
int					get_max(t_stack **stack);
long int			ft_atoi(char *str);
int					ft_strlen(char *str);
long int			get_max_bits(t_stack **stack);
int					get_stack_size(t_stack **stack);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strjoin(int size, char **strs, char *sep);
int					get_min(t_stack **stack);

// Check args -------------------
int					check_base(int argc, char **str);
int					chck(char *str);
int					is_valid_number(char *str);
int					is_exception_number(char *str);

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

int					count_words(char *str, char c);
t_stack				*new_stack(int value);
char				**ft_split(char *s, char c);
int					get_words_count(char *str, char *charset);
t_stack				*add_to_end_linklist(t_stack *stack, char *data);
t_stack				*add_negative_to_end_linklist(t_stack *stack, char *value);
int					initializatiom_with_split(t_stack *stack_a, char *str);

// handle negative

int					index_the_index(t_stack **stack_a);
int					get_min_position_for_index(t_stack **stack, int index);
int					get_min_for_index(t_stack **stack);

int					count_negative(t_stack **stack_a);
void				push_negative(t_stack **stack_a, t_stack **stack_b);
void				negative_to_positive(t_stack **stack_a, t_stack **stack_b);

// error -----------------------
void				free_stack(t_stack **stack);
void				free_array(size_t i, char **array);
void				exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
