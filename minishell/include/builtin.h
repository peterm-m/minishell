/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:26:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/17 17:13:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	bin_cd(int argc, char **argv, char **env);
int	bin_echo(int argc, char **argv, char **env);
int	bin_env(int argc, char **argv, char **env);
int	bin_pwd(int argc, char **argv, char **env);
int	bin_exit(int argc, char **argv, char **env);
int	bin_unset(int argc, char **argv, char **env);

#endif //BUILTIN_H