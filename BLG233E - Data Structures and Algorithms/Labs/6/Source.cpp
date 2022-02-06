#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Header.h"

using namespace std;

StackOP s;

int main(){
	char infix[15];
	char postfix[15];
	infix[0] = '\0';
	postfix[0] = '\0';
	cout << "enter the problem" << endl;
	cin.getline(infix, 15);

	int i = 0;
	int j = 0;

	while (infix[i] != '\0'){
		if (isdigit(infix[i]) != 0){
			postfix[j] = infix[i];
			j++;
			i++;
		}

		else{
			if (s.isempty() || infix[i] == '('){
				s.push(infix[i]);
				i++;
				continue;
			}

			if (!s.isempty()){
				if ((s.topStack == '*' || s.topStack == '/') && (infix[i] == '+' || infix[i] == '-')){
					while (!s.isempty() && (s.topStack == '*' || s.topStack == '/') && (infix[i] == '+' || infix[i] == '-')){
						postfix[j] = s.pop();
						j++;
					}
					s.push(infix[i]);
					i++;
					continue;
				}
				else{
					s.push(infix[i]);
					i++;
				}
				while ((s.topStack != '(') && (infix[i] == ')')){
					postfix[j] = s.pop();
					j++;
				}

			}
		}
	}

	if (!s.isempty()){
		postfix[j] = s.pop();
		j++;
	}

	int k = 0;

	while (postfix[k] != '\0'){
		cout << postfix[k];
		k++;
	}

	getchar();
	return 0;
}