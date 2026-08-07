// class Solution {
// public:
// typedef long long ll;

// string freeSlotsFiller(int required, int length){
//     string str;
//     for(int digit = 9; digit>=2; digit--){
//         while(required%digit==0){
//             str.push_back(digit+'0');
//             required/=digit;
//         }
//     }
//     while(str.length()<length){
//         str.push_back('1');
//     }
//     reverse(begin(str), end(str));
//     return str;
// }
//     string smallestNumber(string num, long long t) {
//         int n= num.length();
        
//         ll temp = t;
//         for(int primeFact : {2,3, 5, 7}){
//             while(temp%primeFact==0){
//                 temp/=primeFact;
//             }
//         }
//         if(temp!=1){
//             return "-1";
//         }
//         vector<ll>remainingFactor(n+1, t);
//         for(int i=0; i<n; i++){
//             int digit = num[i]-'0';
// if(digit==0){
//     break;
// }
//             remainingFactor[i+1]= remainingFactor[i]/gcd(remainingFactor[i], (ll)digit);
//         }
//         if(remainingFactor[n] == 1){
//             return num;
//         }
//         int zeroPos = num.find('0');
//         int zeroIdx = n-1;
//         if(zeroPos != -1){
//             zeroIdx = zeroPos;
//         }
//         for(int i = zeroIdx; i>=0; i--){
//           ll required = remainingFactor[i];
//           int freeSlots = n-1-i;

//           for(int digit=(num[i]-'0'); digit<='9'; digit++){
//             int furtherRequired = required/gcd(required, digit);
//             string requiredNumber = freeSlotsFiller(furtherRequired,freeSlots);

//             if(requiredNumber.length()==freeSlots){
//                 return num.substr(0,i)+(char(digit+'0'))+requiredNumber;
//             }
//           }
//         }
//         return freeSlotsFiller(t, n+1);
//     }
// };


// class Solution {
// public:
//     typedef long long ll;

//     string freeSlotsFiller(ll required, int length) {
//         string str;

//         for (int digit = 9; digit >= 2; digit--) {
//             while (required % digit == 0) {
//                 str.push_back(digit + '0');
//                 required /= digit;
//             }
//         }

//         // required ko completely factor nahi kar paaye
//         if (required != 1) {
//             return "";
//         }

//         while (str.length() < length) {
//             str.push_back('1');
//         }

//         if (str.length() > length) {
//             return "";
//         }

//         reverse(str.begin(), str.end());

//         return str;
//     }

//     string smallestNumber(string num, long long t) {

//         int n = num.length();

//         // Step 1: t should only contain prime factors 2,3,5,7
//         ll temp = t;

//         for (int primeFact : {2, 3, 5, 7}) {
//             while (temp % primeFact == 0) {
//                 temp /= primeFact;
//             }
//         }

//         if (temp != 1) {
//             return "-1";
//         }

//         // Step 2: remainingFactor[i]
//         // = factors of t which are still required
//         vector<ll> remainingFactor(n + 1, t);

//         for (int i = 0; i < n; i++) {

//             int digit = num[i] - '0';

//             if (digit == 0) {
//                 break;
//             }

//             remainingFactor[i + 1] =
//                 remainingFactor[i] /
//                 gcd(remainingFactor[i], (ll)digit);
//         }

//         // Already valid
//         if (remainingFactor[n] == 1) {
//             return num;
//         }

//         // First zero position
//         int zeroPos = num.find('0');

//         int zeroIdx = n - 1;

//         if (zeroPos != string::npos) {
//             zeroIdx = zeroPos;
//         }

//         // Step 3: Try changing digit from right to left
//         for (int i = zeroIdx; i >= 0; i--) {

//             ll required = remainingFactor[i];

//             int freeSlots = n - 1 - i;

//             int currentDigit = num[i] - '0';

//             // We need a STRICTLY bigger digit
//             for (int digit = currentDigit + 1;
//                  digit <= 9;
//                  digit++) {

//                 ll furtherRequired =
//                     required / gcd(required, (ll)digit);

//                 string requiredNumber =
//                     freeSlotsFiller(
//                         furtherRequired,
//                         freeSlots
//                     );

//                 if (requiredNumber.length() == freeSlots) {

//                     return num.substr(0, i)
//                          + char('0' + digit)
//                          + requiredNumber;
//                 }
//             }
//         }

//         // Step 4: If same length answer is impossible,
//         // construct answer of length n+1

//         string ans = freeSlotsFiller(t, n + 1);

//         if (ans.length() == n + 1) {
//             return ans;
//         }

//         return "-1";
//     }
// };
class Solution {
public:
 string smallestNumber(string num, long long t) {
       
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        
        if (temp > 1) return "-1";

        int n = num.length();
        
        
        vector<vector<int>> factors(10, vector<int>(4, 0));
        for (int d = 1; d <= 9; ++d) {
            int val = d;
            while (val % 2 == 0) { factors[d][0]++; val /= 2; }
            while (val % 3 == 0) { factors[d][1]++; val /= 3; }
            while (val % 5 == 0) { factors[d][2]++; val /= 5; }
            while (val % 7 == 0) { factors[d][3]++; val /= 7; }
        }

        
        auto get_min_suffix = [&](int r2, int r3, int r5, int r7) {
            r2 = max(0, r2); r3 = max(0, r3); r5 = max(0, r5); r7 = max(0, r7);
            string suf = "";
           
            while (r7 > 0) { suf += '7'; r7--; }
            
            while (r5 > 0) { suf += '5'; r5--; }

            while (r3 >= 2) { suf += '9'; r3 -= 2; }

            while (r2 >= 3) { suf += '8'; r2 -= 3; }
            
            
            if (r3 == 1 && r2 == 2) { suf += '6'; suf += '2'; r3 = 0; r2 = 0; }
            else if (r3 == 1 && r2 == 1) { suf += '6'; r3 = 0; r2 = 0; }
            else if (r3 == 1 && r2 == 0) { suf += '3'; r3 = 0; }
            else if (r3 == 0 && r2 == 2) { suf += '4'; r2 = 0; }
            else if (r3 == 0 && r2 == 1) { suf += '2'; r2 = 0; }
            
            sort(suf.begin(), suf.end());
            return suf;
        };

        
        vector<int> cur2(n + 1, 0), cur3(n + 1, 0), cur5(n + 1, 0), cur7(n + 1, 0);
        int first_zero = -1;

        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && first_zero == -1) {
                first_zero = i;
            }
            int d = num[i] - '0';
            cur2[i + 1] = cur2[i] + factors[d][0];
            cur3[i + 1] = cur3[i] + factors[d][1];
            cur5[i + 1] = cur5[i] + factors[d][2];
            cur7[i + 1] = cur7[i] + factors[d][3];
        }

        
        if (first_zero == -1 && cur2[n] >= req2 && cur3[n] >= req3 && cur5[n] >= req5 && cur7[n] >= req7) {
            return num;
        }


        int limit = (first_zero != -1) ? first_zero : n - 1;
        for (int i = limit; i >= 0; --i) {
            int start_digit = num[i] - '0' + 1;
            for (int d = start_digit; d <= 9; ++d) {
                int rem2 = req2 - cur2[i] - factors[d][0];
                int rem3 = req3 - cur3[i] - factors[d][1];
                int rem5 = req5 - cur5[i] - factors[d][2];
                int rem7 = req7 - cur7[i] - factors[d][3];

                string min_suf = get_min_suffix(rem2, rem3, rem5, rem7);
                int spaces_left = n - 1 - i;

                if ((int)min_suf.length() <= spaces_left) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    int padded_ones = spaces_left - min_suf.length();
                    ans += string(padded_ones, '1');
                    ans += min_suf;
                    return ans;
                }
            }
        }

        
        string min_suf = get_min_suffix(req2, req3, req5, req7);
        int target_len = max((int)num.length() + 1, (int)min_suf.length());
        string ans = string(target_len - min_suf.length(), '1') + min_suf;
        return ans;
    }
};