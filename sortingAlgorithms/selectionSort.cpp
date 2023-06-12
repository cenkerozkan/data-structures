#include <iostream>
void selection_sort(int *arr, int n){
    int i,j,min,temp;
    for(i=0; i<n-1; i++){
        // Symbolic minimum starts from beginning.
        min = i;
        for(j=i+1; j<n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main(void){
    int list[] = {2,8,5,3,9,4,2};
    for(int i=0; i<7; i++){
        std::cout << list[i] << " ";
    }

    std::cout << "\n";
    selection_sort(list,7);
    for(int i=0; i<7; i++){
        std::cout << list[i] << " ";
    }
    return 0;
}