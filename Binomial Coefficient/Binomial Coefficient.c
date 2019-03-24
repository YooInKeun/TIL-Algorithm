#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void binomial_cal(int(*arr)[MAX_SIZE], int N, int K); // ���װ�� ��� 
void n_k_cal(int(*arr)[MAX_SIZE], int num); // ���װ�� ��� �� �Է� �� (n, k) �� ��� (��, ��� ���� binomial_cal���� ���Ǿ� �־�� ��) 

int main(int argc, char *argv[]) {
	
	int n, k, result;
	int val[MAX_SIZE][MAX_SIZE];
			
	printf("n, k �� �Է� : ");
	
	scanf_s("%d %d", &n, &k);
	
	binomial_cal(val, n, k);
	
	printf("��� �� �Է� : ");
	
	scanf_s("%d", &result);
	
	n_k_cal(val, result);
	
	return 0;
}

void binomial_cal(int(*arr)[MAX_SIZE], int N, int K){
		
		int i, j;
		
		for(i =0 ; i <= N ; i++){
		
		for(j = 0 ; j<=i ; j++){
		
			if(j==0){
				
				arr[i][j] = 1;
				
			}
			
			else if(i == j){
				
				arr[i][j] = 1;
			}
			
			else{
			
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j]; 
			}
		
		}
	}
	
	printf("%d\n", arr[N][K]);
}

void n_k_cal(int(*arr)[MAX_SIZE], int num){
	
	int i, j;
	
	for(i = 0; i< MAX_SIZE ; i++){
		
		for(j=0; j<i; j++){
			
			if(arr[i][j] == num){
				
				printf("%d %d\n", i, j);
			}
			
		}
	}


}
