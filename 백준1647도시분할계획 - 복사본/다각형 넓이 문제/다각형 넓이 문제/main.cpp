#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    long long cross = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        cross += x[i] * y[j] - y[i] * x[j];
    }
    double area = fabs(cross) / 2.0;
    cout << fixed << setprecision(1) << area << "\n";
    return 0;
}
