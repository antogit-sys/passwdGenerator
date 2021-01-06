#include <time.h>
#include "macrodefine.h"

int rand_num(char* p,size_t lenght,size_t opts)
{	
	int done;
	
	if(opts>4 || opts<=0){
		done=-1; 
	}else{
		int c1,c2;
		switch(opts){
			case 1:	c1=94; /*tutti i char*/
					c2=33;
					break;
			
			case 2: c1=26; /*solo lettere minuscole*/
					c2=97;
					break;
	
			case 3:	c1=26; /*solo lettere maiuscole*/
					c2=65;
					break;
				
			case 4:	c1=10; /*solo numeri*/
					c2=48;
					break;
		}
		srand(time(NULL));
		for(size_t i=0;i<lenght;++i){
			p[i]=rand()%c1+c2; 
		}
		done=0;
	}

return done;	
}

int write_file(const char* namefile,char nameaccount[],char *p,size_t l)
{
	int done=0;
	
	if(strlen(namefile)<=0){
		done=-1;
	}else{
		FILE *fp; //creo un puntatore di tipo FILE
		fp=fopen(namefile,"a"); 
		if(fp){
			//scrivi "{name}: {password}\n"
			fprintf(fp,"%s: ",nameaccount);
			for(size_t i=0;i<l;++i){ //fixed bug for windows
				fprintf(fp,"%c",p[i]);	
			}
			fputs("\n",fp);
		}else{
			done=-1;
		}
		fclose(fp); //chiudo il file
	}
return done;
}
