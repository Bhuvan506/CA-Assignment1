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
    unordered_map<int,int> v;        /*v stores the valid bit for the index*/
    unordered_map<int,int> tag;      /*tag stores the tag value present in the cache for a given index value*/
    long long int h=0,m=0;
    int csk = 64;                   /*cache size in kb*/
    int bs = 4;                      /*block size in bytes*/
    int cs = csk * pow(2,10);        /*cache size in bytes*/
    int cl = cs/bs;                  /*number of cache lines*/
    int off = log(bs)/log(2);        /*number of offset bit*/
    int ib = log(cl)/log(2);         /*number of index bits*/
    int tb = 32-off-ib;              /*number of tag bits*/

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
        n = n >> off;                          /*n is the remaining bits after deleting offset bits*/
        i = n;
        t = n;
        t = t >> ib;                           /*t is the tag bits that is used during tag match*/
        j = i/pow(2,ib);
        j = j << ib;  
        i = i - j;                             /*i is the index bits*/
        if(v[i] == 0)                          /*If valid bit for a given index is zero then it is a miss*/
        {
            m+=1;                              /*m calculates the number of misses*/
            v[i]=1;                            /*update the valid bit to 1*/
            tag[i] = t;                        /*upload data to cache and update the tag field with the tag of index i*/
        }
        else if(v[i] == 1 && tag[i] != t)      /*If there is a valid bit but tag match failed*/
        {
            m+=1;                              /*number of misses is increased by 1*/
            tag[i] = t;                        /*upload data to cache and update the tag field with the tag of index i*/
        }
        else if(v[i] == 1 && tag[i] == t)      /*If there is a valid bit and a successful tag match*/
        {
            h+=1;                              /*h calculate the number of hits*/
        }
    }
    float H = h;
    float M = m;
    float hr = H/(H+M);                        /*hr gives the hit ratio*/
    printf("%f\n",hr);
    hr = hr*100;
    printf("%f\n",hr);                         /*now hr gives the hit rates*/
    return 0;
}