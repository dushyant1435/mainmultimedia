#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    int freq;
    node*right,*left;
    node(char x, int y, node*l, node*r){
        data=x;
        freq=y;
        left=l;
        right=r;
    }
};

class cmp{
    public:
    bool operator()(const node*l, const node*r)const
    {
        return l->freq>r->freq;
    }
};

bool leaf(node* temp){
    if(temp->left==NULL and temp->right==NULL)return true;
    else false;
}

void encode(node* temp, string s, map<char,string>&mp){
    if(temp==NULL)return;
    if(leaf(temp)==true){
        mp[temp->data]=s;
    }
    encode(temp->left,s+"0",mp);
    encode(temp->right,s+"1",mp);
}

void build(string s){
    map<char,int>mp;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
    }
    priority_queue<node*,vector<node*>,cmp>pq;
 
    for(auto it:mp){
        node*temp=new node(it.first, it.second,NULL,NULL);
        pq.push(temp);
    }
    while(pq.size()!=1){
        node* t1,*t2;
        t1=pq.top(); pq.pop();
        t2=pq.top(); pq.pop();
        int sum=t1->freq+t2->freq;
        node* temp = new node('\0',sum,t1,t2);
        pq.push(temp);
    }
    node* root=pq.top();
    
    string ems="";
    map<char,string>mpp;
    encode(root,ems,mpp);
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){
    cout<<"enter string please"<<endl;
    string s; cin>>s;
    build(s);

}