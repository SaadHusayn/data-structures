#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// using recursion
// int getMin(vector<int> v, int i, int n){
//     if(i==v.size()) return n;

//     return getMin(v, i+1, min(n, v[i]));
// }

// void solve(vector<int> &v, vector<int> &result, int i){
//     if(i==v.size()){
//         return;
//     }

//     int mini = getMin(v, i+1, v[i]);

//     if(mini<v[i]) result[i] = mini;

//     solve(v, result, ++i);
    
// }

// vector<int> nextSmallerElement(vector<int> &v){
//     vector<int> result(v.size(), -1);
//     solve(v, result, 0);
//     return result;
    
// }

//stack implementation
void sortedInsert(stack<int> &st, int n){
    if(st.empty() || (!st.empty() && n<st.top())){
        st.push(n);
        return;
    }

    int element = st.top();
    st.pop();

    sortedInsert(st, n);

    st.push(element);
}
vector<int> nextSmallerElement(vector<int>& v){
    vector<int> result(v.size(), -1);

    stack<int> st;

    for(int i=(v.size()-1);i>=0;i--){ 

        if(!st.empty() && (st.top()<v[i])){
            result[i] = st.top();
            sortedInsert(st, v[i]);
        }
        else if(!st.empty()){
            st.push(v[i]);

        }else{
            st.push(v[i]);
        }

    }

    return result;
}


int main(){
    vector<int> v = {2, 1, 4, 3};

    vector<int> result = nextSmallerElement(v);

    for(auto i:result){
        cout << i << " ";
    }
}