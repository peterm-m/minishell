#include "minishell.h"

static void	ft_heredoc_handler(int sig)
{
	printf("\n");
	rl_replace_line(NULL, 0);
	(void)sig;
}

char	*ft_expand_heredoc(char *str, int expand)
{
	char	*tmp;
	int		i;

	if (expand == TRUE)
	{
		i = -1;
		while (str[++i])
			if (str[i] == '$' && (str[i + 1] == '\0' || str[i + 1] == ' '))
				return (str);
		tmp = parameter_expansion(str);
	}
	else
		tmp = ft_strdup(str);
	return (tmp);
}


void heredoc(t_redirect *redir, char *delimiter)
{
	char 	*line;
	char	*del;
	int		expand;
	char 	*full_history;

	line = NULL;
	full_history = NULL;
	expand = 0;
	if (is_quotes(delimiter[0]) && is_quotes(delimiter[ft_strlen(delimiter)]))
	{
		expand = 1;
		del = ft_substr(delimiter, 1, ft_strlen(delimiter) - 2);
	}
	else
		del = ft_strdup(delimiter);
	while (TRUE)
	{
		line = readline(BHRED"heredoc> "END);
		if (!line || ft_strncmp(line, del, ft_strlen(del) + 1) == 0)
			return ;
		line = ft_expand_heredoc(line, expand);
		redir->here_doc_eof = ft_strjoin(redir->here_doc_eof, line);
		redir->here_doc_eof = ft_strjoin(redir->here_doc_eof, "\n");
		free(line);
	}
}

/*
static int	ft_heredoc(unsigned char status, char *eof)
{
	int		fd[2];
	char	*prompt;
	char	*line;

	if (pipe(fd) == -1)
		return (ft_perror(ERR_ERRNO, "failed to create heredoc file"), -1);
	prompt = getenv("PS2");
	if (!prompt)
		prompt = "> ";
	while (true)
	{
		signal(SIGINT, ft_heredoc_handler);
		line = readline(prompt);
		signal(SIGINT, ft_sig_handler);
		if (!line && rl_eof_found)
			ft_printf("\e[A\e[K%s", prompt);
		if (!line || !ft_strcmp(line, eof))
			return (free(line), close(fd[1]), fd[0]);
		if (ft_expand(&line, status, HEREDOC) != RMV)
			ft_putstr_fd(line, fd[1]);
		ft_putstr_fd("\n", fd[1]);
		free(line);
	}
}

int	here_doc(char *delimiter)
{
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("Enter here-doc content terminated by '%s':\n", delimiter);
	line = readline("heredoc> ");
	while (line)
	{
		line = dollar_check(line);
		if (ft_strncmp(line, delimiter, ft_strlen(line) - 1) == 0)
			break ;
		write(pipefd[1], line, strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	close(pipefd[1]);
	return (pipefd[0]);
}

void	redirect_in(void)
{
	int	fd;

	if ((g_data->redirect & (1 << 0)) != 0)
	{
		fd = open(g_data->redir_in, O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
	if ((g_data->redirect & (1 << 3)) != 0)
	{
		fd = here_doc(g_data->redir_in);
		dup2(fd, 0);
		close(fd);
	}
}*/