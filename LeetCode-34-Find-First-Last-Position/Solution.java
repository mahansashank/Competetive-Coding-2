class Solution {
      public static int firstOcc(int nums[],int target){
        int left=0;
        int right=nums.length-1;
        int index  =-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target) index = mid;
            if(target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return index;
      }
      public static int lastOcc(int nums[],int target){
        int left=0;
        int right  =nums.length-1;
        int index = -1;
       while(left<=right){
                 int mid = left+(right-left)/2;
                 if(nums[mid]==target) index=mid;
                 if(target>=nums[mid]) left=mid+1;
                 else right=mid-1;
       }
       return index;
      }
    public int[] searchRange(int[] nums, int target) {
       int arr[]=new int[2];
       arr[0]=firstOcc(nums,target);
       arr[1]=lastOcc(nums,target);
       return arr; 
    }
}
