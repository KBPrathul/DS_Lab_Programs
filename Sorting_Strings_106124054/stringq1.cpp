//String q1    Searching in a string

#include<bits/stdc++.h>
using namespace std;

int main(){
    string t,s;
    cout<<"What is the text to search from? ";
    getline(cin,t);
    cout<<"What should I search for? ";
    getline(cin,s);
    bool truth=false;
    for(int i=0;i<t.size() && !truth;i++){
        int count=0;
        for(int j=i;j-i<s.size() && j<t.size();j++){
            if(t[j]==s[j-i]){
                count++;
            }
            else{
                break;
            }
        }
        if(count==s.size()){
            truth=true;
        }
    }
    if(truth){
        cout<<"It is present!"<<endl;
    }
    else{
        cout<<"It is not present!"<<endl;
    }
}

/*What is the text to search from? Today is a good day
What should I search for? a good
It is present!

What is the text to search from? Today is a good day
What should I search for? bad
It is not present!*/