#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& h) {
        int i=0;
        int j=h.size()-1;
        int max=0;
        while(i<j){
            int m=h[i]>h[j]?h[j]:h[i];
            int area= m*(j-i);
            max=max>area?max:area;
            if(h[i]>h[j])j--;
            else i++;
        }
        return max;
    }

int main(){
    vector<int> mp={1,8,6,2,5,4,8,3,7};
    cout<<"max water: "<<maxArea(mp);
    return 0;
}