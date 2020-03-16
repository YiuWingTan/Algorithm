using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 散列表
{
    class Program
    {
        static void Main(string[] args)
        {
            //TextSperateChaningHashST();

            TextLinearLinearProbingHashST();

        }


        private static void TextSperateChaningHashST()
        {
            SperateChaningHashST<string, int> sperateChaningHashSt = new SperateChaningHashST<string, int>(100);

            sperateChaningHashSt.compare = compare;

            Random random = new Random(5151);

            string str = Console.ReadLine();

            foreach (char n in str)
                sperateChaningHashSt.put(n.ToString(), random.Next() % 100);

            sperateChaningHashSt.show();

            Console.Write("请输入您要寻找的键  ");

            string mark = Console.ReadLine();
            Console.Write("您要寻找的的键值对为 ");

            Console.WriteLine(mark[0] + "   " + sperateChaningHashSt.get(mark[0].ToString()));

            Console.ReadLine();

            Console.Clear();

            sperateChaningHashSt.show();

            Console.Write("请输入您想要删除的键值对 ");

            string target = Console.ReadLine();

            sperateChaningHashSt.deleted(target[0].ToString());

            Console.WriteLine("删除后的散列表中的数据为 ");

            sperateChaningHashSt.show();

            Console.ReadLine();
        }

        private static void TextLinearLinearProbingHashST()
        {
            LinearProbingHashST<string, int> linearProbingHashST = new LinearProbingHashST<string, int>();

            linearProbingHashST.Compare = compare;

            Random random = new Random(23);

            Console.Write("请输入键列  ");

            string str = Console.ReadLine();

            foreach(var n in str)
            {
                linearProbingHashST.put(n.ToString(),random.Next()%100);
            }

            linearProbingHashST.show();

            Console.ReadLine();

            Console.Clear();

            linearProbingHashST.show();

            Console.WriteLine("现在进行键值对的寻找 ");
            Console.Write("请输入您要进行查找的键值对  ");

            string target = Console.ReadLine();

            Console.WriteLine(target[0]+"  "+linearProbingHashST.get(target[0].ToString()));


            Console.ReadLine();

            Console.Clear();

            Console.WriteLine("现在进行散列表的删除操作");

            linearProbingHashST.show();

            Console.WriteLine("现在的散列表的长度为 "+linearProbingHashST.Size());

            Console.WriteLine("请输入您要删除的键");

            string mark = Console.ReadLine();

            linearProbingHashST.deleted(mark[0].ToString());

            linearProbingHashST.show();

            Console.WriteLine("现在的散列表的长度为 "+linearProbingHashST.Size());

            Console.ReadLine();
        }

        /// <summary>
        /// 对比两个键是否相等
        /// </summary>
        /// <param name="s1"></param>
        /// <param name="s2"></param>
        /// <returns></returns>
        public static bool compare(string s1,string s2)
        {
            if (s1[0] == s2[0]) return true;
            return false;
        }

    }

    #region 基于拉链法的散列表


    /// <summary>
    /// 基于拉链法的散列表
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    public class SperateChaningHashST<Key,Value>
    {
        public Func<Key,Key,bool> compare
        {
            set { SequentialSearchST<Key, Value>.compare = value; }
        }

        private int N;

        private int M;

        private SequentialSearchST<Key, Value>[] st;

        /// <summary>
        /// 不带参的构造函数
        /// </summary>
        public SperateChaningHashST():this(997)//调用带参的构造函数，散列表默认构造997长度的表
        {
            
        }

        /// <summary>
        /// 带参的构造函数
        /// </summary>
        /// <param name="M"></param>
        public SperateChaningHashST(int M)
        {
            this.M = M;
            st = new SequentialSearchST<Key,Value>[M];
            for(int i = 0;i<M;i++)
            {
                st[i] = new SequentialSearchST<Key, Value>();
            }

        }

        /// <summary>
        /// 把键值散列到表中对应的位置
        /// </summary>
        /// <param name="key">键值</param>
        /// <returns>返回在表中的位置</returns>
        private int hash(Key key)
        {
            return (key.GetHashCode()&0x7fffffff)%M;
        }

        /// <summary>
        /// 往散列表中放置键
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void put(Key key ,Value value)
        {
            N++;
            st[hash(key)].put(key,value);
        }

        /// <summary>
        /// 获取散列表中键对应的值
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public Value get(Key key)
        {
            return st[hash(key)].get(key); ;
        }

        /// <summary>
        /// 根据键值来删除键值对
        /// </summary>
        /// <param name="key"></param>
        public void deleted(Key key)
        {
            st[hash(key)].deleted(key);
        }

        /// <summary>
        /// 输出散列表中的所有数据
        /// </summary>
        public void show()
        {
            foreach(var n in st)
            {
                n.show();
            }
        }

    }

    public class SequentialSearchST<Key ,Value>
    {
        public static Func<Key, Key, bool> compare;

        private int N;

        private Node list;

        public SequentialSearchST()
        {
            list = new Node();
        }

        /// <summary>
        /// 节点
        /// </summary>
        private  class Node
        {
            public Key key;

            public Value vaule;

            public Node next;

            public Node()
            {

            }

            public Node(Key key ,Value vaule)
            {
                this.key = key;
                this.vaule = vaule;
            }

        }

        /// <summary>
        /// 存放
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void put(Key key ,Value value)
        {
            N++;

            Node target  = null;

            Node node = new Node(key,value);

            get(key,ref target);

            if (target != null) { target.vaule = value; return; } 

            node.next = list.next;

            list.next = node;
           
        }

        /// <summary>
        /// 获取
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public Value get(Key key)
        {
            Node node = list.next;

            while(node!=null)
            {
                if (compare(node.key, key)) break;
                node = node.next;
            }
            if(node==null)
            return default(Value);

            return node.vaule;
        }

        /// <summary>
        /// get的重载，如果找到相同的键值对的话就返回
        /// </summary>
        /// <param name="key"></param>
        /// <param name="target"></param>
        private void get(Key key,ref Node target)
        {
            Node node = list.next;

            while (node != null)
            {
                if (compare(node.key, key)) break;
                node = node.next;
            }

            target = node;
        }

        /// <summary>
        /// 获取表的长度
        /// </summary>
        /// <returns></returns>
        public int Size()
        {
            return N;
        }
        /// <summary>
        /// 展示一条链表上的所有数据
        /// </summary>
        public void show()
        {
            Node node = list.next;

            while(node!=null)
            {
                Console.WriteLine(node.key+"   "+node.vaule);
                node = node.next;
            }
            //Console.WriteLine();
        }

        /// <summary>
        /// 删除的算法
        /// </summary>
        /// <param name="key"></param>
        public void deleted(Key key)
        {
            Node node = list;

            while(node.next!=null)
            {
                if(compare(node.next.key,key))
                {
                    node.next = node.next.next;
                    break;
                }
                node = node.next;
            }
        }
    }

    #endregion


    #region 基于线性探测的散列表
    public class LinearProbingHashST<Key,Value>
    {
        private Func<Key, Key, bool> compare;

        public Func<Key,Key,bool> Compare
        {
            set { compare = value; }
        }

        private int N;

        private int M = 50;

        private Node[] Elements;

        private class Node
        {
            public Key key;

            public Value value;

            public Node(Key key,Value value)
            {
                this.key = key;

                this.value = value;
            }
        }

        public LinearProbingHashST()
        {
            Elements = new Node[M];
        }

        public LinearProbingHashST(int cap)
        {
            M = cap;

            Elements = new  Node[M];
        }

        /// <summary>
        /// 插入键值对
        /// </summary>
        public void put(Key key,Value value)
        {
            if (N > M / 2) resize();
            int mark = hash(key);
            for (; Elements[mark] != null; mark = (mark + 1) % M)
            {
                if (compare(Elements[mark].key, key)) { Elements[mark].value = value; return; }
            }
            Node node = new Node(key,value);

            Elements[mark] = node;

            N++;
            
        }

        /// <summary>
        /// 获取键值
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public Value get(Key key)
        {
            int mark = hash(key);

            for (; Elements[mark] != null; mark = (mark+1)%M)
            {
                if (compare(Elements[mark].key, key)) { return Elements[mark].value; }
            }

            Console.WriteLine("没有这样的键值对");

                return default(Value);
        }

        /// <summary>
        /// 根据哈希值获取数组索引
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        private int hash(Key key)
        {
            return ((key.GetHashCode() & 0x7fffffff) % M);//把哈希值进行&位运算
        }

        /// <summary>
        /// 进行数组的扩增
        /// </summary>
        private void resize()
        {
            LinearProbingHashST<Key, Value> linearHashST = new LinearProbingHashST<Key, Value>(M*2);

            for (int i = 0; i < M; i++)
            {
                if (Elements[i] != null)
                    linearHashST.put(Elements[i].key, Elements[i].value);
            }

            Elements = linearHashST.Elements;

            M = linearHashST.M;

        }

        /// <summary>
        /// 根据传入的数值重新设置散列表的大小
        /// </summary>
        /// <param name="number"></param>
        private void resize(int number)
        {
            LinearProbingHashST<Key, Value> linearHashST = new LinearProbingHashST<Key, Value>(number);

            for(int i = 0;i<M;i++)
            {
                if (Elements[i] != null)
                    linearHashST.put(Elements[i].key,Elements[i].value);
            }

            Elements = linearHashST.Elements;

            M = linearHashST.M;
        }

        /// <summary>
        /// 获取散列表
        /// </summary>
        /// <returns></returns>
        public int Size()
        {
            return N;
        }

        /// <summary>
        /// 输出散列表中的所有元素
        /// </summary>
        public void show()
        {
            foreach(var n in Elements)
            {
                if (n != null) { Console.WriteLine(n.key + "  " + n.value); } 
            }

            Console.WriteLine();
        }

        /// <summary>
        /// 查看散列表中是否含有某键
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public bool Contain(Key key)
        {
            Node node = null;

            int mark = hash(key);

            for(;Elements[mark]!=null;mark = (mark+1)%M)
            {
                if (compare(Elements[mark].key, key)) { node = Elements[mark]; break; }
            }

            if (node == null) return false;

            return true;
        }

        /// <summary>
        /// 散列表的删除方法
        /// </summary>
        /// <param name="key"></param>
        public void deleted(Key key)
        {
            if (!Contain(key)) return;

            int mark = hash(key);

            //寻找键,并删除键
            for(;Elements[mark]!=null;mark = (mark+1)%M)
            {
                if (compare(Elements[mark].key, key)) { Elements[mark] = null; break; }
            }

            N--;

            //为什么不让后面的元素直接前移一个位置呢，因为前移的过程可能造成已经有序的散列表的顺序被打乱
            for(mark = (mark+1)%M;Elements[mark]!=null;mark = (mark+1)%M)
            {
                
                Node node = Elements[mark];

                Elements[mark] = null;

                put(node.key,node.value);//把键重新插入回散列表中

                N--;

            }

            if (N > 0 && N < M / 8) { resize(M/2); }
        }

        
    }


    #endregion
    
}
