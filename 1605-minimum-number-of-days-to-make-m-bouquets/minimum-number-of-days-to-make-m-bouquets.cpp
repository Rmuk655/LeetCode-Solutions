class Solution {
public:
    bool feasible(int mid, vector<int>& bloomDay, int m, int k){
        int no = 0, x = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            int temp = bloomDay[i];
            if(temp > mid){
                no += x / k;
                x = 0;
            }
            else{
                x++;
            }
        }
        if(no < m){
            return false;
        }
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); 
        if(m > n / k){
            return -1;
        }
        int maxi = bloomDay[0];
        for(int x: bloomDay){
            maxi = max(maxi, x);
        }
        int l = 1, r = maxi, ans = -1;
        bloomDay.push_back(INT_MAX);
        while(l <= r){
            int mid = (l + r) / 2;
            if(feasible(mid, bloomDay, m, k)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};