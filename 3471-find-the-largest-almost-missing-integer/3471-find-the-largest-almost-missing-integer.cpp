class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
    
        if (k == 1) {
            int maxUnique = -1;
            for (int num : nums) {
                if (counts[num] == 1) {
                    maxUnique = max(maxUnique, num);
                }
            }
            return maxUnique;
        }

        int firstElement = nums.front();
        int lastElement = nums.back();
        int ans = -1;
        
        if (counts[firstElement] == 1) {
            ans = max(ans, firstElement);
        }
        if (counts[lastElement] == 1) {
            ans = max(ans, lastElement);
        }
        
        return ans;
    }
};