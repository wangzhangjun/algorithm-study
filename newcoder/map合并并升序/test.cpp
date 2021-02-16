//
// Created by zhjwang on 2021-02-16.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
#include <typeinfo>
#include<map>

using namespace std;

/*
 * map本身就是按照key升序的顺序存储的.
 * 如果想让降序，可以指定greater,就表示降序，按照字典序
 * map<string, int, greater<string> > map;
 * */
void mapHebingPaixu()
{
    int n;
    map<int,int> m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        pair<int,int> tmp;
        cin>>tmp.first;  //遇到空格停止
        cin>>tmp.second;
        if((m.find(tmp.first))!=m.end())
            m[tmp.first]+=tmp.second;
        else
            m[tmp.first]=tmp.second;
    }
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;

}

int main()
{
    mapHebingPaixu();
    return 0;
}
