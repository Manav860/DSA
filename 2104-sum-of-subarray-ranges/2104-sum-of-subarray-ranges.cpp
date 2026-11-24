class Solution {
public:
    vector<int> pse1(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n);
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
    vector<int> nse1(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);
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
    vector<int> pge1(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pge[i]=-1;
            }
            else{
                pge[i]=st.top();
            }
            st.push(i);
        }
        return pge;
    }
    vector<int> nge1(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }
            else{
                nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }
    long long sumofMinimum(vector<int> &arr){
        int n=arr.size();
        long long total=0;
        vector<int> pse=pse1(arr);
        vector<int> nse=nse1(arr);
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            total=total+(left*right*arr[i]);
        }
        return total;
    }
    long long sumofMaximum(vector<int> &arr){
        int n=arr.size();
        long long total=0;
        vector<int> pge=pge1(arr);
        vector<int> nge=nge1(arr);
        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            total=total+(left*right*arr[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        // BRUTE FORCE
        // int n=nums.size();
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     int mini=nums[i];
        //     int big=nums[i];
        //     for(int j=i;j<n;j++){
        //         mini=min(mini,nums[j]);
        //         big=max(big,nums[j]);
        //         sum=sum+(big-mini);
        //     }
        // }
        // return sum;
        long long minimum=sumofMinimum(nums);
        long long maximum=sumofMaximum(nums);
        return maximum-minimum;
    }
};