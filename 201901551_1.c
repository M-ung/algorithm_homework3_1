#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5 // 행렬의 길이

int M[N+1][N+1]; // DP를 사용하여 현재 위치에서의 가장 큰 정사각형의 길이를 저장할 2차원 배열
int maxSize = 0; // 가장 큰 정사각형의 길이
int maxI = 0, maxJ = 0; // 가장 큰 정사각형의 우측 하단 좌표

// n*n 크기의 배열을 생성하는 함수
int** makeMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));

    srand(time(NULL)); // 난수 생성기 초기화

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2; // 0 또는 1로 이루어진 행렬을 생성
        }
    }

    return matrix;
}

// n*n 크기의 배열을 출력하는 함수
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 세 정수 중 최솟값을 반환하는 함수
int min(int a, int b, int c) {
    if (a < b) return a < c ? a : c;
    else return b < c ? b : c;
}

// n x n 정사각형 내에서 조건에 맞는 가장 큰 정사각형의 길이를 찾는 함수
int nxn(int** A) {
    // 시간 복잡도: O(N^2), N은 행렬의 길이
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            // 행렬의 첫 번째 행 또는 열인 경우, 최대 길이는 1
            if (i == 1 || j == 1) {
                M[i][j] = 1;
            }
            // A[i][j] 기준으로 왼쪽 위 대각선과는 같고 왼쪽, 위쪽과는 다르다면, 정사각형 크기를 갱신
            else if (A[i-1][j-1] != A[i-2][j-1] && A[i-1][j-1] != A[i-1][j-2] && A[i-1][j-1] == A[i-2][j-2]) {
                M[i][j] = min(M[i][j-1], M[i-1][j], M[i-1][j-1]) + 1;
            } else {
                // 번갈아 나오는 패턴이 아닌 경우
                M[i][j] = 1;
            }
            
            // 가장 큰 정사각형의 길이 갱신
            if (M[i][j] > maxSize) {
                maxSize = M[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    return maxSize; // 가장 큰 정사각형의 길이 반환
}

int main() {
    int** A = makeMatrix(N); // N x N 행렬 생성
    printMatrix(A, N); // 생성된 행렬 출력
    
    int Maxsize = nxn(A); // nxn 함수 호출하여 가장 큰 정사각형의 길이를 찾음
    printf("M[%d, %d] = %d\n", maxI, maxJ, Maxsize); // 가장 큰 정사각형의 위치와 길이 출력

    // DP 배열 M 출력
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N+1; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    // 동적 할당한 메모리 해제
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
    
    return 0;
}
