//From the given function we can find out the order in e=which we will have to remove elements from the string s so that the next string is lexographically smalller.
//the array lexographic_removal contains the index of the character of string s in the order in which they are removed.
vector <int> lexographic(string s){
    int n=s.size();
    stack <int> st;
    vector <int> lexographic_removal;
    for(i=0;i<s.size();i++){
        while(!st.empty()&&s[i]<s[st.top()]){
            lexographic_removal.push_back(st.top());
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        lexographic_removal.push_back(st.top());
        st.pop();
    }
    return lexographic_removal;
}
