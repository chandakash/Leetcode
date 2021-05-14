class Solution {
public:
   bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int jump=nums[0];
        if(jump == 0) return false;
        
         for(int i=1; i<n; i++) 
         {
             jump--;
             if(i==n-1) return true;
             jump = max(jump, nums[i]);
             if(jump==0) return false;
         }
        return false;
        
    }
};