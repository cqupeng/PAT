#include<stdio.h>
void fun(int n){
	if(n==0) {
		printf("�ҵ�С����");
		return; 
	}
	printf("����");
	fun(n-1);
	printf("����");
	
}
int main(){
	int n;
	scanf("%d",&n);
	printf("�ŵ��ұ�����");
	fun(n);
	return 0;
}
