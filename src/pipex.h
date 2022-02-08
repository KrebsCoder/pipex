/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:08:11 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/08 01:51:24 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_file
{
	int		in_fd;
	int		out_fd;
	char	*infile;
	char	*outfile;
} t_file;

typedef struct s_data
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd;
	char	**envp;
	char	**bin;
	char	*path;
	int		cmd_qnt;
	t_file files;
}	t_data;

int		pipex(int argc, char *argv[], char **envp);
int		open_files(t_data *data);
void	close_files(t_data *data);
int		exec_cmd(t_data *data, char *argv[]);
int		pipes(t_data *data, char **envp);
void	init_values(t_data *data, int argc, char *argv[], char **envp);
void	dup42(t_data *data, int fd, int std);
void	msg_error(t_data *data);
void	parse_env(t_data *data, char **envp);
char	*path_bin(t_data *data);

// ===== LIBFT FUNCTIONS ===== //
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t	ft_strlen(const char *string);
char	*ft_strchr(const char *string, int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);

#endif