package 链表有环.java;

import java.util.HashSet;
import java.util.Set;

public class cycleList {

    public class ListNode{
        int val;
        ListNode next;
        ListNode(int x) {
            this.val = x;
        }
    }

    // Time: O(n), Space: O(n)
    //方法1：往一个set中添加，每次添加时，如果包含则返回true表明有环,不包含返回false
    public boolean hasCycleWithHashSet(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        for(ListNode p = head; p != null; p = p.next) {
            if(set.contains(p))
                return true;
            set.add(p);
        }
        return false;
    }

    // Time: O(n), Space: O(1)
    //方法2：快慢指针。同时指向头结点，快指针一次性走两个，慢指针一次性走一个，他们的速度相差1，所以如果有环的话，快指针一定会追上慢指针
    public boolean hasCycleWithTwoPointer(ListNode head) {
        ListNode fast = head;
        ListNode low  = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            low = low.next;
            if(fast == low){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        cycleList test = new cycleList();
        cycleList.ListNode listNode = test.new ListNode(1);
        cycleList.ListNode listNode1 = test.new ListNode(2);
        cycleList.ListNode listNode2 = test.new ListNode(3);
        //构造环
        listNode.next = listNode1;
        listNode1.next = listNode2;
        listNode2.next = listNode;

        System.out.println(test.hasCycleWithHashSet(listNode));
        System.out.println(test.hasCycleWithTwoPointer(listNode));
    }
}
