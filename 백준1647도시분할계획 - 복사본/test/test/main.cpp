
#include <iostream>
#include <memory>
using namespace std;

int main() {
    int row = 5, col = 10;

    // shared_ptr 배열 생성
    shared_ptr<shared_ptr<int[]>[]> seat(new shared_ptr<int[]>[row]);
    for (int i = 0; i < row; ++i) {
        seat[i] = make_shared<int[]>(col);  // 각 열 배열 동적 할당
    }

    // 테스트 출력
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            seat[i][j] = i * col + j;  // 예제 데이터
            cout << seat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}