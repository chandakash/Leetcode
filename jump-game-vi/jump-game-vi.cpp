class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
		
        deque<int> dq;
        dq.push_back(nums[0]);
		
        for (int i = 1; i < n; i++) {      // O(n)
            int curMax = dq.front();       // Front at deque has the max score from the last elements
            nums[i] += curMax;
            if (i - k >= 0 && dq.front() == nums[i - k])     // If current max is going out of window of size k, then remove it.
                dq.pop_front();
            while (!dq.empty() && nums[i] > dq.back())       // Remove all smaller elements from deque 
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        return nums[n-1];
    }
};