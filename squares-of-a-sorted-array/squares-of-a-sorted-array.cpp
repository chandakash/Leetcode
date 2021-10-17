class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        vector<int> out(n);
        int pos = n-1;// filling from the end.
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                out[pos--] = nums[i]*nums[i];
                i++;
            }
            else{
                out[pos--] = nums[j]*nums[j];
                j--;
            }
        }
    return out;
    }
};