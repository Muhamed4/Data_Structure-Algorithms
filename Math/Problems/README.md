* [ ] [Prime Subtraction Operation](https://leetcode.com/problems/prime-subtraction-operation/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int N = 1003;
                bool prime[1003];
                vector<int>  sieve() {
                    vector<int> primes;
                    for (int i = 0; i < N; i++){
                        prime[i] = 1;
                    }
                    prime[0] = prime[1] = 0;
                    for (int i = 2; i < N; i++){
                        if (prime[i]){
                            for (int j = i * 2; j < N; j += i){
                                prime[j] = 0;
                            }
                        }
                    }
                    for(int i = 2; i < N;i++)
                        if(prime[i] == true)
                            primes.push_back(i);
                    return primes;
                }
            public:
                bool primeSubOperation(vector<int>& nums) {
                    int n = nums.size(), prev = 0;
                    vector<int> primes = sieve();
                    int sz = primes.size();
                    for(auto &it: nums) {
                        int next = prev + 1, maxPrime = 0;
                        int left = 0, right = sz - 1;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int cur = next + primes[mid];
                            if(cur <= it) {
                                maxPrime = primes[mid];
                                left = mid + 1;
                            }
                            else right = mid - 1;
                        }
                        int newIt = it - maxPrime;
                        if(newIt <= prev) return false;
                        prev = newIt;
                    }
                    return true;
                }
            };
        
    </details>

---