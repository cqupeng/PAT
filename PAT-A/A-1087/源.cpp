#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int INF = 0x3f3f3f3f;
const int Maxn = 222;
int happiness[Maxn];
int N, K;
string start;
struct edge {
	int v, cost;
};
vector<edge> city[Maxn];
bool vis[Maxn] = { 0 };
int dis[Maxn];
vector<int> pre[Maxn];//Ç°Çý
void Dijkstra(int root) {
	fill(dis, dis + Maxn, INF);
	dis[root] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, mindis = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == 0 && dis[j] < mindis) {
				u = j;
				mindis = dis[j];
			}
		}
		if (u == -1) return;
		vis[u] = 1;
		for (auto it = city[u].begin(); it != city[u].end(); it++) {
			if (vis[it->v] == false && dis[u] + it->cost < dis[it->v]) {
				dis[it->v] = dis[u] + it->cost;
				pre[it->v].clear();
				pre[it->v].push_back(u);
			}
			else if (vis[it->v] == false && dis[u] + it->cost == dis[it->v]) {
				pre[it->v].push_back(u);
			}
		}
	}
}
vector<int> result_path, temp_path;
int max_hap = 0, max_ave_hap = 0, cnt = 0;
void DFS(int root) {
	if (root == 0) {
		temp_path.push_back(root);
		cnt++;
		int temp_hap = 0, temp_ave;
		for (int i = temp_path.size() - 2; i >= 0; i--) {
			temp_hap += happiness[temp_path[i]];
		}
		temp_ave = temp_hap / (temp_path.size()-1);
		if (temp_hap > max_hap||(temp_hap == max_hap && max_ave_hap < temp_ave)) {
			max_hap = temp_hap;
			max_ave_hap = temp_ave;
			result_path = temp_path;
		}
		temp_path.pop_back();
		return;
	}
	temp_path.push_back(root);
	for (auto it = pre[root].begin(); it != pre[root].end(); it++) {
		DFS(*it);
	}
	temp_path.pop_back();
	return;
}
int main() {
	ios::sync_with_stdio(false);
	unordered_map<string, int> city_id;
	string city_name[Maxn];
	cin >> N >> K >> start;
	city_id[start] = 0;
	city_name[0] = start;
	for (int i = 1; i < N; i++) {
		string temp_city;
		int temp_hap;
		cin >> temp_city >> temp_hap;
		city_id[temp_city] = i;
		happiness[i] = temp_hap;
		city_name[i] = temp_city;
	}
	for (int i = 0; i < K; i++) {
		string c1, c2;
		int dis;
		cin >> c1 >> c2 >> dis;
		edge e1, e2;
		e1.v = city_id[c1];
		e2.v = city_id[c2];
		e1.cost = dis;
		e2.cost = dis;
		city[city_id[c1]].push_back(e2);
		city[city_id[c2]].push_back(e1);
	}
	Dijkstra(0);
	DFS(city_id["ROM"]);
	cout << cnt << ' ' << dis[city_id["ROM"]] << ' ' << max_hap << ' ' << max_ave_hap << '\n';
	cout << start;
	for (int it = result_path.size() - 2; it >= 0; it--) {
		cout << "->" << city_name[result_path[it]];
	}
	return 0;
}
