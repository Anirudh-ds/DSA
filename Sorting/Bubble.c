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
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[i])
                swap(&arr[i], &arr[j]);
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
