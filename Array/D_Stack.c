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

    while(option){
        printf("\nPress 0 : Exit\nPress 1 : Push\nPress 2 : Pop\nPress 3 : Show Top\nPress 4 : Check Stack is Empty or Not\nPress 5 : Show Size\nPress 6 : Show Stack\nPress 7 : To change size of Stack\n");
        scanf("%d", &option);
        
        if(option == 0){
            printf("\n\nBYE BYE!!\n\n");
        }else if(option == 1){
            push();
        }else if(option == 2){
            pop();
        }else if(option == 3){
            top();
        }else if(option == 4){
            isempty();
        }else if(option == 5){
            sizee();
        }else if(option == 6){
            display();
        }else if(option == 7){
            resize();
        }else{
            printf("\n\nINVALID INPUT!!!\n\n");
        }
    }

    free(stack);

    return 0;
}
