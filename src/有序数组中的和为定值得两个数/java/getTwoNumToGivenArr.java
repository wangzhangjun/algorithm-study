package 有序数组中的和为定值得两个数.java;

/*
* 思想：数组是有序的。
* 所以两个游标，分别从前到后遍历，如果两个游标的对应的值相加比target大，最右边的游标-1.反之如果小，则最左边的游标加1，一直到相等，返回下标
* */
public class getTwoNumToGivenArr {

    public int[] getTwoNum(int[] arr, int target) {
        for(int i =0,j = arr.length-1; i < arr.length;) {
            if((arr[i] + arr[j]) < target) {
                ++i;
            }else if((arr[i] + arr[j]) > target) {
                --j;
            }else{
                return new int[]{i+1, j+1};
            }
        }
        return new int[]{-1, -1};
    }
    public static void main(String[] args) {
        int[] array = new int[]{1,2,3,6,8,11};
        getTwoNumToGivenArr getTwoNumToGivenArr = new getTwoNumToGivenArr();
        int[] result = getTwoNumToGivenArr.getTwoNum(array, 10);
        System.out.println(result[0]);
        System.out.println(result[1]);
    }
}
