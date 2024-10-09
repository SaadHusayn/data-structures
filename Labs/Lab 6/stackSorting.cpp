void sortedInsert(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    
    int element = s.top();
    if(val>=element){
        s.push(val);
        return;
    }
    
    s.pop();
    sortedInsert(s, val);
    
    s.push(element);
}


void solve(stack<int> &s){
    if(s.empty()){
        return ;
    }
    
    int element = s.top();
    s.pop();
    
    solve(s);
    
    sortedInsert(s, element);
}





void SortedStack :: sort()
{
   //Your code here
   solve(s);
   
}