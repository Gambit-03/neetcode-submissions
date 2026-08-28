class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> destination = nums;
        nums.insert(nums.end(), destination.begin(), destination.end());
        return nums;
    }
};