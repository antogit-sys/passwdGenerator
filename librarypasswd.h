/* MACRO */
#define controlAlloc(x) if(x==NULL){printf("\nallocazione fallita...");return 0;}
#define C 100

/* PROTOTIPI DI FUNZIONI */
void intro(); //help command
char *alloc(int); //allocazione array char
int randNum(char[],int,int); //casual generated
void fileW(char[],char[],int); //memorizza sul file: nome e password