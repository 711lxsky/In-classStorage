#include <stdio.h>
#include <string.h>

#define PWD "XIANDIAN"

int Verify(char *password){
	
	int auth;
	
	char buf[12];
	
	auth = strcmp(password,PWD);
	
	strcpy(buf, password);
	
	return auth;
	
}

int main(){
	
	int flag = 0;
	
	char pass[256];
	
	while(1){
		
		printf("Enter password:\t");
		
		scanf("%s",pass);
		
		flag = Verify(pass);
		
		if(flag)
			
			printf("Password incorrect!\n");
		
		else{
			
			printf("Correct!\n");
			
			break;
			
		}
		
	}
	return 0;
	
}
