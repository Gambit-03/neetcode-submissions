class Solution {
    vector<bool> used;
    int target;

   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if (sum % k != 0) return false;

        target = sum / k;
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        return backtrack(nums, k, 0, 0);
    }

   private:
    bool backtrack(vector<int>& nums, int k, int currentsum, int start) {
        if (k == 0) return true;
        if (currentsum == target) return backtrack(nums, k - 1, 0, 0);

        for (int i = start; i < nums.size(); i++) {
            if (used[i] || currentsum + nums[i] > target) continue;
            used[i] = true;
            if (backtrack(nums, k, currentsum + nums[i], i + 1)) return true;
            used[i] = false;
        }
        return false;
    }
};
