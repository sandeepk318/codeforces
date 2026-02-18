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

void solve()
{
    int n;
    cin>> n;
    string s;
    cin>> s;
    vi a(n, -1);
    for(int i = 0;i<n;i++) {
        a[i] = (s[i] == '1') ? 1 : -1;
    }
    for(int i = 0;i<n;i++) {
        if(a[i] == 1) {
            // make i -1 and i + 1 false.
            if(i - 1 >= 0) a[i - 1] = 0;
            if(i + 1 < n) a[i + 1] = 0;
        }
    }

    if(n < 3) {
        cout<< "1" << endl;
        return;
    }

    // for(int i: a) {
    //     cout << i << " ";
    // }
    // cout <<endl;

    int i = 0, ans = 0;
    while( i < n) {
        if(i + 1 < n && a[i] == -1 && a[i + 1] == -1) {
            // cout << " here " << i << " " << i + 1 << endl;
            // place at i + 1.
            a[i + 1] = 1;
            a[i] = 0;
            if(i + 2 < n) a[i + 2] = 0;
        } else if(a[i] == -1){
            // place 1 at i.
            // cout << "here2 " << i << endl;
            a[i] = 1;
            if(i - 1 >= 0) a[i - 1] = 0;
            if(i + 1 < n) a[i + 1] = 0;
        }
        i++;
    }
    // cout << s << " : " << n << " -> ";
    for(int i: a) {
        // cout << i << ", ";
        if(i == 1) ans++;
    }

    cout << ans << endl;
}

int main()
{
    // use code runner for C++ in vs code and have input and output.txt file. also modify code runner executer map to this.code-runner.executorMap
    // "cpp": "cd $dir && mkdir -p build && g++ $fileName -o build/$fileNameWithoutExt && build/$fileNameWithoutExt < input.txt > output.txt",
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--){ 
        solve();
        // cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    }
    return 0;
}