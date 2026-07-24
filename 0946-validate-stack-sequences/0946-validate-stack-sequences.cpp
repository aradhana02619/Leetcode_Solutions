class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int j = 0;
        for(int x:pushed){
            s.push(x);
            while(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
            
        }
        return s.empty();
    }
};