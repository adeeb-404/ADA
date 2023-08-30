#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<bool> fd,bd,c;
bool valid(vector<string> &grid,int row,int col,int n){
    return fd[row+col]==false&&bd[row-col+n-1]==false&&c[col]==false;
}

void solve(vector<string> &grid,int row,int n){
    
    if(row==n){
        ans.push_back(grid);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(valid(grid,row,i,n)){
            fd[row+i]=true;
            bd[row-i+n-1]=true;
            c[i]=true;
            grid[row][i]='Q';
            solve(grid,row+1,n);
            grid[row][i]='.';
            fd[row+i]=false;
            bd[row-i+n-1]=false;
            c[i]=false;
        }
    }
}


int main()
{
    
    int n;
    cout<<"Enter N of N-Queens\n"<<endl;
    cin>>n;
    fd.resize(2*n-1,false);
    bd.resize(2*n-1,false);
    c.resize(n,false);
    
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        string s="";
        for(int j=0;j<n;j++){
            s +='.';
        }
        grid[i]=s;
    }
    
    solve(grid,0,n);
    if(ans.size()==0)   cout<<"Not possible\n";
    else{
    cout<<"The valid combinations are:\n";
    
    for(auto g : ans){
        for(auto r : g){
            for(auto c : r){
                cout<<c<<" ";
            }
            cout<<endl;
        }
        cout<<"\n\n";
    }
}
    return 0;
}


