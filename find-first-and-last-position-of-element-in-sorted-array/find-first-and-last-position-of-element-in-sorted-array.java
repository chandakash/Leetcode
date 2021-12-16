class Solution {
    public int solve(int[] nums, int target, int flag){
        int low = 0;
        int high = nums.length-1;
        int ans = -1;
        
        while(low<=high){
         int mid = (low+high)/2;
            if(nums[mid]<target){
                low = mid +1;
            }else if(nums[mid]>target){
                high = mid -1;
            }else{
                ans = mid;
                if(flag == -1){
                    high = mid+flag;
                }else{
                    low = mid+flag;
                }
            }
        }
                return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        int idx1 = solve(nums,target,-1);// for lower bound;
        int idx2 = solve(nums,target,1); // for upper bound;
        int[] res = new int[2];
        if(idx1 == -1){
           res[0] = -1;
           res[1] = -1;
        }else{
            res[0] = idx1;
            res[1] = idx2;
        }
    return res;
    }
}