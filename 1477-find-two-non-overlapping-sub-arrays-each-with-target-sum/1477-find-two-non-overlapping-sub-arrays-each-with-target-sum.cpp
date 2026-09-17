class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
    
        vector<int> min_len(n, 1e9); 
        
        int left = 0;
        int current_sum = 0;
        int result = 1e9;
        int current_min_len = 1e9;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

            
            if (current_sum == target) {
                int len = right - left + 1;


                if (left > 0 && min_len[left - 1] != 1e9) {
                    result = min(result, len + min_len[left - 1]);
                }
                current_min_len = min(current_min_len, len);
            }

            min_len[right] = current_min_len;
        }

        return result >= 1e9 ? -1 : result;
    }
};
