#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n) {
        if(n==0) return {{}};
        vector<vector<int>> result(n);
        result[0]={1};
        for(int i=1;i<n;i++){
            result[i].push_back(1);
            for(int k=0;k<result[i-1].size()-1;k++){
                if(result[i-1].size()==1) break;
                result[i].push_back(result[i-1][k]+result[i-1][k+1]);
            }
            result[i].push_back(1);
        }
        return result;
}
int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    vector<vector<int>> mp=generate(n);
    for(int i=0;i<mp.size();i++){
        for(int j=0;j<mp[i].size();j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}