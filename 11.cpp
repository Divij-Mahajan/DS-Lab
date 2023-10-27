//11. Quick sort
#include <iostream>
using namespace std;

int partitionArray(int input[], int start, int end){
	int pivot=start;

	while(start<end){
		while(input[start]<=input[pivot]){
			start++;
		}
		while(input[end]>input[pivot]){
			end--;
		}
		if(start<end){
			int temp=input[start];
			input[start]=input[end];
			input[end]=temp;
		}
	}
	int temp=input[end];
	input[end]=input[pivot];
	input[pivot]=temp;
	return end; 
}

void quickSort(int input[], int start, int end) {
	if(start<end){
		int p=partitionArray(input,start,end);
		quickSort(input,p+1,end);
		quickSort(input,start,p-1);
	}
}
int main(){
    int a[10]={2,3,4,6,2,4,6,3,6,78};
    quickSort(a,0,9);
    for (int i = 0; i <9; i++){
        cout<<a[i]<<", ";
    }
    cout<<a[9]<<endl;
    return 0;
}
