#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    vector<int> arr{23,54,66,76,98};
    vector<int>::iterator val;
    val = lower_bound(arr.begin(), arr.end(), 55);
    cout<<"lower bound :"<<val-arr.begin();
}