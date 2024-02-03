class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        auto maxElementIter = max_element(candies.begin(), candies.end());
        int mx = *maxElementIter;
        for(int i=0; i<candies.size(); i++) {
            if((candies[i] + extraCandies) >= mx) {
                res.emplace_back(true);
            } 
            else 
                res.emplace_back(false);
        }
        return res;
    }
};