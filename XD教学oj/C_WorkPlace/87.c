#include <stdio.h>

int main (void)
{
    int num , sum  = 0, i = 0 , j ,gra1 = 2 ,gra2 = 4 , num1 , num2 ;
    int turn[1000] = {0} ;
    while (  scanf("%d" ,&num) != EOF && num != 0 ){
         turn[i] = num ;
         i ++ ;
          }

          i = 1 ;

          if ( turn[0] == 2){
            sum = 2 ;
          }
          else if ( turn[0] == 1){
            sum = 1 ;
          }
   while (turn[i] != 0){
    
    if ( turn[i-1] == 2 ){

        if(turn[i] == 2){
            sum += gra2 ;
            gra2 += 2 ;
        }
        else if (turn[i] == 1){
            sum ++ ;
            gra2 = 4 ;
            gra1 = 2 ;
        }
    }
    else if ( turn[i-1] == 1){

        if ( turn[i] == 2){
            sum += gra1 ;
            gra1 += 2 ;
        } 
        else if ( turn[i] == 1){
            sum ++ ;
            gra1 = 2 ;
             gra2 = 4;
        }
    }
    i ++ ;
   }
   printf("%d" ,sum) ;

   return 0;
    }