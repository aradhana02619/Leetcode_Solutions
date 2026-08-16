#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        
        vector<int> count(3, 0);
        for (int stone : stones) {
            count[stone % 3]++;
        }
    
        if (count[0] % 2 == 0) {
            return std::min(count[1], count[2]) > 0;
        }
    
        return std::abs(count[1] - count[2]) > 2;
    }
};
