package zuo.advanced.class06;

import java.util.ArrayList;
import java.util.List;

public class Code_01_PreToAllPost {

	public static void printAllPostArray(int[] preArr) {
		List<String> res = process(preArr, 0, preArr.length - 1);
		for (int i = 0; i < res.size(); i++) {
			System.out.println(res.get(i));
		}
	}

	public static List<String> process(int[] preArr, int left, int right) {
		List<String> res = new ArrayList<String>();
		if (left > right) {
			res.add("# ");
			return res;
		}
		for (int split = left; split <= right; split++) {
			List<String> leftParts = process(preArr, left + 1, split);
			List<String> rightParts = process(preArr, split + 1, right);
			for (int i = 0; i < leftParts.size(); i++) {
				for (int j = 0; j < rightParts.size(); j++) {
					res.add(leftParts.get(i) + rightParts.get(j)
							+ String.valueOf(preArr[left])+" ");
				}
			}
		}
		return res;
	}

	public static void main(String[] args) {
		int[] preArr = { 1, 2, 3 };
		printAllPostArray(preArr);
	}

}
