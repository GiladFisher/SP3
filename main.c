#include <stdio.h>
void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);
int main(){
    int arr[9] = {7,3,8,5,10,9,1,0,11};
    insertion_sort(arr, 9);
    // shift_element(arr + 3, 5-3);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ,", *(arr + i));
    }
    printf("\n");
    
    return 0;
}