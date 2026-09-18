class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_value =0;
        for(const auto& interval : intervals){
            max_value = max(interval[0], max_value);
        }

        vector<int> mp(max_value + 1,0);
        for(const auto& interval : intervals){
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end+1, mp[start]);
        }

        vector<vector<int>> result;
        int have = -1;
        int intervalStart = -1;
        for(int i = 0;i<mp.size();i++){
            if(mp[i] != 0){
                if(intervalStart == -1) intervalStart = i;
                have = max(mp[i] -1, have);
            }

            if(have == i){
                result.push_back({intervalStart,have});
                have = -1;
                intervalStart = -1;
            }
        }

        if(intervalStart != -1){
            result.push_back({intervalStart,have});
        }

        return result;
    }
};
