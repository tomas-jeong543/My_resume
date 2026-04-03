#include <stdio.h>

int hanoi[1000] = { 0 };


// 아래 함수를 완성하세요
// Complete the function below
int hanoi(int n, char from, char to, char aux) {
    
    int num = 0;
    // Base case: If only one disk, move it and return 1
    if (n == 1)
        return 1;
    // Recursive case:
    // 1. Move (n-1) disks from 'from' to 'aux' using 'to' as auxiliary
    // 2. Move the nth disk from 'from' to 'to'
    // 3. Move (n-1) disks from 'aux' to 'to' using 'from' as auxiliary
    if (hanoi_info[n] != 0) {
        return hanoi_info[n];
    }
    else {
        num += hanoi(n - 1, from, to, aux);
        num += 1;
        num += hanoi(n - 1, from, to, aux);
        hanoi_info[n] = num;
        // Return total number of moves
        return  hanoi_info[n];
    }
   
}

int main() {
    int n = 3;
    printf("Enter the number of disks: ");
    scanf_s("%d", &n);

    int moves = hanoi(n, 'A', 'C', 'B'); // Move n disks from A to C using B
    printf("Total moves required: %d\n", moves);

    return 0;
}