#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;
#define N 2

int parent[N * N * 4]; // 4개 삼각형을 표현하기 위한 parent 배열

// Find 연산: 경로 압축 적용
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return x;
 
}

// Union 연산: 두 집합을 합침
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) parent[rootX] = rootY;
}

int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;

    // 초기화 (모든 요소를 자기 자신으로 설정)
    for (int i = 0; i < N * N * 4; i++) {
        parent[i] = i;
    }


    // 그래프 구성
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //시작점의 위치를 먼저 파악한다
            int index = (i * n + j) * 4;

            // '/' : (0,3)과 (1,2) 분리
            if (grid[i][j] == '/') {
                unite(index, index + 3);
                unite(index + 1, index + 2);
            }
            // '\\' : (0,1)과 (2,3) 분리
            else if (grid[i][j] == '\\') {
                unite(index, index + 1);
                unite(index + 2, index + 3);
            }
            // ' ' : 모든 삼각형 연결
            else {
                unite(index, index + 1);
                unite(index, index + 2);
                unite(index, index + 3);
            }

            // 인접한 셀 연결
            if (i > 0) unite(index, (index - n * 4) + 2); // 위쪽 삼각형과 연결
            if (j > 0) unite(index + 3, (index - 4) + 1); // 왼쪽 삼각형과 연결
        }
    }

    // 영역 개수 계산
    int regions = 0;
    for (int i = 0; i < n * n * 4; i++) {
        if (find(i) == i) regions++;
    }
    return regions;
}


int main() {

    char** grid = new char* [2];
    for (int i = 0; i < 2; i++) {
        grid[i] = new char[2];

        
    }
    grid[0][0] = '/';
    grid[0][1] = ' ';
    grid[1][0] = '/';
    grid[1][1] = ' ';

    //char grid[2][2] = { {'/', ' '},{'/', ' '} };
    cout << regionsBySlashes(grid, 2);
}
