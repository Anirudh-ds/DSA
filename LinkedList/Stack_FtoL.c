#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack * next;
};

struct Stack *head = NULL;

void Push(){
    struct Stack *newnode = malloc(sizeof(struct Stack));
    int data;
    printf("Enter Value : ");
    scanf("%d", &data);
    if(head == NULL){
        head = newnode;
        newnode->data = data;
        newnode->next = NULL;
        printf("\nElement Successfully Pushed\n");
    }else{
        newnode->data = data;
        struct Stack *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
        newnode->next = NULL;
        printf("\nElement Successfully Pushed\n");
    }
}

void Pop(){
    struct Stack *current = head;
    while (current->next->next != NULL){
        current = current->next;
    }
    current->next = NULL;
    printf("\nElement Successfully Popped\n");
}

void Top(){
    struct Stack *current = head;
    while(current->next != NULL){
        current = current->next;
    } 
    printf("\nTop : %d", current->data);
}

void Display(){
    struct Stack *current = head;
    printf("\nStack is : ");
    while(current != NULL){
        printf("%d", current->data);

        if(current->next != NULL)
            printf(" -> ");
        current = current->next;
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
            Top();
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