#include <stdio.h>
void shift_element(int *arr, int i){
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
void insertion_sort(int* arr, int len){
    for (int i = 1; i < len; i++){
        if (*(arr + i) < *(arr + i - 1)){
            int temp = *(arr + i);
            if ( i == 1){
                shift_element(arr, 1);
                *arr = temp;
            }
            else{
                for (int j = i - 2; j >= 0; j--){
                if (temp > *(arr + j)){
                    shift_element((arr + j), i - j);
                    *(arr + j + 1) = temp;
                    break;
                }
                if (j == 0){
                    shift_element(arr, i);
                    *(arr) = temp;
                }
            }
            }
        }
    }
}