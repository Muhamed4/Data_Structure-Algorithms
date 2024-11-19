* [ ] [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                long long maximumSubarraySum(vector<int>& nums, int k) {
                    int n = nums.size();
                    long long sum = 0, res = 0;
                    set<int> distinct;
                    unordered_map<int, int> frq;
                    for(int end = 0, start = 0; end < n;end++) {
                        sum += nums[end];
                        distinct.insert(nums[end]);
                        frq[nums[end]] += 1;
                        while(start < end && (distinct.size() < (end - start + 1) || distinct.size() > k)) {
                            frq[nums[start]] -= 1;
                            if(frq[nums[start]] == 0)
                                distinct.erase(nums[start]);
                            sum -= nums[start];
                            start += 1;
                        }
                        int len = end - start + 1;
                        if(len == k)
                            res = max(res, sum);
                    }
                    return res;
                }
            };
        
    </details>

---