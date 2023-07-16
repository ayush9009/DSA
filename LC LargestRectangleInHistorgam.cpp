class Solution {
public:
    // BAHATREEN QUESTION ON STACK V.V.I.P
    // approach:first of all for finding the maximum area there is atleast one rod which is full
    // then only we find the maximum area,
    // But for this we also what is the left limit and right limit for the particular bar
    // so for those left limit and right limit we two arrays left and right,
    // for left if height of previous element(i.e stack top) is greater than pop it
    // else until the stack is not empty u do myStack.top()+1 and push index of bar in stack
    // for right if height of previosu element(ie.stack top) is greater than pop it
    // else until the stack is not empty u do mystack.top()-1 and push index to stack
    // after that by using area=height*no.of bars i.e no. of bars=right[i]-left[i]+1
    // therefore area=height[i]*(right[i]-left[i]+1)
    int largestRectangleArea(vector<int>& heights) {
    //     int n=heights.size();
    //     vector<int>left(n),right(n);
    //     stack<int>myStack;
    //     for(int i=0;i<n;i++){
    //         if(myStack.empty()){
    //             left[i]=0;
    //             myStack.push(i);
    //         }else{
    //             while(!myStack.empty() && heights[myStack.top()]>=heights[i])myStack.pop();
    //             left[i]=myStack.empty()?0:myStack.top()+1;
    //             myStack.push(i);
    //         }
    //     }
    //     while(!myStack.empty())
    //     myStack.pop(); //cinch(clear) the stack
    //     for(int i=n-1;i>=0;i--){
    //         if(myStack.empty()){
    //             right[i]=n-1;
    //             myStack.push(i);
    //         }else{
    //             while(!myStack.empty() && heights[myStack.top()]>=heights[i])myStack.pop();
    //             right[i]=myStack.empty()?n-1:myStack.top()-1;
    //             myStack.push(i);
    //         }
    //     }
    //     int max_ar=0;
    //     for(int i=0;i<n;i++){
    //         max_ar=max(max_ar,heights[i]*(right[i]-left[i]+1));
    //     }
    //     return max_ar;
    // }

    //most optimised code
    stack<int>st;
    int maxA=0;
    int n=heights.size();
    for(int i=0;i<=n;i++){ //that's the import thing here that we go to till 0-6((if n==5))
         while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
             int height=heights[st.top()];
             st.pop();
             int width;
             if(st.empty())width=i;
             else width=i-st.top()-1;
             maxA=max(maxA,width*height);
         }
         st.push(i);
    }
    return maxA;
    }
};
