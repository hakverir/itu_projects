#include<iostream>
#include<set>
#include<map>
#include<string>
#include<cstdio>
using namespace std;

int main(){
	FILE *wordfile=freopen("stopwords.txt", "r", stdin);
	("temp.txt", "w+", stdout);
	set<string> stopwords;
	set<string>::iterator mystit;

	char temp[20] = " ";
	char c = ' ';
	int i = 0;
	while (!feof(wordfile)){
		while (c != '\n' || !feof(wordfile)){
			scanf("%c", &c);
			temp[i++] = c;
		}
		if (feof(wordfile))
			break;
		c = ' ';
		i = 0;
		stopwords.insert(temp);
	}
	for (mystit = stopwords.begin(); mystit != stopwords.end(); mystit++){
		cout << *mystit << endl;
	}
	getchar();
	getchar();
	return 0;
}