package com.xin.input;

import java.util.Scanner;

public class InputStr2IntArray {

	
	/**
	 * 输入字符串：2,3,5,4-5,2,4,3:6
	 * 得到-前面一个数组，-~：之间为一个数组；:后面那个数
	 */
	public static void str2arr2int1(){
		String strInput, strA, strB, strK;
		Scanner s = new Scanner(System.in);
		strInput = s.next();
		s.close();
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
	}
	
	/**
	 * 输入字符串：2,3,5,4
	 * 将分号去掉，得到字符串数组
	 */
	public static String[] convertStrToArray(String str){   
        String[] strArray = null;   
        strArray = str.split(","); //拆分字符为"," ,然后把结果交给数组strArray 
        return strArray;
    }
}
