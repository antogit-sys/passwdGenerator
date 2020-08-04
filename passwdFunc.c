#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void intro()
{	
	printf("+----------------------+\n");
	printf("|    passwdGenerator   |\n");
	printf("+----------------------+\n");
	printf("\nUSE:\n\n");
	printf("\t./passwdGenerator [name] [nchar] --opts [n]\n");
	printf("\nNUMBER OPTIONS:\n\n");
	printf("\t --opts 1\tcaratteri completi\n"  );
	printf("\t --opts 2\tsolo lettere minuscole\n");
	printf("\t --opts 3\tsolo lettere MAIUSCOLE\n");
	printf("\t --opts 4\tsolo numeri(pin)\n");
	printf("\nUSE EXAMPLE:\n\n");
	printf("\t./passwdGenerator instagram 32 --opts 1\n");
	
}
char *alloc(int lung)
{
	char *p=NULL; 
	return p=(char*)malloc(lung*sizeof(char));
}
int randNum(char p[],int lung,int opts)
{	
	int c1=0;
	int c2=0;
	if(opts==1){
		//tutte
		c1=94;
		c2=33;
	}else if(opts==2){
		c1=26;//lettere minuscole
		c2=97;
	}else if(opts==3){
		c1=26;	//lettere MAIUSCOLE
		c2=65;
	}else if(opts==4){
		c1=10;	//numeri
		c2=48;
	}else if(opts>4 || opts<=0){
		return -1; //ritorno -1 se opts è maggiore di 4 o minore/uguale a 0
	}
	
	
	srand(time(NULL));
	for(int i=0;i<lung;i++){
			p[i]=rand()%c1+c2; //da 33 a 126
	}
return 0;	
}
void fileW(char name[],char p[],int l)
{
	FILE *fp; //creo un puntatore di tipo FILE

	fp=fopen("filePass.txt","a"); //mod. append
	if(fp){ //se il file è stato aperto,allora...
		fprintf(fp,"%s: %s\n",name,p); //scrivi "{name}: {password}\n"
	}else{
		printf("\nerrore sull'apertura del file...");	
	}
	fclose(fp); //chiudo il file
}
