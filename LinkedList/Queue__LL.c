#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}qu;

qu * head = NULL;

bool Isempty(){
    return (head == NULL) ? true : false;
}

void Enqueue(){
    qu *  newnode = malloc(sizeof(qu));
    
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }else{
        qu * current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void Dequeu(){

    if(Isempty()){
        printf("\nQUEUE is empty");
        return;
    }

    qu * del = head;
    head = head->next;
    free(del);
}

void Display(){
    qu * current = head;
    printf("\nQUEUE : ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main(){

    int option = 1;
    while (option){
        printf("\nPress 0 : Exit\nPress 1 : Enqueue\nPress 2 : Dequeue\nPress 3 : Display\n");
        scanf("%d", &option);

        switch (option)
        {
        
        case 0:
            option = 0;
            break;
        case 1:
            Enqueue();
            Display();
            break;
        case 2:
            Dequeu();
            Display();
            break;
        case 3:
            Display();
            break;
        default:
            printf("\nWRONG INPUT!\n");
            break;
        }
    }


    return 0;
}
