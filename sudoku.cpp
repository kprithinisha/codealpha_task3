#include <iostream>
using namespace std;
#define N 9
int grid[N][N] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};
bool isValid(int r,int c,int n){
    for(int x=0;x<N;x++) if(grid[r][x]==n||grid[x][c]==n) return false;
    int sr=r-r%3, sc=c-c%3;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(grid[sr+i][sc+j]==n) return false;
    return true;
}
bool solve(){
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) if(grid[r][c]==0){
        for(int n=1;n<=9;n++) if(isValid(r,c,n)){ grid[r][c]=n; if(solve()) return true; grid[r][c]=0; }
        return false;
    }
    return true;
}
int main(){
    cout<<"Original:\n"; 
    for(int i=0;i<N;i++){ for(int j=0;j<N;j++) cout<<grid[i][j]<<" "; cout<<"\n"; }
    if(solve()){ 
        cout<<"\nSolved:\n"; 
        for(int i=0;i<N;i++){ for(int j=0;j<N;j++) cout<<grid[i][j]<<" "; cout<<"\n"; } 
    }
}