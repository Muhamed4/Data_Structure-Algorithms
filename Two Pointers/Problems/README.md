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



* [ ] [Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int takeCharacters(string s, int k) {
                    int n = s.size(), res = INT_MAX, left = 0, right = n - 1;
                    unordered_map<char, int> frq, minChar;
                    for(auto &ch: s) frq[ch] += 1;
                    if(frq['a'] < k || frq['b'] < k || frq['c'] < k) return -1;
                    while(right >= 0 && (minChar['a'] < k || minChar['b'] < k || minChar['c'] < k))
                        minChar[s[right--]] += 1;
                    right += 1;
                    res = n - right;
                    while(left < n) {
                        minChar[s[left]] += 1;
                        while(right < n) {
                            if(minChar[s[right]] > k)
                                minChar[s[right++]] -= 1;
                            else break;
                        }
                        res = min(res, left + 1 + (n - right));
                        left += 1;
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int countPal(string& s, bool flag = false) {
                    int n = s.size(), res = 0;
                    for(int i = 0; i < n - flag;i++) {
                        int left = i, right = (flag == true ? i + 1 : i), cnt = 0;
                        while(left >= 0 && right < n) {
                            if(s[left] != s[right])
                                break;
                            cnt += 1;
                            left -= 1;
                            right += 1;
                        }
                        res += cnt;
                    }
                    return res;
                }
            public:
                int countSubstrings(string s) {
                    int res = 0;
                    res += countPal(s);
                    res += countPal(s, true);
                    return res;
                }
            };
        
    </details>

---




* [ ] [Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maxArea(vector<int>& height) {
                    int n = height.size(), res = 0;
                    int left = 0, right = n - 1;
                    while(left < right) {
                        res = max(res, min(height[left], height[right]) * (right - left));
                        if(height[left] < height[right]) left += 1;
                        else right -= 1;
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
            * Definition for singly-linked list.
            * struct ListNode {
            *     int val;
            *     ListNode *next;
            *     ListNode(int x) : val(x), next(NULL) {}
            * };
            */
            class Solution {
            public:
                bool hasCycle(ListNode *head) {
                    ListNode* slow = head, *fast = (head == nullptr ? nullptr : head->next);
                    while(fast != nullptr && fast != slow) {
                        slow = slow->next;
                        fast = fast->next;
                        if(fast != nullptr)
                            fast = fast->next;
                    }
                    return fast == slow && slow != nullptr;
                }
            };
        
    </details>

---



* [ ] [3Sum](https://leetcode.com/problems/3sum/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<vector<int>> threeSum(vector<int>& nums) {
                    int n = nums.size();
                    sort(nums.begin(), nums.end());
                    vector<vector<int>> res;
                    for(int i = 0; i < n - 2;i++) {
                        if(i != 0 && nums[i] == nums[i - 1]) continue;
                        int left = i + 1, right = n - 1, target = -nums[i];
                        while(left < right) {
                            int sum = nums[left] + nums[right];
                            if(sum == target) {
                                vector<int> ans = {nums[i], nums[left], nums[right]};
                                res.push_back(ans);
                                int start = left, end = right;
                                while(left < right && nums[start] == nums[left]) left += 1;
                                while(right > left && nums[end] == nums[right]) right -= 1;
                            }
                            else if(sum > target) right -= 1;
                            else left += 1;
                        }
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int characterReplacement(string s, int k) {
                    int n = s.size(), res = 0;
                    unordered_map<char, int> frq;
                    for(int end = 0, start = 0; end < n;end++) {
                        frq[s[end]] += 1;
                        while(start < end) {
                            int mx = 0, len = end - start + 1;
                            for(auto &ch: frq)
                                mx = max(mx, ch.second);
                            if(mx + k >= len)
                                break;
                            frq[s[start]] -= 1;
                            start += 1;
                        }
                        res = max(res, end - start + 1);
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Detect Loop in linked list](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=2&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                // Function to check if the linked list has a loop.
                bool detectLoop(Node* head) {
                    // your code here
                    Node* slow = head, *fast = head->next;
                    while(fast != nullptr && slow != fast) {
                        slow = slow->next;
                        fast = fast->next;
                        if(fast != nullptr)
                            fast = fast->next;
                    }
                    return slow == fast;
                }
            };

        
    </details>

---