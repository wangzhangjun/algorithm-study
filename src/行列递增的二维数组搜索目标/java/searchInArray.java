package 行列递增的二维数组搜索目标.java;

/*
*  1 3 5
*  2 4 6
*  比如有如上的二维数组，行和列都是递增的，在这样的数组中找到一个目标值。
* 思路：从最右上角开始遍历，比它大就往下走，比它小就往左走。一直找到目标值
* */
public class searchInArray {

    public int [] search(int [][] martix, int target) {
        if(martix == null || martix.length == 0 || martix[0] == null || martix[0].length == 0){
            return new int[]{-1,-1};
        }
        int i = 0;
        int j = martix[0].length -1;
        while((i < martix.length) && (j >= 0) ){  //martix.length表示数组行数
            if(target < martix[i][j])
                j--;
            else if(target > martix[i][j])
                i++;
            else
                return new int[]{i,j};
        }
        return new int[]{-1,-1};
    }

    public static void main(String[] args) {
        int a[][] = {{1,3,5},{2,4,6}};
        searchInArray test = new searchInArray();
        int[] res = test.search(a,4);
        System.out.println(res[0]);
        System.out.println(res[1]);
    }
}
