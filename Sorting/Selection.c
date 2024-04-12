#include<stdio.h>

#define size 5

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int * arr)
{
    printf("\nArray : ");
    for(int i = 0; i < size; i ++){
        printf("%d ", arr[i]);
    }
}

// int arr[] = {5, 8, 2, 10, 6};

// ==> Insertion Swap with multiple swaps
void sortSelection_01(int * arr)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[i])
                swap(&arr[j], &arr[i]);
        }
        
    }
}

// ==> Insertion Swap with limited swaps
void sortSelection_02(int * arr)
{
    int noSmall = 0, indexSmall = 0;

    for(int i = 0; i < size; i++)
    {
        noSmall = arr[i];
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < noSmall){
                noSmall = arr[j];
                indexSmall = j;
            }
        }
        swap(&arr[indexSmall], &arr[i]);
    }
}


int main()
{
    int arr[] = {5, 8, 4, 10, 6};

    display(arr);
    // sortSelection_02(arr);
    sortSelection_02(arr);
    display(arr);


    return 0;
}
