class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int min_height = INT_MAX;
        int water = 0;
        while(i<j)
        {
            min_height = min(height[i],height[j]);
            water = max(water, min_height*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
    return water;
    }
};