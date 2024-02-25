#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct linkedlist{
    int data;
    struct linkedlist *next;
};
struct linkedlist *top = NULL;

bool Isempty(){
    return (top == NULL) ? true : false ;
}

void Display(){
    if(Isempty()){
        printf("\nSTACK IS EMPTY!\n");
        return;
    }

    struct linkedlist *display = top;
    printf("\nSTACK : ");
    while(display != NULL){
        printf("%d", display->data);
        if(display->next != NULL)
            printf(" -> ");
        display = display->next;
    }

}

void Push(){
    struct linkedlist *newnode = malloc(sizeof(struct linkedlist));
    
    int data;
    printf("\nData : ");
    scanf("%d", &data);
    newnode->data = data;

    if(top == NULL){
        top = newnode;
        newnode->next = NULL;
    }else{
        newnode->next = top;
        top = newnode;
    }

}

void Pop(){
    if(Isempty()){
        printf("\nSTACK IS EMPTY!\n");
        return;
    }

    if(top->next == NULL){
        top = NULL;
        printf("\nPOPPED\n");
    }else{
        top = top->next;
        printf("\nPOPPED\n");
    }
}


int main(){
    int option = 1;
    do{
        printf("\nPress : \n0 : Close\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n");
        scanf("%d", &option);

        switch (option){
        case 0:
            printf("\n\n!BYE BYE!\n\n");
            break;
        case 1:
            Push();
            Display();
            break;
        case 2:
            Pop();
            Display();
            break;
        case 3:
            printf("TOP : %d", top->data);
            break;
        case 4:
            Display();
            break;
        default:
            printf("\nWrong Input!\n");
            break;
        }    
    }while(option != 0);

    return 0;

}