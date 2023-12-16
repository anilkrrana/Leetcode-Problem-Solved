#include<bits/stdc++.h>
using namespace std;
void solve(){
   int n;
   cin>>n;
   queue<int> q;
   for(int i=1;i<=n;i++){
       q.push(i);
   }
   while(q.size()>1){
       int x=q.front();
       q.pop();
       q.pop();
       q.push(x);
   }
   cout<<q.front()<<endl;;
}
int main()
{
int t;
cin>>t;
while(t--){
    solve();
}
return 0;
}