#include <bits/stdc++.h>

using namespace std;


unordered_map<string, pair<int,int>>db;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
int c, n, d,rest;
string e , sd;

cin>>c;

for(int b = 0; b<c;++b){
   cin>>n;
   if(n>0){
   for(int y = 0; y<n ; ++y){
      cin>>e;
      auto exist = db.find(e);
      if(exist != db.end()){
          (int&)exist->second.first+=1;
          continue;
      }
      db.insert({e, {1,0}});
   }


   cin>>d;

   if(d>0){
      for(int x = 0; x<d ; ++x){
      cin>>sd;
      auto exist = db.find(sd);
      if(exist != db.end()){
          (int&)exist->second.second+=1;
          continue;
      }
      db.insert({sd, {0,1}});
   }
   }
   
}
}

unordered_set<string>max;

for(auto&c:db){
    if((c.second.first - c.second.second)>=0){
        max.insert(c.first);
    }
}

cout<<max.size()<<" ";
for(auto&l:max){
    cout<<l<<" ";
}

return 0;
}
