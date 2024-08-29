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


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---



* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---


* [ ] []() 
    * <details>
        <summary> Solution </summary>

        ```c++
            
        
    </details>

---