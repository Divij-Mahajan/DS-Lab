//37. Rotten oranges
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int> >& grid) {
        int min=0,last=0;
        int m=grid.size(),n=grid[0].size();
            
        while(true){
            int k=0,x=0;  
            vector<pair<int,int> > temp;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==2){
                        k++;
                        if(i>0&&grid[i-1][j]==1){
                            pair<int,int> p;
                            p.first=i-1;
                            p.second=j;
                            temp.push_back(p);
                        }
                        if(j>0&&grid[i][j-1]==1){
                            pair<int,int> p;
                            p.first=i;
                            p.second=j-1;
                            temp.push_back(p);
                           
                        }
                        if(i<m-1&&grid[i+1][j]==1){
                            pair<int,int> p;
                            p.first=i+1;
                            p.second=j;
                            temp.push_back(p);
                           
                        }
                        if(j<n-1&&grid[i][j+1]==1){
                            pair<int,int> p;
                            p.first=i;
                            p.second=j+1;
                            temp.push_back(p);
                        }
                    }
                    if(grid[i][j]==1){
                        x++;
                    }

                }
            }
            for(int i=0;i<temp.size();i++){
                grid[temp[i].first][temp[i].second]=2;
            }
            if(last==k){
                if(min!=0)min--;
                if(x!=0)min=-1;
                break;
            }else{
                last=k;
            }
            min++;
        }
       
        return min;
    }
};
vector<vector<int> > create(int a[3][3]){
    vector<vector<int> > v;
    for (int i = 0; i < 3; i++){
        vector<int> vi;
        for (int j = 0; j < 3; j++){
            vi.push_back(a[i][j]);
        }
        v.push_back(vi);
    }
    return v;
}
int main(){
    Solution S;
    int a[3][3]={{2,1,1},{1,1,0},{0,1,1}};
    int b[3][3]={{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int> > v1=create(a);
    vector<vector<int> > v2=create(b);
    
    cout<<S.orangesRotting(v1)<<endl;//4
    cout<<S.orangesRotting(v2)<<endl;//-1
}