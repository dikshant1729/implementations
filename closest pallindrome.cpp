// C++ Program to find the closest Palindromic number

#include <bits/stdc++.h>
using namespace std;

string closestPalindrome(string n)
{

	vector<long> candidates;
	int len = n.length();

	int mid = (len + 1) / 2;

	if (len == 1)
		return to_string(stoi(n) - 1);

	candidates.push_back(pow(10, len) + 1);
	candidates.push_back(pow(10, len - 1) - 1);

	long prefix = stol(n.substr(0, mid));

	vector<long> temp = { prefix, prefix + 1, prefix - 1 };

	for (long i : temp) {
		string res = to_string(i);
		if (len & 1)
			res.pop_back();
		reverse(res.begin(), res.end());
		string peep = to_string(i) + res;
		candidates.push_back(stol(peep));
	}

	long minDiff = LONG_MAX, result, tip = stol(n);

	for (int i = 0; i < 5; i++) {
		cout<<candidates[i]<<endl;
		if (candidates[i] != tip
			&& minDiff > abs(candidates[i] - tip)) {
			result = candidates[i];
			minDiff = abs(candidates[i] - tip);
		}
		else if (abs(candidates[i] - tip) == minDiff)
			result = min(result, candidates[i]);
	}

	return to_string(result);
}

// driver's code
int main()
{
	string num = "17971";
	cout << closestPalindrome(num) << endl;
	return 0;
}
