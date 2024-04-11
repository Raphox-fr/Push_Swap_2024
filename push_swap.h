/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:11 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/11 18:45:53 by raphox           ###   ########.fr       */
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

void				sort_3_elements(t_stack **stack_a);
int					sort_4_elements(t_stack **stack_a, t_stack **stack_b);
int					sort_5_elements(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack **stack_a);

// Get_stack_info --------------------------

int					get_max(t_stack **stack);
int					get_min(t_stack **stack);
long int			get_max_bits(t_stack **stack);
int					get_max_position(t_stack **stack);
int					get_min_position(t_stack **stack);

// Annexe -----------------------
long int			ft_atoi(char *str);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_count_string(int size, char **strs, char *sep);
char				*real_bruv(int size, char *tab, char **strs, char *sep);
char				*ft_strjoin(int size, char **strs, char *sep);

// Check_args -------------------
int					check_base(int argc, char **str);
int					is_valid_number(char *str);
int					is_exception_number(char *str);
int					get_stack_size(t_stack **stack);

// Move ------------------------
// i = 0 = Stack_a | i = 1 = Stack_b | i = -1 Print rien

void				swap(t_stack **stack_a_b, int i);
void				swap_swap(t_stack **stack_a, t_stack **stack_b);
void				push(t_stack **stack_a, t_stack **stack_b, int i);
void				rotate(t_stack **stack, int i);
void				rotate_rotate(t_stack **stack_a, t_stack **stack_b);

// Move 2 -----------------------

int					ft_strlen(char *str);
t_stack				*get_stack_bottom(t_stack *stack);
void				reverse_rotate(t_stack **stack_a_b, int i);
void				reverse_reverse_rotate(t_stack **stack_a,
						t_stack **stack_b);

// Initialization --------------

int					initialize_all(int argc, char **argv, t_stack *stack_a);
int					initialization_with_split(t_stack *stack_a, char *str);
t_stack				*new_stack(int value);
t_stack				*add_to_end_linklist(t_stack *stack, char *data);

// Index_stack

int					get_min_for_index(t_stack **stack);
int					get_min_position_for_index(t_stack **stack, int index);
int					index_the_index(t_stack **stack_a);

// Error -----------------------
void				free_stack(t_stack **stack);
void				free_array(size_t i, char **array);
void				exit_error(t_stack **stack_a, t_stack **stack_b);

// Split -----------------------
char				**ft_split(char *s, char c);
int					count_words(char *str, char c);

#endif
