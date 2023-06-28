int compare ( int x , int y)
{
    int jud = 0 ;
    if ( x % 2 == 0 && y % 2 != 0) 
    jud = 2 ;
    else if ( x % 2 != 0 && y % 2== 0 ) 
    jud = -2 ;
    else {
    if ( x > y)  jud = 1 ;
    else if ( x < y ) jud = -1 ;
    else jud = 0 ; }
    
    return jud ;
}