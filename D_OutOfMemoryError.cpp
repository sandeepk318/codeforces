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
    int n, m, h;
    cin >> n >> m >> h;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    int last_reset = 1e6;
    vi last_update(n, 1e6);

    for(int i =1;i<=m;i++) {
        int x, y;
        cin>> x >> y;
        if(last_reset <= i && last_update[x-1] <= last_reset) {
            // reset this value first to original.
            b[x - 1] = a[x - 1];
        }

        if(b[x - 1] > h - y) {
            // crash
            // b = a;
            b[x - 1] = a[x - 1];
            last_reset = i;
        } else {
            b[x - 1] += y;
            last_update[x - 1] = i;
        }
    }
    for(int i = 0;i<n;i++) {
        if(last_reset <= m && last_update[i] <= last_reset) {
            // reset this value to original.
            b[i] = a[i];
        }
    }
    for(int i: b) {
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