#include <stdio.h>
#include <string.h>

#include "extern.h"
#include "lowerFunctions.h"
#include "print.h"

void bgrp1(FILE *fptr, char *bg);
void bgrp2(FILE *fptr, char *bg);

void bloodgroup() {
	char c, bg[10];
	while((c=getchar())!='\n' && c!=EOF)
		;
	printf("Enter blood group: ");
	scanf("%s", bg);
	printf("\n");

	FILE *fptr = fopen("records.dat","rb");

	if(bg[1]=='+' || bg[1]=='-') {
		bgrp1(fptr, bg);	
	} else {
		bgrp2(fptr, bg);
	}

	fclose(fptr);
}

void bgrp1(FILE *fptr, char *bg) {
	FILE *blood = fopen("bloodgroup.dat","wb+");
	struct patient p;
	int flag=0;

	int l = strlen(bg);
	char s_bgrp[l];
	strlower(s_bgrp,bg);

	while(fread(&p, sizeof(struct patient), 1, fptr)==1) {
		if(p.bgrp[1]=='+' || p.bgrp[1]=='-') {

			l = strlen(p.bgrp);
			char p_bgrp[l];
			strlower(p_bgrp,p.bgrp);

			if(strstr(p_bgrp, s_bgrp)) {
				fwrite(&p, sizeof(struct patient), 1, blood);
				flag=1;
			}
			
			if(flag==0) {
				printf("No records found.");
			} else {
				fseek(blood, 0, SEEK_SET);
				print(blood);
				fclose(blood);
			}
		}
	}
}

void bgrp2(FILE *fptr, char *bg) {
	FILE *blood = fopen("bloodgroup.dat","wb+");
	struct patient p;
	int flag=0;

	int l = strlen(bg);
	char s_bgrp[l];
	strlower(s_bgrp,bg);

	while(fread(&p, sizeof(struct patient), 1, fptr)==1) {
		if(p.bgrp[1]!='+' || p.bgrp[1]!='-') {

			l = strlen(p.bgrp);
			char p_bgrp[l];
			strlower(p_bgrp,p.bgrp);

			if(strstr(p_bgrp, s_bgrp)) {
				fwrite(&p, sizeof(struct patient), 1, blood);
				flag=1;
			}

		}
	}

	if(flag==0) {
		printf("No records found.");
	} else {
		fseek(blood, 0, SEEK_SET);
		print(blood);
		fclose(blood);
	}
}
