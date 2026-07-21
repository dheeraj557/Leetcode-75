class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxval = -1;
        for(int i:candies)
        {
            maxval = max(i,maxval);
        }
        vector<bool>ans;
        for(int i:candies)
        {
            if(i+extraCandies>=maxval)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};