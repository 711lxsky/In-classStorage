#include<stdio.h>
#include<string.h>
int main()
{
    char ifis[101],c[101],d[101],e[101],o[101][101];
    gets(ifis);
    int is,n,i=0,k=0,t,j=0,m=0;
    scanf("%d\n%d\n",&is , &n);
//    scanf("%d\n",&n);
    strcmp(d,ifis);
    for(i=0;i<n;i++){
        gets(c);
        strcpy(e,c);
        if(is==0){
            strlwr(ifis);
            strlwr(c);
        }for(k=0;k<strlen(c);k++){
            if(c[k]==ifis[0]){
                for(t=0;c[k+m]==ifis[m]&&m<strlen(c);m++){
                    t++;
                }if(t==strlen(ifis)){
                    strcpy(o[j],e);
                    j++;
                    break;
                }
            }m=0;
        }
    }
    for(i=0;i<=j;i++)
    {
        puts(o[i]);
    }
    return 0;
}