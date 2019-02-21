#include<iostream>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;
struct book_info {
	string id, title, author, publisher, publised_year;
};
int main() {
	unordered_map<string, set<string>> get_id[6];
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		book_info temp;
		getline(cin,temp.id);
		getline(cin, temp.title);
		get_id[1][temp.title].insert(temp.id);
		getline(cin, temp.author);
		get_id[2][temp.author].insert(temp.id);
		string key_word;
		while(1) {
			char key = getchar();
			if (key == ' '||key=='\n') {
				get_id[3][key_word].insert(temp.id);
				key_word.clear();
			}
			else key_word.insert(key_word.end(), key);
			if (key == '\n') break;
		}
		getline(cin, temp.publisher);
		get_id[4][temp.publisher].insert(temp.id);
		getline(cin, temp.publised_year);
		get_id[5][temp.publised_year].insert(temp.id);
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int k;
		scanf("%d%*c%*c", &k);
		string query;
		getline(cin, query);
		printf("%d: %s\n", k, query.c_str());
		for (auto it = get_id[k][query].begin(); it != get_id[k][query].end(); it++) {
			printf("%s\n", (*it).c_str());
		}
		if (get_id[k][query].size() == 0) printf("Not Found\n");
	}
	return 0;
}