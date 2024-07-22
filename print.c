#include <stdio.h>
#include <string.h>

#include "extern.h"

void date(struct patient p) {
	//int date[3];
	//while(fread(date, sizeof(date), 1, fptr)==1) {
		printf("   %2d-%2d-%4d\n",p.date[0], p.date[1], p.date[2]);
	//}

}

void menu()
{
	printf("\nMain menu:\n");
	printf("1. Display patient records\n");
	printf("2. Add patient record\n");
	printf("3. Search a patient's records in the database\n");  
	printf("4. Edit patient records\n");
	printf("5. Delete patient records\n");
	printf("6. Display patients of a particular blood group\n");
	printf("7. Display patients treated by a particular doctor\n");
	printf("8. Display patients of a particular diagnosis\n");
	printf("9. Display patients who visited on a particular day\n");
	printf("0. Quit the program\n");
}

void print(FILE *fptr) {
	struct patient p;
	char c;
	printf("Patient ID\tName\t\t\tAge  Sex   Height\tWeight\tBlood Group \tStatus\t\tBill\t\t\tAmt. Deposited\t\tAmt. Due\n");

	while(fread(&p, sizeof(p), 1, fptr)==1) {
		printf("%.0ld\t\t", p.pid);
		if(strlen(p.name)<8) {
			printf("%s\t\t\t", p.name);
		} else if (strlen(p.name)<16) {
			printf("%s\t\t", p.name);
		} else {
			printf("%s\t", p.name);
		}
		
		if(p.age>10) {
			printf(" %d ", p.age);
		} else {
			printf("  %d ", p.age); 
		}
		
		printf("  %c    ", p.sex);
		printf("%.2f\t", p.height);
		printf("%.2f\t", p.weight);
		printf("   %s\t\t", p.bgrp);

		if(p.stat==0) {
			printf("Discharged\t");
		} else if (p.stat==1) {
			printf("O.P.D\t\t");
		} else {
			printf("Emergency\t");
		}

		int a = p.bill/1000000000;
		
		if (a > 0) {
			printf("%lf\t", p.bill);
		} else {
			printf("%lf\t\t", p.bill);
		}

		double due = p.bill-p.amtdep;

		if(due==0) {
			printf("No dues");
		} else {
			printf("%lf", due);
		}

		printf("\n");		
	}

	while((c=getchar())!='\n' && c!=EOF)
		;
	printf("\nDo you want more details of all patients?(Y/N): ");
	char ans;
	scanf("%c",&ans);

	if(ans=='y' || ans=='Y') {
		fseek( fptr, 0, SEEK_SET );
		while (fread(&p, sizeof(p), 1, fptr)==1) {
			printf("Patient ID(%ld):\n", p.pid);
			printf("   Patient's Name: %s\n", p.name);
			printf("   Doctor's Name : %s\n", p.doc);
			printf("   Diagnosis     : %s\n", p.diag);
		}
	}
	while((c=getchar())!='\n' && c!=EOF)
		;
	printf("\nDo you want to print the date log of a patient?(Y/N): ");
	scanf("%c", &ans);
	
	while(ans=='y' || ans=='Y') {
		long p_id;
		printf("Enter patient ID: ");
		scanf("%ld", &p_id);

		fseek( fptr, 0, SEEK_SET );
		while(fread(&p, sizeof(struct patient), 1, fptr)==1) {

			if(p_id==p.pid) {
				//FILE *fileptr = fopen(p.name, "rb");

				//if (fileptr==NULL) {
				//	printf("No record");
				//	goto a;
				//}

				printf("%s:\n", p.name);
				date(p);
				//fclose(fileptr);
				break;
			}
		}
a:		while((c=getchar())!='\n' && c!=EOF)
			;
		printf("\nDo you want to get the log of another patient? (Y/N): ");
		scanf("%c", &ans);
	}
}
