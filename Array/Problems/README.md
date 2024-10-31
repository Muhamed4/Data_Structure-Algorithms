

* [ ] [Tram ride](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tram-ride-d7ff3a92/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;

            long long solve (int N, int start, int finish, vector<int> Ticket_cost) {
            // Write your code here
            long ans1 = 0, ans2 = 0;
            vector<int> newv = Ticket_cost;
            for(auto it: Ticket_cost)newv.push_back(it);
            start--,finish--;
            start = (start + N) % N;
            finish = (finish + N ) % N;
            for(int i = start; i < newv.size();i++){
                if(i % N == finish)break;
                ans1 += newv[i];
            }
            for(int i = finish;i < newv.size();i++){
                if(i % N == start)break;
                ans2 += newv[i];
            }
            return min(ans1, ans2);
            }

            int main() {

                ios::sync_with_stdio(0);
                cin.tie(0);
                int N;
                cin >> N;
                int start;
                cin >> start;
                int finish;
                cin >> finish;
                vector<int> Ticket_cost(N);
                for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
                {
                    cin >> Ticket_cost[i_Ticket_cost];
                }

                long long out_;
                out_ = solve(N, start, finish, Ticket_cost);
                cout << out_;
            }
        
    </details>

---



* [ ] [Double inversions](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/double-inversions-2-881a7d34/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            // ordered set
            #include <ext/pb_ds/assoc_container.hpp>
            #include <ext/pb_ds/tree_policy.hpp>
            using namespace std;
            using namespace __gnu_pbds;
            template <class T>
            using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

            vector<int> Inversion(vector<int>&a, vector<int>&b){
                vector<int>ans;
                int n = (int)a.size(), idx = n - 1;
                for(int i = 0; i < n;i++){
                    int x = i, y = idx;
                    if(a[i] > x || b[idx] > y){
                        return {-1};
                    }
                    int res = n - a[i] - b[idx];
                    ans.push_back(res);
                    --idx;
                }
                map<int,int>mp;
                ordered_set<int>st;
                for(int i = 0 ; i < n;i++){
                    st.insert(ans[i]);
                    ++mp[ans[i]];
                    int res = (int)st.size() - st.order_of_key(ans[i]) - mp[ans[i]];
                    if(res != a[i])return {-1};
                }
                return ans;
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n;cin >> n;
                    vector<int>a(n), b(n);
                    for(auto &it : a)cin >> it;
                    for(auto &it : b)cin >> it;
                    for(auto it: Inversion(a, b))cout << it << ' ';
                    cout << '\n';
                }
                return 0;
            }
        
    </details>

---



* [ ] [Non-decreasing arrays](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/make-it-non-decreasing-7d3391fd/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            // ordered set
            #include <ext/pb_ds/assoc_container.hpp>
            #include <ext/pb_ds/tree_policy.hpp>
            using namespace std;
            using namespace __gnu_pbds;
            template <class T>
            using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

            void solve(vector<long long>&v){
                long long first = v[0];
                for(auto &it: v){
                    long long l = 1, r = first / it + 10, mid = 0, ans = 0;
                    while(l <= r){
                        mid = (l + r) / 2;
                        long long res = 1ll*mid * it;
                        if(res >= first){
                            ans = res;
                            r = mid - 1;
                        }
                        else l = mid + 1;
                    }
                    cout << ans << ' ';
                    first = ans;
                }
                cout << '\n';
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n;cin >> n;
                    vector<long long>v(n);
                    for(auto &it: v)cin >> it;
                    solve(v);
                }
                return 0;
            }
        
    </details>

---




* [ ] [Non-empty subsets](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minor-4-41918cb8/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n;cin >> n;
                    vector<int>v(n);
                    long long _or = 1e10;
                    for(auto &it: v){
                        cin >> it;
                        _or = min(_or, 1ll*it);
                    }
                    cout << _or << endl;
                }
                return 0;
            }
        
    </details>

---




* [ ] [James and the menus](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/howie-and-the-menus-2-48359fe4/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int n, m;cin >> n >> m;
                vector<vector<int>>v(n, vector<int>(m));
                vector<long long>mx(m), sum(n);
                for(int i = 0 ; i < n;i++){
                    for(int j = 0 ; j < m;j++){
                        cin >> v[i][j];
                        mx[j] = max(mx[j], 1ll*v[i][j]);
                        sum[i] += v[i][j];
                    }
                }
                set<pair<int,pair<long long,int>>>st;
                map<int,int>cur_ans;
                for(int i = 0; i < n;i++){
                    st.insert({0,{sum[i], i}});
                }
                for(int i = 0; i < n;i++){
                    for(int j = 0; j < m;j++){
                        if(v[i][j] == mx[j]){
                            pair<int,pair<long long,int>> p = {cur_ans[i], {sum[i], i}};
                            st.erase(st.find(p));
                            ++p.first;
                            st.insert(p);
                            cur_ans[i] = p.first;
                        }
                    }
                }
                cout << (*prev(st.end())).second.second + 1 << endl;
                return 0;
            }
        
    </details>

---




* [ ] [Sum as per frequency](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/sum-as-per-frequency-88b00c1f/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;

            long long solve(vector<long long>&prefix, int l, int r){
                return prefix[r] - prefix[l - 1];
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif

                int n;cin >> n;
                map<int,int>mp;
                for(int i = 0 ; i < n;i++){
                    int x;cin >> x;
                    mp[x]++;
                }
                vector<long long>prefix(n + 1);
                for(auto it: mp){
                    prefix[it.second] += (1ll*it.first * it.second);
                }
                for(int i = 1 ; i <= n;i++)prefix[i] += prefix[i - 1];
                int t;cin >> t;
                while (t--){
                    int l, r;cin >> l >> r;
                    cout << solve(prefix, l, r) << '\n'; // Don't use endl it will take more time and cause time limit because it flush the output.
                }
                
            }
        
    </details>

---




* [ ] [Maximize the sum](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-sum-0423b95e/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n, k;cin >> n >> k;
                    map<int,long long>mp;
                    for(int i = 0 ; i < n;i++){
                        int x;cin >> x;
                        mp[x] += x;
                    }
                    long long ans = 0;
                    priority_queue<long long>p;
                    for(auto it: mp)p.push(it.second);
                    while(!p.empty() && p.top() > 0 && k--){
                        ans += p.top();
                        p.pop();
                    }
                    cout << ans << '\n';
                }

            }
        
    </details>

---




* [ ] [Bitwise AND sum](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/bitwise-and-sum-d8a0d265/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n;cin >> n;
                    vector<int>v(n);
                    vector<pair<int,int>>cnt(27);
                    long long res = 1ll*n * (n + 1) / 2;
                    for(int i = 0 ; i < 27;i++) cnt[i].first = 1e9, cnt[i].second = -1;
                    for(int i = 0 ; i < n;i++){
                        cin >> v[i];
                        bitset<27>bit(v[i]);
                        for(int j = 0 ; j < 27;j++){
                            if(!bit[j]){
                                cnt[j].first = min(cnt[j].first, i);
                                cnt[j].second = max(cnt[j].second, i);
                            }
                        }
                    }
                    //for(auto it: cnt)cout << it.first << ' ' << it.second << endl;
                    long long ans = 0;
                    for(int i = 0 ; i < 27;i++){
                        long long cost = (1 << i);
                        if(cnt[i].second == -1){
                            ans += ((res - 1) * cost);
                            continue;
                        }
                        if(cnt[i].first == 0 && cnt[i].second == n - 1)continue;
                        if(cnt[i].first > 0 && cnt[i].second < n - 1){
                            long long x = cnt[i].first + 1, y = n - cnt[i].second;
                            long long total = x * y - 1;
                            ans += (total * cost);
                        }
                        else if(cnt[i].first == 0) ans += (1ll*(n - cnt[i].second - 1) * cost);
                        else if(cnt[i].second == n - 1) ans += (1ll*cnt[i].first * cost);
                    }
                    cout << ans << '\n';
                }
            }
        
    </details>

---




* [ ] [Minimum additions](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-additions-0142ac80/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n, k;cin >> n >> k;
                    vector<int>v(n);
                    long long sum = 0;
                    for(auto &it: v){
                        cin >> it;
                        sum += it;
                    }
                    long long l = n, r = 2e14, mid = 0, ans = 0;
                    while(l <= r){
                        mid = (l + r) / 2;
                        long long res = sum / mid;
                        if(res <= k){
                            ans = mid - n;
                            r = mid - 1;
                        }
                        else l = mid + 1;
                    }
                    cout << ans << '\n';
                }
            }
        
    </details>

---




* [ ] [Bracket sequences](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/bracket-sequence-1-40eab940/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                string s;cin >> s;
                int n = (int)s.size();
                s += s;
                int ans = 0, l = 1, r = n;
                stack<int>st;
                for(int i = 0 ; i < 2 * n - 1;i++){
                    if(st.empty()){
                        st.push(i);
                    }
                    else{
                        if(s[st.top()] == '(' && s[i] == ')')st.pop();
                        else st.push(i);
                    }
                    if(i == n - 1){
                        if(st.empty())ans++;
                    }
                    else if(i >= n){
                        if(st.empty())ans++;
                        else if(st.top() < l)ans++;
                        l++, r++;
                    }
                }
                cout << ans << '\n';
            }
        
    </details>

---




* [ ] [Permutations](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/nevedle-and-permutations-c6acb85e/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int n, t;cin >> n >> t;
                vector<int>v(n + 1), left(n + 2), right(n + 2);
                for(int i = 1; i <= n;i++)cin >> v[i];
                for(int i = 1; i <= n;i++)left[i] = max(left[i - 1], v[i]);
                for(int i = n; i >= 1;i--)right[i] = max(right[i + 1], v[i]);
                while(t--){
                    int l, r;cin >> l >> r;
                    cout << max(left[l - 1], right[r + 1]) << '\n';
                }

            }
        
    </details>

---




* [ ] [Minimum operations](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-operations-2-8000e855/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int n;cin >> n;
                vector<int>v(n);
                for(auto &it: v)cin >> it;
                int ans = 1;
                for(int i = 1; i < n;i++){
                    if(v[i] != v[i - 1])ans++;
                }
                cout << ans << endl;
            }
        
    </details>

---





* [ ] [Scoreboard queries](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tournament-and-ranks-67cd4b7e/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t;cin >> t;
                while(t--){
                    int n, t;cin >> n >> t;
                    vector<int>v(n + 1);
                    map<int,int>mp;
                    set<int>st;
                    for(int i = 1; i <= n;i++){
                        cin >> v[i];
                        mp[v[i]]++;
                        st.insert(v[i]);
                    }
                    while(t--){
                        int pos, val;cin >> pos >> val;
                        mp[v[pos]]--;
                        if(mp[v[pos]] == 0)st.erase(v[pos]);
                        v[pos] = val;
                        mp[val]++;
                        st.insert(val);
                        cout << (int)st.size() + 1 << '\n';
                    }
                }
            }
        
    </details>

---




* [ ] [In an array](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/in-an-array-9fbe4c12/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int n, k, x, y;cin >> n >> k >> x >> y;
                int *a = new int[n], *frq = new int[1001];
                for(int i = 0; i < n;i++){
                    cin >> a[i];
                    frq[a[i]]++;
                }
                long long ans = 0;
                for(int i = 1; i <= 1000;i++){
                    if(!frq[i])continue;
                    for(int j = i;j <= 1000;j++){
                        if(!frq[j])continue;
                        int xx = (i + j) % k;
                        int yy = (i * j) % k;
                        if(xx == x && yy == y){
                            if(i == j)ans += (1ll*frq[i] * (frq[i] - 1) / 2);
                            else ans += (1ll*frq[i] * frq[j]);
                        }
                    }
                }
                cout << ans << '\n';
                delete[] a;
                delete[] frq;
                a = frq = nullptr;
            }
        
    </details>

---



* [ ] [2 arrays](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/2-arrays-90c9019c/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int n;cin >> n;
                int *a = new int[n], *b = new int[n];
                long long sum1 = 0 , sum2 = 0;
                int cnt1 = 0 , cnt2 = 0;
                for(int i = 0 ; i < n;i++){
                    cin >> a[i];
                    if(a[i] == -1)cnt1++;
                    else sum1 += a[i];
                }
                for(int i = 0 ; i < n;i++){
                    cin >> b[i];
                    if(b[i] == -1)cnt2++;
                    else sum2 += b[i];
                }
                if(cnt1 == 2 && cnt2 == 0){
                    if(sum1 > sum2)cout << 0 << '\n';
                    else cout << (sum2 - sum1) + 1 << '\n';
                }
                else if(cnt1 == 1 && cnt2 == 1){
                    cout << "Infinite" << '\n';
                }
                else if(cnt1 == 0 && cnt2 == 2){
                    if(sum2 > sum1)cout << 0 << '\n';
                    else cout << (sum1 - sum2) + 1 << '\n';
                }
                else if(cnt1 == 1 && cnt2 == 0){
                    if(sum1 > sum2)cout << 0 << '\n';
                    else cout << 1 << endl;
                }
                else{
                    if(sum2 > sum1)cout << 0 << '\n';
                    else cout << 1 << '\n';
                }
                delete[] a;
                delete[] b;
                a = b = nullptr;
            }
        
    </details>

---



* [ ] [Infinite arrays](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/infinity-array-715a233b/ "HackerEarth")
    * <details>
        <summary> Solution </summary>

        ```c++
            #include <bits/stdc++.h>

            using namespace std;

            typedef long long int ll;

            ll p = 1000000007;

            int main()
            {

                ios_base::sync_with_stdio(false);

                cin.tie(NULL);

                int t;

                cin >> t;

                for (int i = 0; i < t; i++)
                {

                    int n;

                    cin >> n;

                    ll suff[n + 1], temp;

                    suff[0] = 0;

                    for (int i = 1; i <= n; i++)
                    {

                        cin >> temp;

                        suff[i] = (suff[i - 1] + temp) % p;
                    }

                    int q;

                    cin >> q;

                    ll a[q], b[q];

                    for (int i = 0; i < q; i++)

                        cin >> a[i];

                    for (int i = 0; i < q; i++)

                        cin >> b[i];

                    for (int i = 0; i < q; i++)
                    {

                        ll l = a[i] - 1, r = b[i];

                        ll sum1 = (suff[l % n] + ((l / n) % p * suff[n]) % p) % p;

                        ll sum2 = (suff[r % n] + ((r / n) % p * suff[n]) % p) % p;

                        cout << (sum2 - sum1 + p) % p << " ";
                    }

                    cout << "\n";
                }

                return 0;
            }
        
    </details>

---



* [ ] [Digital Sequence](https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/digitial-sequence-ee0ea080/)
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;


            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int n;cin >> n;
                int *v = new int[n];
                map<int,int>mp;
                for(int i = 0; i < n;i++){
                    cin >> v[i];
                    int *frq = new int[10];
                    for(int j = 0 ; j < 10;j++)frq[j] = 0;
                    // memset(frq, 0, sizeof(frq));
                    // for(int j = 0 ; j < 10;j++)cout << frq[j] << ' ';
                    // cout << endl;
                    //while(v[i] % 10 == 0)v[i] /= 10;
                    while(v[i]){
                        int x = v[i] % 10;
                        if(!frq[x])mp[x]++;
                        frq[x]++;
                        v[i] /= 10;
                    }
                    delete[] frq;
                }
                int ans = 0;
                for(auto &it: mp){
                    ans = max(ans, it.second);
                    //cout << it.first << ' ' << it.second << endl;
                }
                cout << ans << endl;
                delete[] v;
            }
        
    </details>

---



* [ ] [Minimum Jumps](https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&company=Amazon,Microsoft,Google,Facebook&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int minJumps(vector<int>& arr) {
                    int n = arr.size();
                    bool flag = false;
                    int len = arr[0], path = 1, lastCell = 0;
                    for(int i = 1; i < n;i++) {
                        if(i <= len) lastCell = max(lastCell, i + arr[i]);
                        else {
                            if(lastCell <= len) {
                                flag = true;
                                break;
                            }
                            len = lastCell;
                            path += 1;
                        }
                    }
                    return flag == false ? path : -1;
                }
            };
        
    </details>

---



* [ ] [Majority Element](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&company=Amazon,Microsoft,Google,Facebook&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int majorityElement(vector<int>& arr) {
                    int n = arr.size(), majorityElement = -1, cnt = 0, othCount = 0;
                    for(int i = 0; i < n;i++) {
                        if(majorityElement == arr[i]) 
                            cnt += 1;
                        else if(cnt == 0) {
                            majorityElement = arr[i];
                            cnt = 1;
                        }
                        else cnt -= 1;
                    }
                    for(int i = 0; i < n;i++) {
                        if(arr[i] == majorityElement) 
                            othCount += 1;
                    }
                    return othCount > (n / 2) ? majorityElement : -1;
                }
            };
        
    </details>

---




* [ ] [Minimize the Heights II](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1?page=1&company=Amazon,Microsoft,Google,Facebook&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int getMinDiff(vector<int> &arr, int k) {
                    int n = arr.size(), res = 0;
                    multiset<int> st;
                    vector<int> in(n), de(n);
                    sort(arr.begin(), arr.end());
                    for(int i = 0; i < n;i++) {
                        int increase = arr[i] + k;
                        int decrease = (arr[i] - k >= 0 ? arr[i] - k : arr[i] + k);
                        in[i] = increase;
                        de[i] = decrease;
                        st.insert(increase);
                    }
                    res = *prev(st.end()) - *st.begin();
                    for(int i = n - 1; i >= 0;i--) {
                        st.erase(st.find(in[i]));
                        st.insert(de[i]);
                        res = min(res, *prev(st.end()) - *st.begin());
                    }
                    return res;
                }
            };
        
    </details>

---