#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int tq, bt[N], rem_bt[N], tat[N], wt[N], p[N], n;

int32_t main () {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> bt[i], rem_bt[i] = bt[i];
  
  cin >> tq;

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
			tat[i] = ex;
		}
	}

	float av_wt = 0.0, av_tat = 0.0;

	cout << "P\t\tbt\t\ttat\t\twt\n"; 

	for (int i = 0; i < n; i++) {
		wt[i] = tat[i] - bt[i];
		av_tat += tat[i];
		av_wt += wt[i];
		cout << "p[" << p[i] << "] \t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
	}

	cout << "average tat = " << av_tat/n << endl;
	cout << "average wt = " << av_wt/n << endl;


  
}