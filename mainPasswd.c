#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "librarypasswd.h"
#include "macrodefine.h"

int main(int argc,char **argv)
{
	char name[C];
	char *p=NULL;
	int lunghezza=0;
	int opts=0;
	
	//argv[0] nameprogramm
	//argv[1] name
	//argv[2] char pass
	//argv[3] --opts
	//argv[4] num opts
	
	if(argc<5 || strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--h")==0|| strcmp(argv[1],"help")==0||strcmp(argv[1],"-help")==0){ //se non ci sono argomenti o gli argomenti sono -h/--help stampa intro
		intro();
	}else if(argc>1 && strcmp(argv[3],"--opts")==0 ){
			
		opts=atoi(argv[4]); //converto da stringa a numero
		lunghezza=atoi(argv[2]); //atoi() --> converto da stringa a numero				
		if(lunghezza<6 || lunghezza>32){ //controllo per buffer overflow
			printf("\nnumero non compreso tra 6 e 32...\n");
			return 0;
		}
		
		p=(char*)alloc(lunghezza); //alloco array
		controlAlloc(p); //controllo se l'allocazione è andata a buon fine
		
		/*fixed bug for windows*/
		int i=0;
		do{
			name[i]=(char)argv[1][i]; //salvo nome
		}while(argv[1][i++]!='\0');
		
		int verifica=randNum(p,lunghezza,opts); //opts range[1;6] 
		if(verifica==-1){ //se verifica=-1 l'utente ha sbagliato numero opzione
			printf("\n--opts [n] non valido\n");
			return -1;	
		}else{
			fileW(name,p,lunghezza);
			printf("\npassword: ");
			
			/*stampo pass*/
			for(int i=0;i<lunghezza;i++){
				printf("%c",p[i]);	
			}
			printf("\n\n");
			
			free(p);
		}	
	}
return 0;
}
