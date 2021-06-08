#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n) {
	if(i == m && j == n) {
		soln[m][n] = 1;
		//print the path
		for(int i= 0; i<=m;i++) {
			for(int j=0;j<=n;j++) {
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}

	//rat should be inside the grid
	if(i>m || j>n) {
		return false;
	}

	if(maze[i][j] == 'X') {
		return false;
	}

	//assume solution exists through current cell
	soln[i][j] = 1;

	bool rightSuccess = ratInMaze(maze, soln, i, j+1, m ,n);
	bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);

	//Backtracking
	soln[i][j] = 0;

	if(rightSuccess || downSuccess) {
		return true;
	}
	return false;
}

int main() {

	char maze[10][10] = {
						"0000",
						"00X0",
						"000X",
						"0X00"
	};

	int soln[10][10] = {0};
	int m =4, n=4;

	bool ans = ratInMaze(maze, soln ,0 , 0, m-1, n-1);

	if(ans == false) {
		cout<<"Path doesn't exist"<<endl;
	}

	return 0;
}


// or 
    void solve(vector <vector <int>> &m, vector <vector <int> > &vis, int n, int di[], int dj[], 
                int i, int j, vector <string> &ans, string move ) {
                    
        if(i == n-1 and j == n-1) {
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        for(int idx = 0; idx<4;idx++) {
            int nexti = i + di[idx];
            int nextj = j = dj[idx];
            if(nexti < n and nexti >= 0 and nextj < n and nextj >= 0 and !vis[nexti][nextj]
                and m[nexti][nextj] == 1) {
                
                vis[i][j] = 1;
                solve(m , vis, n, di, dj, nexti ,nextj, ans, move + dir[idx]);
                vis[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector <string> ans;
        vector <vector <int> > vis(n , vector <int> (n, 0));
        
        int di[] = {1, 0,0, -1};
        int dj[] = {0,-1,1, 0};
        
        if(m[0][0] == 1) {
            solve(m ,vis, n, di, dj, 0, 0, ans,  "");
        }
        return ans;
    }


// or

        void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, 
    vector<vector<int>> &vis, int di[], int dj[]) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return; 
        }
        string dir = "DLRU"; 
        for(int ind = 0; ind<4;ind++) {
            int nexti = i + di[ind]; 
            int nextj = j + dj[ind]; 
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[i][j] = 1; 
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0; 
            }
        }
        // downward
        // if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
        //     vis[i][j] = 1; 
        //     solve(i+1, j, a, n, ans, move + 'D', vis);
        //     vis[i][j] = 0; 
        // }
        
        // // left
        // if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1) {
        //     vis[i][j] = 1; 
        //     solve(i, j-1, a, n, ans, move + 'L', vis);
        //     vis[i][j] = 0; 
        // }
        
        // // right 
        // if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
        //     vis[i][j] = 1; 
        //     solve(i, j+1, a, n, ans, move + 'R', vis);
        //     vis[i][j] = 0; 
        // }
        
        // // upward
        // if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1) {
        //     vis[i][j] = 1; 
        //     solve(i-1, j, a, n, ans, move + 'U', vis);
        //     vis[i][j] = 0; 
        // }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0)); 
        int di[] = {+1, 0, 0, -1}; 
        int dj[] = {0, -1, 1, 0}; 
        if(m[0][0] == 1) solve(0,0,m,n, ans, "", vis, di, dj); 
        return ans; 
    }





    
    