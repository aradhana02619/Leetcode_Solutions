class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            if(m.count(nums[i])){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }
        int ans=0;
        for(pair<int,int>p : m){
            if(p.second>n/2){
                ans=p.first;
            }
        }
      return ans;   
    }
};