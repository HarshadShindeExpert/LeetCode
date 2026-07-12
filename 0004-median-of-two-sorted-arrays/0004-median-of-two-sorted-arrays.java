// java solution

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int total = (nums1.length + nums2.length );
        int med = total/2;
        int median=0 ;
        int prevMedian=0;
        int i=0 , j=0 ;
        int count = 0 ;
        while(count<=med)
        {
            if(i==nums1.length)
            {
                prevMedian = median ;
                median = nums2[j];
                j++;
            }
            else if(j==nums2.length)
            {
                prevMedian = median ;
                median = nums1[i];
                i++;
            }
            else if(nums1[i]<nums2[j])
            {
                prevMedian = median ;
                median = nums1[i];
                i++;
            }
            else 
            {
                prevMedian = median ;
                median = nums2[j];
                j++;
            }
            count++;
        }
        if(total%2==0)
        {
            return (double)(median + prevMedian)/2;
        }
        return median ;

    }
}