//9. Selection sort
#include <iostream>
using namespace std;
void selectionSort(int arr[],int n) {
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }   
        int x;
        x=arr[i];
        arr[i]=arr[min];
        arr[min]=x;
    }
}

int main(){
    int a[10]={2,3,4,6,2,4,6,3,6,78};
    selectionSort(a,10);
    for (int i = 0; i <9; i++){
        cout<<a[i]<<", ";
    }
    cout<<a[9]<<endl;
    return 0;
}
