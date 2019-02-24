#include<stdio.h>
#include<string.h>
char input[11000];
char n2[1000];
int main(){
	fgets(input, sizeof(input), stdin);
	char fuhao1,fuhao2, n1;
	int n3;
	sscanf(input, "%c%c.%[0-9]%*c%c%d", &fuhao1, &n1, &n2, &fuhao2, &n3);
	if (fuhao1 == '+');
	else printf("-");
	if (fuhao2 == '+'){
		putchar(n1);
		int j = 0;
		int length = strlen(n2);
		if (length > n3){
			for (int i = 0; i < n3; i++){
				putchar(n2[i]);
				j = i + 1;
			}
			putchar('.');
			while (n2[j] != '\0'){
				putchar(n2[j]);
				j++;
			}
		}
		else{
			int i = n3 - length;
			printf("%s", n2);
			while (i--)
				printf("0");
		}
	}
	else{
		if (n3 == 0) printf("%c.%s", n1, n2);
		else{
			printf("0.");
			n3--;
			while (n3 > 0){
				putchar('0');
				n3--;
			}
			printf("%c%s", n1, n2);
		}
	}
	return 0;
}