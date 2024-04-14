/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:14:34 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 20:05:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_connection(t_connection *connection, int level)
{
	t_command	*cmd1;
	t_command	*cmd2;
	if (connection == NULL)
		return ;
	cmd1 = connection->first;
	cmd2 = connection->second;
	printf("├CONECTION: type %d", connection->connector);
	if (cmd1 != NULL)
	{
		printf("\n");
		print_command(cmd1, level + (cmd1->type != cmd_simple));
	}
	if (cmd2 != NULL)
	{
		printf("\n");
		print_command(cmd2, level + (cmd1->type != cmd_simple));
	}
}

static void	print_subshell(t_subshell *subshell, int level)
{
	if (subshell == NULL)
		return ;
	printf("├SUBSHELL: \n");
	if (subshell->command != NULL)
		print_command(subshell->command, level +1);
}

static void	print_simple(t_simple *cmd)
{
	int			i;
	t_word		*words;
	t_redir		*r;

	i = 0;
	printf("├SIMPLE : WORDS-> \t");
	words = cmd->words;
	while (words != NULL)
	{
		printf("%d: %s\t", i++, words->word);
		words = words->next;
	}
	i = 0;
	r = cmd->redirs;
	printf(" REDIRS-> \t");
	while (r != NULL)
	{
		printf("%d:dest=%s source=%d rtype=%d\t", i++, r->dest.filename,
			r->source.fd, r->rtype);
		r = r->next;
	}
}

void	print_command(t_command *cmd, int level)
{
	int		i;
	t_redir	*r;

	i = 1;
	while (i++ < level)
		printf("|\t");
	if (cmd == NULL)
		return ;
	if (cmd->type == cmd_simple)
		print_simple(cmd->value.simple);
	else if (cmd->type == cmd_connection)
		print_connection(cmd->value.connection, level +1);
	else if (cmd->type == cmd_subshell)
		print_subshell(cmd->value.subshell, level +1);
	r = cmd->redirs;
	while (r != NULL)
	{
		printf("%d:dest=%s source=%d rtype=%d\t", i++, r->dest.filename,
			r->source.fd, r->rtype);
		r = r->next;
	}
	if (level == 0)
		printf("\n");
}
