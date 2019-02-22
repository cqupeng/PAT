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
	double fee = 0.0, dissum = 0;//fee：总费用；dissum：总距离
	double tempgas = 0;
	double per_tank_dis = tankmax * dis_per_gas;//满油能跑的距离
	int i = 0;//起点；
	int flag = 1;//代表是否能够到达终点决定最后的输出
	if (sta[0].dis != 0) flag = 0;//如果起点没有加油站直接停止
	else{
		while (i <= N){
			if (i == N) break;//如果当前是终点结束循环
			else{
				int nextflag = 0;//代表能否找到一个能去的站
				int nextsta = i + 1;//下一个站
				int minsta = i + 1;//接下来油价最低的加油站或者接下来的最远距离内的所有站里油价最低的
				while ((sta[nextsta].dis - sta[i].dis) <= per_tank_dis){
					if (sta[nextsta].price <= sta[i].price){//如果下一个站比当前站油价低直接出发
						minsta = nextsta;
						nextflag = 1;
						break;
					}
					else if (sta[nextsta].price <= sta[minsta].price){ //如果下一个站比当前站油价高但是是距离内的最低油价站
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
