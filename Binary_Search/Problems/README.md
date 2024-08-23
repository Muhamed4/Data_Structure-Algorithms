# Problems :

* [ ] [Count Pairs Whose Sum is Less than Target](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int countPairs(vector<int>& nums, int target) {
                    int n = nums.size();
                    sort(nums.begin(), nums.end());
                    int cntPairs = 0;
                    for(int i = 0; i < n;i++) {
                        int left = i, right = n - 1, index = i;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            if(nums[i] + nums[mid] < target) {
                                index = mid;
                                left = mid + 1;
                            }
                            else right = mid - 1;
                        }
                        cntPairs += (index - i);
                    }
                    return cntPairs;
                }
            };
        
    </details>

---



* [ ] [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int countNegatives(vector<vector<int>>& grid) {
                    int n = grid.size();
                    int m = grid[0].size();
                    int count = 0;
                    for(int i = 0; i < n;++i) {
                        int left = 0, right = m - 1, index = m;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            if(grid[i][mid] < 0) {
                                index = mid;
                                right = mid - 1;
                            }
                            else left = mid + 1;
                        }
                        count += (m - index);
                    }
                    return count;
                }
            };
        
    </details>

---