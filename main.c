#include <stdio.h>
#define N 50
void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);
int main(){
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", (arr + i));
    }
    insertion_sort(arr, N);
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1){
            printf("%d", *(arr + i));
        }
        else{
            printf("%d,", *(arr + i));
        }
        
    }
    printf("\n");
    return 0;
}