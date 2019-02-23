#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
struct node{
	int data;
	node* left_child = NULL;
	node* right_child = NULL;
};
int N;//节点总数
void insert_node(node* &root, int x){
	if (root == NULL){
		node* temp = new node;
		temp->data = x;
		root = temp;
	}
	else if (x >= root->data) insert_node(root->right_child, x);
	else insert_node(root->left_child, x);
}
void DFS_pri(node* root, vector<int> &p){
	if (root == NULL) return;
	p.push_back(root->data);
	DFS_pri(root->left_child, p);
	DFS_pri(root->right_child, p);
	return;
}
int n = 0;
vector<int> output;
void DFS_pos(node* root){
	if (root == NULL) return;
	DFS_pos(root->left_child);
	DFS_pos(root->right_child);
	output.push_back(root->data);
	return;
}
void mirror_tree(node* root){
	if (root == NULL) return;
	if (root->left_child != NULL || root->right_child != NULL){
		node* temp;
		temp = root->left_child;
		root->left_child = root->right_child;
		root->right_child = temp;
		mirror_tree(root->left_child);
		mirror_tree(root->right_child);
	}
	return;
}
int main(){
	scanf("%d", &N);
	node* root = NULL;
	vector<int> input;
	for (int i = 0; i < N; i++){
		int temp_data;
		scanf("%d", &temp_data);
		input.push_back(temp_data);
		insert_node(root, temp_data);//前序建树
	}
	vector<int> pri, mir_pri;
	DFS_pri(root, pri);
	DFS_pos(root);
	bool flag = 0;
	if (pri == input) flag = 1;
	else{
		mirror_tree(root);
		DFS_pri(root, mir_pri);
		if (mir_pri == input){
			flag = 1;
			output.clear();
			DFS_pos(root);
		}
	}
	if (flag == 0) printf("NO\n");
	else{
		printf("YES\n");
		for (int i = 0; i < N; i++){
			printf("%d", output[i]);
			if (i != N - 1) printf(" ");
		}
	}
	system("pause");
	return 0;
}