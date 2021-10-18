class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length-1;
        int sum;
        int[] res = new int[2];
        while(left < right){
            sum = numbers[left] + numbers[right];
            if(sum == target){
                res[0] = left+1;
                res[1] = right+1;
                return res;
            }else if(sum > target){
                right--;
            }else
                left++;
        }
    return res;
    }
}