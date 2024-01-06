class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        int i=0, j=len-1;
        while (i + 1 < len && arr[i] < arr[i + 1]) i++;
        while (j > 0 && arr[j - 1] > arr[j]) j--;
        return i > 0 && i == j && j < len - 1;  
        
    }
};