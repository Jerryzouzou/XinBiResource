package com.xin.demo;

import java.util.Arrays;
import java.util.Scanner;

public class Xunlei {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String strInput, strA, strB, strK;
		Scanner s = new Scanner(System.in);
		strInput = s.next();
		//index = strInput.charAt("-");
		strA = strInput.substring(0, strInput.indexOf("-"));
		strB = strInput.substring(strInput.indexOf("-")+1, strInput.indexOf(":"));
		strK = strInput.substring(strInput.indexOf(":")+1);
		String[] strArrayA=convertStrToArray(strA);
		String[] strArrayB=convertStrToArray(strB);
		int m = strArrayA.length;
		int n = strArrayB.length;
		int A[] = new int[m];
	    int B[] = new int[n];
		for(int i=0; i<m; i++){
			A[i] = Integer.parseInt(strArrayA[i]);
		}
		for(int i=0; i<n; i++){
			B[i] = Integer.parseInt(strArrayB[i]);
		}
		int k=Integer.parseInt(strK);
		
	    int res[] = new int[m*n];
	    for(int i=0; i<m; i++){
	    	for(int j=0; j<n; j++){
	    		res[i*n+j] = A[i]+B[j];
	    	}
	    }
	    System.out.println();
	    
	    Arrays.sort(res, 0, res.length);
	    for(int i=res.length; i>res.length-k; i--){
	    	System.out.print(res[i-1]+",");
	    }
	}

	public static String[] convertStrToArray(String str){   
        String[] strArray = null;   
        strArray = str.split(","); //拆分字符为"," ,然后把结果交给数组strArray 
        return strArray;
    }

}
