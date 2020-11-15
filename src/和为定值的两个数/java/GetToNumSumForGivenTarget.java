package 和为定值的两个数.java;

import java.util.HashMap;
import java.util.Map;

//时间复杂度：O(n的平方)
public class GetToNumSumForGivenTarget {
    public int[] getByForceLoop(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            for (int j = i + 1; j < array.length; j++) {
                int sum = array[i] + array[j];
                if (sum == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};
    }

    /*
     * 只遍历一次数组，借助一个hashmap，map中存放的是<值，下标>
     * 每到一个数字，判断需要加的数组（numNeed）是否已经在数组，如果在就找到了。没在就加入到map，如果遍历完还没有找到，就说明没有，返回-1
     * 时间复杂度：O(n),但是引入了空间
     * */
    public int[] getByHashMap(int[] array, int target) {
        Map<Integer, Integer> temMap = new HashMap<>();
        for (int i = 0; i < array.length; i++) {
            int numNeed = target - array[i];
            if (temMap.containsKey(numNeed)) {
                return new int[]{temMap.get(numNeed), i};
            }
            temMap.put(array[i], i);
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[] array = new int[]{1, 2, 3, 6, 8, 11};
        GetToNumSumForGivenTarget getToNumSumForGivenTarget = new GetToNumSumForGivenTarget();
        int[] result = getToNumSumForGivenTarget.getByForceLoop(array, 10);
        System.out.println(result[0]);
        System.out.println(result[1]);
        int[] result2 = getToNumSumForGivenTarget.getByHashMap(array, 10);
        System.out.println(result2[0]);
        System.out.println(result2[1]);
    }
}
