class Solution {
public:
    set<vector<int>> res;

    void help(int ind, vector<int>& nums, int target, vector<int>& ans) {
        if (target == 0) {
            res.insert(ans);
            return;
        }

        if (ind >= nums.size() || target < 0) return;

        // Take current element
        ans.push_back(nums[ind]);
        help(ind + 1, nums, target - nums[ind], ans);
        ans.pop_back();

        // Skip all duplicates of current element in NOT TAKE case
        int next = ind + 1;
        while (next < nums.size() && nums[next] == nums[ind]) {
            next++;
        }

        // Not take current element
        help(next, nums, target, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        res.clear(); // important
        sort(nums.begin(), nums.end()); // very important

        vector<int> ans;
        help(0, nums, target, ans);

        vector<vector<int>> temp;
        for (auto it : res) {
            temp.push_back(it);
        }
        return temp;
    }
};