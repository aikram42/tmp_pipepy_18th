#ifndef PP_H
# define PP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# define ERR_PPE "error_pipe"
# define ERR_FRK "error_fork"
# define ERR_INF "error_infile"
# define ERR_OUF "error_outfile"
# define ERR_INP "error_argc.\n"
# define ERR_CMD "Cmd not found\n"

typedef struct s_info
{
	char	**cmd;
	int		in;
	int		out;

	char	*cmd_p;
	char	**env;
	char	**vec;
	char	**pthz;

	int		pp[2];
	int		pid1;
	int		pid2;

} t_info;

/* pp.c */
void	pipex(t_info *info);
void	get_path(t_info *info);
void	close_ppe(t_info *info);

/* child */
void	child_a(t_info *info);
void	child_b(t_info *info);

/* errs.c */
int		msg_err(char *err);
void	err_ext(char *err);

/* free.c */
void	free_parent(t_info *info);
void	free_child(t_info *info);

/* UTILS utils_a */
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(char *s1, char *s2, size_t n);

/* UTILS utils_b */
char	**ft_split(char *s, char c);
void	ft_spit(char *s, char c, char **strr, int *i);

#endif





/* // void	getcmd(t_info *info, char *argv[]) just incl it in the main function */
// {
// 	info->cmd1 = argv[1];
// 	info->cmd2 = argv[4];
// }