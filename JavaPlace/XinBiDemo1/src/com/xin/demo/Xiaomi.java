package com.xin.demo;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Xiaomi {

	
	// 打印和为n的组合，动规法，O(n^2)
		public static List<List<Object>> findSums(int[] a, int n) {
			boolean[] dp = new boolean[n + 1];
			List<List<Object>>[] list = new ArrayList[n + 1];
			for (int i = 0; i < list.length; i++) {
				list[i] = new ArrayList<>();
			}
			List<Object> temp = new ArrayList<>();
			for (int i = 0; i < a.length; i++) {
				if (a[i] > n) {
					continue;
				}
				for (int j = n; j >= a[i]; j--) {
					if (dp[j - a[i]]) {
						dp[j] = true;
						for (List<Object> arrayList : list[j - a[i]]) {
							temp = new ArrayList<>(arrayList);
							temp.add(a[i]);
							list[j].add(new ArrayList<>(temp));
							System.out.println("111---"+a[i]+"--j=="+j);
						}
					}
				}
				dp[a[i]] = true;
				temp.clear();
				temp.add(a[i]);
				//System.out.println("222---"+a[i]);
				list[a[i]].add(new ArrayList<>(temp));
			}
			System.out.println(list[n].size());
			return list[n];
		}


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
    static boolean miHomeGiftBag(int[] p, int M) {
    	boolean[] dp = new boolean[M + 1];
		List<List<Object>>[] list = new ArrayList[M + 1];
		for (int i = 0; i < list.length; i++) {
			list[i] = new ArrayList<>();
		}
		List<Object> temp = new ArrayList<>();
		for (int i = 0; i < p.length; i++) {
			if (p[i] > M) {
				continue;
			}
			for (int j = M; j >= p[i]; j--) {
				if (dp[j - p[i]]) {
					dp[j] = true;
					for (List<Object> arrayList : list[j - p[i]]) {
						temp = new ArrayList<>(arrayList);
						temp.add(p[i]);
						list[j].add(new ArrayList<>(temp));
						System.out.println("111---"+p[i]);
					}
				}
			}
			dp[p[i]] = true;
			temp.clear();
			temp.add(p[i]);
			//System.out.println("222---"+a[i]);
			list[p[i]].add(new ArrayList<>(temp));
		}
		if(list[M].size() == 0){
			return false;
		}else{
			return true;
		}
    }
/******************************结束写代码******************************/


  public static void main(String[] args){
    /*Scanner in = new Scanner(System.in);
    boolean res;
    int _p_size = 0;
    _p_size = Integer.parseInt(in.nextLine().trim());
    int[] _p = new int[_p_size];
    int _p_item;
    String []_ps = in.nextLine().split(" ");
    for(int _p_i = 0; _p_i < _p_size; _p_i++) {
      _p_item = Integer.parseInt(_ps[_p_i]);
      _p[_p_i] = _p_item;
    }

    int _M;
    _M = Integer.parseInt(in.nextLine().trim());

    res = miHomeGiftBag(_p, _M);
    System.out.println(String.valueOf(res ? 1 : 0));*/
	  
	 int a[] = {99, 199, 1999, 10000, 39, 1499};
	 int b = 10238;
	 List<List<Object>> cc = findSums(a, b);
	 System.out.println(cc.toString());
  }
}