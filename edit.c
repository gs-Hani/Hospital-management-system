#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include"extern.h"

void edit() {
	FILE* fptr;
	int id;

	fptr=fopen("records.dat","rb");

	printf("Enter patient ID: ");
	scanf("%d", &id);

	struct patient pat,ptr;

	while(fread(&ptr,sizeof(ptr),1,fptr)) {
		if(ptr.pid==id) {
			break;
		}	
	}

	char ch,c;

	while((ch=getchar())!='\n' && ch!= EOF)
		;
	printf("Would you like to record the date?(Y/N): ");
	scanf("%c",&c);
	if(c=='Y'||c=='y') {	
		time_t T=time(NULL);
		struct tm tm=*localtime(&T);
		ptr.date[0] = tm.tm_mday;
		ptr.date[1] = tm.tm_mon+1;
		ptr.date[2] = tm.tm_year+1900;
	}

	int op;
	char dummy[100];
	char dummy1[100];
	char dummy0[100];

	do {
		printf("\nWhich field of the patient do you want to edit?\n");
		printf("1.Name\n2.Age\n3.Sex\n4.Doctor\n5.Diagnosis\n6.Height\n7.Weight\n8.BloodGroup\n9.Patient's Status\n10.Bill\n11.Amount Deposited\n");
		scanf("%d",&op);
		while((ch=getchar())!='\n' && ch!= EOF)
			;
		switch(op) {
			case 1:
				strcpy(dummy0,ptr.name);
				printf("Enter the updated name:");
				fgets(ptr.name, 100, stdin);
				rename(dummy0,ptr.name);

				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			default:
				printf("Invalid choice...Try Again!!!");
				break;
		}

		while((ch=getchar())!='\n' && ch!= EOF);
		printf("Do you want to continue editing more information of the Patient? (Y/N): ");
		scanf("%c",&ch);

	} while(ch=='y' || ch=='Y');

	if(ch=='n' || ch=='N') {
		printf("Information of the patient has been updated successfully!!");
	}

}
