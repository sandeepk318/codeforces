 // Author -> Sandeep Kumar: sk921815
 #ifndef _GLIBCXX_NO_ASSERT
  #include <cassert>
  #endif
  #include <cctype>
  #include <cerrno>
  #include <cfloat>
  #include <ciso646>
  #include <climits>
  #include <clocale>
  #include <cmath>
  #include <csetjmp>
  #include <csignal>
  #include <cstdarg>
  #include <cstddef>
  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <ctime>

  #if __cplusplus >= 201103L
  #include <ccomplex>
  #include <cfenv>
  #include <cinttypes>
  #include <cstdbool>
  #include <cstdint>
  #include <ctgmath>
  #include <cwchar>
  #include <cwctype>
  #include <exception>
  #include <stdexcept>
  #endif

  // C++
  #include <algorithm>
  #include <bitset>
  #include <complex>
  #include <deque>
  #include <exception>
  #include <fstream>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <istream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <locale>
  #include <map>
  #include <memory>
  #include <new>
  #include <numeric>
  #include <ostream>
  #include <queue>
  #include <set>
  #include <sstream>
  #include <stack>
  #include <stdexcept>
  #include <streambuf>
  #include <string>
  #include <typeinfo>
  #include <utility>
  #include <valarray>
  #include <vector>

  #if __cplusplus >= 201103L
  #include <array>
  #include <atomic>
  #include <chrono>
  #include <condition_variable>
  #include <forward_list>
  #include <future>
  #include <initializer_list>
  #include <mutex>
  #include <random>
  #include <ratio>
  #include <regex>
  #include <scoped_allocator>
  #include <system_error>
  #include <thread>
  #include <tuple>
  #include <typeindex>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #endif
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
// typedef for(int i = 0;i<n;i++) fori(n);
ll modulo = 1e9 + 7;

ll countNodes(int i, int n, vl &nodes, vvi &A) {
    if(A[i].size() == 0) {
        nodes[i] = 1;
        return 1;
    }

    if(nodes[i] != -1) {
        return nodes[i];
    }

    ll ans = 0;
    for(int j : A[i]) {
        ans += countNodes(j, n, nodes, A);
    }

    nodes[i] = 1 + ans;
    return nodes[i];
}

void dis(int i, vl &nodes, vvi &A, vl &ans) {
    if(A[i].size() == 0) {
        return ;
    }

    for(int j : A[i]) {
        ll value_here = (nodes[j] == 1) ? 0 : 2 * (nodes[j] -1);
        value_here %= modulo;
        ans[j] = (1 + value_here + ans[i]) % modulo;
    }

    for(int j: A[i]) {
        dis(j, nodes, A, ans);
    }
}
void solve()
{
    int n;
    cin>> n;
    vvi A(n);
    for(int i = 0;i< n;i++) {
        int a, b;
        cin>> a>> b;
        if(a != 0 && b != 0) {
            A[i].push_back(a - 1);
            A[i].push_back(b - 1);
        }
    }

    vl nodes(n, -1);
    countNodes(0, n, nodes, A);
    // for(auto i: nodes ) {
    //     cout << i << ", ";
    // }
    // cout << endl;
    vl ans(n, -1);
    ans[0] = (ll(2 * nodes[0]) - 1) % modulo;
    dis(0, nodes, A, ans);
    for(ll i: ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    // use code runner for C++ in vs code and have input and output.txt file. also modify code runner executer map to this.code-runner.executorMap
    // "cpp": "cd $dir && mkdir -p build && g++ $fileName -o build/$fileNameWithoutExt && build/$fileNameWithoutExt < input.txt > output.txt",
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--){ 
        solve();
        // cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    }
    return 0;
}