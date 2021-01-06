/****************************
 *	
 * author: antogit-sys 
 * 
 * =-=-=-=-=-=-=-=-=-=-=_
 * argv[0] nameprogramma
 * argv[1] nome account
 * argv[2] num char passwd
 * argv[3] --opts
 * argv[4] num opts
 ****************************/
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "hpasswd.h"
#include "portability.h"

void intro(void);
int main(int argc,char **argv)
{
		
	char name[C];
	char *p=NULL;
	
	if(argc<5 || argc>5){
		intro();
	}else if(argc>1 && strop(argv[3],==,"--opts")){
		
		size_t lenght=atoi(argv[2]); //atoi() --> converto da stringa a numero	
		size_t opts=atoi(argv[4]); //converto da stringa a numero					
		
		if(lenght<6 || lenght>32){
			//controllo per buffer overflow
			puts("lunghezza password non compresa tra 6 e 32...");
			exit(EXIT_FAILURE);	
		}
		
		p=ANEW(char,lenght); //alloco array di tipo char
		assert(p!=NULL);	//controllo se l'allocazione è andata a buon fine
		
		/*fixed bug for windows*/
		size_t i=0;
		do{
			name[i]=(char)argv[1][i]; //salvo nome
		}while(argv[1][i++]!='\0');
		
		int verifica=rand_num(p,lenght,opts);
		if(verifica){
			puts("--opts [n] non valido");
		}else{
			//writing the file
			if(write_file("filePass.txt",name,p,lenght)){
				puts("errore nell'apertura del file...");
			
			}
			//output passwd
			fputs("password: ",stdout);
			for(size_t i=0;i<lenght;++i){
				fputc(p[i],stdout);	
			}
			fputs("\n",stdout);
		}
			
	}else{
		puts("parametro non riconosciuto");	
	}
	
return EXIT_SUCCESS;
}

void intro(void)
{	
	puts("+----------------------+");
	puts("|    passwdGenerator   |");
	puts("+----------------------+");
	puts("\nUSE:");
	puts(USE);
	puts("\nPARAMETERS:\n");
	puts("\t [name]\t\tnome account");
	puts("\t [nchar]\tnumero di caratteri della password");
	puts("\t --opts\t\tspecificare opzione [n]");
	puts("\t [n]\t\topzione (da 1 a 4 opzioni)");
	puts("\n\nNUMBER OPTIONS:");
	puts("\t --opts 1\tcaratteri completi"  );
	puts("\t --opts 2\tsolo lettere minuscole");
	puts("\t --opts 3\tsolo lettere MAIUSCOLE");
	puts("\t --opts 4\tsolo numeri(pin)");
	puts("\nUSE EXAMPLE:");
	puts(USEXAMPLE);	
}
