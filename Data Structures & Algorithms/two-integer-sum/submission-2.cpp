class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        vector<vector<int>> eleIndex;
        for (int i = 0; i < nums.size(); i++) {
            eleIndex.push_back({nums[i], i});
        }

        sort(eleIndex.begin(), eleIndex.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = eleIndex[left][0] + eleIndex[right][0];
            if (sum == target) {
                int idx1 = eleIndex[left][1];
                int idx2 = eleIndex[right][1];
                ans.push_back(min(idx1, idx2));
                ans.push_back(max(idx1, idx2));
                return ans;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};