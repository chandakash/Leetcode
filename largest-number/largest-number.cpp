class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end(),[](int &n1, int &n2){
            string s1 = to_string(n1);
            string s2 = to_string(n2);
            
            return s1+s2 > s2+s1;
        });
        
        string ans = "";
        for(auto x : nums){
            ans+=to_string(x);
        }
        if(nums[0]==0) return "0";
        return ans;
    }
};