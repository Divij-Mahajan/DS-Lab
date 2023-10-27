//12. Merge sort
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;     
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid); 
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high); 
}
vector<int> vec(int a[],int n){
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(a[i]);
    }
    return r;
}

int main(){
    int a[10]={2,3,4,6,2,4,6,3,6,78};
    vector<int> v=vec(a,10);
    mergeSort(v,0,9);
    for (int i = 0; i <9; i++){
        cout<<v[i]<<", ";
    }
    cout<<v[9]<<endl;
    return 0;
}
