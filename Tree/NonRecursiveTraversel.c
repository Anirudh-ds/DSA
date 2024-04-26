#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    char data;
    struct tree * left;
    struct tree * right;
}t;

t* createNode(char data){
    t * newnode = malloc(sizeof(t));

    if(newnode != NULL){    // Memory allocated
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    }else
        printf("\nMEMORY NOT ALLOCATED FOR NEW NODE");

    return newnode;
}

void push(t * stack[], int * stackTop, t * current){
    *stackTop = *stackTop + 1;
    stack[*stackTop] = current;
}

t * pop(t * stack[], int * stackTop){
    t *  temp = stack[*stackTop];
    *stackTop = *stackTop - 1;

    return temp;
}

void preOrder(t * h, t * stack[], int * stackTop){
    printf("\n Pre Order : ");
    /*
    while(h != NULL || *stackTop != -1){

        printf("%c ", h->data);
        if(h->right != NULL)
            push(stack, stackTop, h->right);
        
        if(h->left != NULL){
            h = h->left;
        }else if(*stackTop != -1){
            h = pop(stack, stackTop);
        }else{
            h = NULL;
        }
    }
    */
   
    // ==> BOOK LOGIC
    /*
    if(h != NULL)
    {
        printf("%c ", h->data);
        if(h->right != NULL)
            push(stack, stackTop, h->right);
        h = h->left;
        while(*stackTop >= -1)
        {
            while(h != NULL)
            {
                printf("%c ", h->data);
                if(h->right != NULL)
                    push(stack, stackTop, h->right);
                h = h->left;
            }
            h = pop(stack, stackTop);
        }
    }
    */
    // ==> EASIEST [Push right node into stack first then left node]
    push(stack, stackTop, h);
    while(*stackTop != -1)
    {
        h = pop(stack, stackTop);
        printf("%c ", h->data);
        if(h->right != NULL)
            push(stack, stackTop, h->right);
        if(h->left != NULL)
            push(stack, stackTop, h->left);
    }
}

void inOrder(t * h, t * stack[], int * stackTop){
    printf("\n In Order : ");
    while(h != NULL || *stackTop  != -1){
        while(h != NULL){
            push(stack, stackTop, h);
            h = h->left;
        }
        h = pop(stack, stackTop);
        printf("%c ", h->data);
        h = h->right;
        if(h != NULL){
            push(stack, stackTop, h);
            h = h->left;
        }
    }
    // BOOK LOGIC
    /* 
    if(h != NULL)
    {
        push(stack, stackTop, h);
        h = h->left;
        while(*stackTop >= 0)
        {
            while(h != NULL)
            {
                push(stack, stackTop, h);
                h = h->left;
            }
            h = pop(stack, stackTop);
            printf("%c ", h->data);
            h = h->right;
            if(h != NULL)
            {
                push(stack, stackTop, h);
                h = h->left;
            }
        }
    }
    */
   
}

void postOrder(t * h, t * stack[], int * stackTop){
    // ==>  EASIEST [Take 2 different stack here ans & stack; put root in stack then put its left & right element in it, pop from stack and push in ans]
    
    t * ans[100];
    int ansTop = -1;
    push(stack, stackTop, h);
    while(*stackTop != -1)
    {
       h = pop(stack, stackTop);
       push(ans, &ansTop, h);
       if(h->left != NULL)
            push(stack, stackTop, h->left);
        if(h->right != NULL)
            push(stack, stackTop, h->right);
    }
    printf("\nPostOrder : ");
    while(ansTop != -1)
    {
        h = pop(ans, &ansTop);
        printf("%c ", h->data);
        
    }
    
   // BOOK LOGIC
   /*
    int top, sig, sign[100];
    top = -1;
    if(h!= NULL)
    {
        top++;
        push(stack, stackTop, h);
        sign[top] = 1;
    }
    if(h->right != NULL)
    {
        top++;
        push(stack, stackTop, h->right);
        sign[top] = -1;
    }
    h = h->left;
    printf("\nPostOrder : ");
    while(top >= 0)
    {
        while(h != NULL)
        {
            top++;
            push(stack, stackTop, h);
            sign[top] =1;
            if(h->right != NULL)
            {
                top++;
                push(stack, stackTop, h->right);
                sign[top] = -1;
            }
            h = h->left;
        }
        h = pop(stack, stackTop);
        sig = sign[top];
        top--;
        
        while(sig>0 && top>=-1)
        {
            printf("%c ", h->data);
            h = pop(stack, stackTop);
            sig = sign[top];
            top--;
        }
    }
   */
    
}

int main(){
    t * root = NULL;
    t * stack[100];
    int stackTop = -1;

    root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');

    t *l1 = root->left, *r1 = root->right;
    l1->left = createNode('D');
    l1->right = createNode('E');
    r1->left = createNode('F');
    r1->right = createNode('J');
    

    preOrder(root, stack, &stackTop);
    stackTop = -1;
    inOrder(root, stack, &stackTop);
    stackTop = -1;
    postOrder(root, stack, &stackTop);
    
    return 0;
}
