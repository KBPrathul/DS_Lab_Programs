//q4    Implementing Minstack

#include<bits/stdc++.h>
using namespace std;

struct st{
    int top;
    int cap;
    int min;
    pair<int,int>* arr;
    st(int c){
        top=-1;
        min=INT_MAX;
        cap=c;
        arr=new pair<int,int>[cap];
    }
};

bool isfull(struct st* s){
    if(s->top==s->cap-1){
        return true;
    }
    return false;
}

bool isempty(struct st* s){
    if(s->top==-1){
        return true;
    }
    return false;
}

void push(struct st* s, int val){
    if(isfull(s)){
    }
    else{
        if(val<s->min){
            s->min=val;
        }
        s->arr[++s->top]={val,s->min};
    }
}

int pop(struct st* s){
    if(isempty(s)){
        return -1;
    }
    else{
        int k=s->arr[s->top].first;
        s->top--;
        return k;
    }
}

int peek(struct st* s){
    if(isempty){
        return -1;
    }
    else{return s->arr[s->top].first;}
}

int getmin(struct st* s){
    return s->arr[s->top].second;
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    struct st* s=new st(n);
    push(s,2);
    push(s,3);
    cout<<peek(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<getmin(s)<<endl;
    push(s,1);
    cout<<getmin(s)<<endl;
}

/*Enter size: 5
-1
3
2
1*/