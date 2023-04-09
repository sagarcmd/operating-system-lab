#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int tq, at[N], bt[N], rem_bt[N], temp[N], ct[N], tat[N], wt[N], p[N], n;

int32_t main () {
  int n; cin >> n;
  
  for (int i = 0; i < n; i++) cin >> bt[i];
  for (int i = 0; i < n; i++) cin >> at[i];
  for (int i = 0; i < n; i++) cin >> p[i];

  vector<vector<int> >v;
  for (int i = 0; i < n; i++) {
    v.push_back({at[i], bt[i], p[i]});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    at[i] = v[i][0];
    bt[i] = v[i][1];
    p[i] = v[i][2];
  }
	
	double awt = 0.0, atat = 0.0;

	cout << "P\t\tbt\tat\twt\ttat\t" << endl; 

  temp[0] = 0;
  for (int i = 0; i < n; i++) {
  	wt[i] = 0;
  	tat[i] = 0;
    temp[i+1] = temp[i] + bt[i];
    wt[i] = temp[i] - at[i];
    tat[i] = wt[i] + bt[i];

  	awt += wt[i];
  	atat += tat[i];
  	cout << "p[" << p[i] << "] \t" << bt[i] << "\t" << at[i] << "\t" << wt[i] << "\t" << tat[i] << endl; 
  }
  awt /= n;
  atat /= n;

  cout << "Average Turn Around Time = " << atat << endl;
  cout << "Average Waiting Time = " << awt << endl;

  
   
}