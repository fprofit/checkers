#include <unistd.h>

int check_in(char **av){
	int i;
	int j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if(av[i][j] != 'W' && av[i][j] != 'w' && 
				av[i][j] != 'B' && av[i][j] != 'b' && av[i][j] != '.')
				return 0;
			if(i % 2 != 0 && j % 2 == 0 && av[i][j] != '.')
				return 0;
			if(i % 2 == 0 && j % 2 != 0 && av[i][j] != '.')
				return 0;
		}
		if(av[i][8] != '\0')
			return 0;
	}
	return 1;
}

int check_step(char **av, int i, int j, int arg)
{
	if((arg == 1 || arg >= 5) && (av[i+1][j+1] == 'b' || av[i+1][j+1] == 'B'))
		return(1);
	else if((arg == 2 || arg >= 5) && (av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B'))
		return (1);
	else if((arg == 3 || arg > 5 ) && (av[i-1][j+1] == 'b' || av[i-1][j+1] == 'B'))
		return(1);
	else if((arg == 4 || arg > 5 )  && (av[i-1][j-1] == 'b' || av[i-1][j-1] == 'B'))
		return(1);
	return(0);
}
int checkers(char **av, int i, int j, int sum, int fl)
{
		if(i <= 4 && j <= 4 && av[i+2][j+2] == '.' && 
				check_step(av, i, j, 1) && check_step(av, i+2, j+2, 5))
			{
				av[i+1][j+1] = '.';
				sum = checkers(av, i+2, j+2, sum+1, fl);
				av[i+1][j+1] = 'b';
			}
		else if(i <= 4 && j >= 2 && av[i+2][j-2] == '.' &&
				 check_step(av, i, j, 2) && check_step(av, i+2, j-2, 5))
			{
				av[i+1][j-1] = '.';			
				sum = checkers(av, i+2, j-2, sum+1, fl);
				av[i+1][j-1] = 'b';
			}
		else if(fl == 1 && i >= 2 && j <= 5 && av[i-2][j+2] == '.' &&
				check_step(av, i, j, 3) &&	check_step(av, i-2, j+2, 6))
			{
				av[i-1][j+1] = '.';			
				sum = checkers(av, i-2, j+2, sum+1, fl);
				av[i-1][j+1] = 'b';
			}
		else if(fl == 1 && i >= 2 && j >= 2 && av[i-2][j-2] == '.' &&
				check_step(av, i, j, 4) &&	check_step(av, i-2, j-2, 6))
			{
				av[i-1][j-1] = '.';		
				sum = checkers(av, i-2, j-2, sum+1, fl);
				av[i-1][j-1] = 'b';
			}
		else if(i <= 5 && j <= 5 && av[i+2][j+2] == '.' &&
				check_step(av, i, j, 1))
			{
				av[i+1][j+1] = '.';
				sum = checkers(av, i+2, j+2, sum+1, fl);
				av[i+1][j+1] = 'b';
				
			}
		else if(i <= 5 && j >= 2 && av[i+2][j-2] &&
				check_step(av, i, j, 2))
			{
				av[i+1][j-1] = '.';			
				sum = checkers(av, i+2, j-2, sum+1, fl);
				av[i+1][j-1] = 'b';
			}
		else if(fl == 1 && i >= 2 && j <= 5 && av[i-2][j+2] == '.' &&
				check_step(av, i, j, 3))
			{
				av[i-1][j+1] = '.';			
				sum = checkers(av, i-2, j+2, sum+1, fl);
				av[i-1][j+1] = 'b';
			}
		else if(fl == 1 && i >= 2 && j >= 2 && av[i-2][j-2] == '.' &&
				check_step(av, i, j, 4))
			{
				av[i-1][j-1] = '.';		
				sum = checkers(av, i-2, j-2, sum+1, fl);
				av[i-1][j-1] = 'b';
			}
		return(sum);
	return(sum);
}
void checkers_print(char **av, int i, int j, int fl)
{
	char num = '1';
	char alf = 'A';
		if(i <= 4 && j <= 4 && av[i+2][j+2] == '.' && 
				check_step(av, i, j, 1) && check_step(av, i+2, j+2, 5))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i+1][j+1] = '.';
				checkers_print(av, i+2, j+2, fl);
			}
		else if(i <= 4 && j >= 2 && av[i+2][j-2] == '.' &&
				 check_step(av, i, j, 2) && check_step(av, i+2, j-2, 5))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i+1][j-1] = '.';			
				checkers_print(av, i+2, j-2, fl);
			}
		else if(fl == 1 && i >= 2 && j <= 4 && av[i-2][j+2] == '.' &&
				check_step(av, i, j, 3) &&	check_step(av, i-2, j+2, 6))
			{
				
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i-1][j+1] = '.';			
				checkers_print(av, i-2, j+2, fl);
			}
		else if(fl == 1 && i >= 2 && j >= 2 && av[i-2][j-2] == '.' &&
				check_step(av, i, j, 4) &&	check_step(av, i-2, j-2, 6))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i-1][j-1] = '.';		
				checkers_print(av, i-2, j-2, fl);
			}
		else if(i <= 5 && j <= 5 && av[i+2][j+2] == '.' &&
				check_step(av, i, j, 1))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i+1][j+1] = '.';
				checkers_print(av, i+2, j+2, fl);
				
			}
		else if(i <= 5 && j >= 2 && av[i+2][j-2] &&
				check_step(av, i, j, 2))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i+1][j-1] = '.';			
				checkers_print(av, i+2, j-2, fl);
			}
		else if(fl == 1 && i >= 2 && j <= 5 && av[i-2][j+2] == '.' &&
				check_step(av, i, j, 3))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i-1][j+1] = '.';			
				checkers_print(av, i-2, j+2, fl);
			}
		else if(fl == 1 && i >= 2 && j >= 2 && av[i-2][j-2] == '.' &&
				check_step(av, i, j, 4))
			{
				num = num + i;
				alf = alf + j;
				write(1, &alf, 1);
				write(1, &num, 1);
				write(1, "-", 1);
				av[i-1][j-1] = '.';		
				checkers_print(av, i-2, j-2, fl);
			}
		else
		{
			num = num + i;
			alf = alf + j;
			write(1, &alf, 1);
			write(1, &num, 1);
			write(1, "\n", 1);
			av[i-1][j-1] = '.';
		}
}

int che(char **av, int i, int j)
{
	int startI;
	int startJ;
	int sum;
	int fl;
	sum = -1;
	for(; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(av[i][j] == 'w')
			{
				
				if(sum < checkers(av, i, j, 0, 0))
				{
					fl = 0;
					startI = i;
					startJ = j;
					sum = checkers(av, i, j, 0, fl);
				}
			}
			if(av[i][j] == 'W')
			{
				if(sum < checkers(av, i, j, 0, 1))
				{
					fl = 1;
					startI = i;
					startJ = j;
					sum = checkers(av, i, j, 0, fl);
				}
			}
		}
	}
	checkers_print(av, startI, startJ, fl);
	return 0;
}

int main(int ac, char **av)
{
	av++;
	if(ac != 9 || !check_in(av)){
		write(1, "ERROR\n", 6);
		return 0;
	}
	che(av, 0, 0);
	return 0;
}