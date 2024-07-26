#include <stdio.h>
#include <string.h>

#include "extern.h"
#include "lowerFunctions.h"
#include "print.h"

int diagnosis() {
	char c,di[100];
	while((c=getchar())!='\n' && c!=EOF)
		;
diag:	printf("Enter diagnosis: ");
	fgets(di,100,stdin)
		;
	FILE* fptr=fopen("records.dat","rb");
	FILE *diag = fopen("diagnosis.dat", "wb+");
	int l, i;
	int flag=0;
	l = strlen(di);
	struct patient p;
	char s_diag[l];
	strlower(di,s_diag)
		;
	while(fread(&p, sizeof(struct patient), 1, fptr)==1) {
		l = strlen(p.diag);
		char p_diag[l];
		strlower(p_diag,p.diag)
			;
		if(strstr(p_diag, s_diag)) {
			fwrite(&p, sizeof(struct patient), 1, diag);
			flag=1;
		}	
	}
	if(flag==0) {
		printf("No records found.\n");
		fclose(diag);
		fclose(fptr);
		goto diag;
	} else {
		fseek(diag,0,SEEK_SET);
		print(diag);
		fclose(diag);
		fclose(fptr);
		return 0;
	}
}
