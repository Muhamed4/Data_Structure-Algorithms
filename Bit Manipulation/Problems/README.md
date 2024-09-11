

* [ ] [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int countBits(int n) {
                    int cnt = 0;
                    while(n) {
                        n &= (n - 1);
                        cnt += 1;
                    }
                    return cnt;
                }
            public:
                int minBitFlips(int start, int goal) {
                    int _xor = (start ^ goal);
                    return countBits(_xor);
                }
            };
        
    </details>

---