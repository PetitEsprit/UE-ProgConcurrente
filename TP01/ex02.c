#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(void *arg)
{
	int	n;

	printf("Nous sommes dans le thread.\nEntrez un nombre: \n");
	scanf("%d", &n);
	++n;
	printf("Le nombre entré + 1 est: %d.\n", n);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t thread1;

	printf("Avant la création du thread.\n");
	if (pthread_create(&thread1, NULL, thread_1, NULL))
	{
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	if (pthread_join(thread1, NULL)) 
	{
		perror("pthread_join");
		return EXIT_FAILURE;
	}
	printf("Après la création du thread.\n");
	return EXIT_SUCCESS;
}