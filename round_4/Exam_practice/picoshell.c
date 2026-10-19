int picoshell(char **cmds[])
{
	pid_t pid;
	int prev_fd = -1;
	int fd[2];
	int i = 0;
	int status;
	if (!cmds || !cmds[0])
		return (1);
	
	while (cmds[i])
	{
		if (pipe(fd) < 0)
			retunr (1);
		if (pid = fork() < 0)
			return(1);
		if(!pid)
		{
			if(prev_fd != -1)
			{
				if(dup2(prev_fd, STDIN_FILENO <0))
					exit(1);
				close(prev_fd);
			}
			if (cmds[i+1] != NULL)
			{
				if (dup2(fd[1], STDOUT_FILENO) < 0)
					exit (1);
				close(fd[1]);
			}
			close(fd[0]);
			if (execvp(cmds[i][0], cmds[i] == -1))
				return(1);
		}
		if (prev_fd != -1)
			close(prev_fd);
		close(fd[1]);
		if (cmds[i + 1] != NULL)
			prev_fd = fd[0];
		else
			close(fd[0]);
			i++;
	}
	while (wait(&status) > 0)
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
	}
	return(0);
}