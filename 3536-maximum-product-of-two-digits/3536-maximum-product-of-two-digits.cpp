class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        int rem;
        while(n>0){
            rem = n%10;
            v.push_back(rem);
            n=n/10;
        }
        sort(v.begin(), v.end(), greater<int>());
        int ans=v[0]*v[1];
        return ans;
        
    }
};