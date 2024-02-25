#include<stdio.h>
#include<stdlib.h>

int * ptr = NULL;
int size = 0;
int current = 0;

// Operations : Enqueue, Dequeue, Peek, Isempty, Isfull, Size

void Enqueue(){
    if(current == size){
        printf("\nQEUEU IS FULL!!\n");
        return;
    }else{
        int num;
        printf("\nEnter the number : ");
        scanf("%d", &num);
        ptr[current] = num;
        current++;
    }
}
void Dequeue(){
    if(current == 0){
        printf("\nQUEUE IS EMPTY!!");
        return;
    }else{
        for (int i = 0; i < current-1; i++)
        {
            ptr[i] = ptr[i+1];
        }
        current--;
        printf("\nDEQUEUED!!");
    }
}
void Peek(){
    printf("\nPeek : %d", ptr[current-1]);
}
void Isempty(){
    if (current == 0){
        printf("\nQUEUE IS EMPTY!");
    }else{
        printf("\nQUEUE IS NOT EMPTY!");
    }
}
void Isfull(){
    if(current == size){
        printf("\nQUEUE IS FULL!!");
    }else{
        printf("\nQUEUE IS NOT FULL!!");
    }
}
void Size(){
    printf("\nSize of QUEUE : %d\nElement in QUEUE : %d", size, current);
}
void Display(){
    printf("\nQUEUE is : ");
    for (int i = 0; i < current; i++){
        printf("%d ", ptr[i]);
    }
}

int main(){
    int option = 1;
    printf("\nEnter the size of queue you want : ");
    scanf("%d", &size);
    ptr = (int *)malloc(size * sizeof(int));

    while (option){
        printf("\nPress 0 : Exit\nPress 1 : Enqueue\nPress 2 : Dequeue\nPress 3 : Peek\nPress 4 : Isempty\nPress 5 : Isfull\nPress 6 : Size\nPress 7 : Display\n");
        scanf("%d", &option);

        if(option == 1){
            Enqueue();
        }else if(option == 2){
            Dequeue();
        }else if(option == 3){
            Peek();
        }else if (option == 4){
            Isempty();
        }else if(option == 5){
            Isfull();
        }else if(option == 6){
            Size();
        }else if(option == 7){
            Display();
        }else if(option == 0){
            printf("\nBYE\nBYE\nBYE");
        }else{
            printf("\nWRONG INPUT!!");
        }
    }
    return 0;
}