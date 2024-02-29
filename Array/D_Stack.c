#include <stdio.h>
#include <stdlib.h>
int current = 0, size = 0;
int * stack;

void display(){
    if(current == 0){
        printf("\nSTACK IS EMPTY!!\n");
    }else{
        printf("\nStack is : ");
        for (int i = 0; i < current; i++)
        {
            printf(" %d ", stack[i]);
        }
        printf("\n");
    }
    
}
void push(){
    if(current == size){
        printf("\nStack is full\n");
    }else{
        int number;
        printf("\nEnter the number to push : ");
        scanf("%d", &number);
        stack[current] = number;
        current++;
        printf("\nElement Successfully Pushed!\n");
    }
}
void pop(){
    if(current == 0){
        printf("\nStack is EMPTY!!\n");
    }else{
        stack[current] = 0;
        current--;
        printf("\nElement Successfully Popped!\n");
    }
}
void top(){
    printf("\nTOP element is : %d\n", stack[current-1]);
}
void isempty(){
    if(current == 0){
        printf("\nStack is EMPTY!!\n");
    }else
    {
        printf("\nStack is NOT EMPTY!!\n");
    }
    
}
void sizee(){
    printf("\nSize of stack is %d\n", size);
    printf("Number of Elements in stack %d\n", current);

}
void resize(){
    printf("Enter new size of stack : ");
    scanf("%d", &size);
    stack = (int *)realloc(stack, size * sizeof(int));
    printf("\n\n STACK RESIZED!!\n\n");
}

int main(){
    int option = 1;

    printf("Enter the size of stack : ");
    scanf("%d", &size);
    stack = (int *) malloc(size * sizeof(int));
    if(stack != NULL){
        printf("\n\nStack Created Successfully!!\n\n");
  
    }
        
    
    do{
        printf("\nPress 0 : Exit\nPress 1 : Push\nPress 2 : Pop\nPress 3 : Show Top\nPress 4 : Check Stack is Empty or Not\nPress 5 : Show Size\nPress 6 : Show Stack\nPress 7 : To change size of Stack\n");
        scanf("%d", &option);
        switch(option){
            case 0:
                printf("\n\nBYE BYE!!\n\n");
                break;
            case 1: 
                push();
                break;
        case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                isempty();
                break;
            case 5:
                sizee();
                break;
            case 6:
                display();
                break;
            case 7:
                resize();
                break;
            default:
                printf("\n\nINVALID INPUT!!!\n\n");
                break;
        }    
    }while(option != 0);

    free(stack);

    return 0;
}
