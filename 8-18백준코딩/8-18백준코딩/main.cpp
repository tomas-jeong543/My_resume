#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define MINF -100000000000

using namespace std;
vector<int> nums;

vector<int> ans;

void sol(int low, int high)
{
	//cout << low << " " << high << "\n";
	int mid = low + 1;

	if (mid == high)
		return;




	for (int i = low + 1; i < high; i++) {
		if (abs(nums[low] + nums[high] + nums[mid]) > abs(nums[low] + nums[high] + nums[i]))
			mid = i;
	}

	long long Mval = nums[low] + nums[high] + nums[mid];

	if (Mval > 0) {
		while (high - 1 > mid && abs(Mval) > abs(nums[low] + nums[mid] + nums[high - 1])) {
			high -= 1;
			Mval = nums[low] + nums[high] + nums[mid];
		}
	}
	else if (Mval < 0) {
		while (low + 1 < mid && abs(Mval) > abs(nums[low + 1] + nums[mid] + nums[high])) {
			low += 1;
			Mval = nums[low] + nums[high] + nums[mid];
		}
	}
	else {
		cout << nums[low] << " " << nums[mid] << " " << nums[high] << "\n";
		return;
	}

	int left = low + (mid - low) / 2;
	int right = mid + (high - mid) / 2;

	long long Lval = MINF;
	long long Rval = MINF;

	
	if (left > low && left < mid)
		Lval = abs(nums[low] + nums[left] + nums[mid]);

	if (right > mid && right < high)
		Rval = abs(nums[high] + nums[right] + nums[mid]);

	Mval = abs(Mval);
	Rval = abs(Rval);
	Lval = abs(Lval);
	
	if (Mval < Rval && Mval < Lval) {
		cout << nums[low] << " " << nums[mid] << " " << nums[high];
	}
	else if (Lval < Rval) {
		sol(low, left);
	}
	else {
		sol(right, high);
	}

}

int main(){
	stringstream buf;
	string input;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	cin.ignore();
	nums.assign(N, 0);
	ans.assign(3, 0);

	getline(cin, input);
	buf << input;

	for (int i = 0; i < N; i++) {
		buf >> nums[i];
	}
	
	sort(nums.begin(), nums.end());

	//for (auto num : nums)
	//	cout << num << " ";
	//cout << "\n";

	sol(0, nums.size() - 1);
	return 0;
}