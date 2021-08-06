//showf.c - echoes file arguments onscreen sequentially
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define BUF 1024

int main(int argc, const char *argv[])
{
	int i;
	FILE *in[argc];
	char buffer[BUF];
	//BEGIN error checking block for command line call
	for(i=1; i < argc; i++){
		in[i]=fopen(argv[i],"r");
		if(isalnum(*argv[i] == 0)){
			fputs("filenames must be alphanumeric characters.\n",stderr);
			exit(1);
		}
		if(in[i] == NULL){
			fprintf(stderr,"unable to open file %s\n",argv[i]);
			exit(2);
		}
	}
	//END error checking

	for(i=1; i < argc; i++){
		setvbuf(in[i],buffer,_IOFBF,BUF);
		while(1){
		if(feof(in[i]))
			break;
		fread(buffer,sizeof(char),1,in[i]);
		fwrite(buffer,sizeof(char),1,stdout);
		}
	}

return 0;
}
