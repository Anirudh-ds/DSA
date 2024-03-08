#include<stdio.h>
#include<stdlib.h>

typedef struct CircularLL{
    int data;
    struct CircularLL * next;
}cl;

cl *head = NULL, *tail = NULL;

void AddStart(){
    cl * newnode = malloc(sizeof(cl));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(head == NULL && tail == NULL){
        head = newnode;
        tail = newnode;
    }else{
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}

void AddMiddle(){
    int position;
    printf("\nEnter Position : ");
    scanf("%d", &position);

    cl * newnode = malloc(sizeof(cl));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    cl * current = NULL;
    for(int i = 1; i < position; i++){

        if(current == NULL)
            current = head;
        else
            current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;

}

void AddLast(){
    cl * newnode = malloc(sizeof(cl));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    tail->next = newnode;
    tail = newnode;

}

void DeleteStart(){
    cl * del = head;
    head = head->next;
    tail->next = head;
    free(del);
}

void DeleteMiddle(){
    int position;
    cl * del;
    printf("\nEnter position : ");
    scanf("%d", &position);

    cl * currnet = NULL;
    for(int i = 1; i < position; i++){
        if(currnet == NULL)
            currnet  = head;
        else
            currnet = currnet->next;
    }
    del = currnet->next;
    currnet->next = del->next;
    free(del);

}

void DeleteLast(){
    cl * del = head;
    while(del->next != tail){
        del = del->next;
    }
    tail = del;
    free(tail->next);
    tail->next = head;

}

void Display(){
    cl * current = head;

    printf("\nLinked List : ");
    do{
        printf("%d ", current->data);
        current = current->next;
    }while(current != head);
}

void Show(){
    printf("\nHead : %d\tTail : %d\n", head->data, tail->data);
}

int main(){

    int option = 1;

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
                // Display();
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
