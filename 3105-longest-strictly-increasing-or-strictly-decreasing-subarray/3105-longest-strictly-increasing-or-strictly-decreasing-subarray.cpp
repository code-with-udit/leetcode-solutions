
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                bool inc = true, dec = true;
                for(int k = i + 1; k <= j; k++) {
                    if(nums[k] <= nums[k-1])
                        inc = false;

                    if(nums[k] >= nums[k-1])
                        dec = false;
                }
                if(inc || dec) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
