#include <stdio.h>

int main(int argc, char *argv[])
{
	long long int N, B;

	scanf("%lld %lld", &N, &B);

	long long int ini = 0, fim = N / 2, meio, X = 0;

	while (ini <= fim)
	{
		meio = (ini + fim) / 2;
		if (4 * meio * (N - meio) < B)
		{
			X = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	long long int resto_feijoes = B - 4 * X * (N - X);
	long long int casca = X + 1;
	long long int lim = N + (casca - 1) * (-2);
	long long int coordX = casca, coordY = casca;
	long long int resto;

	
	if(resto_feijoes >= lim)
	{
		resto_feijoes -= lim;
		coordY += (lim - 1);
	}
	else
	{
		resto = resto_feijoes % lim;
		coordY += (resto - 1);
		resto_feijoes -= resto;
	}
	
	if(resto_feijoes > 0)
	{
		if(resto_feijoes >= lim - 1)
		{
			resto_feijoes -= (lim - 1);
			coordX += (lim - 1);
		}
		else
		{
			resto = resto_feijoes % (lim - 1);
			coordX += resto;
			resto_feijoes -= resto;
		}

		if(resto_feijoes > 0)
		{
			if(resto_feijoes >= lim - 1)
			{
				resto_feijoes -= (lim - 1);
				coordY -= (lim - 1);
			}
			else
			{
				resto = resto_feijoes % (lim - 1);
				coordY -= resto;
				resto_feijoes -= resto;
			}
					
			if(resto_feijoes > 0)
				coordX -= resto_feijoes;
		}
	}

	printf("%lld %lld\n", coordX, coordY);

	return 0;
}
