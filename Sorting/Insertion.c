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
    for(int i = 0; i < size; i ++)
        printf("%d ", arr[i]);
}

void sortInsertion(int * arr)
{
    int index = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            index = j;
            while(arr[j] < arr[i] && index > 0)
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 8, 4, 10, 6};

    display(arr);
    sortInsertion(arr);
    display(arr);

    return 0;
}
