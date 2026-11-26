class Solution {
public:
    vector<int> nse1(vector<int> &arr){
        stack<int> st;
        vector<int> nse(arr);
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> pse1(vector<int> &arr){
        stack<int> st;
        vector<int> pse(arr);
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int largestHistogram(vector<int> &arr){
        int n=arr.size();
        vector<int> pse=pse1(arr);
        vector<int> nse=nse1(arr);
        int maxarea=0;
        for(int i=0;i<n;i++){
            int area=(nse[i]-pse[i]-1)*arr[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                    sum++;
                }
                else{
                    sum=0;
                }
                prefix[i][j]=sum;
            }
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largestHistogram(prefix[i]));
        }
        return maxarea;
    }
};