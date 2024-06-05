#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str="aabBAcCc";

    stack<char> st;
    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch>='a' && ch<='z'){
            st.push(ch);
        }

        else{
            if(st.top()){
                if(ch-'A'+'a'==st.top()){
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }
    }
    str="";
    while(!st.empty()){
        str=st.top()+str;
        st.pop();
    }

    cout<<str<<endl;
}