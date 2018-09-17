package com.xin.demo;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Baidu {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Queue<Character> queue = new LinkedList<>();
		HashSet<String> map = new HashSet<>();
		int count = 0;
		String strInput;
		//String str = "abab";
		Scanner s = new Scanner(System.in);
		strInput = s.next();
		//s.close();
		for(int i=0; i<strInput.length(); i++){
			//String strTmp = queue.poll();
			queue.offer(strInput.charAt(i)); 		//加入队列
		}
		map.add(queue.toString());
		for(int i=0; i<strInput.length(); i++){
			char cTmp = queue.poll();	//取出队列头
			queue.offer(cTmp);		//将头放入尾
			String strTmp = queue.toString();
			//System.out.println("strTmp=="+strTmp+"len="+strTmp.length());
			/*if(map.contains(strTmp)){
				count++;
			}else{
				map.add(strTmp);
				
			}*/
			map.add(strTmp);
		}
		count = map.size();
		System.out.println(count);
	}
	
	
}
