#include <bits/stdc++.h>
#include<math.h>
#include<unordered_map>
using namespace std;

int main()
{
    int x;
    cin >> x;
    unordered_map<int,int> v;
    unordered_map<int,int> tag;
    int h=0,m=0;
    for (int k=0;k<x;k++)
    {
        int n,i,t,j;
        scanf("%X",&n);
        n = n >> 2;
        i = n;
        t = n;
        t = t >> 14;
        j = i/pow(2,14);
        j = j << 14;  
        i = i - j;
        //printf("%#X\n",i);
        //printf("%#X\n",t);
        if(v[i] == 0)
        {
            m+=1;
            v[i]=1;
            tag[i] = t;
            //cout << V[i] << endl;
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