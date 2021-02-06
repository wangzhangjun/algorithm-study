package 单身数字.java;

import java.util.HashSet;
import java.util.Set;

/*
* 什么是单身数字：比如 : 5,7,5,6,6
* 除了7其他都是成对出现的。所以7就是单身数字
*
* */
public class signalNumber {

    public  int signaleNumberWithSet(int nums[]){
        Set<Integer> set = new HashSet<>();
        int sum = 0, signalSum = 0;
        for(int num : nums) {
            if(!set.contains(num)) {
                set.add(num);
                signalSum += num;
            }
            sum += num;
        }
        int signalNum =2*signalSum - sum;
        return signalNum;
    }

    public static void main(String[] args) {
        int nums[] = {5,7,5,6,6};
        signalNumber signalNumber = new signalNumber();
        int ret = signalNumber.signaleNumberWithSet(nums);
        System.out.println(ret);
    }
}
