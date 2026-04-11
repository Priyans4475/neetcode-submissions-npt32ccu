class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int tempMax = maxi;
            int tempMin = mini;

            maxi = max(nums[i], max(nums[i] * tempMax, nums[i] * tempMin));
            mini = min(nums[i], min(nums[i] * tempMax, nums[i] * tempMin));

            ans = max(ans, maxi);
        }

        return ans;
    }
};