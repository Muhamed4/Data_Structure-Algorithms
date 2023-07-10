class Solution {
public:
    string intToRoman(int num) {

        unordered_map<int,string>hash;
        hash[1] = "I"; hash[5] = "V"; hash[10] = "X"; hash[50] = "L"; 
        hash[100] = "C"; hash[500] = "D"; hash[1000] = "M"; hash[4] = "IV";
        hash[9] = "IX"; hash[40] = "XL"; hash[90] = "XC"; hash[400] = "CD"; hash[900] = "CM";
        vector<int> values{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        string ans = "";

        int idx = 12;
        while(num){
            int cnt = num / values[idx];
            num %= values[idx];
            while(cnt--){
                ans += hash[values[idx]];
            }
            --idx;
        }
        return ans;
    }
};