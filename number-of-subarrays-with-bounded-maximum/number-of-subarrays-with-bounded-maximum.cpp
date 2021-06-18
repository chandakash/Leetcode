// Brief Explanation:
// There are three cases:

// The current number is greater than right - there are no new subarrays to add to res. We just update prev_bigger_than_r = current index.
// The current number is smaller than left - we can add the new number to all valid previous subarrays which end here so far. But the current number can't form it's own valid subarray.
// The current number is between right and left. In this case we add the new number to all valid previous subarrays which end here so far and the number itself can form a valid subarray too.
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        int prev_bigger_than_r = -1;
        int count_prev = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                prev_bigger_than_r = i;
                count_prev = 0;
            }
            
            else if (nums[i] < left) {
                res += count_prev;
            }
            
            else {
                count_prev = i - prev_bigger_than_r;
                res += count_prev;
                
            }
        }
        return res;
    }
};