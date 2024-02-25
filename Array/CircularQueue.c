// Included Header Files
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Golbal Variables Declarations
int front = -1;
int rear = -1;
int * ptr;
int size = 0;

// Functions Delcarations
void Enqueue();
void Dequeue();
void Front();
void Rear();
bool Isempty();
bool Isfull();
void Display();

//Function Definations
void Display(){
    if(Isempty()){
        printf("\nQueue is empty");
        return;
    }else{
        int i = front;
        printf("QUEUE IS : ");
        while(i != rear){
            printf(" %d ", ptr[i]);
            i = (i+1) % size;
        }
        printf(" %d ", ptr[i]);
        
    }
}
void Enqueue(){
    int num;
    if(Isfull()){
        printf("\nQueue is full");
        return;
    }else if(front == -1 && rear == -1){
        printf("\nEnter the number : ");
        scanf("%d", &num);
        front = 0;
        rear = 0;
        ptr[rear] = num;
    }else{
        printf("\nEnter the number : ");
        scanf("%d", &num);
        rear = (rear + 1) % size;
        ptr[rear] = num;
    }
}
void Dequeue(){
    if(Isempty()){
        printf("\nQueue is empty");
        return;
    }else if(front == rear){
        front = -1;
        rear = -1;
        printf("\nDequeued");
    }else{
        front = (front + 1) % size;
        printf("\nDequeued");
    }
}
void Front(){
    int this_empty = Isempty();
    if(this_empty){
        printf("\nPrint Queue is empty");
    }else{
        printf("\nFront : %d", ptr[front]);
    }
}
void Rear(){
    int this_empty = Isempty();
    if(this_empty){
        printf("\nQueue is empty");
    }else{
        printf("\nRear : %d", ptr[rear]);
    }
    
}
bool Isempty(){
    if(front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}
bool Isfull(){
    if((rear + 1) % size == front){
        return true;
    }else{
        return false;
    }
}
void Size(){
    int local_size = (rear - front)+1; 
    printf("\nTotal Size of Queue : %d\nElement is Queue : %d", size, local_size);
}

void show0(){
    printf("Ele : %d", ptr[0]);
}
int main(){
    int option = 1;
    printf("Enter the size of circular queue : ");
    scanf("%d", &size);
    ptr = (int *)malloc(size * sizeof(int));

    while(option){
        printf("\nPress 0 : Exit\nPress 1 : Enqueue\nPress 2 : Dequeue\nPress 3 : Front\nPress 4 : Rear\nPress 5 : Isempty\nPress 6 : Isfull\nPress 7 : Size\nPress 8 : Display\n");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("\nBYE\nBYE\nBYE");
            break;
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Front();
            break;
        case 4:
            Rear();
            break;
        case 5: 
            // int empty = Isempty();
            if(Isempty())
                printf("\nQueue is empty");
            else   
                printf("\nQueue is not empty");
            break;
        case 6:
            // int full = Isfull();
            if(Isfull())
                printf("\nQueue is full");
            else
                printf("\nQueue is not full");
            break;
        case 7:
            Size();
            break;
        case 8:
            Display();
            break;
        case 9:
            show0();
            break;
        default:
            printf("\n\nWRONG INPUT!!\n\n");
            break;
        }
    }
    return 0;
}