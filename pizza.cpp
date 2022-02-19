


/*
/* ONLY THE  maximize FUNCTION NEED OPTIMIZATION TO SERVE THE MAX CLINETS (THE RIGHT OUTPUT)
/* THE maximize FUNCTION GIVES 10000 INGIREDIENTS FOR THE ELABORATE DATA SET WICH IS NOT THE RIGHT ANSWER.
/* YOU CAN TRY TO MODIFY THE maximize FUNCTION TO GET THE RIGHT ANSWER .
*/
#include <bits/stdc++.h>

using namespace std;


/*each client has some ingredients they like/dislik*/
struct client{
    unordered_set<string>like;
    unordered_set<string>dislike;
};

class OnePizza{
    vector<client>clients;/*sotre every new client*/

    unordered_set<string>max;/*for finale result after maximize*/

    void get_input();/*read the data set*/

    int clinets_number();/*return clients number clients.size()*/

    OnePizza& maximize();/*maximize clients*/

    OnePizza& save();/*save the final results in unordered_set<string>max*/
    
    void print_result(); /*print the final outputs*/

    public:
    explicit OnePizza(){
        get_input();/*read the data set*/
    }

    void start();/*start work*/
};


int main(){
    OnePizza p;
    p.start();
    return 0;
}


void OnePizza::get_input(){//read the data set
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int c, n, d;
        string e , sd;
        cin>>c;
        for(int b = 0; b<c;++b){
            client new_client;
            cin>>n;
            if(n>0){
            for(int y = 0; y<n ; ++y){
                cin>>e;
                new_client.like.insert(e);/*one liked ingredient store it in like container of the current client(new_client)*/
            }       
        }
        cin>>d; 
        if(d>0){
        for(int x = 0; x<d ; ++x){
        cin>>sd;
        new_client.dislike.insert(sd);/*one disliked ingredient store it in dislike container of the current client (new_client)*/
        }
    }
    clients.push_back(new_client);/*add each new_client to clients container*/
    }
}


int OnePizza::clinets_number(){
    return clients.size();
}


/**maximize
try to maximize the number of clients that will visit the pizzeria.
after each valid ingredient founded add it to  the client like set in clients container
because the save function read the like set only for each clinet and insert the liked 
ingredient in the max set.

*/
OnePizza& OnePizza::maximize(){
    int i =0;
    for(auto rr: clients){
        if(i == clients.size()-1) break;
    for(auto&l:rr.like){//A- get earch liked (current clinet )ingredient 
        
        for(auto&ll: clients.at(i+1).like){
             if(l != ll){//B- compare with other clients likes
                auto dex = clients.at(i+1).dislike.find(l);//C-compare with other clients dislikes
                if(dex == clients.at(i+1).dislike.end()){
                    auto check = clients.at(i).dislike.find(ll);//check if ll not in the A dislike
                    if(check == clients.at(i).dislike.end()){//if ll not in the A dislike add ll to A like set.
                        clients.at(i).like.insert(ll);/* insert the ll inn the current client like set*/
                        break;
                    }
                    
                }else break;
            }
        }
    }
    ++i;
    }
    return *this;
}


OnePizza& OnePizza::save(){// save the maximized results in max container (unordered_set<string>max)
    for(auto&c:clients){
        for(auto&l:c.like){
            max.insert(l);
        }
    }
return *this;    
}


void OnePizza::print_result(){//print the outputs 
    cout<<max.size()<<" ";
    for(auto&ll:max){
        cout<<ll<<" ";
    }
}




void OnePizza::start(){
    maximize().save().print_result();
}


