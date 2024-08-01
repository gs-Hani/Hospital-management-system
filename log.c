#include <stdio.h>
#include <stdlib.h>

#include "extern.h"
#include "print.h"

int log_patient(int OGdate[], int date[])		/*Date file*/ {
	if(OGdate[0]==date[0] && OGdate[1]==date[1] && OGdate[2]==date[2]) {
	 	 return 1;
	} else { return 0; }
}	

void openfile()	/*Main record file.*/ {
	int d, m, y,flag=0
		;
	printf("Enter date(dd)  : "); scanf("%d", &d);
	printf("Enter month(mm) : "); scanf("%d", &m);
	printf("Enter year(yyyy): "); scanf("%d", &y)
		;
	FILE* fptr=fopen("records.dat","rb");
	int date[3]={d, m, y};
	struct patient p;
	FILE *log = fopen("log.dat", "wb+")
		;
	if(log==NULL) {
		printf("error\n");
		exit(0);
	}

	while(fread(&p, sizeof(struct patient), 1, fptr)==1) {

		if(log_patient(p.date, date)==1) {
			fwrite(&p, sizeof(struct patient), 1, log);
			flag=1;
		}	
	}

	fseek(log, 0, SEEK_SET);

	if(flag==0) {
		printf("No records found.\n");
		fclose(log);
		fclose(fptr);
	} else {
		print(log);
		fclose(log);
		fclose(fptr);
	}
}
