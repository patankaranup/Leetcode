class Solution {
    
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0;
        int end = arr.length -1 ;

        while (start<end){
            int mid = start+(end-start)/2;
            
            if (arr[mid]>arr[mid+1]){
                // we are in decreasing part of the array this may be the 
answer but look at left half of the array
                // this is may be the answer that is why we are not saying 
end = mid -1
                end = mid;

            }
            else{
                // we are in the ascending part of the array
                start = mid+1; // beacuase we know that the mid + 1 
elemnet is grater than the mid element hence we ignore the mid 1
                // and at the end mid will be pointing towards the maximum 
value because of the above 2 checks 
                // start and end are always trying to check the max 
element in the above 2 checks 
                // hence when the loop breaks they will be pointing to the 
same element that is the maximum one 
            }
            // we can return end also as both are pointing towards same 
index
        }

        return start; 
        
    }
}
