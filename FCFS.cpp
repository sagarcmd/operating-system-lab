#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int tq, at[N], bt[N], rem_bt[N], ct[N], tat[N], wt[N], p[N], n;

int32_t main () {
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> bt[i];
	
	double awt = 0.0, atat = 0.0;

	cout << "P\t\tbt\twt\ttat\t" << endl; 

  for (int i = 0; i < n; i++) {
  	wt[i] = 0;
  	tat[i] = 0;
  	for (int j = 0; j < i; j++) {
  		wt[i] += bt[j];
  	}
  	tat[i] = wt[i] + bt[i];
  	awt += wt[i];
  	atat += tat[i];
  	cout << "p[" << i+1 << "] \t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl; 
  }
  awt /= n;
  atat /= n;

  cout << "Average Turn Around Time = " << atat << endl;
  cout << "Average Waiting Time = " << awt << endl;

  
   
}