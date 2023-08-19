#include <stdio.h>
#include <string.h>

typedef struct {
	int length; // 字符串长度,0-99
	char data[150]; // 字符数据，包括结束字符'\0'
} FIXED_STRING;
char *insert(FIXED_STRING *s, char *t, int pos);

int main() {
	FIXED_STRING s;
	char t[20];
	scanf("%s", s.data);
	s.length = strlen(s.data);
	scanf("%s", t);
	int pos;
	scanf("%d", &pos);
	char *ps = insert(&s, t, pos);
	printf("%d %s\n", s.length, ps);
	return 0;
}
char *insert(FIXED_STRING *s, char *t, int pos){
	int lenS = strlen(s -> data) ;
	int lenT = strlen(t) ;
	if(pos >= lenS){
		for(int i = pos , j = 0 ; j < lenT ; ++ i , ++ j ){
			s -> data[pos] = t[j] ;
		}
	}
	//char str[151] ;
	else{
        char str[151] ;
		for(int i = pos , j = 0 ; i < lenS ; i ++ , j ++){
			str[j] = s -> data[i] ;
		}
		for( int i = pos , j = 0 ; j < lenT ; j ++ , i ++){
			s -> data[i] = t[j] ;
		}
		for( int i = pos + lenT , j = 0 ; j < strlen(str) ; j ++ , i ++){
			s -> data[i] = str[j] ;
		}
	}
	s -> length = strlen(s -> data) ;
	
	return s -> data ;
}
