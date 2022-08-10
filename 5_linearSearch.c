// programmed by sudhan
#include <stdio.h>

int linearSearch(int a[], int s, int e)
{
    for (int i = 0; i < s; i++)
    {
        if (a[i] == e)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 7, 8, 96, 445};
    int element = 445;
    int size = sizeof(arr) / sizeof(int);
    int index = linearSearch(arr, size, element);
    if (index != -1)
    {
        printf("The element is found at index %d.\n", index);
    }
    else
    {
        printf("The element isnot found.\n");
    }

    return 0;
}