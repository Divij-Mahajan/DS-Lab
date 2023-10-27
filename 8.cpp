//8. Bubble sort 
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int x;
                x=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=x;
            }
        }    
    }
}

int main(){
    int a[10]={2,3,4,6,2,4,6,3,6,78};
    bubbleSort(a,10);
    for (int i = 0; i <9; i++){
        cout<<a[i]<<", ";
    }
    cout<<a[9]<<endl;
    return 0;   
}