#include <bits/stdc++.h>
using namespace std;
 
int lengthOfLIS(vector<int>& nums)
{
 
    // Binary search approach
    int n = nums.size();
    vector<int> ans;
 
    // Initialize the answer vector with the
    // first element of nums
    ans.push_back(nums[0]);
 
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
 
            // If the current number is greater
            // than the last element of the answer
            // vector, it means we have found a
            // longer increasing subsequence.
            // Hence, we append the current number
            // to the answer vector.
            ans.push_back(nums[i]);
        }
        else {
 
            // If the current number is not
            // greater than the last element of
            // the answer vector, we perform
            // a binary search to find the smallest
            // element in the answer vector that
            // is greater than or equal to the
            // current number.
 
            // The lower_bound function returns
            // an iterator pointing to the first
            // element that is not less than
            // the current number.
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
 
            // We update the element at the
            // found position with the current number.
            // By doing this, we are maintaining
            // a sorted order in the answer vector.
            ans[low] = nums[i];
        }
    }
 
    // The length of the answer vector
    // represents the length of the
    // longest increasing subsequence.
    return ans.size();
}
 
 
 
void solve(){
	int n, i;
	cin>>n;
	vector <int> a(n);
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<lengthOfLIS(a)<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int TT = 1;
    // cin >> TT;
 
    while (TT--) {
        solve();
    }
 
    return 0;
