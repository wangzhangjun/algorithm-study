package 数组中超过一半的数字.java;

import java.util.HashMap;
import java.util.Map;

public class hasHalfNum {

    void func(int[] arr)
    {
        HashMap<Integer,Integer> result = new HashMap<Integer, Integer>();
        for(int i =0; i< arr.length; i++) {
            if (result.get(arr[i]) == null) {
                result.put(arr[i], 1);
            } else {
                result.put(arr[i], result.get(arr[i]) + 1);
            }
        }
        for (Map.Entry<Integer, Integer> entry : result.entrySet()) {
            if(entry.getValue()*2>arr.length)
            {
                System.out.println("超过一个的数字是：" + entry.getKey() + " 次数是：" + entry.getValue());
            }
        }
    }
    public static void main(String[] args) {
        int arr[] = new int[]{1,1,1,3,3,3,3};
        hasHalfNum halfNum = new hasHalfNum();
        halfNum.func(arr);
    }
}
