#include "minishell.h"

void heredoc(t_dlst **lex, char *delimiter)
{
	char *line;
	char *full_history;
	int		size;
	t_token	*token;

	line = NULL;
	full_history = NULL;
	size = ft_strlen(delimiter);
	full_history = ft_strjoin(full_history, delimiter);
	full_history = ft_strjoin(full_history, "\n");
	while (ft_strncmp(line, delimiter, size) != 0)
	{
		line = readline(BHCYN"heredoc>"END);
		full_history = ft_strjoin(full_history, line);
		full_history = ft_strjoin(full_history, "\n");
		//free(line);
	}
	//full_history = ft_strjoin(full_history, delimiter);
	if (is_quotes(delimiter[0]) && is_quotes(delimiter[size]))
		printf("quotes\n");
		//expand(full_history);
	token = new_token();
	set_token(full_history, ft_strlen(full_history), tt_dgreat, token);
	ft_dlstaddb(lex, ft_dlstnew(token));
}