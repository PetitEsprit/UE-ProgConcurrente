#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *fsomme(void *arg)
{
	int i , somme=0 ;
	int n = atoi(( char *) arg) ;
	for (i=0 ;i <= n ;i ++) somme = somme + i ;
	printf ( " Somme = % d\n" , somme) ;
	pthread_exit(0) ;
}
void *fproduit(void *arg)
{
	int i , produit=1 ;
	int n = atoi (( char *) arg) ;
	for (i=1 ;i <= n ;i ++) produit = produit * i ;
	printf ( " Produit = %d\n" , produit) ;
	pthread_exit(0) ;
}

int main ( int argc , char * argv [])
{
	int i;
	pthread_t fils[2];
	void* (*op_tab[2])(void *) = {fsomme, fproduit};

	char *temp;
	temp = ( char *) malloc ( sizeof ( int ) + sizeof ( char));
	sprintf (temp, " %d ", 10) ;
	for (int i = 0; i < 2 ; i++)
	{
		if (pthread_create ( &fils[i], NULL , op_tab[i], (void*)temp))
			perror("pthread_create somme");
	}
	printf ( " Sortie du main \n") ;
	pthread_exit (0) ;
}