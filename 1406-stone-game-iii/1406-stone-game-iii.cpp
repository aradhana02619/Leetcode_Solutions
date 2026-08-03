class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int a = 0;
        int b = 0;
        int c = 0;

        for(int i=n-1; i>=0; i--){
            int result = INT_MIN;

            result = max(result, stoneValue[i]-a);

            if(i+2 <= n)
                result=max(result, stoneValue[i] + stoneValue[i+1] - b);
            
            if(i+3 <= n)
               result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - c);
               c=b;
               b=a;
               a=result;
        }
        int diff = a;

        if(diff<0)
          return "Bob";
        else if(diff>0)
           return "Alice";

        return "Tie";
        
    }
};