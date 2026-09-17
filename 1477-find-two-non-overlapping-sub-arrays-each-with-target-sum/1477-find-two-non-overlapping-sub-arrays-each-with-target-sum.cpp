

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] will store the minimum length of a valid subarray in arr[0...i]
        std::vector<int> min_len(n, 1e9); 
        
        int left = 0;
        int current_sum = 0;
        int result = 1e9;
        int current_min_len = 1e9;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            // Shrink the window from the left if the sum exceeds the target
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

            // If a valid subarray is found ending at 'right' and starting at 'left'
            if (current_sum == target) {
                int len = right - left + 1;

                // Check if a valid non-overlapping subarray exists before 'left'
                if (left > 0 && min_len[left - 1] != 1e9) {
                    result = std::min(result, len + min_len[left - 1]);
                }

                // Update the minimum length seen up to the current right pointer
                current_min_len = std::min(current_min_len, len);
            }

            // Record the minimum length available up to index 'right'
            min_len[right] = current_min_len;
        }

        return result >= 1e9 ? -1 : result;
    }
};
