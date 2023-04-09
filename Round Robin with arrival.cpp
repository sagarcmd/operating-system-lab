#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int tq, at[N], bt[N], rem_bt[N], ct[N], tat[N], wt[N], p[N], n;

int32_t main () {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> at[i];
  for (int i = 0; i < n; i++) cin >> bt[i], rem_bt[i] = bt[i];
  
  cin >> tq;
  
  vector<vector<int> >v;
  for (int i = 0; i < n; i++) {
    v.push_back({at[i], bt[i], rem_bt[i], p[i]});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    at[i] = v[i][0];
    bt[i] = v[i][1];
    rem_bt[i] = v[i][2];
    p[i] = v[i][3];
  }

  int cnt = 0, ex = 0;
  while(cnt < n) {
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if(rem_bt[i] == 0) {
        cnt++;
        continue;
      }
      if(rem_bt[i] > tq) {
        rem_bt[i] -= tq;
        ex += tq;
      }
      else if(rem_bt[i] >= 0) {
        ex += rem_bt[i];
        rem_bt[i] = 0;
      }
      ct[i] = ex;
    }
  }

  float av_wt = 0.0, av_tat = 0.0;

  cout << "P\t\tat\tbt\tct\ttat\twt\t" << endl; 

  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    av_tat += tat[i];
    av_wt += wt[i];
    cout << "p[" << p[i] << "] \t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << endl; 
  }

  cout << "average tat = " << av_tat/n << endl;
  cout << "average wt = " << av_wt/n << endl;


  
}