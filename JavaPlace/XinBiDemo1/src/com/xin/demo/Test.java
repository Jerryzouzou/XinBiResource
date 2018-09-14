package com.xin.demo;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	/**
	 * 查找两个排序好的数组的中位数，如果是没有排好序的数组，请先用sort排序
	 */
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		double res = 0.0;
		int m = nums1.length;
		int n = nums2.length;
        int len=nums1.length+nums2.length;
        int midIndex = len/2;
        int[] help = new int[len];
        for(int i=0, j=0, k=0; k<len; k++){
        	if(i<m && j<n){
        		help[k] = nums1[i]<nums2[j] ? nums1[i++]:nums2[j++];
        	}else if(i==m){
        		help[k] = nums2[j++];
        	}else if(j==n){
        		help[k] = nums1[i++];
        	}
        }
        if((len%2) == 1){
        	res = help[midIndex];
        }else{
        	res = (double)(help[midIndex]+help[midIndex-1])/2;
        }
        return res;
    } 
}
