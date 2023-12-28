#include <bits/stdc++.h>
using namespace std;
#define int long long
int i, j;
//do not use the code directly as that can lead to wrong answers.


void solve() {
    int N;
    int Q;
    cin >> N >> Q;
    // read in the initial trees
    vector<vector<int>> forest(1002, vector<int>(1002, 0)), tree_pref(1002, vector<int>(1002, 0));

    for (i = 0; i < 1002; i++) {
        for (j = 0; j < 1002; j++) {
            forest[i][j] = 0;
            tree_pref[i][j] = 0;//do i+1 and j+1 for a 0 intialised array
        }
    }
    for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a>>b;
            forest[a][b] +=a*b;
    }

    for (int i = 1; i < 1002; i++) {
        for (int j = 1; j < 1002; j++) {
            tree_pref[i][j] = forest[i][j] + tree_pref[i - 1][j] +
                              tree_pref[i][j - 1] - tree_pref[i - 1][j - 1];
        }
    }

    for (int q = 0; q < Q; q++) {
        int from_row, to_row, from_col, to_col;
        cin >> from_row >> from_col >> to_row >> to_col;
      //do from_col&from_row ++ if you want to not involve the rowwe are starting from in the sum
      //do to_col & to_row -- if you do not want to involve them in the ans 
        cout << tree_pref[to_row][to_col] - tree_pref[from_row - 1][to_col] -
                    tree_pref[to_row][from_col - 1] +
                    tree_pref[from_row - 1][from_col - 1]
             << endl;
    }}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TT=1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}
