class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())return false;

        int hashTable[26]{0}, frq[26]{0};
        int dif = 0, _size = (int)goal.size(), cnt = 0;
        bool flag = false;
        for(int i = 0; i < _size;i++){
            hashTable[s[i] - 'a']++;
            hashTable[goal[i] - 'a']--;
            frq[s[i] - 'a']++;
            if(frq[s[i] - 'a'] > 1)flag = true;
            dif += (s[i] != goal[i]);
        }
        cnt = *max_element(hashTable, hashTable + 26);
        return (cnt == 0 && (dif == 2 || (dif == 0 && flag)));
    }
};