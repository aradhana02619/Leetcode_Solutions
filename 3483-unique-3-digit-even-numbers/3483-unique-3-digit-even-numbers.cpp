class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int totalUniqueEvenNumbers = 0;
    
        for (int num = 100; num <= 998; num += 2) {
            int c = num / 100;          
            int b = (num / 10) % 10;     
            int a = num % 10;            
            
            
            vector<int> current_needed(10, 0);
            current_needed[c]++;
            current_needed[b]++;
            current_needed[a]++;
        
            if (count[c] >= current_needed[c] && 
                count[b] >= current_needed[b] && 
                count[a] >= current_needed[a]) {
                totalUniqueEvenNumbers++;
            }
        }
        
        return totalUniqueEvenNumbers;
    
    }
};