#include <stdio.h>
#include <time.h>

#include"extern.h"

void input(char *string,int length)
{
    int x=0;

    fgets(string,length,stdin);
    while(*string)
    {
        if(*string == '\n')
        {
            *string = '\0';
            return;
        }
        x++;
        if(x == length)
        {
            *string = '\0';
            return;
        }
        string++;
    }
}

void addPatient() {
	struct patient p;
	int pid;
	char c,yn;

add:	printf("ENTER PATIENT DETAILS\n");
	while ((c = getchar()) != '\n' && c != EOF) {};
		;
	printf("Enter name (max 99 characters): ");input(p.name,100);
	printf("Enter age: "); scanf("%d", &p.age);
	while ((c = getchar()) != '\n' && c != EOF) {}
		;
	printf("Enter sex: \nM for Male\nF for Female\nO for Others\n"); p.sex=getchar();
	printf("Enter height(in cm): "); scanf("%f", &p.height);
	printf("Enter weight(in kg): "); scanf("%f", &p.weight);
	printf("Enter blood group(max 9 characters): "); input(p.bgrp,10);
	while ((c = getchar()) != '\n' && c != EOF) {}
		;
	p.pid=100;
	// Insert time of patient file creation in the file
	time_t T=time(NULL);
   	struct tm tm=*localtime(&T);
   	p.date[0] = tm.tm_mday;
	p.date[1] = tm.tm_mon+1;
	p.date[2] = tm.tm_year+1900;
	printf("date: %i, %i, %i \n", p.date[0],p.date[1],p.date[2]);
//	int arr[3];
//   	arr[0]=tm.tm_mday;
//  	arr[1]=tm.tm_mon+1;
//   	arr[2]=tm.tm_year+1900;
//	printf("time: %i, %i, %i", arr[0],arr[1],arr[2]);
// 	fwrite(arr,sizeof(arr),1,p.fpat);
//	fclose(p.fpat);

	// Write file
	FILE *fptr= fopen("records.dat", "ab+");
	int seek =  fseek(fptr,-1*sizeof(p),SEEK_END);
//	printf("seek = %i & fptr = %d \n", seek,ftell(fptr));

	struct patient dummy;
	if(fread(&dummy,sizeof(p),1,fptr)!=0)
		p.pid=dummy.pid+1;
	printf("p.pid = %li\n", p.pid);

//	size_t x =
	fwrite(&p, sizeof(p), 1, fptr);
	fclose(fptr);
//	printf("x = %zu",x);

	//while ((c = getchar()) != '\n' && c != EOF) {}
		;
	printf("\nDo you want to add another patient record?(Y/N): ");
	scanf("%c", &yn);
	if(yn == 'Y' || yn == 'y') {
		goto add;
	}
	printf("\n");	
}
