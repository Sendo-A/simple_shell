#include "shell.h"

/**
 * sig_handler - Handles the signal.
 * @sig: The signal.
*/

void sig_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	write(1, "\033[38;2;0;63;92adou_shell$\033[0m ", 33);
}
/**
 * read_and_execute - Reads and executes the command.
 * (I split the main function to respect betty's syntax style)
 * @args: The arguments struct.
*/

void read_and_execute(args_t *args)
{
	args->read_check = getline(&args->buff, &args->len, stdin);
	if (args->read_check == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			free_all(args);
			errno = args->errno_value;
			exit(errno);
		}
		errno = args->errno_value;
		free_all(args);

		if (!errno)
			exit(EXIT_SUCCESS);
		exit(errno);
	}
	split_path(args);
	split_cmd(args);
	if (!check_builtin(args))
	{
		if (args->check)
			execute(args);
		else
		{
			if (args->buff[0] != '\n')
			{
				write(2, args->av[0], _strlen(args->av[0]));
				write(2, ": ", 2);
				print_number(args->input_count);
				write(2, ": ", 2);
				write(2, args->cmd_args[0], _strlen(args->cmd_args[0]));
				write(2, ": not found\n", 12);
				args->errno_value = 127;
			}
		}
	}
}

/**
 * main - entry point to the shell program
 * @ac: number of arguments passed to the program
 * @av: array of strings containing the arguments
 * @env: array of strings containing the environment variables
 * Return: 1 if ac != 1.
*/

int	main(int ac, char **av, char **env)
{
	args_t args;

	args.input_count = 1;
	if (ac == 1)
	{
		args.buff = NULL;
		args.cmd_args = NULL;
		args.path = NULL;
		args.cmd = NULL;
		args.len = 0;
		args.env = env;
		args.av = av;
		args.errno_value = 0;
		if (signal(SIGINT, sig_handler) == SIG_ERR)
		{
			perror("Can't catch SIGINT");
			exit(EXIT_FAILURE);
		}
		while (1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\033[38;2;0;63;92msimple_shell$\033[0m ", 33);
			read_and_execute(&args);
			args.input_count++;
		}
		free_all(&args);
	}
	else
		write(2, "Usage: ./hsh\n", 13);
	return (EXIT_FAILURE);
}
