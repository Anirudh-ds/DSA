#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int * ptr = NULL;
int front = -1, rear = -1, size = 0;

bool Isempty(){
    return (front == -1) ? true : false ;
}

bool Isfull(){
    return (front == ((rear + 1)%size)) ? true : false ;
    // if(front == 0 && rear == (size - 1))
    //     return true;
    // else if(front == (rear + 1))
    //     return true;
    // else
    //     return false;
}

void Startadd(){
    if(Isfull()){
        printf("\nQUEUE IS FULL!");
        return;
    }
    
    int element;
    printf("\nElement : ");
    scanf("%d", &element);

    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        ptr[front] = element;
    }else if(front == 0){
        front = size - 1;
        ptr[front] = element;
    }else{
        front--;
        ptr[front] = element;
    }
}

void Endadd(){
    if(Isfull()){
        printf("\nQUEUE IS FULL!");
        return;
    }

    int element;
    printf("\nElement : ");
    scanf("%d", &element);

    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        ptr[rear] = element;
    }else{
        rear = (rear + 1) % size;
        ptr[rear] = element;
    }
}

void Startdelete(){
    if(Isempty()){
        printf("\nQUEUE IS EMPTY!");
        return;
    }

    if(front == rear){
        front = -1;
        rear = -1;
        printf("\nElement Dequeued\n");
    }else{
        front = (front + 1) % size;
        printf("\nElement Dequeued\n");
    }
}

void Enddelete(){
    if(Isempty()){
        printf("\nQUEUE IS EMPTY!");
        return;
    }

    if(front == rear){
        front = -1;
        rear = -1;
        printf("\nElement Dequeued\n");
    }else if(rear == 0){
        rear = size -1;
        printf("\nElement Dequeued\n");
    }else{
        rear--;
        printf("\nElement Dequeued\n");
    }

}

void Display(){
   if(Isempty()){
    printf("\nQUEUE IS EMPTY\n");
    return;
   }
   int i = front;
   printf("\nQUEUE IS : ");
   while(i != rear){
    printf(" %d ", ptr[i]);
    i = (i+1) % size;
   }
   printf(" %d ", ptr[i]);
    
}

int main(){
    int option = 1;
    printf("\nEnter the size of Queue : ");
    scanf("%d", &size);
    ptr = (int *)malloc(size * sizeof(int));

    do{
        printf("\n\nPress\n0 : Exit\n1 : StartAdd\n2 : EndAdd\n3 : Startdelelte\n4 : Enddelete\n5 : Display\n");
        scanf("%d", &option);

        switch (option){
        case 0:
            printf("\n\nBYE BYE\n\n");
            break;
        case 1:
            Startadd();
            Display();
            break;
        case 2:
            Endadd();
            Display();
            break;
        case 3:
            Startdelete();
            Display();
            break;
        case 4:
            Enddelete();
            Display();
            break;
        case 5:
            Display();
            break;
        default:
            printf("\nWrong Input\n");
            break;
        }
    }while(option != 0);
}