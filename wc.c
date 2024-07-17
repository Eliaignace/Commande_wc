#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"

FILE* open(char *fichier)
{ 
	FILE *fic=NULL;
	fic=fopen(fichier , "r");
	if(fic==NULL)
	{
		printf("probleme d'ouverture");
		exit(1);
	}
	return fic;
}
int caractere(FILE *fic)
{   
	int c = 0;
	int parametre;
	
	rewind(fic);
	 while((parametre=fgetc(fic))!=EOF)
	{
		c++;
	}
	return c;
}
int mot(FILE *fic,char *fichier)
{	
	int m = 0; 
	char mot[100];
	rewind(fic);
	while(feof(fic)!=1)
	{
		fscanf(fic, "%s" , mot);
		m++;
	}
	return m-1;
}
int octet(FILE *fic)
{   
	
	int o = 0;
	int parametre;
	
	rewind(fic);
	 while((parametre=fgetc(fic))!=EOF)
	{
		o++;
	}
	return o;
}
int ligne(FILE *fic)
{	
	int l = 0;
	char chaine[100];
	//char mot;
	rewind(fic);
	while(feof(fic)!=1)
	{
		fgets(chaine,100,fic);
		l++;
	}

	return l-1;
}	
int longue_ligne(FILE *fic)
{	
	int i = 0;
	int max = 0;
	//int ll = 0;
	char t;
	rewind(fic);
	while((t=fgetc(fic))!=EOF)
	{
		if(t!='\n')
		{
			i++;
		}
		else{
			if(max<i)
			{
				max=i;
			}	
			i=0;
		}
	}
	
	return max;
}

void option(FILE *fic,char *fichier,char *opt)
{	
	int m,c,o,l,L;
	if(strcmp(opt,"-w")==0)
	{
		m=mot(fic,fichier);
		printf("%d %s\n" , m, fichier);
	}
	else if(strcmp(opt,"-m")==0)
	{
		c=caractere(fic);
		printf("%d %s\n" ,c,fichier);
		
	}
	else if(strcmp(opt,"-c")==0)
	{
		o=octet(fic);
		printf("%d %s\n" ,o,fichier);
	}
	else if(strcmp(opt,"-l")==0)
	{
		l=ligne(fic);
		printf("%d %s\n" ,l,fichier);
	}
	else if(strcmp(opt,"-L")==0)
	{
		L=longue_ligne(fic);
		printf("%d %s\n",L,fichier);
	}
	
}
void without_option(FILE *fic,char *fichier,int argc)
{
	int m,o,l;
	if (argc == 2)
	{
	m=mot(fic,fichier);
	//c=caractere(fic);
	o=octet(fic);
	l=ligne(fic);
	printf(" %d %d %d %s\n" , l,m,o,fichier);
	}
}
void execution(FILE *fic,int argc,char *argv[],char *opt,char *fichier)
{	int i=0;
	if(argv[1][0]=='-')
	{
		for(i=1;i<argc-1;i++)
		{
			fic=open(argv[i+1]);
			option(fic,argv[i+1],argv[1]);
		}
	}
	else
	{
		for(i=1;i<argc;i++)
		{
			fic=open(argv[i]);
			without_option(fic,argv[i],argc);
		}
	}
	fclose(fic);
	
	
}

	
