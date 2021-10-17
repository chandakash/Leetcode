class Solution {
    public void rotateHelper(int[] nums,int i,int j){
        while(i<=j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        if(n==1) return;
        k = k%n;
        
        // first rotate last k elements
        rotateHelper(nums,n-k,n-1);
        // then rotate remaning front elements
        rotateHelper(nums,0,n-k-1);
        // then rotate whole array 
        rotateHelper(nums,0,n-1);
    }
}