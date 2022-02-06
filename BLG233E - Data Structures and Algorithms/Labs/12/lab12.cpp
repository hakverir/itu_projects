#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;
set <string> stopwords;
map <string,int> freq;
bool isLetter(char x)
{
    if((x>64 && 91>x) || (x>96 && 123>x))
        return true;
    return false;
}
int main()
{
    ifstream file;
    string x;
    int count=0;
    file.open ("stopwords.txt", ifstream::in);
    while(file.good())
    {
        file >> x;
        if(x.length()!=1)
            stopwords.insert(x);
    }
    file.close();
    file.open ("input.txt", ifstream::in);
    char y;

    while(file.good())
    {
        file.get(y);

        if(isLetter(y))
        {
            x=x+y;
        }
        else
        {
            if(stopwords.find(x)!=stopwords.end())//found
            {
                count++;
                freq[x]++;
                //cout <<x<<endl;
            }
            x.clear();
        }
    }
    file.close();
        int tempint=0;
        map<string,int>::iterator tempitr;
    for (map<string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)
        {
            tempint=0;
            for (map<string,int>::iterator it2=freq.begin(); it2!=freq.end(); ++it2)
            if(it2->second > tempint)
             {
                 tempint=it2->second;
                 tempitr=it2;


             }

             cout << tempitr->first << " " << tempitr->second<<"   "<< (float)tempitr->second/float(count)*100<<endl;

             tempitr->second=0;
        }

}
