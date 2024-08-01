#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "addPatient.h"
#include "bgrp.h"
#include "delete.h"
#include "diagnosis.h"
#include "doctor.h"
#include "edit.h"
#include "log.h"
#include "print.h"
#include "search.h"

int main() {
	int option,id;
	char yn;
	char c,phi,l;
	int flag=0;

	system("clear");

	printf("\n\n\n\n\t\t\t\t\t*******************************\t\tWELCOME TO WE-CARE\t*******************************\n\n");
	sleep(1);

menu:	menu();
	printf("Enter option number: ");
	scanf("%d", &option);
	printf("\n");

	switch (option) {
		case 0 :
			system("clear");
			printf("\n\n\t\t\t\t*******************************\t\tThank you for using our services.\t*******************************\n\n\n");
			sleep(2);
			system("clear");
			exit(0);
			break;
		case 1 :
			FILE * fptr;
			fptr= fopen("records.dat", "rb");

			if(fptr==NULL) {
				printf("No records to be displayed\n");
			} else {
				print(fptr);
				fclose(fptr);
			}

			break;
		case 2 :
			addPatient();
			break;
		case 3 :
			search(fopen("records.dat","rb"));
			break;
		case 4 :
			edit();
			break;
		case 5 :
			if(delete()==0) { goto menu; }
			break;
		case 6 :
			bloodgroup();
			break;
		case 7 :
			doctor();
			break;
		case 8 :
			diagnosis();
			break;
		case 9 :
			openfile();
			break;
		default:
			printf("Enter valid option\n");
			while ((phi = getchar()) != '\n' && phi != EOF) {};
			goto menu;
	}
	return 0;
}
