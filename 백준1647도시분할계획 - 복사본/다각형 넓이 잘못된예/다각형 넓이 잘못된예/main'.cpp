#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<vector>
#include <iomanip>
using namespace std;


double CalArea(pair<   double, double> p1, pair<  double, double> p2, pair<  double, double> p3) {

	return abs(p1.first * (p2.second - p3.second) + p2.first * (p3.second - p1.second) + p3.first * (p1.second - p2.second)) / 2.0;
}


int main()
{
	string input;
	stringstream buf;
	int N;
	double x, y;
	double sueface_area = 0;
	vector<pair< double, double>> poses;

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, input);
		buf << input;
		buf >> x >> y;
		//cout << x << " " << y << endl;
		poses.push_back({ x,y });
		buf.str("");
		buf.clear();
	}

	for (int i = 0; i < N - 2; i++) {
		sueface_area += CalArea(poses[0], poses[i + 1], poses[i + 2]);
	}

	double ans = std::round(sueface_area * 100) / 100;

	cout << std::fixed << setprecision(1) << ans << "\n";

	return 0;
}