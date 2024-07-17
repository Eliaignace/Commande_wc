#ifndef WC_H
#define WC_H
FILE* open(char *fichier);
int caractere(FILE *fic);
int mot(FILE *fic,char *fichier);
int octet(FILE *fic);
int ligne(FILE *fic);
int longue_ligne(FILE *fic);
void option(FILE *fic,char *fichier,char *opt);
void without_option(FILE *fic,char *fichier,int argc);
void execution(FILE *fic,int argc,char *argv[],char *opt,char *fichier);
#endif
