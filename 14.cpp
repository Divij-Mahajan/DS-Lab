//14. Floor, ceil, peak, minimum in sorted rotated array
#include <iostream>
#include <vector>

using namespace std;

int findFloor(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target) {
            result = nums[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int findCeil(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            result = nums[mid];
            right = mid - 1;
        }
    }

    return result;
}

int findPeak(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            return nums[mid];
        } else if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int findMinimum(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}
vector<int> vec(int a[],int n){
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(a[i]);
    }
    return r;
}

int main() {
    int a[10]={2,3,4,6,2,4,6,3,6,78};
    vector<int> rotatedArray = vec(a,10);
    int target = 5;
    cout << "Floor of " << target << ": " << findFloor(rotatedArray, target) << endl;
    cout << "Ceil of " << target << ": " << findCeil(rotatedArray, target) << endl;
    cout << "Peak element: " << findPeak(rotatedArray) << endl;
    cout << "Minimum element: " << findMinimum(rotatedArray) << endl;

    return 0;
}
