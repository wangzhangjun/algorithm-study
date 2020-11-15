package 回文字符串.java;

public class PalinDrome {
    private boolean isAlphOrNumber(char c) {  //除了数字和字母其他的跳过
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    private boolean isEqualIgnoreCae(char a, char b) {
        if (a >= 'A' && a <= 'Z') a += 32; //全部转换成小写
        if (b >= 'A' && b <= 'Z') b += 32;
        return a == b;
    }

    public int isPalindrome(String s) {
        if (s == null || s.length() == 0)
            return 0;
        int i = 0, j = s.length() - 1; //两个变量，分别指向头尾
        while (i <= j){
            if(!isAlphOrNumber(s.charAt(i)))
                i++;
            if(!isAlphOrNumber(s.charAt(j)))
                j--;
            if(!isEqualIgnoreCae(s.charAt(i),s.charAt(j)))
                return 1;
            i++;
            j--;
        }
        return 0;
    }

    public static void main(String[] args) {
        String s = "abc3cb3";
        PalinDrome palinDrome = new PalinDrome();
        int result = palinDrome.isPalindrome(s);
        System.out.println(result);
    }
}
