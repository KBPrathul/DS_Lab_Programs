//Linear probe hashing implementation

#include<bits/stdc++.h>
using namespace std;

struct node{
    string username;
    string password;
    node(string user, string pass){
        username=user;
        password=pass;
    }
};

string search(vector<struct node>& table, string name){
    int index=(name[0]-'a')%26;
    for(int i=0; i<26; i++){
        int moveindex=(index+i)%26;
        if(table[moveindex].username==name){
            cout<<"Found username at index "<<moveindex<<endl;
            return table[moveindex].password;
        }
        if(table[moveindex].username=="x"){
            cout<<"Username not found."<<endl;
            return "";
        }
    }
    cout<<"Username not found."<<endl;
    return "";
}

void display(vector<struct node>& table){
    for(int i=0;i<26;i++){
        if(table[i].username!="x"){
            cout<<"Index "<<i<<": ("<<table[i].username<<", "<<table[i].password<<")"<<endl;
        } else{
            cout<<"Index "<<i<<": Empty"<<endl;
        }
    }
}

int main(){
    vector<struct node> arr(26, node("x", "x"));
    int n;
    cout<<"How many pairs are there? ";
    cin>>n;
    for(int i=0; i<n; i++){
        string name, pass;
        cout<<"Enter the username: ";
        cin>>name;
        cout<<"Enter the password: ";
        cin>>pass;
        int index=(name[0]-'a')%26;
        bool inserted = false;
        for(int j=0; j<26; j++){
            int moveindex=(index+j)%26;
            if(arr[moveindex].username=="x"){
                arr[moveindex].username=name;
                arr[moveindex].password=pass;
                cout<<"Inserted '"<<name<<"' at index "<<moveindex<<endl;
                inserted = true;
                break;
            }
            else if(arr[moveindex].username == name){
                arr[moveindex].password = pass;
                cout<<"Successfully updated password for '"<<name<<"' at index "<<moveindex<<endl;
                inserted = true;
                break;
            }
        }
        if(!inserted){
            cout<<"ERROR: Table is full. Could not insert '"<<name<<"'."<<endl;
        }
    }
    cout<<endl;
    display(arr);
    cout<<endl;
    search(arr, "hello123");
    search(arr, "hi123");
    search(arr, "testing123");
    search(arr, "missing");
}

/*How many pairs are there? 3
Enter the username: hello123
Enter the password: pass123
Inserted 'hello123' at index 7
Enter the username: testing123
Enter the password: p123
Inserted 'testing123' at index 19
Enter the username: hi123
Enter the password: pass
Inserted 'hi123' at index 8

Index 0: Empty
Index 1: Empty
Index 2: Empty
Index 3: Empty
Index 4: Empty
Index 5: Empty
Index 6: Empty
Index 7: (hello123, pass123)
Index 8: (hi123, pass)
Index 9: Empty
Index 10: Empty
Index 11: Empty
Index 12: Empty
Index 13: Empty
Index 14: Empty
Index 15: Empty
Index 16: Empty
Index 17: Empty
Index 18: Empty
Index 19: (testing123, p123)
Index 20: Empty
Index 21: Empty
Index 22: Empty
Index 23: Empty
Index 24: Empty
Index 25: Empty

Found username at index 7
Found username at index 8
Found username at index 19
Username not found.*/