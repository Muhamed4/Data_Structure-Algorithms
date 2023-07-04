class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;

        int hashTable[26]{0};
        int _size = (int)s.size();
        for(int i = 0; i < _size;i++){
            // The way that we hash the strings :).
            hashTable[s[i] - 'a']++;
            hashTable[t[i] - 'a']--;
        }
        for(int i = 0 ;i < 26;i++){
            if(hashTable[i] != 0)return false;
        }
        return true;
    }
};