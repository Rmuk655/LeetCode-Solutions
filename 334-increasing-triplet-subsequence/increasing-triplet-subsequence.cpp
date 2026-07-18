class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n = nums.size();
        // map<int, vector<int>> mp;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[j] > nums[i]){
        //             mp[i].push_back(j);
        //         }
        //     }
        // }
        // for(auto x: mp){
        //     for(int y: x.second){
        //         if(mp[y].size() > 0){
        //             return true;
        //         }
        //     }
        // }
        int first = INT_MAX, second = INT_MAX;
        for(int x: nums){
            if(x <= first){
                first = x;
            }
            else if(x <= second){
                second = x;
            }
            else{
                return true;
            }
        }
        return false;
    }
};