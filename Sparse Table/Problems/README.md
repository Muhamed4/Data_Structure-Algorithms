* [ ] [Matchsticks](https://www.codechef.com/problems/MSTICK?tab=statement) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include <bits/stdc++.h>
            using namespace std;

            int getResult(int x, int y, int type) {
                if (type == 0)
                    return min(x, y);
                return max(x, y);
            }

            void getSparseTable(int maxLog, int n, vector<int>& arr, vector<vector<int>>& SparseTable, int type = 0) {
                for (int i = 0; i < maxLog; i++) {
                    for (int j = 0; j + (1 << i) <= n; j++) {
                        if (i == 0) {
                            SparseTable[i][j] = arr[j];
                            continue;
                        }
                        
                        SparseTable[i][j] = getResult(SparseTable[i - 1][j], SparseTable[i - 1][j + (1 << (i - 1))], type);
                    }
                }
            }

            void buildLogs(int n, vector<int>& lg) {
                for (int i = 2; i <= n; i++) {
                    lg[i] = lg[i / 2] + 1;
                }
            }

            int getValue(int L, int R, int n, vector<int>& lg, vector<vector<int>>& SparseTable, int type = 0) {
                if (L > R || L < 0 || R >= n)
                    return 0;
                int len = R - L + 1;
                int index = lg[len];
                if (type == 0) {
                    return min(SparseTable[index][L], SparseTable[index][R - (1 << index) + 1]);
                }
                return max(SparseTable[index][L], SparseTable[index][R - (1 << index) + 1]);
            }

            int main() {
                int n; cin >> n;
                int maxLog = floor(log2(n)) + 1;
                vector<int> arr(n), lg(n + 1);
                vector<vector<int>> minSparseTable(maxLog, vector<int>(n + 1));
                vector<vector<int>> maxSparseTable(maxLog, vector<int>(n + 1));
                
                for (auto &it: arr) cin >> it;
                buildLogs(n, lg);
                getSparseTable(maxLog, n, arr, minSparseTable);
                getSparseTable(maxLog, n, arr, maxSparseTable, 1);
                
                int q; cin >> q;
                while(q--) {
                    int L, R; cin >> L >> R;
                    int firstMax = getValue(0, L - 1, n, lg, maxSparseTable, 1);
                    int secondMax = getValue(R + 1, n - 1, n, lg, maxSparseTable, 1);
                    int thirdMax = getValue(L, R, n, lg, maxSparseTable, 1);
                    int minValue = getValue(L, R, n, lg, minSparseTable);
                    double firstResult = 1.0 * firstMax + ((L - 1) >= 0 ? minValue : 0);
                    double secondResult = 1.0 * secondMax + ((R + 1) < n ? minValue : 0);
                    double thirdResult = 1.0 * minValue + (1.0 * (thirdMax - minValue) / 2.0);
                    double result =  1.0 * max(firstResult, max(secondResult, thirdResult));
                    cout << fixed << setprecision(1) << result << endl;
                }
            }

        
    </details>

---

* [ ] [RMQSQ - Range Minimum Query](https://www.spoj.com/problems/RMQSQ/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include <bits/stdc++.h>
            using namespace std;
            typedef long long ll;
            #define endl '\n'

            void buildSparseTable(int maxLog, int n, vector<int>& arr, vector<vector<int>>& sparseTable) {
                for (int i = 0; i < maxLog; i++) {
                    for (int j = 0; j + (1 << i) <= n; j++) {
                        if (i == 0) {
                            sparseTable[i][j] = arr[j];
                            continue;
                        }

                        sparseTable[i][j] = min(sparseTable[i - 1][j], sparseTable[i - 1][j + (1 << (i - 1))]);
                    }
                }
            }

            void buildLog(int n, vector<int>& lg) {
                for (int i = 2; i <= n;i++) {
                    lg[i] = lg[i / 2] + 1;
                }
            }

            int getMinValue(int L, int R, vector<int>& lg, vector<vector<int>>& sparseTable) {
                int k = lg[R - L + 1];
                return min(sparseTable[k][L], sparseTable[k][R - (1 << k) + 1]);
            }

            void solve() {
                int n; cin >> n;
                int maxLog = log2(n) + 1;
                vector<int> arr(n);
                vector<int> lg(n + 1);
                vector<vector<int>> sparseTable(maxLog + 1, vector<int>(n + 1));
                for (auto &it: arr) cin >> it;
                buildLog(n, lg);
                buildSparseTable(maxLog, n, arr, sparseTable);
                int q; cin >> q;
                while (q--) {
                    int L, R; cin >> L >> R;
                    int result = getMinValue(L, R, lg, sparseTable);
                    cout << result << endl;
                }
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                    freopen("D:/Competitive Programming/Input.txt", "r", stdin);
                    freopen("D:/Competitive Programming/Output.txt", "w", stdout);
                #endif
                int t = 1; // cin >> t;
                for (int i = 1; i <= t; i++){
                    solve();
                }
                return 0;
            }

        
    </details>

---


* [ ] [THRBL - Catapult that ball](https://www.spoj.com/problems/THRBL/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include <bits/stdc++.h>
            using namespace std;
            typedef long long ll;
            #define endl '\n'

            void buildLog(int n, vector<int>& lg) {
                for (int i = 2; i <= n;i++) {
                    lg[i] = lg[i / 2] + 1;
                }
            }

            void buildSparseTable(int maxLog, int n, vector<int>& arr, vector<vector<int>>& sparseTable) {
                for (int i = 0; i < maxLog; i++) {
                    for (int j = 0; j + (1 << i) <= n; j++) {
                        if (i == 0) {
                            sparseTable[i][j] = arr[j];
                            continue;
                        }

                        sparseTable[i][j] = max(sparseTable[i - 1][j], sparseTable[i - 1][j + (1 << (i - 1))]);
                    }
                }
            }

            int getMaxValue(int L, int R, vector<int>& lg, vector<vector<int>>& sparseTable) {
                int k = lg[R - L + 1];
                return max(sparseTable[k][L], sparseTable[k][R - (1 << k) + 1]); 
            }

            void solve() {
                int n, q;cin >> n >> q;
                int result = 0;
                int maxLog = log2(n) + 1;
                vector<int> arr(n);
                vector<int> lg(n + 1);
                vector<vector<int>> sparseTable(maxLog + 1, vector<int>(n + 1));
                for (auto &it: arr) cin >> it;
                buildLog(n, lg);
                buildSparseTable(maxLog, n, arr, sparseTable);
                while (q--) {
                    int L, R; cin >> L >> R;
                    if (L > (R - 1)) continue;
                    int ans = getMaxValue(L - 1, R - 2, lg, sparseTable);
                    result += (arr[L - 1] == ans);
                }
                cout << result << endl;
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                    freopen("D:/Competitive Programming/Input.txt", "r", stdin);
                    freopen("D:/Competitive Programming/Output.txt", "w", stdout);
                #endif
                int t = 1; // cin >> t;
                for (int i = 1; i <= t; i++){
                    solve();
                }
                return 0;
            }

        
    </details>

---