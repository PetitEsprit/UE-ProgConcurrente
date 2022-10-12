#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *ask_number(void *ptr)
{
	void	*n;

	printf("Entrez un nombre: \n");
	scanf("%d", &n);
	printf("Le nombre entré est: %d.\n", n);
	pthread_exit(n);
}

void *inc_10_fois(void *arg)
{
	int	n;

	n = (int)arg;
	for (int i=0 ; i < 10 ; i++)
	{
		++n;
		printf("Resultat = %d\n", n) ;
	}
	pthread_exit(0) ;
}

int main( int argc , char * argv [])
{
	int i;
	pthread_t th1, th2;

	pthread_create(&th1, NULL, ask_number, NULL);
	pthread_join(th1, &i);
	pthread_create(&th2, NULL, inc_10_fois, i);
	pthread_join(th2, NULL);
}