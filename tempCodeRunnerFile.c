int main() {
    int Maxsize = nxn(N); // nxn 함수 호출 후 리턴 값 저장
    printf("M[%d, %d] = %d\n", maxI+1, maxJ+1, Maxsize); // 출력
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}