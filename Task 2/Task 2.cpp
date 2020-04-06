#include <iostream>
#include <vector>

using namespace std;

const struct student {
	string name{};
	double average{};
};

vector<student> wsort_by_average(vector<student> v) {
	if (v.size() > 1) {
		while (true) {
			bool mist = false;
			for (int i = 0; i < v.size() - 1; ++i) {
				if (v[i].average < v[i + 1].average) {
					mist = true;
					student new_s = v[i];
					v[i] = v[i + 1];
					v[i + 1] = new_s;
				}
			}
			if (mist == false)
				break;
		}
	}
	return v;
}

vector<student> filling() {
	vector<student> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		student new_s{};
		int sum{};
		cin >> new_s.name;
		{
			string last_name{};
			cin >> last_name;
			new_s.name = new_s.name + ' ' + last_name;
		}
		for (int j = 0; j < 3; ++j) {
			int mark{};
			cin >> mark;
			sum += mark;
		}
		new_s.average = double(sum) / 3;
		v.push_back(new_s);
	}
	return v;
}

int main() {
	vector<student> v = filling();
	v = wsort_by_average(v);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].name << ' ' << endl;
}