class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0;
        int i = 0;
        while(i<n){
        
            if(nums[i]!=0){
                swap(nums[i],nums[low]);
                low++;i++;
            }
            else
                i++;
        }
        
    }
};