#include<bits/stdc++.h>
using namespace std;

string find_window(string s, string pat) {
	int SL = s.length();
	int PL = pat.length();

	// 1. corner case
	if(PL > SL) {
		return "None";
	}

	// 2. freq maps
	int FS[256] = {0};
	int FP[256] = {0};

	for(int i=0;i<PL;i++) {
		char ch = pat[i];
		FP[ch]++;
	}

	// sliding window (expansion and contraction + update the min length window)
	int cnt = 0;
	int start = 0;    // left pointer for shrinking the window
	int min_len = INT_MAX;
	int start_idx = -1;
	for(int i=0;i<SL;i++) {
		char ch = s[i];
		FS[ch]++;

		// maintain the cnt of characters matched
		if(FP[ch] != 0 and FS[ch] <= FP[ch]) {
			cnt++;							// cnt is total count of characters matched
		}

		// if all the characters match
		if(cnt == PL) {
			// start shrinking the window
			char temp = s[start];
			// loop to remove all unwanted characters
			while(FP[temp] == 0 or FS[temp] > FP[temp]) {
				FS[temp]--;
				start++;
				temp = s[start];
			}
			// window size
			int window_len = i - start + 1;
			if(window_len < min_len) {
				min_len = window_len;
				start_idx = start;
			}
		}
	}
	if(start_idx == -1) {
		return "None";
	}
	string ans = s.substr(start_idx, min_len);
	return ans;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s = "hllloeaeo world";
	string p = "eelo";

	cout<<find_window(s, p)<<endl;

	return 0;
}