// Author -> Sandeep Kumar: sk921815
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int mex(vl a) {
    unordered_set<ll> st;
    // cout << "inside MEX: ";
    for(ll i: a) {
        // cout << i << " ";
        st.insert(i);
    }
    int ans = a.size();
    for(int i = 0;i<=a.size();i++) {
        if(st.find(i) == st.end()){
            ans = i;
            break;
        }
    }
    // cout << " => " << ans <<endl;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int a;
        cin>> a;
        st.insert(a);
    }

    // answer is maximum consecutive numbers after removing duplicates.
    vi a;
    for(auto i: st) {
        a.push_back(i);
    }
    // for(int i: a ) {
    //     cout << i << " ";
    // }
    // cout << "=> ";
    int ans = 1, curr = 1;
    for(int i = 1;i<a.size();i++) {
        if(a[i] == a[i-1] + 1) {
            curr++;
        } else {
            ans = max(ans, curr);
            curr = 1;
        }
    }
    ans = max(ans, curr);
    cout << ans << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t;
    while(t--){
        solve();
        // cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs" << endl;
    }
    return 0;
}