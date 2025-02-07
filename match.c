#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int strcmp(char const *s1, char const *s2)
{
	while(!(s1 == '\0' || s2 == '\0') && s1 == s2) {
		s1++;
		s2++;
	}
}





int match(char const *s1, char const *s2)
{
	if(strcmp(s2, "*") == 0 || strcmp(s1, s2) == 0) {
		return(1);
	}
	if(strlen(s1) == 0) {
		return(0);
	}
	if(s1[0] == s2[0]) {
		return (match(s1 + 1, s2 + 1));
	}
	else if(s2[0] == '*') {
		return(match(s1 + 1, s2) || match(s1, s2 + 1));
	}
	return(0);
}
