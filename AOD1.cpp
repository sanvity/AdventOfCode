//AOD1: 1197984
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm> 

using namespace std;
int main(){
    vector<int> l = {3, 4, 2, 1, 3, 3};
    vector<int> r = {4, 3, 5, 3, 9, 3};
    
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    
    vector<int> difference;
    int sum=0;
    for (size_t i = 0; i < l.size(); ++i){
        difference.push_back(abs(l[i] - r[i]));
        sum=sum + abs(l[i] - r[i]);
    }
    

//print both l,r
    for (int i : l)
        cout << i << " ";
    cout<<"\n";
    for (int i : r)
        cout << i << " ";
    cout<<"\n";    
    for (int i : difference)
        cout << i << " ";    
    cout<<"\n"<<sum;    
    
    return 0;}
