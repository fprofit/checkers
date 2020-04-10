#include <stdio.h>
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
	if(arg < 2 && (av[i+1][j+1] == 'b' || av[i+1][j+1] == 'B' || av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B'))
		return(1);
	
	return(0);
}
int checkers(char **av, int i, int j, int sum, int fl)
{
	
	if(i <= 5)
	{
		if(fl < 2 && i <= 4 && j <= 5 && (av[i+1][j+1] == 'b' || av[i+1][+1] == 'B') && av[i+2][j+2] == '.' &&
				check_step(av, i+2, j+2, fl))
			return(sum = checkers(av, i+2, j+2, sum+1, fl));
		else if(fl <2 && i <= 4 && j >=2 && (av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B') && av[i+2][j-2] == '.' &&
				check_step(av, i+2, j+2, fl))			
			return(sum = checkers(av, i+2, j-2, sum+1, fl));
		else if(i <= 5 && j <= 5 && (av[i+1][j+1] == 'b' || av[i+1][j+1] == 'B') && av[i+2][j+2] == '.')
			return(sum = checkers(av, i+2, j+2, sum+1, fl));
		else if(i <= 5 && j >=2 && (av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B') && av[i+2][j-2] == '.')
			return(sum = checkers(av, i+2, j-2, sum+1, fl));
		return(sum);
	}
	return(sum);
}

int che(char **av, int i, int j)
{
	int startI;
	int startJ;
	int sum;
	int temp;
	sum = -1;
	for(; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(av[i][j] == 'w')
			{
				temp = checkers(av, i, j, 0, 1);
				if(sum < temp)
				{
					startI = i;
					startJ = j;
					sum = temp;
				}
			}
			if(av[i][j] == 'W')
			{
				temp =checkers(av, i, j, 0, 0);
				if(sum < temp)
				{
					startI = i;
					startJ = j;
					sum = temp;
				}
			}
		}
	}
	printf("OK res i: %d res j: %d sum: %d char: %c\n", startI, startJ, sum,  av[startI][startJ]);
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

	printf("Ok\n");
	return 0;
}