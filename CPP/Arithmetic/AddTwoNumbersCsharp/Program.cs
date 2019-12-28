using System;

namespace AddTwoNumbersCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            ListNode l1 = new ListNode(2);
            l1.next = new ListNode(4);
            l1.next.next = new ListNode(3);

            ListNode l2 = new ListNode(5);
            l2.next = new ListNode(6);
            l2.next.next = new ListNode(4);

            ListNode node = AddTwoNumbers(l1, l2);

            Console.WriteLine(node);
        }


        public static ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            var carry = 0;
            var result = new ListNode(0);
            ListNode p = l1, q = l2, cur = result;
            while (q != null || p != null)
            {
                carry += (p?.val ?? 0) + (q?.val ?? 0);
                cur = cur.next = new ListNode(carry % 10);
                carry /= 10;
                p = p?.next;
                q = q?.next;
            }

            if (carry>0) cur.next = new ListNode(carry);
            return result.next;
            
        }
    }


    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

}
