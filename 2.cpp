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
    int csk = 512;
    int bs = 4;
    int cs = csk * pow(2,10);
    int cl = cs/bs;
    int off = log(bs)/log(2);
    int ib = log(cl)/log(2);
    int tb = 32-off-ib;

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
       n = n >> off;
        i = n;
        t = n;
        t = t >> ib;
        j = i/pow(2,ib);
        j = j << ib;  
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
    float H = h;
    float M = m;
    float hr = H/(H+M);
    printf("%f\n",hr);
    return 0;
}