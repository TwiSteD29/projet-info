#include"fonctions_tri_ABR.h"

int mode1ABR(){
	Variables var;
	FILE *fichierATrier;
	fichierATrier = fopen ("temp1","r");
	rewind(fichierATrier);
	if (fichierATrier==NULL){
		printf("Erreur lors de l'ouverture d'un fichier");
		return 2;
	}
	Variables* tab=NULL;
	int y=0;
	int i=0;
	float res=0;
	
	while(i<3){
		fscanf(fichierATrier,"%d",&var.station);
		tab=malloc(var.station*sizeof(Variables));
		printf("%d ", var.station);
		fseek(fichierATrier, 1, SEEK_CUR);
		fscanf(fichierATrier,"%f",&var.temperature);
		tab=malloc(var.temperature*sizeof(Variables));
		printf("%f\n",var.temperature);	
		res=res+var.temperature;
		i++;y++;
	}
	

	res=res/y;
	printf("%f\n",res);
			
		
		
	
	

	



	/*FILE* fichierRetour;
	fichierRetour = fopen ("mode1_trie","w+");*/
	


	fclose(fichierATrier);
	//fclose(fichierRetour);
}


