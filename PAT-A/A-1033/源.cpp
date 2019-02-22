#include<stdio.h>
#include<algorithm>
using namespace std;
struct station{
	double price;
	double dis;
}sta[501];
bool cmp(station a, station b){
	if (a.dis != b.dis) return a.dis < b.dis;
	else return a.price < b.price;
}
int main(){
	double tankmax, alldis, dis_per_gas;
	int N;
	scanf("%lf%lf%lf%d", &tankmax, &alldis, &dis_per_gas, &N);
	for (int i = 0; i < N; i++){
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}
	sta[N].dis = alldis;
	sta[N].price = 0;
	sort(sta, sta + N, cmp);
	double fee = 0.0, dissum = 0;//fee���ܷ��ã�dissum���ܾ���
	double tempgas = 0;
	double per_tank_dis = tankmax * dis_per_gas;//�������ܵľ���
	int i = 0;//��㣻
	int flag = 1;//�����Ƿ��ܹ������յ�����������
	if (sta[0].dis != 0) flag = 0;//������û�м���վֱ��ֹͣ
	else{
		while (i <= N){
			if (i == N) break;//�����ǰ���յ����ѭ��
			else{
				int nextflag = 0;//�����ܷ��ҵ�һ����ȥ��վ
				int nextsta = i + 1;//��һ��վ
				int minsta = i + 1;//�������ͼ���͵ļ���վ���߽���������Զ�����ڵ�����վ���ͼ���͵�
				while ((sta[nextsta].dis - sta[i].dis) <= per_tank_dis){
					if (sta[nextsta].price <= sta[i].price){//�����һ��վ�ȵ�ǰվ�ͼ۵�ֱ�ӳ���
						minsta = nextsta;
						nextflag = 1;
						break;
					}
					else if (sta[nextsta].price <= sta[minsta].price){ //�����һ��վ�ȵ�ǰվ�ͼ۸ߵ����Ǿ����ڵ�����ͼ�վ
						minsta = nextsta;
						nextsta++;
						nextflag = 2;
					}
					else nextsta++;
				}
				if (nextflag == 1){
					fee += ((sta[minsta].dis - sta[i].dis) / dis_per_gas - tempgas)*sta[i].price;
					dissum += sta[minsta].dis - sta[i].dis;
					i = minsta;
					tempgas = 0;
				}
				else if (nextflag == 2){
					fee += (tankmax - tempgas) * sta[i].price;
					dissum += sta[minsta].dis - sta[i].dis;
					tempgas = tankmax - (sta[minsta].dis - sta[i].dis) / dis_per_gas;
					i = minsta;
				}
				else{
					flag = 0;
					dissum += per_tank_dis;
					break;
				}

			}
		}
	}
	if (flag){
		printf("%.2f", fee);
	}
	else{
		printf("The maximum travel distance = %.2f", dissum);
	}
	system("pause");
	return 0;
}
