#include<iostream>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<cctype>
#include<string>
using namespace std;
double caculate(double a,double b,char o){
	if(o=='+') return a+b;
	else if(o=='-') return a-b;
	else if(o=='/') return a/b;
	else return a*b;
}
int main() {
	stack<double> num;
	stack<char> op;
	unordered_map<char, int> level;
	level['+'] = level['-'] = 1;
	level['*'] = level['/'] = 2;
	level['('] = level[')'] = 3;
	string input;
	getline(cin, input);
	int len=input.length() ;
	for(int i=0;i<len;i++){
		if(isdigit(input[i]){
			int j=i+1;
			while(isdigit(input[j])) j++;
			double temp=stof(input.substr(i,j-i));
			num.push((temp)) ;
			i=j-1;
		}
		else{
			if(op.empty()) op.push(input[i]);
			else{
				if(input[i]==')'){
					while(op.top() !=')'){
						double n1=num.top();
						num.pop() ;
						double n2=num.top() ;
						num.pop() ;
						n1=caculate(n1,n2,op.top() );
						op.pop() ;
						num.push(n1) ;
					}
				}
				else if(level[input[i]]<=level[op.top() ]){
					double n1=nun.top();
					num.pop() ;
					double n2=num.top() ;
					n1=caculate(n1,n2,op.top() );
					op.pop() ;
					num.pusn(n1);
					op.push(input[i]) ;
				}
				else op.push(input[i]) ;
			}
		}
	}
	printf("%.2lf",num.top() );
	return 0;
}
