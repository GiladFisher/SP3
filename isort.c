#include <stdio.h>
void shift_element(int* arr, int i){
    int temp1 = *(arr);
    int temp2 = *(arr + 1);
    int j = 0;
    while (j < i ){
        *(arr + j + 1) = temp1; // arr[j + 1]
        temp1 = temp2;
        temp2 = *(arr + j + 2); // arr[j + 2]
        j++;
    }
}