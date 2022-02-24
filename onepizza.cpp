#include <bits/stdc++.h>
#define in :
using namespace std;

typedef long long like, dislike;

unordered_map<string, pair<like,dislike>>db;
unordered_set<string>results;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);

int c, n, d;
string e , sd;

cin>>c;

for(int b = 0; b<c;++b){
   cin>>n;
   if(n>0){
   for(int y = 0; y<n ; ++y){
      cin>>e;
      auto exist = db.find(e);
      if(exist != db.end()){
        (like&)exist->second.first+=1;
      }else db.insert({e, {1,0}});
   }

   cin>>d;

   if(d>0){
      for(int x = 0; x<d ; ++x){
      cin>>sd;
      auto exist = db.find(sd);
      if(exist != db.end()){
          (dislike&)exist->second.second+=1;
      }else db.insert({sd, {0,1}});
   }
   }
}
}


for_each(db.begin(), db.end(),[&](pair<string, pair<like, dislike>>engr){
     
     if(engr.second.first>0 and engr.second.second == 0){
       results.insert(engr.first);
     }
     if(engr.second.first>=engr.second.second){
       results.insert(engr.first);
     }
});



cout<<results.size()<<" ";
for(auto&ingr in results){
    cout<<ingr<<" ";
}


return 0;
}
