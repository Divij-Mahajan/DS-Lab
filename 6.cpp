//6. linear search using switch case

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linear(vector<int> a, int target)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);

    cout << linear(a, 6) << endl;
    cout << linear(a, 7) << endl;

    return 0;
}
