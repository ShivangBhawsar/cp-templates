// Next smaller or equal element using stack ( if you need smaller just replace '>=' with '>')
vector <int> ans(n, -1);
stack <int> st;
for (int i=0;i<n;i++)
{
    while (!st.empty()&&arr[st.top()]>=arr[i])
    {
        ans[st.top()]=i; // next smaller for index st.top() is at i
        st.pop();
    }
    st.push(i);
}