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

    do{
        printf("\nPress 0 : Exit\nPress 1 : Enqueue\nPress 2 : Dequeue\nPress 3 : Peek\nPress 4 : Isempty\nPress 5 : Isfull\nPress 6 : Size\nPress 7 : Display\n");
        scanf("%d", &option);
        switch(option){
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
                Peek();
                break;
            case 4:
                Isempty();
                break;
            case 5:
                Isfull();
                break;
            case 6:
                Size();
                break;
            case 7:
                Display();
                break;
            default:
                printf("\n!!Wrong Input!\n");
                break;
        }
    }while(option);
    return 0;
}
