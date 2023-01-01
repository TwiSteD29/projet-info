#include"fonctions_tri_TAB.h"
#include"fonctions_tri_ABR.h"
#include"fonctions_tri_AVL.h"
#include"redirection.h"


// La fonction main a deux paramètres : argc de type int et argv de type char * []. argc donne le nombre d'éléments de la ligne de commande, et argv contient ces éléments sous la forme d'un tableau de chaînes de caractères. argv[0] contient le nom de la commande, argv[i], pour i allant de 1 à argc-1, le ième argument.


int main(int argc, char* argv[]){ 

	printf("Nombre d'argument : %d\n", argc);

	printf("Fichier exécuté : %s\n", argv[0]); 
	printf("fichier des données filtrées : %s\n", argv[1]); 
	printf("Mode de tri : %s\n", argv[2]); 
	
	if(argc<2){ // inferieur à 2 car si pas de methode de tri selectionnée alors AVL par défaut.
		printf("ERREUR\n");
		exit(1);
	}
	char *p1=0;
	p1=argv[1];
	char *p2=0;
	p2=argv[2];

	redirection(&p1,&p2);
	
	

	return 0;
}
