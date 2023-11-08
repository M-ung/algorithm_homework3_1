#include <stdio.h>
#define N 5 // 행렬의 크기

int M[N+1][N+1]; // DP를 사용하여 현 위치에서의 가장 큰 정사각형의 크기를 저장할 2차원 배열
int maxSize = 0; // 정사각형의 최대 길이
int maxI = 0, maxJ = 0; // 최대 길이를 가진 정사각형의 우측 하단 좌표
int A[N][N] = { // 주어진 0과 1의 행렬 A
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
};

// 세 정수 중에서 최솟값을 반환하는 함수
int min(int a, int b, int c) {
    if (a < b) return a < c ? a : c;
    else return b < c ? b : c;
}

// n x n 정사각형 안에서 조건에 맞는 최대 크기 정사각형을 찾는 함수
int nxn(int n) {
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (A[i-1][j-1] != A[i-2][j-1] && A[i-1][j-1] != A[i-1][j-2] && A[i-1][j-1] == A[i-2][j-2]) {
                // A[i][j] 기준으로 왼쪽 위 대각선과는 같고 왼쪽, 위쪽과는 다르다면, 정사각형 크기를 갱신
                M[i][j] = min(M[i][j-1], M[i-1][j], M[i-1][j-1]) + 1;
            } else {
                // 번갈아 나오는 패턴이 아닌 경우
                M[i][j] = 1;
            }
            
            // 최대 정사각형 크기 갱신
            if (M[i][j] > maxSize) {
                maxSize = M[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    return maxSize; // 최대 정사각형 크기 반환
}

int main() {
    int Maxsize = nxn(N); // nxn 함수 호출 후 리턴 값 저장
    printf("M[%d, %d] = %d\n", maxI, maxJ, Maxsize); // 출력
    
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N+1; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}