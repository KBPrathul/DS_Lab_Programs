//Separate chain hashing implementation

#include<bits/stdc++.h>
using namespace std;

struct node{
    string username;
    string password;
    node* next;
    node(string user, string pass){
        username=user;
        password=pass;
        next=nullptr;
    }
};

void search(vector<struct node>& arr,string name){
    int index=(name[0]-'a')%26;
    struct node* temp=&arr[index];
    while(temp!=nullptr){
        if(temp->username==name){
            cout<<"Found '"<<name<<"'. Password: "<<temp->password<<endl;
            return;
        }
        temp=temp->next;
    }

    cout<<"User not found."<<endl;
}

void display(vector<struct node>& arr){
    for(int i=0; i<26; i++){
        cout<<"Bucket "<<i<<": ";
        struct node* temp=&arr[i];
        if(temp->username=="x"){
            cout<<"Empty"<<endl;
            continue;
        }
        while(temp!=nullptr){
            cout<<" -> ("<<temp->username<<", "<<temp->password<<")";
            temp=temp->next;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<struct node>arr(26,node("x","x"));
    int n;
    cout<<"How many pairs are there? ";
    cin>>n;
    for(int i=0;i<n;i++){
        string name,pass;
        cout<<"Enter the username: ";
        cin>>name;
        cout<<"Enter the password: ";
        cin>>pass;
        struct node* temp=&arr[(name[0]-'a')%26];
        while(temp->next!=nullptr && temp->username!="x"){
            temp=temp->next;
        }
        if(temp->username=="x"){
            temp->username=name;
            temp->password=pass;
        }
        else{
            temp->next=new node(name,pass);
        }
    }
    cout<<"Hashing has been completed!"<<endl;
    display(arr);
    search(arr, "hello123");
    search(arr, "hi123");
    search(arr, "testing123");
    search(arr, "missing");
}

/*How many pairs are there? 3
Enter the username: hello123
Enter the password: pass123
Enter the username: testing123
Enter the password: p123
Enter the username: hi123
Enter the password: password123
Hashing has been completed!
Bucket 0: Empty
Bucket 1: Empty
Bucket 2: Empty
Bucket 3: Empty
Bucket 4: Empty
Bucket 5: Empty
Bucket 6: Empty
Bucket 7:  -> (hello123, pass123) -> (hi123, password123)
Bucket 8: Empty
Bucket 9: Empty
Bucket 10: Empty
Bucket 11: Empty
Bucket 12: Empty
Bucket 13: Empty
Bucket 14: Empty
Bucket 15: Empty
Bucket 16: Empty
Bucket 17: Empty
Bucket 18: Empty
Bucket 19:  -> (testing123, p123)
Bucket 20: Empty
Bucket 21: Empty
Bucket 22: Empty
Bucket 23: Empty
Bucket 24: Empty
Bucket 25: Empty

Found 'hello123'. Password: pass123
Found 'hi123'. Password: password123
Found 'testing123'. Password: p123
User not found.*/