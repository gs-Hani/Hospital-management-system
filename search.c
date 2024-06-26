#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "display.h"
#include "extern.h"
#include "printname_pid.h"

void name_pid(struct patient p);
void strlower(char* p,char* c);

void search(FILE *fptr) {
	FILE *fnew,fdum;
	char ch;
	struct patient pat;
	char s[100];
	char c[100];
	int flag = 0;

a:	fnew = fopen("search.dat","wb+");

	printf("\nBy which field would you like to search?");
	printf("\n1)Name");
	printf("\n2)Patient ID");
	printf("\n3)Doctor consulted");
	printf("\n4)Status\nPlease enter your choice: ");

    	int inp;
    	scanf("%d",&inp);

	switch(inp) {
		case 1:
			flag = 0;
			fseek(fptr,0,SEEK_SET);

			printf("\nEnter the name of the patient: ");
            		scanf("%s",s);
            		strlower(s,s);

			while(fread(&pat,sizeof(pat),1,fptr)) {
				strlower(pat.name,c);
				if(strstr(c,s)) {
					fwrite(&pat,sizeof(pat),1,fnew);
					flag=1;
				}
			}

			if(flag == 0) {
				printf("No records found. \n\n");
				break;
			}

			fseek(fnew,0,SEEK_SET);
            		printname_pid(fnew);
            		goto case2;
			
			break;

		case 2:
case2:			fseek(fptr,0,SEEK_SET);

			printf("\nEnter the Patient Id: ");
			int num;
            		scanf("%d",&num);

			while(fread(&pat,sizeof(pat),1,fptr))
            		{
                		if(pat.pid==num) {	
                    			display(pat);
                    			goto d;
                		}
            		}
            		printf("No records found.");
            		goto case2;
d:     			break;

		case 3:
			fseek(fptr,0,SEEK_SET);
            		flag=0
				;
            		while((ch=getchar())!='\n' && ch!= EOF)
				;
            		printf("\nEnter the name of the doctor : ");
            		fgets(s,100,stdin);
            		strlower(s,s)
				;
            		while(fread(&pat,sizeof(pat),1,fptr)) {
                		strlower(pat.doc,c)
					;
                		if(strstr(c,s)) {
                    			fwrite(&pat,sizeof(pat),1,fnew);
                    			flag=1;
                		}
            		}

            		if(flag==0) {
            			printf("No records found.\n\n");
            			break;
            		}

            		fseek(fnew,0,SEEK_SET);
            		printname_pid(fnew);
            		goto case2;

		case 4:
			break;
		default:
			printf("\nPlease enter a valid option");
            		goto a;
            		break;
	}
}

void strlower(char* p,char* c) {
    	for(int i=0; i<strlen(p); i++) {
        	c[i]=tolower(p[i]);
    	}
}
