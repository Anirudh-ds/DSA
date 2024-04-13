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
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
}

void sortBubble(int * arr)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j+1], &arr[j]);
        }
    }
}

int main()
{
    int arr[] = {5, 8, 4, 10, 6};

    display(arr);
    sortBubble(arr);
    display(arr);

    return 0;
}
