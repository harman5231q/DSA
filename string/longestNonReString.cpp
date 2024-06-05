#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>

string longestNonRepeatingString(string str){
    int arr[26]={0};
    string ans="";
    int start=0;
    int s=0;
    for(int i= 0 ;i<str.length();i++){
        char ch=str[i];
        int index=ch-'a';
        arr[index]++;
        while(arr[index]>1){
            char ch=str[start];
            int index=ch-'a';
            arr[index]--;
            start++;
        }
        string newString =str.substr(s,i-start+1);

        if(newString.length()>ans.length()){
            ans=newString;
        }

        s=start;
        
    }

    return ans;

}
int lengthOfLongestSubstring1(string str){
    unordered_map<char,int> arr;
    int ans=0;
    int len=0;
    for(int i= 0 ;i<str.length();i++){
        char ch=str[i];
        arr[ch]++;
        while(arr[ch]>1){
            char ch1=str[len];
            arr[ch1]--;
            len++;
        }
        ans = max(ans, i - len + 1);   
    }

    return ans;

}

int lengthOfLongestSubstring(string str){
    int arr[26]={0};
    int ans=INT_MIN;
    int len=0;
    for(int i= 0 ;i<str.length();i++){
        char ch=str[i];
        int index=ch-'a';
        arr[index]++;
        while(arr[index]>1){
            char ch=str[len];
            int index=ch-'a';
            arr[index]--;
            len++;
        }
        ans = max(ans, i - len + 1);   
    }

    return ans;

}

int main(){
    string str="";
    string returningString =longestNonRepeatingString(str);
    cout<<"this is result : "<<returningString<<endl;

    cout<<"length is : "<<lengthOfLongestSubstring1(str)<<endl;

    return 0;
}