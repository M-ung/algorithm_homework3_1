#include <stdio.h>
#define N 5 // 행렬의 크기

int M[N][N]; // DP를 사용하여 현 위치에서의 가장 큰 정사각형의 크기를 저장할 2차원 배열
int maxSize = 0; // 최대 정사각형의 크기
int maxI = 0, maxJ = 0; // 최대 정사각형의 우측 하단 좌표
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

// n x n 정사각형의 최대 크기를 찾는 함수
int nxn(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 배열의 경계 처리
            if (i == 0 || j == 0) {
                M[i][j] = 1;
            } else if (A[i][j] != A[i-1][j] && A[i][j] != A[i][j-1] && A[i][j] == A[i-1][j-1]) {
                // 인접한 상하좌우 셀들이 번갈아 나오는 패턴을 이루는 경우, 정사각형 크기를 갱신
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
    int size = nxn(N); // nxn 함수 호출 후 리턴 값 저장
    printf("M[%d, %d] = %d\n", maxI+1, maxJ+1, size); // 출력
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
