#include<iostream>
using namespace std;
int preorder[50011], inorder[50011];
int flag = 1;
void function(int preleft, int preright, int inleft, int inright) {
	if (flag == 0) return;
	if (preleft > preright) return;
	if (inleft > inright) return;
	int pos = inleft;
	while (inorder[pos] != preorder[preleft]) pos++;
	function(preleft + 1, preleft + pos - inleft, inleft, pos - 1);
	function(preleft + pos - inleft + 1, preright, pos + 1, inright);
	if (flag) {
		cout << preorder[preleft];
		flag = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> preorder[i];
	for (int i = 0; i < N; i++) cin >> inorder[i];
	function(0, N - 1, 0, N - 1);
	return 0;
}