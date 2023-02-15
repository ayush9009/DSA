class Solution {
public:
        //     approach:  awe have to do arr1[i]&arr2[0] ^ arr1[i]&arr2[1] means a&b ^ a&c  => a&(b^c)
        // //ab a&(b^c) to tab karte agr sirf a hota ya to lakin puri list hai to kya kare,aur b,ckai alva aur bhi haito
        // //to bhai jo a mai are unsabka xor kar do,aur b^c^d----- and so on
        // yani xorsum1=arr1[0]^arr1[1]^arr1[2]^arr1[3]------- and so on
        // yani xorsum2=b^c^d^e--- and so on
        // iske bad result=xorsum1 & xorsum2;
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int result1=arr1[0];
        int result2=arr2[0];
        for(int i=1;i<arr1.size();i++){
            result1^=arr1[i];
        }
        for(int i=1;i<arr2.size();i++){
            result2^=arr2[i];
        }
        return result1 & result2;
        
    }
};
