#include<iostream>
#include<stack>
#include<string>
using namespace std;
int calculate(int num1,int num2,int op){
    switch(op){
        case '+':
            return num1 + num2;
        case '-':
            return num1 + num2;
    }
}
int calculator(string s){
    stack<int> nums;
    int sign=1;
    int res=0;
    int num=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }
        if(s[i]!='(' && s[i]!=')' && s[i]!='+' && s[i]!='-'){
            int digit=s[i]-'0';
            num=num*10 +digit;
            if(s[i+1]!='+' && s[i+1]!='-'){
                res+=num*sign;
                sign=1;
                num=0;
            }
        }
        else if(  s[i]=='+' || s[i]=='-'){
            res=num;
            num=0;
            int tempSign=1;
            if(s[i]!='+'){
                tempSign=-1;
            }
            sign=sign*tempSign;
        }
        else{
            if(s[i]=='('){
                nums.push(res);
                res=0;
                nums.push(sign);
                sign=1;
            }
            else{
                int newSign=nums.top();
                nums.pop();
                int newRes=nums.top();
                nums.pop();
                newRes+=res*newSign;
                nums.push(newRes);
            }
        }

    }
    if(nums.empty()){
        return res;
    }

    return nums.top();


}

int main(){
    string s="(1+(4+5+2)-3)+(6+8) ";
    int ans=calculator(s);

    cout<<"Ans is : "<<ans<<endl;

}
