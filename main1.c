#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"

int main(int argc , char *argv[])
{
	FILE *fic=NULL;
	execution(fic,argc,argv,argv[1],argv[2]);
	return 0;
}
