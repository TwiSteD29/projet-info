#include"redirection.h"


int  redirection( char *p1[], char *p2[]){

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

	else if((strchr(*p1,'4') !=NULL)){ //altitude
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
