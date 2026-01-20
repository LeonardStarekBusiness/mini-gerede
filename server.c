#include "minitalk.h"

t_octet	octet = {0, 0};

int ft_pow(int num1, int num2)
{
    int orig;

    orig = num1;
	if (!num2)
		return (1);
    while (num2 > 1)
    {
        num1 *= orig;
        num2--;
    }
	return (num1);
}

void zero(int num, siginfo_t *info, void *mask)
{
	(void)num;(void)mask;
	if (octet.recieved >= 7)
	{
		octet.byte = -octet.byte;
		octet.byte--;
		write(STDOUT_FILENO, &octet.byte, 1);
		if (octet.byte)
			kill((int)info->si_pid, SIGUSR1);
		octet.byte = 0;
		octet.recieved = 0;
	}
	else
	{
		octet.recieved++;
		kill((int)info->si_pid, SIGUSR1);
	}
}

void one(int num, siginfo_t *info, void *mask)
{
	(void)num;(void)mask;
	octet.byte += ft_pow(2, octet.recieved);
	if (octet.recieved >= 7)
	{
		octet.byte = -octet.byte;
		octet.byte--;
		write(STDOUT_FILENO, &octet.byte, 1);
		if (octet.byte)
			kill((int)info->si_pid, SIGUSR1);
		octet.byte = 0;
		octet.recieved = 0;
	}
	else
	{
		octet.recieved++;
		kill((int)info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction add_zero;
	struct sigaction add_one;

    add_zero.sa_sigaction = zero;
    add_zero.sa_flags = SA_SIGINFO;
    sigemptyset(&add_zero.sa_mask);
    sigaction(SIGUSR1, &add_zero, NULL);

    add_one.sa_sigaction = one;
    add_one.sa_flags = SA_SIGINFO;
    sigemptyset(&add_one.sa_mask);
    sigaction(SIGUSR2, &add_one, NULL);

	ft_printf("Server ID: %d\n", getpid());
	while (1)
		pause();
}