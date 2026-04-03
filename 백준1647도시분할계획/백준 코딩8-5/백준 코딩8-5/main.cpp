#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 3000000001

using namespace std;


int bineary_search(vector<int>& nums,int left, int right) {

	int mid = left + (right - left) / 2;

	int leftcal, rightcal, midcal , leftpos, rightpos;

	while (mid > left && mid < right) {


		cout << "mid: " << mid << "\n";
		leftpos = left + (mid - left) / 2;
		rightpos = mid + (right - mid) / 2;

		midcal = abs(nums[left] + nums[mid] + nums[right]);
		leftcal = abs(nums[left] + nums[leftpos] + nums[mid]);
		rightcal = abs(nums[mid] + nums[rightpos] + nums[right]);

		cout << leftcal << " " << midcal << " " << rightcal << "\n";

		if (midcal <= leftcal && midcal <= rightcal) {
			return mid;
		}
		else if (leftcal < rightcal) {
			right = mid;
		}
		else {
			left = mid;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	stringstream buf;
	long long sum = INF;
	int N;
	long long start = 0, end = 0, mid = 0;
	long long left, right , middle;
	vector<int> nums;
	pair<long long, int> info;
	pair<long long, int> ins;
	info.first = -1, info.second = -1;

	cin >> N;
	cin.ignore();
	nums.assign(N, 0);

	getline(cin, input);
	buf << input;

	for (int i = 0; i < N; i++) {
		buf >> nums[i];
	}

	sort(nums.begin(), nums.end());

	for (auto num : nums) {
		std::cout << num << " ";
	}
	std::cout << "\n";

	
	for (int i = 0; i < N; i++) {
		for (int j = i + 2; j < N; j++) {
			int ins = bineary_search(nums, i, j);
			//cout << "ins: " << ins << "\n";

			if (sum > abs(nums[i] + nums[j] + nums[ins])) {
				//cout << "here\n";
				sum = abs(nums[i] + nums[j] + nums[ins]);
				mid = ins;
				start = i;
				end = j;
				cout << start << " " << mid << " " << end << "\n";
			}
			else {
				break;
			}
		}
	}

	std::cout << nums[start] << " " << nums[mid] << " " << nums[end] << "\n";

	return 0;
}