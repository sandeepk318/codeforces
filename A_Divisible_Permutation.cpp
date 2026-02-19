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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    int x = n, y = 1, i = n-1;
    while(i >= 0) {
        if(i >= 0) {
            a[i] = y;
            y++;
            i--;
        }

        if(i >= 0) {
            a[i] = x;
            x--;
            i--;
        }
    }
    for(int i: a) {
        cout << i << " ";
    }
    cout << endl;
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