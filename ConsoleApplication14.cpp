#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Sliding_window.h"
#define all(v) v.begin(), v.end()
using namespace std;
template<class _Pr = less<int>>
int bin_search(vector<int> v, int val, _Pr p = _Pr()) {
    int l, r, m;
    l = 0;
    r = v.size();
    while (l < r - 1) {
        m = (r - l) / 2 + l;
        if (p(val, v[m])) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return l;
}
int main()
{
    vector<int> v({ 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3 });
    auto l = lower_bound(all(v), 2);
    auto r = upper_bound(all(v), 2);
    cout << *l << ' ' << *r;
    for (; l != r; ++l){
        cout << *l << ' ';
    }
    
}
