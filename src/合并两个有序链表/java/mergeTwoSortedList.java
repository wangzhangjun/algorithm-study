package 合并两个有序链表.java;


public class mergeTwoSortedList {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }

    public ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p  = dummy;
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val){
                p.next = l1;
                l1 = l1.next;
            }else{
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        if(l1 != null) p.next = l1;
        if(l2 != null) p.next = l2;
        return dummy.next;
    }

    public static void main(String[] args) {
        mergeTwoSortedList test = new mergeTwoSortedList();
        mergeTwoSortedList.ListNode listNode = test.new ListNode(1);
        mergeTwoSortedList.ListNode listNode1 = test.new ListNode(3);
        mergeTwoSortedList.ListNode listNode2 = test.new ListNode(5);
        listNode.next = listNode1;
        listNode1.next = listNode2;
        listNode2.next = null;

        mergeTwoSortedList.ListNode listNode3 = test.new ListNode(2);
        mergeTwoSortedList.ListNode listNode4 = test.new ListNode(4);
        mergeTwoSortedList.ListNode listNode5 = test.new ListNode(6);
        listNode3.next = listNode4;
        listNode4.next = listNode5;
        listNode5.next = null;

        ListNode res = test.merge(listNode, listNode3);
        while(res != null){
            System.out.println(res.val);
            res = res.next;
        }
    }
}
