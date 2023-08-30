#include <bits/stdc++.h>

using namespace std;

int main()
{
  
    // string matching
    
    string text = "adnanamna";
    string pattern = "ananama";
    int n = text.size();
    int m = pattern.size();
    vector<int> hash(27,m);
    
    for(int i=0;i<m-1;i++)
        hash[pattern[i]-'a'] = m-1-i;
        
    //horse
    int i=m-1;
    while(i<n){
        int k=0;
        while(k<m&&pattern[m-k-1]==text[i-k])
            k++;
        if(k==m){
            cout<<"Matched at index "<<i-k+1<<endl;
            break;
        }
        else    i+= hash[text[i]-'a'];
    }
return 0;
}
