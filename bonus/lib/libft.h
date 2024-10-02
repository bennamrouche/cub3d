/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:15:36 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/10 14:33:22 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(char *s1, const char *s2, size_t n);
int			ft_strcmp( char *str1, char *str2);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strchr(const char *s, int x);
char		*ft_strdup(char *src);
char		*ft_strjoin(char const *string1, char const *string2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strrchr(const char *str, int x);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		*ft_memset(void *str, int x, size_t n);
void		ft_bzero(void *dst, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
int			ft_isdigit(int x);
//bounus part
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);

#endif
