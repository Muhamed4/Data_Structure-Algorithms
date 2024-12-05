* [ ] [Move Pieces to Obtain a String](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                bool canChange(string start, string target) {
                    int n = start.size();
                    queue<pair<char, int>> startChar, targetChar;
                    for(int i = 0; i < n;i++) {
                        if(start[i] != '_')
                            startChar.push({start[i], i});
                        if(target[i] != '_')
                            targetChar.push({target[i], i});
                    }
                    if(startChar.size() != targetChar.size()) return false;
                    while(!startChar.empty()) {
                        auto [sCh, sIdx] = startChar.front();
                        auto [tCh, tIdx] = targetChar.front();
                        startChar.pop();
                        targetChar.pop();
                        if(sCh != tCh || (sCh == 'L' && sIdx < tIdx) || (sCh == 'R' && sIdx > tIdx)) 
                            return false;
                    }
                    return true;
                }
            };

        
    </details>

---