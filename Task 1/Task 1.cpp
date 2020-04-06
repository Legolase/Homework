#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N < 100000) {
		vector<int> v;
		for (int i = 0; i < N; ++i) {
			int j{};
			cin >> j;
			v.push_back(j);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int j : v)
			cout << j << ' ';
	}
	else
		cout << "The last number is more than access value!";
}