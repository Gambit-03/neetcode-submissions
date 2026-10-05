class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> frequencyMap;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            frequencyMap[nums[i]]++;
        
        if(frequencyMap[nums[i]] > n/2 ){
            return nums[i];
        }
    }
    return -1;
    }
};