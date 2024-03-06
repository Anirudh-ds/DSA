// ==> Infix : A + B * C, Postfix : AB+C*

// ==> For Postfix : Reverse the input, convert it into prefix(pushing elements with higher precedence only not with equal precedence) reverset the output again
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

#define size 100

bool isEmpty(int current){
    // ==> Checks if the stack is empty or not using stack top
    return (current == -1) ? true : false;
}

int getPrecedence(char operator){
    // ==> Return precedence of the given character
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
        break;

    case '*':
    case '/':
        return 2;
        break;
    
    case '^':
        return 3;
        break;
    
    default:
        return 0;
        break;
    }
}

bool isAplhabet(char current){
    // ==> Checks if the current element is alphabet or not
    if(current >= 'A' && current <= 'Z' ){
        return true;
    }else if(current >= 'a' && current <= 'z'){
        return true;
    }else{
        return false;
    }
}

bool isOperator(char current){
    // ==> Check if the current element is an operator or not
    return (current == '+' || current == '-' || current == '*' || current == '/' || current == '^' || current == '(' || current == ')') ? true : false;
}

void push(char current, char stack[], int *stackTop){
    // Increase stack top and push the given element in it
    *stackTop = *stackTop + 1;
    stack[*stackTop] = current;
}

void pop(char stack[], int *stackTop, char postfix[], int *postTop){
    // ==> Puts the top element of stack in output or just returns if the stack is empty
    if(isEmpty(*stackTop))
    {
        return;
    }else
    {
        postfix[*postTop] = stack[*stackTop];
        *postTop = *postTop + 1;
        *stackTop = *stackTop - 1;
    }
    
}

void convertPostfix(char input[], char postfix[], char stack[], int *postTop, int *stackTop){
    // ==> Traversing the user given string
    for(int i = 0; input[i] != '\0'; i++)
    {   // ==> If brackets are encountered
        if(input[i] == '(' || input[i] == ')')
        {
            switch(input[i])
            {
                case '(':
                    push(input[i], stack, stackTop);
                    break;
                case ')':
                    while(stack[*stackTop] != '(')
                        pop(stack, stackTop, postfix, postTop);
                    *stackTop = *stackTop - 1;
                    break;
                default:
                    // printf("\nSwtich Default");
                    break;
            }
        }else if(isAplhabet(input[i]))
       {    // ==> In case of alphabet just push it into output string
            postfix[*postTop] = input[i];
            *postTop = *postTop + 1;
       }else if(isOperator(input[i]))
       {    // ==> In case of operator push into stack if stack is empty other check precedence and push accordingly 
            if(isEmpty(*stackTop))
            {
                push(input[i], stack, stackTop);
            }else if(input[i] == '^' && stack[*stackTop] == '^'){
                push(input[i], stack, stackTop);

            }else if((getPrecedence(input[i]) > getPrecedence(stack[*stackTop])) )
            {
                push(input[i], stack, stackTop);
            }else if(getPrecedence(input[i]) <= getPrecedence(stack[*stackTop]))
            {
                while(getPrecedence(input[i]) <= getPrecedence(stack[*stackTop]) )
                {
                    pop(stack, stackTop, postfix, postTop);
                }
                push(input[i], stack, stackTop); 
            }else{
                continue;
            }
                
       }else if(input[i] == ' ') continue;
       else{
            printf("ERROR OCCURED AT %c\n", input[i]);
            break;
        }
        
    }
    // ==> Empty stack when you are done traversing the input 
    while(*stackTop != -1){
        pop(stack, stackTop, postfix, postTop);
    }

}

void convertPrefix(char input[], char postfix[], char stack[], int *postTop, int *stackTop){
    // ==> Traversing the user given string
    for(int i = 0; input[i] != '\0'; i++)
    {   // ==> If brackets are encountered
        if(input[i] == '(' || input[i] == ')')
        {
            switch(input[i])
            {
                case '(':
                    push(input[i], stack, stackTop);
                    break;
                case ')':
                    while(stack[*stackTop] != '(')
                        pop(stack, stackTop, postfix, postTop);
                    *stackTop = *stackTop - 1;
                    break;
                default:
                    // printf("\nSwtich Default");
                    break;
            }
        }else if(isAplhabet(input[i]))
       {    // ==> In case of alphabet just push it into output string
            postfix[*postTop] = input[i];
            *postTop = *postTop + 1;
       }else if(isOperator(input[i]))
       {    // ==> In case of operator push into stack if stack is empty other check precedence and push accordingly 
            if(isEmpty(*stackTop))
            {
                push(input[i], stack, stackTop);
            }else if(input[i] == '^' && stack[*stackTop] == '^'){
                push(input[i], stack, stackTop);

            }else if((getPrecedence(input[i]) > getPrecedence(stack[*stackTop])) )
            {
                push(input[i], stack, stackTop);
            }else if(getPrecedence(input[i]) < getPrecedence(stack[*stackTop]))
            {
                while(getPrecedence(input[i]) < getPrecedence(stack[*stackTop]) )
                {
                    pop(stack, stackTop, postfix, postTop);
                }
                push(input[i], stack, stackTop); 
            }else{
                continue;
            }
                
       }else if(input[i] == ' ') continue;
       else{
            printf("ERROR OCCURED AT %c\n", input[i]);
            break;
        }
        
    }
    // ==> Empty stack when you are done traversing the input 
    while(*stackTop != -1){
        pop(stack, stackTop, postfix, postTop);
    }

}

void revString(char input[], char output[]){
    // This function takes input[] and reverses it into output[]
    int currentSize = 0;
    while(input[currentSize] != '\0'){
        currentSize++;
    }
    // printf("\nSize : %d", currentSize);
   int start = 0, end = currentSize-1;
   for (int i = 0; i <= currentSize; i++)
   {    // ==> Condition for reversing brackets
        if(input[end] == '(')
            output[start] = ')';
        else if(input[end] == ')')
            output[start] = '(';
        else
            output[start] = input[end];
        
        start++;
        end--;
   }
   
}

void displayOutput(char output[], int *top){
    int i = 0;
    // printf("\nOUTPUT : ");
    while(i <= *top){
        // printf("%d", i);
        printf("%c", output[i]);
        i++;
    }
    printf("\n\n\n");
}


int main(){
    int option;
    printf("\n\t\t\t WELCOME TO PREFIX/POSTFIX CONVERTER \t\t\t\n");
    printf("\nNOTE\n1. Use alphabet statements\t\t\t\t\tEg: A+B*C, a+b*c\n2. This program does NOT feature number statements for now\tEg : 7+8*9\n3. MAX size of statement is 100\n4. Use '/' for divide\n");

    do{
        printf("\n\nPress : \n0 : To EXIT\n1 : To convert into POSTFIX/PREFIX\n");
        scanf("%d", &option);

        char input[size] = {'0'}, stack[size] = {'0'}, postfix[size] = {'0'}, prefix[size] = {'0'};
        int postTop = 0, stackTop = -1;

        switch (option)
        {
        case 0:
            printf("\nBYE\nBYe\nBye\nbye\n");
            break;
         
        case 1:
            // ==> Put input expression in a characted array 
            printf("\nEnter INFIX expression : ");
            scanf("\n");
            scanf("%[^\n]%*c", input);

            
            convertPostfix(input, postfix, stack, &postTop, &stackTop);
            
            printf("\nPOSTFIX : ");
            displayOutput(postfix, &postTop);
            
        //     break;
        // case 2:
            // ==> Re-initialization of variables so that they are emptry before performing prefix operations
            char stack[size] = {'0'}, postfix[size] = {'0'}, prefix[size] = {'0'};
            int postTop = 0, stackTop = -1;
            // ==> Put input expression in a characted array 

            // printf("\nEnter expression : ");
            // scanf("\n");
            // scanf("%[^\n]%*c", input);

            // ==> Taking input and reversing it into prefix
            revString(input, prefix);
            // ==> Below 3 prints can be used to debug  the errors while converting input to postfix and back from postfix to output
            // printf("\n\nInput : "); // 1
            // puts(input);
            // printf("\nReverse : "); // 2
            // puts(prefix);
            convertPrefix(prefix, postfix, stack, &postTop, &stackTop);
            // printf("\nPostfix : "); // 3
            // puts(postfix);

            // ==> Taking postfix and reversing it get prefix
            revString(postfix, prefix);
            printf("\nPREFIX : ");
            displayOutput(prefix, &postTop);

            break;

        default:
            printf("\n\nWRONG INPUT!!\n\n");
            break;
        }
        

    }while(option != 0);
    
    return 0;
}
