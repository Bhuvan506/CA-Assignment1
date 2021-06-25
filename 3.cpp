#include<bits/stdc++.h>
#include<math.h>
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
using namespace std;

int main(){
    char filename[100];
    scanf("%s",filename);
    unordered_map<int,int> v;
    unordered_map<int,int> tag;
    long long int h=0,m=0;
    std::ifstream file(filename);
    string function, addressinhex;
    long long int data;
    string line;
    while(getline(file,line)){
        istringstream iss(line);
        if(!(iss >> function >> addressinhex >> data)) {break;}
        char addr[11];
        strcpy(addr,addressinhex.c_str());
        string address;
        for(int i=2; i<10; i++) address += addr[i];
        long long int n = stol(address,0,16);
        long long int i,t,j;
        n = n >> 2;
        i = n;
        t = n;
        t = t >> 14;
        j = i/pow(2,14);
        j = j << 14;  
        i = i - j;
        if(v[i] == 0)
        {
            m+=1;
            v[i]=1;
            tag[i] = t;
        }
        else if(v[i] == 1 && tag[i] != t)
        {
            m+=1;
            tag[i] = t;
        }
        else if(v[i] == 1 && tag[i] == t)
        {
            h+=1;
        }
    }
    cout << h << endl;
    cout << m << endl;
    return 0;
}