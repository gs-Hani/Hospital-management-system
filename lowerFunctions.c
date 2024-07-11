#include <ctype.h>
#include <string.h>

void strlower(char* p, char* c) {
	for(int i=0; i<strlen(p); i++) {
		c[i]=tolower(p[i]);
	}
}
