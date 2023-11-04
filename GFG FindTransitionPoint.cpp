class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        int ind=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                ind=i;
                break;
            }
        }
        if(ind==-1)return 0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==1 && (ind !=-1 && i>ind)){
                idx=i;
                break;
            }
        }
        return idx;
    }
};
