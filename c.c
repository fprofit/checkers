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
int check_step_dama(char **av, int i, int j, int sum)
{
	printf("1 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
		if(i <= 5 && j <= 5 && av[i+2][j+2] == '.' &&
			(av[i+1][j+1] == 'b' || av[i+1][+1] == 'B') &&
			(av[i+3][j+3] == 'b' || av[i+3][j+3] == 'B' ||
			av[i+3][j+1] == 'b' || av[i+3][j+1] == 'B' ||
			av[i+1][j+3] == 'b' || av[i+1][j+3] == 'B'))
			{
				av[i+1][j+1] = '.';
				printf("2 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
				sum = check_step_dama(av, i+2, j+2, sum+1);
			}
		else if(i >= 2 && j <= 5 && av[i-2][j+2] == '.' &&
			(av[i-1][j+1] == 'b' || av[i-1][+1] == 'B') &&
			(av[i-3][j+3] == 'b' || av[i-3][j+3] == 'B' || 
			av[i-3][j+1] == 'b' || av[i-3][j+1] == 'B' ||
			av[i-1][j+3] == 'b' || av[i-1][j+3] == 'B'))
			{
				av[i-1][j+1] = '.';
				printf("3 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
				sum = check_step_dama(av, i-2, j+2, sum+1);
			}
		else if(i <= 5 && j >=2 && av[i+2][j-2] == '.' &&
			(av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B') &&
			(av[i+3][j-1] == 'b' || av[i+3][j-1] == 'B' || 
			av[i+3][j-3] == 'b' || av[i+3][j-3] == 'B' ||
			av[i+1][j-3] == 'b' || av[i+1][j-3] == 'B'))
			{
				av[i+1][j-1] = '.';
				printf("4 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
				sum = check_step_dama(av, i+2, j-2, sum+1);
			}
		else if(i >= 2 && j >=2 && av[i-2][j-2] == '.' &&
			(av[i-1][j-1] == 'b' || av[i-1][j-1] == 'B') &&
			(av[i-3][j-1] == 'b' || av[i-3][j-1] == 'B' || 
			av[i-3][j-3] == 'b' || av[i-3][j-3] == 'B' ||
			av[i-1][j-3] == 'b' || av[i-1][j-3] == 'B'))
			{
				av[i-1][j-1] = '.';
				printf("5 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
				sum = check_step_dama(av, i-2, j-2, sum+1);
			}
		else if(i <=5 && j <= 5 && (av[i+1][j+1] == 'b' || av[i+1][j+1] == 'B') && av[i+2][j+2] == '.')
		{	av[i+1][j+1] = '.';
			printf("6 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
			sum = check_step_dama(av, i+2, j+2, sum+1);
		}
		else if(i >= 2 && j <= 5 && (av[i-1][j+1] == 'b' || av[i-1][j+1] == 'B') && av[i-2][j+2] == '.')
		{
			av[i-1][j+1] = '.';
			printf("7 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
			sum = check_step_dama(av, i-2, j+2, sum+1);
		}
		else if(i <= 5 && j >=2 && (av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B') && av[i+2][j-2] == '.')
		{
			av[i+1][j-1] = '.';
			printf("8 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
			sum = check_step_dama(av, i+2, j-2, sum+1);
		}
		else if(i <= 2 && j >=2 && (av[i-1][j-1] == 'b' || av[i-1][j-1] == 'B') && av[i-2][j-2] == '.')
		{
			av[i-1][j-1] = '.';
			printf("9 res i: %d res j: %d char: %c\n", i, j, av[i][j]);
			sum = check_step_dama(av, i-2, j-2, sum+1);
		}
		else
			return(sum);
		return(sum);
	}
int check_step(char **av, int i, int j, int sum)
{
	
	if(i < 6){
		if(j <= 5 && (av[i+1][j+1] == 'b' || av[i+1][+1] == 'B') && av[i+2][j+2] == '.' &&
			(av[i+3][j+3] == 'b' || av[i+3][j+3] == 'B' || av[i+3][j+1] == 'b' || av[i+3][j+1] == 'B'))
			sum = check_step(av, i+2, j+2, sum+1);
		else if(j >=2 && (av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B') && av[i+2][j-2] == '.' &&
			(av[i+3][j-1] == 'b' || av[i+3][j-1] == 'B' || av[i+3][j-3] == 'b' || av[i+3][j-3] == 'B'))
			sum = check_step(av, i+2, j-2, sum+1);
		else if(j <= 5 && (av[i+1][j+1] == 'b' || av[i+1][j+1] == 'B') && av[i+2][j+2] == '.')
			sum = check_step(av, i+2, j+2, sum+1);
		else if(j >=2 && (av[i+1][j-1] == 'b' || av[i+1][j-1] == 'B') && av[i+2][j-2] == '.')
			sum = check_step(av, i+2, j-2, sum+1);
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
				temp = check_step(av, i, j, 0);
				if(sum < temp)
				{
					startI = i;
					startJ = j;
					sum = temp;
				}
			}
			if(av[i][j] == 'W')
			{
				temp = check_step_dama(av, i, j, 0);
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