class Solution {
public:
    vector<int> pse1(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else {
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> nse1(vector<int> &arr){
        stack<int> st;
        int n=arr.size();
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else {
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> pse=pse1(heights);
        vector<int> nse=nse1(heights);
        int maxarea=0;
        for(int i=0;i<n;i++){
            int area=(nse[i]-pse[i]-1)*heights[i];
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};