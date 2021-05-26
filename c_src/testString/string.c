




int my_strlen(const char *str)
{
	int count = 0;
	while (*str++)
		++count;
		
	return count;
}


/*
int my_strlen(const char *src) 
{
	int count = 0;
	for (int i = 0; src[i] != '\0'; ++i) {
		++count;
	}
	return count;
}
*/

void my_strcpy(char *des, const char *src)
{
	while(*des++ = *src++) 
		
}
/*
void my_strcpy(char *des, const char *src) 
{
	int i;
	for (i = 0; src[i] != '\0'; ++i) {
		des[i] = src[i];
	}
}
*/

void my_strcat(char *des, const char *src)
{
	my_strcpy(des + my_strlen(des), src);
}
/*
void my_strcat(char *des, const char *src) 
{
	int i;
	for (i = 0; des[i] != '\0'; ++i) {
	}
	int j;
	for (j = 0; src[j] != '\0'; ++j) {
		des[i+j] = src[j];
	}
	des[i+j] = '\0';
}
*/

int my_strcmp(const char *s1, const char *s2) 
{
	if (my_strlen(s1) != my_strlen(s2)) {
		return 1;
	}
	while (*s2)
		if (*s1++ != *s2++)
		break;
		
	return (*s1) ? 1 : 0;
}
/*
int my_strcmp(const char *s1, const char *s2) 
{
	int count = 0;
	for (int i = 0; s1[i] != '\0'; ++i) {
		if (s1[i] == s2[i]) {
		 } else {
		 	++count;
		 }
	} 
	if(count == 0) {
		return 0;
	} else {
		return 1;
	}
}
	*/
			
	
	
	
	
	
	
	
	
