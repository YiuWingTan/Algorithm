using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Aggregation;

namespace 链表
{
    class Program
    {
        static void Main(string[] args)
        {
           
            MyList<int> list = new MyList<int>();
            Random random = new Random(54);
            Console.WriteLine("原来链表的数据有:");
            for (int i = 20; i > 0; i--)
                list.Add(random.Next()%100);
            list.Show();


            int mark = -2;
            Console.WriteLine("现在进行链表的添加数据操作,输入0时停止链表的添加操作");
            while((mark = Convert.ToInt32(Console.ReadLine()))!=0)
            {
                list.Add(mark);
            }

            Console.Clear();
            Console.WriteLine("现在链表的数据有:");
            list.Show();

            Console.ReadLine();
            Console.Clear();
            Console.WriteLine("现在链表的数据有:");
            list.Show();
            Console.WriteLine("现在进行链表的数据查找操作，请输入数据所在的位置进行查找");
            int value = list.FindIndex(Convert.ToInt32(Console.ReadLine()));
            if (value == 0) Console.WriteLine("链表中没有这个位置的数据");
            else Console.WriteLine("您要查找的数据是"+value);
            Console.ReadLine();


            Console.Clear();
            Console.WriteLine("现在链表的数据有:");
            list.Show();
            Console.WriteLine("现在进行链表的数据删除操作:");
            int position = Convert.ToInt32(Console.ReadLine());
            int m = list.DeletedIndex(position);
            if (m == position) { Console.WriteLine("数据已经删除了，现在的链表中的数据为"); list.Show(); }
            else Console.WriteLine("链表中不存在这样的数据，所以删除不了");
            Console.ReadLine();

            Console.Clear();
            Console.WriteLine("现在进行链表的归并操作，请输入两个有序的链表");
            Console.WriteLine("请输入第一个链表,输入0时停止链表的添加操作:");
            MyList<int> list1 = new MyList<int>();
            MyList<int> list2 = new MyList<int>();
            mark = -2;
            while ((mark = Convert.ToInt32(Console.ReadLine())) != 0)
                list1.Add(mark);
            Console.Clear();
            Console.WriteLine("现在请输入第二链表中的数据,输入0时停止链表的添加操作");
            mark = -2;
            while ((mark = Convert.ToInt32(Console.ReadLine())) != 0)
                list2.Add(mark);
            Console.Clear();
            Console.WriteLine("现在链表一中的数据为");
            list1.Show();
            Console.WriteLine("现在链表二中的数据为");
            list2.Show();
            MyList<int> newList = MyList<int>.Merage(list1,list2,(a,b)=>(a-b));
            Console.WriteLine("现在归并后新的链表为");
            newList.Show();

            Console.ReadLine();
        }
    }

    public class MyList<T>
    {
        public class Node
        {
            public Node next;
            public T data;

            public Node()
            {
                next = null;
                data = default(T);
            }
        }

        public Node head;

        private Node tail;

        private int size;

        public MyList()
        {
            tail =  head = new Node();
        }

        public int Size()
        {
            return size;
        }

        public void Add(T data)
        {
            Node node = new Node();
            node.data = data;
            tail.next = node;
            tail = node;
            size++;
        }

        public void Show()
        {
            Node node = head.next;

            while(node!=null)
            {
                Console.Write(node.data+" ");
                node = node.next;
            }
            Console.WriteLine();
        }

        public T FindIndex(int mark)
        {
            int i = 0;
            Node node = head.next;
            while(node!=null)
            {
                if (++i == mark) break;
                node = node.next;
            }
            if (node != null) return node.data;
            return default(T);
        }

        public int DeletedIndex(int mark)
        {
            int i = 0;
            Node node = head;
            while(node.next!=null)
            {
                if(++i==mark)
                {
                    Node pre = node;
                    Node next = node.next.next;
                    pre.next = next;
                    break;
                }
                node = node.next;
            }
            if (i == mark) return mark;
            return 0;
        }

        public static MyList<T> Merage(MyList<T> list1, MyList<T> list2,Func<T,T,int>compare)
        {
            MyList<T> list = new MyList<T>();
            Node i = list1.head.next;
            Node j = list2.head.next;
            while(i!=null||j!=null)
            {
                 if (i == null) { list.Add(j.data); j = j.next; }
                 else if (j == null) { list.Add(i.data); i = i.next; }
                 else if (compare(i.data, j.data) < 0) { list.Add(i.data); i = i.next; }
                 else { list.Add(j.data); j = j.next; }
            }
            return list;
        }
    }
}
