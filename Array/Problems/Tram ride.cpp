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