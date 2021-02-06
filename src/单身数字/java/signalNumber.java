package 单身数字.java;

import java.util.HashSet;
import java.util.Set;

/*
* 什么是单身数字：比如 : 5,7,5,6,6
* 除了7其他都是成对出现的。所以7就是单身数字。
*
* */
public class signalNumber {

    /*
    * 方法1：使用set的唯一性，已经存在的，一定不会再set中再次出现。
    * 把set中的元素乘以2，然后减去原有的元素的和。就是我们要找出的。
    * Time:O(n),Space:O(n)
    * */
    public  int signaleNumberWithSet(int nums[]) {
        Set<Integer> set = new HashSet<>();
        int sum = 0, signalSum = 0;
        for (int num : nums) {
            if (!set.contains(num)) {
                set.add(num);
                signalSum += num;
            }
            sum += num;
        }
        int signalNum = 2 * signalSum - sum;
        return signalNum;
    }

    /*
    * 方法2: 使用异或的性质。
    * 异或 ： X^X = 0 0^Y=Y
    * 所以两两异或所有的数字，最终的结果一定是单身数字
    * Time:O(n),Space:O(1)
    * */
    public int signalNumWithXor(int nums[]) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    public static void main(String[] args) {
        int nums[] = {5,7,5,6,6};
        signalNumber signalNumber = new signalNumber();
        int ret = signalNumber.signaleNumberWithSet(nums);
        System.out.println("方法1：" + ret);
        int ret2 = signalNumber.signalNumWithXor(nums);
        System.out.println("方法2：" + ret2);
    }
}
