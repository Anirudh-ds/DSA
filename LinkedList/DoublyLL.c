#include<stdio.h>
#include<stdlib.h>

typedef struct DoublyLL{
    int data;
    struct DoublyLL *left;
    struct DoublyLL *right;
}dll;

dll *head = NULL, *tail = NULL;

void AddStart(){
    dll * newnode = malloc(sizeof(dll));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    
    if(head == NULL && tail == NULL){
        head = newnode;
        tail = newnode;
        newnode->left = NULL;
        newnode->right = NULL;
    }else{
        newnode->right = head;
        head->left = newnode;
        head = newnode;
        head->left = NULL;
    }

}

void AddMiddle(){
    int position;
    dll * newnode = malloc(sizeof(dll));
    dll * current = NULL;
    
    printf("\nEnter position : ");
    scanf("%d", &position);
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);

    for(int i = 1; i < position; i++){
        if(current == NULL)
            current = head;
        else
            current = current->right;
    }

    newnode->left = current;
    newnode->right = current->right;
    current->right->left = newnode;
    current->right = newnode;

}

void AddLast(){
    dll * newnode = malloc(sizeof(dll));
    newnode->right = NULL;
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);

    newnode->left = tail;
    tail->right = newnode;
    tail = newnode;

}

void DeleteStart(){
    dll * del = NULL;

    del = head;
    head = head->right;
    head->left = NULL;

    free(del);

}

void DeleteMiddle(){
    dll * del = NULL;
    dll * current = NULL;

    int position;
    printf("\nEnter position : ");
    scanf("%d", &position);

    for(int i = 1; i < position; i++){
        if(current == NULL)
            current = head;
        else
            current = current->right;
    }

    del = current->right;
    current->right = del->right;
    del->right->left = current;

    free(del);
}

void DeleteLast(){
    dll * del = NULL;
    
    del = tail;
    tail = tail->left;
    tail->right = NULL;

    free(del);

}

void Display(){

    dll * current = head;
    printf("Linked List Forward:");
    while(current != NULL){
        printf(" %d", current->data);
        current = current->right;
    }

    current = tail;
    printf("\nLinked List Backward:");
    while(current != NULL){
        printf(" %d", current->data);
        current = current->left;
    }
}

void Show(){
    printf("\nHead : %d\tTail : %d\n", head->data, tail->data);
}

int main(){

    int option;
    
    do{
        printf("\nPress : \n1:Add Start\t4:Delete Start\n2:Add Middle\t5:Delete Middle\n3:Add Last\t6:Delete Last\n7:Display\t8:Show HEAD&TAIL\n");
        scanf("%d", &option);

        switch(option){
            case 0:
                option = 0;
                printf("\n..Exiting..\n");
                break;
            case 1:
                AddStart();
                Display();
                break;
            case 2:
                AddMiddle();
                Display();
                break;
            case 3:
                AddLast();
                Display();
                break;
            case 4:
                DeleteStart();
                Display();
                break;
            case 5:
                DeleteMiddle();
                Display();
                break;
            case 6:
                DeleteLast();
                Display();
                break;
            case 7:
                Display();
                break;
            case 8:
                Show();
                break;
            default:
                printf("\nWrong INPUT!\n");
                break;
        }

    }while(option != 0);


    return 0;
}
