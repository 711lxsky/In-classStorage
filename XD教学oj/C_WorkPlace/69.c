#include <stdio.h>

int main ( void )
{
    int num[102][102] = { 0 } ;
    int row , line ;
    scanf("%d %d" , &row , &line) ;
    for ( int i = 0 ; i < row ; i ++){
        for ( int j = 0 ; j < line ; j ++){
            scanf("%d" , &num[i][j]) ;
        }
    }

    for ( int k = 0 ; k < row ; k ++){
        int lab_sta = line ,des_lab_sta , lab_end =line , des_lab_end , lab_one ,jud = 0 , sum = 0 , sum_max = -1;
        for ( int l = 0 ; l < line   ; l ++){
            
            int rep = num[k][l] ;
            if ( rep == 1 ){
                jud ++ ;
                lab_one = l ;
            }
            if ( num[k][l] == 1 && num[k][l+1] == 1 ){
               lab_end = l + 1 ;
               sum ++ ;
            }
            else {
                sum = 0 ;
            }
            
            if ( sum_max < sum ){
                sum_max = sum ;
                des_lab_end =lab_end ;
                des_lab_sta = des_lab_end - sum ;
            }     
            }
            if ( jud == 0 ){
                printf("-1 -1\n") ;
            }
            else if ( jud == 1){
                printf("%d %d\n" , lab_one , lab_one) ;
            }
            else {
                printf("%d %d\n" , des_lab_sta , des_lab_end) ;
            }
        }

        return 0 ;
    }

