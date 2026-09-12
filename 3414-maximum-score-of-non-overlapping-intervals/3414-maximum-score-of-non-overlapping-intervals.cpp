class Solution {
     struct Interval {
        int start, end, weight, id;
        bool operator<(const Interval& other) const {
            return start < other.start;
        }
    };

    struct Element {
        long long weight = 0;
        vector<int> ids;

        
        bool isBetterThan(const Element& other) const {
            if (weight != other.weight) {
                return weight > other.weight; 
            }
           
            return ids < other.ids;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervalsInput) {
        int n = intervalsInput.size();
        vector<Interval> intervals(n);
        for (int i = 0; i < n; ++i) {
            intervals[i] = {intervalsInput[i][0], intervalsInput[i][1], intervalsInput[i][2], i};
        }
        
        sort(intervals.begin(), intervals.end());
        vector<vector<Element>> dp(n + 1, vector<Element>(5));

        for (int i = n - 1; i >= 0; --i) {
          
            Interval target;
            target.start = intervals[i].end + 1;
            int nextIdx = lower_bound(intervals.begin() + i + 1, intervals.end(), target) - intervals.begin();

            for (int count = 1; count <= 4; ++count) {
               
                Element best = dp[i + 1][count];

                
                Element take = dp[nextIdx][count - 1];
                take.weight += intervals[i].weight;
                take.ids.push_back(intervals[i].id);
                
                sort(take.ids.begin(), take.ids.end()); 

        
                if (take.isBetterThan(best)) {
                    best = take;
                }
                dp[i][count] = best;
            }
        }

        return dp[0][4].ids;
    }
};
