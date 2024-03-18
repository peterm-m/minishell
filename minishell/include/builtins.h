#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int cd_main(char **argv);
int	echo_main(char **argv);
int	env_main();
int exit_main (char **argv);
int export_main(char **argv);
int	pwd_main();
int unset_main(char **argv);
int get_arr_len(char **env);

#endif