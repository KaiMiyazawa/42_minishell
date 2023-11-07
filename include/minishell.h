/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:52:07 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/11/06 12:35:43 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//minishell.hは、すべてのinclude、define、関数の宣言を含んでいます。
//ヘッダーファイルは、基本的に一つにまとめるつもりで現状書いています。(宮澤2023/10/29

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <stdbool.h>

# define FAILED -1
# define SPACE_AND_TAB " \t"

typedef struct s_data
{
	int			ac;
	char		**av;
	char		**envp;

	char			*path_line;
	char			**path;

	int				in_fd;
	int				out_fd;
	char			*infile;
	char			*outfile;
}				t_data;

int	g_state;

//関数の定義は、ファイルのabc順に並べています。
//関数名に_eをつけた関数を作り、エラーハンドリングを内包させる方針でとりあえず書いていってます。

//error.c
void	print_error(char *error_msg, char*addition, bool exit_state, t_data *d);

//executer.c
void	executor(t_data *data);

//expander.c
void	expander(t_data *data);

//lexer.c
void	lexer(char *line, t_data *data);

//main.c

//make_path.c
char	**make_path(const char *path_line);

//minishell.c
void	handler(int sig);
void	minishell(t_data *data);

//perser.c
void	perser(t_data *data);

//signals.c
void	handle_signals(void);

//utils_libft.c
int		ft_strlen(const char *str);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

//utils_libft2.c
char	*ft_strtrim(char const *s1, char const *set);

#endif
