#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int tq, at[N], bt[N], ct[N], tat[N], wt[N], pr[N], temp[N], n;

int32_t main () {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> bt[i];
  for (int i = 0; i < n; i++) cin >> at[i];
  for (int i = 0; i < n; i++) cin >> pr[i];
  
  vector<vector<int> >v;
  for (int i = 0; i < n; i++) {
    v.push_back({at[i], bt[i]});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    at[i] = v[i][0];
    bt[i] = v[i][1];
  }

  int b, k = 1, mn, t;
  for (int j = 0; j < n; j++) {
    b = b + bt[j];
    mn = bt[k];
    for (int i = k; i < n; i++) {
      mn = pr[k];
      if(b >= at[i]) {
        if(pr[i] < mn) {
          t = at[k];
          at[k] = at[i];
          at[i] = t;

          t = bt[k];
          bt[k] = bt[i];
          bt[i] = t;

          t = pr[k];
          pr[k] = pr[i];
          pr[i] = k;
        }
      }
    }
    k++;
  }
  
  cout << "P\t\tbt\ttat\twt\t" << endl; 
  int tot_tat = 0, tot_wt = 0;

  for (int i = 0; i < n; i++) {
    wt[i] = 0;
    tat[i] = 0;
    temp[i+1] = temp[i] + bt[i];
    wt[i] = temp[i] - at[i];
    tat[i] = wt[i] + bt[i];
    tot_tat += tat[i];
    tot_wt += wt[i];
    
    cout << "p[" << i+1 << "] \t" << bt[i] << "\t" << tat[i] << "\t" << wt[i] << endl; 
  }

  float av_wt = (tot_tat * 1.0)/n, av_tat = (tot_wt * 1.0) / n;

  cout << "average turn around time = " << av_tat << endl;
  cout << "average waiting time = " << av_wt << endl;
  
}