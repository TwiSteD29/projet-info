#include"redirection.h"


int date_filtrage(char *date_min[],char *date_max[]){
	printf("%s %s\n", *date_min, *date_max);
	char line[1024];
	char saveline[1024];
        char *date;

        FILE *file = fopen("tmp1", "r");
        FILE *newFile = fopen("filtered", "w");
	rewind(newFile);
	if(file==NULL){
		printf("Erreur lors de l'ouverture d'un fichier");
		return 2;
	}
    // Lire chaque ligne du fichier
        while(fgets(line, 1024, file)){
		memset(saveline,0,1024);
		memcpy(saveline,line,1024);
		if (line != NULL) {
			date = strstr(line, ";");
			sscanf(date + 1 ,"%[^;]s", date);
		}
  
		if(strcmp(date,*date_min) > 0 && strcmp(*date_max,date) > 0){
			fputs(saveline,newFile);
		}
    	}
    	fclose(file);
    	fclose(newFile);
	remove("tmp1");
	rename("filtered","tmp1");
    	return 0;
}

int territoire_filtrage(char *p1[]){

		if(strchr(*p1,'5')!=NULL){ 
			printf("Territoire : France\n");
			char *Xmax="52.0";
			char *Xmin="41.0";
			char *Ymin="-6.0";
	    		char *Ymax="10.0";
			
			char *Xmax2="1000";
			char *Xmin2="1000";
			char *Ymin2="1000";
	    		char *Ymax2="1000";
			territoire(&Xmax,&Xmin,&Ymin,&Ymax,&Xmax2,&Xmin2,&Ymin2,&Ymax2);
		}
		else if(strchr(*p1,'6')!=NULL){ 
			printf("Territoire : Guyane\n");
			char *Xmax="9.28";
			char *Xmin="-0.23";
			char *Ymin="-62.70";
	    		char *Ymax="-50.30";
		
			char *Xmax2="1000";
			char *Xmin2="1000";
			char *Ymin2="1000";
	    		char *Ymax2="1000";
			territoire(&Xmax,&Xmin,&Ymin,&Ymax,&Xmax2,&Xmin2,&Ymin2,&Ymax2);
		}	
		else if(strchr(*p1,'7')!=NULL){ 
			printf("Territoire : SaintPierre\n");
			char *Xmax="47.17";
			char *Xmin="46.70";
			char *Ymin="-56.50";
	    		char *Ymax="-56";
		
			char *Xmax2="1000";
			char *Xmin2="1000";
			char *Ymin2="1000";
	    		char *Ymax2="1000";
			territoire(&Xmax,&Xmin,&Ymin,&Ymax,&Xmax2,&Xmin2,&Ymin2,&Ymax2);
		}	
		else if(strchr(*p1,'8')!=NULL){ 
			printf("Territoire : Antilles\n");
			char *Xmax="-2.55";
			char *Xmin="-26.82";
			char *Ymin="41.44";
	    		char *Ymax="63.44";

			char *Xmax2="21.05";
			char *Xmin2="11.60";
			char *Ymin2="-75.32";
	    		char *Ymax2="-58.31";
			territoire(&Xmax,&Xmin,&Ymin,&Ymax,&Xmax2,&Xmin2,&Ymin2,&Ymax2);
		}	
		else if(strchr(*p1,'9')!=NULL){ 
			printf("Territoire : Ocean\n");
			char *Xmax="-28.26";
			char *Xmin="-61.59";
			char *Ymin="26.10";
	    		char *Ymax="106.48";
			
			char *Xmax2="1000";
			char *Xmin2="1000";
			char *Ymin2="1000";
	    		char *Ymax2="1000";
			territoire(&Xmax,&Xmin,&Ymin,&Ymax,&Xmax2,&Xmin2,&Ymin2,&Ymax2);
		}	
		else if(strchr(*p1,'0')!=NULL){ 
			printf("Territoire : Antarctique\n");
			char *Xmax="-62.70";
			char *Xmin="-82.80";
			char *Ymin="73.20";
	    		char *Ymax="163";

			char *Xmax2="1000";
			char *Xmin2="1000";
			char *Ymin2="1000";
	    		char *Ymax2="1000";
			territoire(&Xmax,&Xmin,&Ymin,&Ymax,&Xmax2,&Xmin2,&Ymin2,&Ymax2);
		}	
		
}



int  redirection( char *p1[], char *p2[],char *p3[]){
	
	if((strchr(*p1,'t') !=NULL) && (strchr(*p1,'1') !=NULL)){ //temp1
		printf("TEST\n");
	

		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
			mode1ABR();
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	}
	
	else if((strchr(*p1,'t') !=NULL) && (strchr(*p1,'2') !=NULL)){ //temp2
		printf("TEST5\n");
		
		
		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'t') !=NULL) && (strchr(*p1,'3') !=NULL)){ //temp3
		printf("TEST6\n");

		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'r') !=NULL) && (strchr(*p1,'1') !=NULL)){ //pression1
		printf("TEST7\n");
	
		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'r') !=NULL) && (strchr(*p1,'2') !=NULL)){ //pression2
		printf("TEST8\n");

		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'r') !=NULL) && (strchr(*p1,'3') !=NULL)){ //pression3
		printf("TEST9\n");

		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'v') !=NULL)){ //vent
		printf("TEST10\n");
	
		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'h') !=NULL)){ //humidite
		printf("TEST11\n");
	
		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 

	else if((strchr(*p1,'l') !=NULL)){ //altitude
		printf("TEST12\n");
	
		if(*p2==NULL){
		//On appelle fonction de tri par avl (tri par défaut)
			printf("TEST1\n");
		}
		else if((strchr(*p2,'t') !=NULL) && (strchr(*p2,'b') !=NULL)){
		//On appelle fonction de tri par tab
			printf("TEST2\n");
		}
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'r') !=NULL)){
		//On appelle fonction de tri par abr
			printf("TEST3\n");
		} 
		else if((strchr(*p2,'a') !=NULL) && (strchr(*p2,'l') !=NULL)){
		//On appelle fonction de tri par avl
			printf("TEST4\n");
		} 
	} 
	return 0;
}
