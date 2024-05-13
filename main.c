#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "print.h"

int main() {
	int option,id;
	char yn;
	char c,phi;
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
			break;
		case 2 :
			break;
		case 3 :
			break;
		case 4 :
			break;
		case 5 :
			break;
		case 6 :
			break;
		case 7 :
			break;
		case 8 :
			break;
		case 9 :
			break;
		default:
			printf("Enter valid option\n");
			while ((phi = getchar()) != '\n' && phi != EOF) {};
			goto menu;
	}
	return 0;
}
