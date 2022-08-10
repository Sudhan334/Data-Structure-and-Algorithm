// programmed by sudhan
#include <stdio.h>

int binarySearch(int a[], int s, int e)
{
    int low = 0, mid, high = s - 1;
    while (low <= high)
    {

        mid = (low + high) / 2;
        if (a[mid] == e)
        {
            return mid;
        }
        else
        {
            if (a[mid] < e)
            {
                low = mid + 1;
            }
            else if (a[mid] > e)
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 7, 8, 96, 445};
    int element = 78;
    int size = sizeof(arr) / sizeof(int);
    int index = binarySearch(arr, size, element);
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