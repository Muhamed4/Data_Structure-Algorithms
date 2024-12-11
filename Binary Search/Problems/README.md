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



* [ ] [Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                long long convert(long long mid) {
                    string cur = to_string(mid);
                    int l = 0, r = cur.size() - 1;
                    while(l <= r)
                        cur[r--] = cur[l++];
                    return stol(cur);
                }
                long long prevPal(long long x) {
                    long long left = 0, right = x - 1, res = -1;
                    while(left <= right) {
                        long long mid = left + (right - left) / 2;
                        long long cur = convert(mid);
                        if(cur < x) {
                            res = cur;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                    }
                    return res;
                }

                long long nextPal(long long x) {
                    long long left = x + 1, right = LONG_MAX, res = -1;
                    while(left <= right) {
                        long long mid = left + (right - left) / 2;
                        long long cur = convert(mid);
                        if(cur > x) {
                            res = cur;
                            right = mid - 1;
                        }
                        else left = mid + 1;
                    }
                    return res;
                }
            public:
                string nearestPalindromic(string n) {
                    long long x = stol(n);
                    long long prev = prevPal(x);
                    long long next = nextPal(x);
                    if((x - prev) > (next - x))
                        prev = next;
                    return to_string(prev);
                }
            };
        
    </details>

---




* [ ] [Heaters](https://leetcode.com/problems/heaters/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool isExist(pair<int, int>& p, vector<int>& heaters) {
                    int n = heaters.size();
                    int left = 0, right = n - 1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        if(heaters[mid] >= p.first && heaters[mid] <= p.second)
                            return true;
                        if(heaters[mid] > p.second)
                            right = mid - 1;
                        else left = mid + 1;
                    }
                    return false;
                }
            public:
                int findRadius(vector<int>& houses, vector<int>& heaters) {
                    int n = houses.size();
                    int left = 0, right = INT_MAX, res = 0;
                    sort(heaters.begin(), heaters.end());
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        bool flag = true;
                        for(int i = 0; i < n;i++) {
                            pair<int, int> p = { houses[i] - mid, houses[i] + mid };
                            flag &= isExist(p, heaters);
                        }
                        if(flag == true) {
                            res = mid;
                            right = mid - 1;
                        }
                        else left = mid + 1;
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int OO = 2000000;
                void change(vector<int>& v) {
                    int n = v.size();
                    v.push_back(-OO);
                    v.push_back(OO);
                    for(int i = n - 1; i >= 0;i--) {
                        swap(v[i + 1], v[i]);
                    }
                }
                int getMid(vector<int>& v1, vector<int>& v2, int n, int m) {
                    int len = (n + m + 1) / 2;
                    int left = 1, right = min(n, len), idx = 0;
                    while(left <= right) {
                        int mid = (left + right) / 2;
                        int rem = len - mid;
                        if(rem > m) left = mid + 1;
                        else if(v1[mid] > v2[rem + 1]) right = mid - 1;
                        else if(v2[rem] > v1[mid + 1]) left = mid + 1;
                        else {
                            idx = mid;
                            break;
                        }
                    }
                    return idx;
                }
            public:
                double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                    int n = nums1.size(), m = nums2.size(), len = (n + m + 1) / 2;
                    change(nums1);
                    change(nums2);
                    double ans = 0;
                    int res = getMid(nums1, nums2, n, m);
                    int rem = len - res;
                    ans = max(nums1[res], nums2[rem]) + 
                            ((n + m) % 2 == 0 ? min(nums1[res + 1], nums2[rem + 1]) : 0);
                    if((n + m) % 2 == 0) ans /= 2.0;
                    return ans;
                }
            };
        
    </details>

---




* [ ] [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int GetPivot(const vector<int>&nums){
                    int n = nums.size();
                    int low = 0, high = n - 1, mid = 0, index = -1;
                    while(low <= high){
                        mid = (low + high) / 2;
                        int nextPos = (mid + 1) % n;
                        int prevPos = (mid - 1 + n) % n;
                        if(nums[mid] > nums[nextPos] && nums[mid] > nums[prevPos]){
                            index = mid;
                            break;
                        }
                        else if(nums[mid] < nums[0]) high = mid - 1;
                        else low = mid + 1;
                    }
                    return index;
                }

                int BinarySearch(const vector<int>&arr, int low, int high, int target){
                    int index = -1;
                    while(low <= high) {
                        int mid = (low + high) / 2;
                        if(arr[mid] == target){
                        index = mid;
                        break;
                        }
                        else if(arr[mid] < target) low = mid + 1;
                        else high = mid - 1;
                    }
                    return index;
                }
            public:
                int search(vector<int>& nums, int target) {
                    int n = nums.size() - 1;
                    int pivot = GetPivot(nums);
                    int ans1 = BinarySearch(nums, 0, pivot, target);
                    int ans2 = BinarySearch(nums, pivot + 1, n, target);
                    return max(ans1, ans2);
                }
            };
        
    </details>

---




* [ ] [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int firstPosition(vector<int>& v, int target){
                    int low = 0, high = v.size() - 1, mid = 0, ans = -1;
                    while(low <= high){
                        mid = (low + high) / 2;
                        if(v[mid] == target){
                            ans = mid;
                            high = mid - 1;
                        }
                        else if(v[mid] > target) high = mid - 1;
                        else low = mid + 1;
                    }
                    return ans;
                }

                int lastPosition(vector<int>& v, int target){
                    int low = 0, high = v.size() - 1, mid = 0, ans = -1;
                    while(low <= high){
                        mid = (low + high) / 2;
                        if(v[mid] == target){
                            ans = mid;
                            low = mid + 1;
                        }
                        else if(v[mid] > target) high = mid - 1;
                        else low = mid + 1;
                    }
                    return ans;
                }
            public:
                vector<int> searchRange(vector<int>& nums, int target) {
                    int first = firstPosition(nums, target);
                    int last = lastPosition(nums, target);
                    vector<int> ans = { first, last };
                    return ans;
                }
            };
        
    </details>

---



* [ ] [Search Insert Position](https://leetcode.com/problems/search-insert-position/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int searchInsert(vector<int>& nums, int target) {
                    int l = 0, r = nums.size() - 1, mid = 0, ans = -1;
                    while(l <= r){
                        mid = (l + r) / 2;
                        if(nums[mid] < target){
                            ans = mid;
                            l = mid + 1;
                        }
                        else r = mid - 1;
                    }
                    return ans + 1;
                }
            };
        
    </details>

---



* [ ] [Sqrt(x)](https://leetcode.com/problems/sqrtx/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int mySqrt(int x) {
                    int low = 0, high = x, mid = 0, ans = -1;
                    while(low <= high){
                        mid = (low + high) / 2;
                        long long res = 1ll*mid * mid;
                        if(res <= x){
                            ans = mid;
                            low = mid + 1;
                        }
                        else high = mid - 1;
                    }
                    return ans;
                }
            };
        
    </details>

---



* [ ] [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int findRow(vector<vector<int>>& v, int targ){
                    int low = 0, high = v.size() - 1, m = v[0].size(), index = -1;
                    while(low <= high){
                        int mid = (low + high) / 2;
                        if(v[mid][0] <= targ && v[mid][m - 1] >= targ){
                            index = mid;
                            break;
                        }
                        else if(v[mid][0] > targ) high = mid - 1;
                        else low = mid + 1;
                    }
                    return index;
                }

                bool findValue(vector<int>& v, int val){
                    int low = 0, high = v.size() - 1;
                    while(low <= high){
                        int mid = (low + high) / 2;
                        if(v[mid] == val) return true;
                        if(v[mid] > val) high = mid - 1;
                        else low = mid + 1;
                    }
                    return false;
                }

                bool findValue(vector<vector<int>>& v, int target){
                    int n = v.size();
                    int m = v[0].size();
                    int low = 0, high = n * m - 1;
                    while(low <= high){
                        int mid = (low + high) / 2;
                        int row = mid / m;
                        int col = mid % m;
                        if(v[row][col] == target) return true;
                        if(v[row][col] > target) high = mid - 1;
                        else low = mid + 1;
                    }
                    return false;
                }
            public:
                bool searchMatrix(vector<vector<int>>& matrix, int target) {
                    return findValue(matrix, target);
                }
            };
        
    </details>

---


* [ ] [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int findMin(vector<int>& nums) {
                    int n = nums.size();
                    int low = 0, high = n - 1, mid = 0, index = -1;
                    while(low <= high){
                        mid = (low + high) / 2;
                        int nextPos = (mid + 1) % n;
                        int prevPos = (mid - 1 + n) % n;
                        if(nums[mid] > nums[nextPos] && nums[mid] > nums[prevPos]){
                            index = mid;
                            break;
                        }
                        else if(nums[mid] < nums[0]) high = mid - 1;
                        else low = mid + 1;
                    }
                    return nums[(index + 1) % n];
                }
            };
        
    </details>

---


* [ ] [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int findMin(vector<int>& v) {
                    int n = v.size();
                    int left = 0, right = n - 1, res = -1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        if(left == right) {
                            if(res == -1 || v[mid] < v[res])
                                res = mid;
                            break;
                        }
                        if(v[left] == v[right]) {
                            left += 1;
                            continue;
                        }
                        if(v[mid] <= v[right] && v[mid] <= v[left]) {
                            if(res == -1 || v[mid] < v[res])
                                res = mid;
                            right = mid - 1;
                        }
                        else if (v[mid] >= v[left] && v[mid] <= v[right]) {
                            if(res == -1 || v[mid] < v[res])
                                res = mid;
                            right = mid - 1;
                        }
                        else if(v[mid] >= v[left] && v[mid] >= v[right]) {
                            left = mid + 1;
                        }
                    }
                    return v[res];
                }
            };
        
    </details>

---


* [ ] [Find Peak Element](https://leetcode.com/problems/find-peak-element/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                long long N = -1e10;
            public:
                int findPeakElement(vector<int>& arr) {
                    int n = arr.size();
                    int low = 0, high = n - 1, mid = 0, ans = -1;
                    while(low <= high){
                        mid = (low + high) / 2;
                        if((arr[mid] > (mid == 0 ? N : arr[mid - 1])) && 
                            (arr[mid] > (mid == (n - 1) ? N : arr[mid + 1]))){
                                ans = mid;
                                break;
                            }
                        else if(arr[mid] < arr[mid + 1]) low = mid + 1;
                        else high = mid - 1;
                    }
                    return ans;
                }
            };

            /*

                5 1 2 6 4 5 4 3 2 1

                1- if arr[mid] < ar[mid + 1] && arr[mid] > arr[mid - 1];
                    bin(mid + 1, high);

                2- if arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1]
                    bin(mid + 1, high);

                3- if arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1];
                    return mid;


                time complexity ---> O(log N);
                space complexity ---> O(1);
            */
        
    </details>

---


* [ ] [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> twoSum(vector<int>& numbers, int target) {
                    int low = 0, high = numbers.size() - 1, sum = 0;
                    vector<int> ans;
                    while(low < high){
                        sum = numbers[low] + numbers[high];
                        if(sum == target){
                            ans = { low + 1, high + 1 };
                            break;
                        }
                        else if(sum > target) high--;
                        else low++;
                    }
                    return ans;
                }
            };
        
    </details>

---


* [ ] [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool Check(vector<int>& v, int slide, int target){
                    int sum = 0, n = v.size(), idx = 0;
                    for(int i = 0; i < n;i++){
                        sum += v[i];
                        if(i >= (slide - 1)){
                            if(i >= slide) {
                                sum -= v[idx];
                                ++idx;
                            }
                            if(sum >= target) return true;
                        }
                    }
                    return false;
                }
            public:
                int minSubArrayLen(int target, vector<int>& nums) {
                    int low = 1, high = nums.size(), n = nums.size(), ans = 0;
                    while(low <= high){
                        int mid = (low + high) / 2;
                        bool can = Check(nums, mid, target);
                        if(can) {
                            ans = mid;
                            high = mid - 1;
                        }
                        else low = mid + 1;
                    }
                    return ans;
                }
            };
        
    </details>

---


* [ ] [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
            * Definition for a binary tree node.
            * struct TreeNode {
            *     int val;
            *     TreeNode *left;
            *     TreeNode *right;
            *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
            *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            * };
            */
            class Solution {
                int getLevel(TreeNode* root){
                    if(root == nullptr)
                        return 0;
                    int ret = getLevel(root->left) + 1;
                    return ret;
                }

                vector<int> direction(int n){
                    vector<int>dir;
                    while(n > 1){
                        dir.push_back(n % 2);
                        n /= 2;
                    }
                    reverse(dir.begin(), dir.end());
                    return dir;
                }

                bool Check(TreeNode* root, int idx, int n, vector<int>& dir){
                    if(root == nullptr) return false;
                    if(idx == n) return true;
                    bool flag = false;
                    if(dir[idx] == 0) flag |= Check(root->left, idx + 1, n, dir);
                    else flag |= Check(root->right, idx + 1, n, dir);
                    return flag;
                }
            public:
                int countNodes(TreeNode* root) {
                    if(root == nullptr) return 0;
                    int level = getLevel(root);
                    int low = 1, high = (1 << level) - 1, ans = 0;
                    int st = (1 << (level - 1)), end = (1 << level) - 1;
                    while(st <= end){
                        int mid = (st + end) / 2;
                        vector<int> dir = direction(mid);
                        bool flag = Check(root, 0, dir.size(), dir);
                        if(flag) {
                            ans = mid;
                            st = mid + 1;
                        }
                        else end = mid - 1;
                    }
                    return ans;
                }
            };
        
    </details>

---


* [ ] [1493. Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool can(int mid, int n, vector<int>& v) {
                    int sum = v[mid - 1];
                    if(sum >= mid - 1) return true;
                    for(int i = mid; i < n;i++) {
                        sum = v[i] - v[i - mid];
                        if(sum >= mid - 1) return true;
                    }
                    return false;
                }
            public:
                int longestSubarray(vector<int>& nums) {
                    int n = nums.size();
                    for(int i = 1; i < n;i++) nums[i] += nums[i - 1];
                    int left = 1, right = n, res = 0;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        bool flag = can(mid, n, nums);
                        if(flag == true) {
                            res = mid - 1;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                    }
                    return res;
                }
            };
        
    </details>

---


* [ ] [Find a Value of a Mysterious Function Closest to Target](https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void buildBits(int n, vector<vector<int>>& bitPrefix, vector<int> arr) {
                    for(int i = 0; i < n;i++) {
                        int idx = 0;
                        while(arr[i] > 0) {
                            bitPrefix[i][idx] = (arr[i] & 1);
                            arr[i] >>= 1;
                            idx += 1;
                        }
                    }

                    for(int i = 0; i < 30;i++) {
                        for(int j = 1; j < n;j++)
                            bitPrefix[j][i] += bitPrefix[j - 1][i];
                    }
                }

                int getClosestNumLessThanOrEqualTarget(vector<vector<int>>& bitPrefix, int n, int target) {
                    int mnAND = -1E9;
                    for(int i = 0; i < n;i++) {
                        int left = i, right = n - 1, res = -1E9;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int cur = 0, len = mid - i + 1;
                            for(int j = 0; j < 30;j++) {
                                int sum = bitPrefix[mid][j] - (i == 0 ? 0 : bitPrefix[i - 1][j]);
                                if(len == sum)
                                    cur |= (1 << j);
                            }
                            if(cur <= target) {
                                res = cur;
                                right = mid - 1;
                            }
                            else left = mid + 1;
                        }
                        mnAND = max(mnAND, res);
                    }
                    return mnAND;
                }

                int getClosestNumGreaterThanOrEqualTarget(vector<vector<int>>& bitPrefix, int n, int target) {
                    int mxAND = 1E9;
                    for(int i = 0; i < n;i++) {
                        int left = i, right = n - 1, res = 1E9;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int cur = 0, len = mid - i + 1;
                            for(int j = 0; j < 30;j++) {
                                int sum = bitPrefix[mid][j] - (i == 0 ? 0 : bitPrefix[i - 1][j]);
                                if(len == sum)
                                    cur |= (1 << j);
                            }
                            if(cur >= target) {
                                res = cur;
                                left = mid + 1;
                            }
                            else right = mid - 1;
                        }
                        mxAND = min(mxAND, res);
                    }
                    return mxAND;
                }
            public:
                int closestToTarget(vector<int>& arr, int target) {
                    int n = arr.size();
                    int mnAND = -1E9, mxAND = 1E9;
                    vector<vector<int>> bitPrefix(n, vector<int>(30));
                    buildBits(n, bitPrefix, arr);
                    int mnValue = getClosestNumLessThanOrEqualTarget(bitPrefix, n, target);
                    int mxValue = getClosestNumGreaterThanOrEqualTarget(bitPrefix, n, target);
                    int closest = min(mxValue - target, target - mnValue);
                    return closest;
                }
            };

            /*

                011 --> 3 
                101 --> 5
                111 --> 7
                1000 --> 8
                1001 --> 9

                when applying AND for (x & y) the number will be less than or equal to the minimum between them

            */
        
    </details>

---


* [ ] [Last Day Where You Can Still Cross](https://leetcode.com/problems/last-day-where-you-can-still-cross/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dx[4] = {0, 1, 0, -1};
                int dy[4] = {1, 0, -1, 0};
                bool isValid(int i, int j, int n, int m) {
                    return (i >= 0 && i < n && j >= 0 && j < m);
                }

                bool dfs(int i, int j, int n, int m, vector<vector<bool>>& grid, vector<vector<int>>& dp) {
                    if(isValid(i, j, n, m) == false || grid[i][j] == true) return false;
                    if(i == n - 1) return true;
                    int& ret = dp[i][j];
                    if(~ret) return ret;
                    ret = false;
                    for(int k = 0; k < 4;k++) {
                        int newI = i + dx[k];
                        int newJ = j + dy[k];
                        ret |= dfs(newI, newJ, n, m, grid, dp);
                    }
                    return ret;
                }
            public:
                int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
                    int n = cells.size();
                    vector<vector<bool>> grid(row, vector<bool>(col, false));
                    int left = 0, right = n - 1, res = -1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        for(int i = 0; i <= mid;i++)
                            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
                        bool canReach = false;
                        vector<vector<int>> dp(row, vector<int>(col, -1));
                        for(int i = 0; i < col;i++)
                            canReach |= dfs(0, i, row, col, grid, dp);
                        if(mid == 2) cout << canReach << endl;
                        if(canReach == true) {
                            res = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                        for(int i = 0; i <= mid;i++)
                            grid[cells[i][0] - 1][cells[i][1] - 1] = false;
                    }
                    return res + 1;
                }
            };
        
    </details>

---




* [ ] [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void findLongestIncreasingSub(vector<int>& nums, vector<int>& lis, vector<int>& finlList, int dir, int start, int end) {
                    for(int i = start; i != end; i += dir) {
                        if(lis.empty()) lis.push_back(nums[i]);
                        else {
                            int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                            if(idx == lis.size()) lis.push_back(nums[i]);
                            else lis[idx] = nums[i];
                        }
                        finlList[i] = lis.size();
                    }
                }
            public:
                int minimumMountainRemovals(vector<int>& nums) {
                    int n = nums.size(), res = 0;
                    vector<int> lis1, lis2;
                    vector<int> start(n), end(n);
                    findLongestIncreasingSub(nums, lis1, start, 1, 0, n - 1);
                    findLongestIncreasingSub(nums, lis2, end, -1, n - 1, 0);
                    for(int i = 1; i < n - 1;i++) {
                        int len = 0;
                        if(start[i] >= 2 && end[i] >= 2)
                            len = start[i] + end[i] - 1;
                        res = max(res, len);
                    }
                    return n - res;
                }
            };
        
    </details>

---


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




* [ ] [Most Beautiful Item for Each Query](https://leetcode.com/problems/most-beautiful-item-for-each-query/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
                    int q = queries.size(), n = items.size(), mx = 0;
                    vector<int> res;
                    sort(items.begin(), items.end());
                    for(int i = 0; i < n;i++) {
                        mx = max(mx, items[i][1]);
                        items[i][1] = mx;
                    }
                    for(auto &q: queries) {
                        int left = 0, right = n - 1, ans = 0;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            if(items[mid][0] <= q) {
                                ans = items[mid][1];
                                left = mid + 1;
                            }
                            else right = mid - 1;
                        }
                        res.push_back(ans);
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int lowerIndex(int i, int n, int lower, int upper, vector<int>& arr) {
                    int left = i + 1, right = n - 1, res = 1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        if(arr[i] + arr[mid] >= lower && arr[i] + arr[mid] <= upper) {
                            res = mid;
                            right = mid - 1;
                        }
                        else if(arr[i] + arr[mid] < lower) left = mid + 1;
                        else if(arr[i] + arr[mid] > upper) right = mid - 1;
                    }
                    return res;
                }
                
                int upperIndex(int i, int n, int lower, int upper, vector<int>& arr) {
                    int left = i + 1, right = n - 1, res = 0;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        if(arr[i] + arr[mid] <= upper && arr[i] + arr[mid] >= lower) {
                            res = mid;
                            left = mid + 1;
                        }
                        else if(arr[i] + arr[mid] < lower) left = mid + 1;
                        else if(arr[i] + arr[mid] > upper) right = mid - 1;
                    }
                    return res;
                }
            public:
                long long countFairPairs(vector<int>& nums, int lower, int upper) {
                    int n = nums.size();
                    long long res = 0;
                    sort(nums.begin(), nums.end());
                    for(int i = 0; i < n;i++) {
                        int lowerIdx = lowerIndex(i, n, lower, upper, nums);
                        int upperIdx = upperIndex(i, n, lower, upper, nums);
                        res += (upperIdx - lowerIdx + 1);
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int minimizedMaximum(int n, vector<int>& quantities) {
                    int m = quantities.size();
                    int left = 1, right = 100000, ans = 0;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        int stores = 0;
                        for(int i = 0; i < m;i++) {
                            stores += (quantities[i] / mid);
                            stores += (quantities[i] % mid != 0);
                        }
                        if(stores <= n) {
                            ans = mid;
                            right = mid - 1;
                        }
                        else left = mid + 1;
                    }
                    return ans;
                }
            };
        
    </details>

---




* [ ] [Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int minimumSize(vector<int>& nums, int maxOperations) {
                    int n = nums.size();
                    int left = 1, right = 1E9, res = -1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        int cnt = 0;
                        for(int i = 0; i < n;i++) {
                            int divide = nums[i] / mid;
                            divide += (nums[i] % mid != 0);
                            cnt += (divide - 1);
                        }
                        if(cnt <= maxOperations) {
                            res = mid;
                            right = mid - 1;
                        } else left = mid + 1;
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maxTwoEvents(vector<vector<int>>& events) {
                    int n = events.size(), prevMax = INT_MIN, res = 0;
                    vector<int> maxValue(n);
                    sort(events.begin(), events.end());
                    for(int i = n - 1; i >= 0;i--) {
                        prevMax = max(prevMax, events[i][2]);
                        maxValue[i] = prevMax;
                    }
                    for(int i = 0; i < n;i++) {
                        int left = i + 1, right = n - 1, ans = 0, end = events[i][1];
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int start = events[mid][0];
                            if(start > end) {
                                ans = maxValue[mid];
                                right = mid - 1;
                            }
                            else left = mid + 1;
                        }
                        res = max(res, events[i][2] + ans);
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Special Array II](https://leetcode.com/problems/special-array-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
                    int n = nums.size(), q = queries.size();
                    vector<bool> res;
                    vector<pair<int, int>> parity;
                    for(int i = 0; i < n - 1;i++) {
                        if((nums[i] & 1) == (nums[i + 1] & 1))
                            parity.push_back({i, i + 1});
                    }
                    for(int i = 0; i < q;i++) {
                        bool correct = true;
                        int idx = lower_bound(parity.begin(), parity.end(), make_pair(queries[i][0], queries[i][0])) - parity.begin();
                        if(idx != parity.size()) {
                            if(parity[idx].first >= queries[i][0] && parity[idx].second <= queries[i][1])
                                correct = false;
                        }
                        res.push_back(correct);
                    }
                    return res;
                }
            };
        
    </details>

---





* [ ] [Find Longest Special Substring That Occurs Thrice I](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool isCan(string& s, int mid, int n) {
                    bool can = false;
                    set<char> distinctChar;
                    unordered_map<char, int> frq, strFrq;
                    for(int i = 0; i < mid;i++) {
                        frq[s[i]] += 1;
                        distinctChar.insert(s[i]);
                    }
                    if(distinctChar.size() == 1)
                        strFrq[s[0]] += 1;
                    for(int i = mid; i < n;i++) {
                        frq[s[i - mid]] -= 1;
                        if(frq[s[i - mid]] == 0)
                            distinctChar.erase(s[i - mid]);
                        frq[s[i]] += 1;
                        distinctChar.insert(s[i]);
                        if(distinctChar.size() == 1)
                            strFrq[s[i]] += 1;
                        if(strFrq[s[i]] >= 3)
                            can = true;
                    }
                    return can;
                }
            public:
                int maximumLength(string s) {
                    int n = s.size();
                    int left = 1, right = n, res = -1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        bool can = isCan(s, mid, n);
                        if(can == true) {
                            res = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                    }
                    return res;
                }
            };
        
    </details>

---





* [ ] [Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maximumBeauty(vector<int>& nums, int k) {
                    int n = nums.size(), res = 0;
                    sort(nums.begin(), nums.end());
                    for(int i = 0; i < n;i++) {
                        int last = nums[i] + 2 * k;
                        int idx = upper_bound(nums.begin(), nums.end(), last) - nums.begin();
                        res = max(res, idx - i);
                    }
                    return res;
                }
            };
        
    </details>

---