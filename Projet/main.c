
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
	char *p3=0;
	p3=argv[3];

	char *date_min=0;
	date_min=argv[1];
	char *date_max=0;
	date_max=argv[2];


	if(argv[3]!=NULL){
		if((strchr(argv[3],'z')!=NULL) && (strchr(argv[3],'1')!=NULL)){ //Si l'utilisateur a choisi un intervalle pour la date alors on exécute la fonction qui va filtrer le fichier
			printf("toto\n");
			date_filtrage(&date_min,&date_max);
		}
	}
	
	if(argv[2]!=NULL){
		if((strchr(argv[2],'z')!=NULL) && (strchr(argv[2],'2')!=NULL)){ //Si l'utilisateur a choisi un territoire alors on exécute la fonction qui va filtrer le fichier
			printf("titi\n");
			territoire_filtrage(&p1);
		}
	}	
	

	
	
	
	//redirection(&p1,&p2,&p3);
	
	

	return 0;
}
