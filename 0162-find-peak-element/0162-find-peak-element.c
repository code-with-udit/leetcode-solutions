int findPeakElement(int* nums, int numsSize) {
    int st=0 ;
    int end=numsSize-1 ;
    while(st<end){
        int mid=st+(end-st)/2 ;
        if(nums[mid]<nums[mid+1])st=mid+1 ;
        else end=mid ;
    }
    return st ;
}