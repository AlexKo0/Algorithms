#include "Sliding_window.h"
#include <deque>
using namespace std;
vector<int> sliding_window(vector<int> v, int k) {
	deque<pair<int, int>> d;
	vector<int> ans;
	int pos;
	for (int i = 0; i < v.size(); ++i) {
		pos = i - k + 1;
		while (!d.empty() && d.front().second < pos) d.pop_front();
		while (!d.empty() && d.back().first >= v[i]) d.pop_back();
		d.push_back({ v[i], i });
		ans.push_back(d.front().first);
	}
	return ans;
}