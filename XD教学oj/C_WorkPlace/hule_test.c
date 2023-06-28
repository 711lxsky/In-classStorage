#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LEN sizeof(struct Node)
typedef struct Node
{
    int num ;
    struct Node *next ;
}NODE ;
NODE *creat()
{
    NODE *head , *current , *last ;
    head = current = (NODE *)malloc(LEN) ;
    head -> num = 2023 ;
    last = (NODE *)malloc(LEN) ;
    scanf("%d" , &last->num) ;
    while(last->num != -1){
        current->next = last ;
        current = last ;
        last = (NODE *)malloc(LEN) ;
        scanf("%d" ,&last->num) ;
    }
    current->next = NULL ;
    free(last) ;
    return(head) ;
}
NODE *reverse(NODE *head)
{
    if(head == NULL) return(NULL) ;
    if(head->next == NULL) return(head) ;
    NODE *pre = head ;
    NODE *cur = head->next ;
    NODE *next = cur->next ;
    pre->next = NULL ;
    while(cur != NULL){
        cur->next = pre ;
        pre = cur ;
        cur = next ;
        if(next != NULL)
            next = next->next ;
    }
    //free(cur) ;
    //free(next) ;
    return(pre) ;
}
void print(NODE *head)
{
   
        while(head -> next != NULL){
            printf("%d " ,head->num) ;
            head = head->next ;
        }
    

}
int main()
{
    NODE *head , *current ;
    head = creat();
    current = reverse(head) ;
    print(current) ;
    return 0 ;
}
