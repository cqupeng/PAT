#include<stdio.h>
void fun(int n){
	if(n==0) {
		printf("我的小鲤鱼");
		return; 
	}
	printf("抱着");
	fun(n-1);
	printf("的我");
	
}
int main(){
	int n;
	scanf("%d",&n);
	printf("吓得我抱起了");
	fun(n);
	return 0;
}
