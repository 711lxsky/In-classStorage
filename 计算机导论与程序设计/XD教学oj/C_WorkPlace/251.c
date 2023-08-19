#include <stdio.h>

struct Data
{
    int year ;
    int month ;
    int day ;
};

int main ( void )
{
    struct Data data ;
     int jud = 0 , des = 0 ;
    
    scanf("%d,%d,%d" , &data.year , &data.month , &data.day) ;
    if (  0 ==data.year % 4)
    if ( 0 == data.year % 100  ) {
        if (0 == data.year % 400) jud = 1 ;
    }
    else jud = 1 ;
    if ( jud ) {
        if ( 1 == data.month ) des = data.day ;
        else if ( 2 == data.month) des = data.day + 31 ;
        else {
            switch (data.month)
            {
            case 3:
                des = data.day + 60 ;
                break;
            case 4 :
                des = data.day + 91 ;
                break;
            case 5 :
                des = data.day + 121 ;
                break;
            case 6 :
                des = data.day + 152 ;
                break;
            case 7 : 
                des = data.day + 182 ;
                break;
            case 8 :
                des = data.day + 213 ;
                break;
            case 9 :
                des = data.day + 244 ;
                break;
            case 10 :
                des = data.day + 274 ;
                break;
            case 11 :
                des = data.day + 305 ;
                break;
            case 12 :
                des = data.day + 335 ;
                break;
            default:
                break;
            }
        } 
    }
    else {
        if ( 1 == data.month ) des = data.day ;
        else if ( 2 == data.month) des = data.day + 31 ;
        else {
            switch (data.month)
            {
            case 3:
                des = data.day + 59 ;
                break;
            case 4 :
                des = data.day + 90 ;
                break;
            case 5 :
                des = data.day + 120 ;
                break;
            case 6 :
                des = data.day + 151 ;
                break;
            case 7 : 
                des = data.day + 181 ;
                break;
            case 8 :
                des = data.day + 212 ;
                break;
            case 9 :
                des = data.day + 243 ;
                break;
            case 10 :
                des = data.day + 273 ;
                break;
            case 11 :
                des = data.day + 304 ;
                break;
            case 12 :
                des = data.day + 334 ;
                break;
            default:
                break;
            }
        } 
    }
 printf("%d" , des) ;
 return 0 ;
}
