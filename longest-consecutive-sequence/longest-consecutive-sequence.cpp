class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(auto x : nums)
            hashSet.insert(x);
        
        int longestStreak = 0;
        for(int x : nums)
        {
            if(!hashSet.count(x-1))
            {
                int currNum = x;
                int currStreak = 1;
                
                while(hashSet.count(currNum+1))
                {
                    currNum++;
                    currStreak++;
                }
            longestStreak = max(longestStreak, currStreak);
            }
        }
    return longestStreak;
    }
};