class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int current_height = min(height[left], height[right]);
            int current_width = right - left;
            max_water = max(max_water, current_height * current_width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};