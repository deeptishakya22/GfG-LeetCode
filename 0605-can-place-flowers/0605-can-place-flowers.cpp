class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        int len = flowerbed.size();
        for(int i=0; i<len; i++) {
            if((i==0 || flowerbed[i-1]==0) && flowerbed[i]==0 && (i==len-1 || flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        if(cnt>=n) {
            return true;
        }
        else return false;
    }
};