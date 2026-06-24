class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(mp[nums[i]] >= 2){
                ans = nums[i];
            }
        }
        return ans;
    }
};