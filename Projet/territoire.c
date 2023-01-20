#include"territoire.h"


int territoire(char *Xmax[],char *Xmin[],char *Ymin[], char *Ymax[],char *Xmax2[],char *Xmin2[],char *Ymin2[],char *Ymax2[]){
	
	char line[1024];
	char saveline[1024];
	char saveline2[1024];
	char *X, *Y;
        FILE *file = fopen("tmp1", "r");
        FILE *newFile = fopen("filtered", "w");
	rewind(newFile);
	if (file==NULL){
		printf("Erreur lors de l'ouverture d'un fichier");
		return 2;
	}
	 // Lire chaque ligne du fichier
	while (fgets(line, 1024, file)){
       		memset(saveline,0,1024);
		memcpy(saveline,line,1024);
		memset(saveline2,0,1024);
		memcpy(saveline2,line,1024);
		if (line != NULL) {
			X = strtok(line, ";");
			for(int i=1;i<8;i++){
				X = strtok(NULL, ";,");
			}
		
		}
		if(saveline != NULL){
			Y = strtok(saveline, ";");
			for(int i=1;i<9;i++){
				Y = strtok(NULL, ";,");
			}
			
		} 
		//printf("%s %s %s %s\n",*Xmax,*Xmin,*Ymax,*Ymin);
		//printf("%s %s\n", X,Y);
		//printf("%s\n",saveline2);
		if(X > *Xmin && X < *Xmax && Y > *Ymin && Y < *Ymax){
			fputs(saveline2,newFile);
		}
		exit(1);
    	}
		
	
	fclose(file);		
	fclose(newFile);
	//remove("tmp1");
	//rename("filtered","tmp1");
	return 0;
}


/*int territoire(float Xmax, float Xmin, float Ymin, float Ymax,float Xmax2,float Xmin2,float Ymin2,float Ymax2){
	printf("%f %f %f %f\n",Xmax,Xmin,Ymax,Ymin);
	Variables var;
	int carActuel = EOF+1;
	FILE *fichierATrier = fopen ("tmp1","r");
	FILE *tmp = fopen("filtered","a");
	rewind(fichierATrier);
	if (fichierATrier==NULL){
		printf("Erreur lors de l'ouverture d'un fichier");
		return 2;
	}
	while(carActuel != EOF){
		carActuel = fgetc(fichierATrier);
		fscanf(fichierATrier,"%d;%f,%f;%f;%f;%f \n",&var.station,&var.X,&var.Y,&var.temperature,&var.temp_min,&var.temp_max);
		if((Xmin<var.X && var.X<Xmax &&  Ymin<var.Y && var.Y<Ymax) || (Xmin2<var.X && var.X<Xmax2 &&  Ymin2<var.Y && var.Y<Ymax2)){
			fprintf(tmp,"%d;%f,%f;%f;%f;%f \n",var.station,var.X,var.Y,var.temperature,var.temp_min,var.temp_max);
		}
	}
	fclose(fichierATrier);		
	fclose(tmp);
	remove("tmp1");
	rename("filtered","tmp1");
}*/


