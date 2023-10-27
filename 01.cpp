// 1.Take input 2d array : marks in 5 subjects calculate total of every student and average of every subject
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of students :";
    cin>>n;
    int** marks=new int*[n];
    for (int i = 0; i < n; i++){
        marks[i]=new int[5];

        cout<<endl<<"For Student "<<i+1<<endl;
        for (int j = 0; j < 5; j++){
            cout<<"Enter Marks of Subject "<<j+1<<":";
            cin>>marks[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        int s=0;
        for (int j = 0; j < 5; j++){
            s+=marks[i][j];
        }
        cout<<"Total of Student "<<i+1<<" is "<<s<<endl;
        
    }
    for (int j = 0; j < 5; j++){
        int s=0;
        for (int i = 0; i < n; i++){
            s+=marks[i][j];
        }
        cout<<"Average of Subject "<<j+1<<" is "<<s/n<<endl;
        
    }


    return 0;
}