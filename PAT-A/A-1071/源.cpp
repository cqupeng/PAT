#include<string>
#include<iostream>
#include<cctype>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	unordered_map<string, int> hash;
	string word, input;
	vector<string> output;
	int maxcnt = 0;
	getline(cin, input);
	input.insert(input.end(), ' ');
	for (auto it = input.begin(); it != input.end(); it++) {
		if (isalnum(*it)) {
			if (isupper(*it)) *it = tolower(*it);
			word.insert(word.end(), *it);
		}
		else if (word.size() != 0) {
			hash[word]++;
			if (hash[word] > maxcnt) {
				maxcnt = hash[word];
				output.clear();
				output.push_back(word);
			}
			else if (hash[word] == maxcnt) output.push_back(word);
			word.clear();
		}
	}
	sort(output.begin(), output.end());
	printf("%s %d", output.begin()->c_str(), maxcnt);
	return 0;
}