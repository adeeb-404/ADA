#include <bits/stdc++.h>

using namespace std;

int main()
{
    string text ="0100000";
    string pat = "10000";
    bool flag = false;
    for(int i=0;i<1000;i++)
        text +='0';
    
    int n = text.size(),m = pat.size();
    vector<int> hash(2,m);
    
    for(int i=0;i<m-1;i++)
        hash[pat[i]-'0'] = m-i-1;
        
    int i=m-1;
    int count =0;
    while(i<n){
        int k=0;
        while(++count&&k<m&&text[i-k]==pat[m-k-1])
            k++;
        
        if(k==m){
        cout<<"Done\n";
        flag = true;
        break;    
        }   
        else i += hash[text[i]-'0'];
    }
    
    if(!flag) cout<<"Does not match"
    
    return 0;
}
