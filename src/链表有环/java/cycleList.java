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
    public boolean hasCycleWithHashSet(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        for(ListNode p = head; p != null; p = p.next) {
            if(set.contains(p))
                return true;
            set.add(p);
        }
        return false;
    }

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
