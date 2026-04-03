#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int** val;

// nums: 물건 목록, pos: 지금 고려할 인덱스, leftW: 남은 무게, N: 아이템 수, limit: (사용 안 함)
int Dp(pair<int, int>* nums, int pos, int leftW, int N)
{
    // 기저 사례: 더 이상 아이템이 없거나 무게가 0이면 0
    if (pos >= N || leftW == 0)
        return 0;

    // 이미 계산된 조합이 있으면 바로 리턴
    if (val[pos][leftW] != -1)
        return val[pos][leftW];

    int best = 0;
    // pos부터 N-1까지 각각 포함/미포함을 따져본다
    for (int i = pos; i < N; i++) {
        int W = nums[i].first;
        int V = nums[i].second;
        if (leftW >= W) {
            // i번째 물건을 선택했을 때
            int cand = Dp(nums, i + 1, leftW - W, N) + V;
            if (cand > best)
                best = cand;
        }
    }

    // 결과를 메모이제이션
    return val[pos][leftW] = best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    cin.ignore();

    auto prices = new pair<int, int>[N];
    string input;
    stringstream buf;
    for (int i = 0; i < N; i++) {
        getline(cin, input);
        buf.clear();  buf.str(input);
        buf >> prices[i].first >> prices[i].second;
    }

    // val[pos][w]를 -1로 초기화
    val = new int* [N];
    for (int i = 0; i < N; i++) {
        val[i] = new int[K + 1];
        for (int w = 0; w <= K; w++)
            val[i][w] = -1;
    }

    cout << Dp(prices, 0, K, N) << "\n";
    return 0;
}
