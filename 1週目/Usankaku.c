#include<stdio.h>
#include<math.h>
#define N 6

int main(){
	int k, j, n;
	char z, zz;
	static double p, s, a[N][N+1], x[N];
	while(1){
		printf("上三角型連立1次方程式の解法 \n");
		printf("未知数の個数 n を入力してください。(1 < n < 7) n = ");
		scanf("%d%c", &n, &zz);
		if((n <= 1) || (7 <= n)) continue;
		printf("係数と右辺の値を入力してください。\n\n");

		for(k = 0; k < n; k++){
			printf("第%d式\n", k+1);
			for(j = k; j < n;j++){
				printf("        x%dの係数 = ", j+1);
				scanf("%lf%c", &a[k][j], &zz);
			}
			printf("\n        右辺の値 = ");
			scanf("%lf%c", &a[k][n], &zz);
			printf("\n");
		}
		printf("正しく入力しましたか。(y/n) ");
		scanf("%c%c", &z,&zz);
		if(z == 'y') break;
	}

	for(k = 0; k < n; k++){
		p = a[k][k];
		if(fabs(p) < 1.0e-6){
			printf("一意解を持ちません．\n");
			exit(-1);
		}
		for(j = k; j < n+1; j++) a[k][j] = a[k][j] / p;
	}
	for(k = n-1; k >= 0; k--){
		s = 0.0;
		for(j = k+1; j < n ;j++){
			s = s + a[k][j] * x[j];
		}
		x[k] = a[k][n]-s;
	}
	printf("上三角型連立1次方程式の解\n\n");
	for(k = 0;k < n; k++) printf("        x%d =    %lf\n", k+1, x[k]);
}