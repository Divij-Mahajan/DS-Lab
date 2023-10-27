//10. Insertion sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main(){
    int a[10]={2,3,4,6,2,4,6,3,6,78};
    insertionSort(a,10);
    for (int i = 0; i <9; i++){
        cout<<a[i]<<", ";
    }
    cout<<a[9]<<endl;
    return 0;
}
