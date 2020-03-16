using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二叉查找树
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "kjdsfbasdfheirwqirqvzcxbnow9346465fdsfigj";
            Random random = new Random(3565);
            BST<string, int> bst = new BST<string, int>();
            bst.Compare = compare;
            foreach(char n in str)
            {
                bst.Put(n.ToString(),random.Next()%100);
            }

            bst.Show();
           /* Console.WriteLine("请输入您想要获取的键值对");
            Console.Write(bst.Get(Console.ReadLine())+"\n");*/
            Console.WriteLine("符号表中的最大键为为:"+ bst.Max());

            Console.WriteLine("符号表中的最小键为:"+bst.Min());

            Console.WriteLine("7向上取整的结果为:"+bst.Floor("7"));
            Console.WriteLine("7向下取整的结果为:"+bst.Celling("7"));

            Console.Clear();
            bst.Show();
            Console.Write("请输入您想要查找的排名数;  ");
            int mark = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("这个数是 "+bst.Select(mark));
            Console.ReadLine();

            Console.Clear();
            bst.Show();
            Console.WriteLine("请输入您要查找的键");
            str = Console.ReadLine();
            mark = bst.Rank(str);
            Console.WriteLine("这个键的排名是 "+mark);
            Console.ReadLine();

            Console.Clear();
            Console.WriteLine("在没有删除最小数之前 ");
            bst.Show();
            Console.WriteLine("删除最小数之后：");
            bst.DeletedMin();
            bst.Show();
            Console.ReadLine();

            Console.Clear();
            Console.WriteLine("在没有删除最大数之前 ");
            bst.Show();
            Console.WriteLine("删除最大数之后：");
            bst.DeletedMax();
            bst.Show();
            Console.ReadLine();

            Console.WriteLine("现在进行删除键的操作");
            Console.Clear();
            bst.Show();
            Console.Write("请输入您要删除的键: ");
            str = Console.ReadLine();
            bst.Deleted(str);
            Console.WriteLine("删除后符号表的数据为：");
            bst.Show();

            Console.Clear();
            Console.WriteLine("请输入您要进行输出的范围");
            Console.Write("最小范围为：");
            string min = Console.ReadLine();
            Console.Write("最大范围为：");
            string max = Console.ReadLine();
            var queue = bst.Keys(min,max);
            foreach(var n in queue)
            {
                Console.WriteLine(n);
            }
            Console.ReadLine();
        }

        public static int compare(string a,string b)
        {
            int mark = 0;
            if (a[0] < b[0]) mark = -1;
            else if (a[0] > b[0]) mark = 1;
            return mark;
        }
    }

    public class BST<Key,Value>
    {
        private Func<Key, Key, int> _compare;

        public Func<Key, Key, int> Compare
        {
            set { _compare = value; }
            get { return _compare; }
        }

        /// <summary>
        /// 二叉查找树中的根节点
        /// </summary>
        private Node root;

        /// <summary>
        /// 二叉查找树中的节点
        /// </summary>
        private class Node
        {
            public Node left, right;
            public Key key;
            public Value value;
            public int N;
            public Node()
            {
                left = null;
                right = null;
                N = 0;
            }

            public Node(Key key,Value value,int N)
            {
                this.key = key;
                this.value = value;
                this.N = N;
            }
        }

        public void Put(Key key ,Value value)
        {
            root = put(root,key,value);
        }

        public int Size()
        {
            return size(root);
        }

        private int size(Node x)
        {
            if (x == null) return 0;

            return x.N;
        }

        /// <summary>
        /// 插入数据的算法
        /// </summary>
        /// <param name="node"></param>
        /// <param name="key"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        private Node put(Node node ,Key key,Value value)
        {
            if (node == null) return new Node(key, value,1);

            int cmp = Compare(key,node.key);

            if (cmp > 0) { node.right = put(node.right, key, value); }
            else if (cmp < 0) { node.left = put(node.left, key, value); }
            else { node.value = value; }
            //分别对应小于等于和大于这三中情况

            node.N = size(node.left)+size(node.right)+1;//加上一表示算上了自己

            return node;
        }

        public Value Get(Key key)
        {
            Node target = get(root,key);
            if(target ==null)
            return default(Value);

            return target.value;
        }

        /// <summary>
        /// BST的选择算法
        /// </summary>
        /// <param name="node"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        private Node get(Node node , Key key)
        {
            if (node == null) return null;

            int comp = Compare(key,node.key);

            if (comp < 0) return get(node.left, key);
            else if (comp > 0) return get(node.right, key);
            else return node;
            
        } 

        public void Show()
        {
            show(root);
        }

        /// <summary>
        /// 查找的算法
        /// </summary>
        /// <param name="node"></param> 
        private void show(Node node)
        {
            if (node == null) return;
            show(node.left);
            Console.WriteLine(node.key + " " + node.value.ToString());
            show(node.right);
        }

        #region Max方法组
        public Key Max()
        {
            if(Size()==0) 
                return default(Key);
            Node node = Max(root);
            return node.key;
        }

        private Node Max(Node node)
        {
            if (node.right == null) return node;
            return Max(node.right);
        }
        #endregion

        #region Min方法组
        public Key Min()
        {
            if(Size()==0) return default(Key);
            Node node = Min(root);
            return node.key;
        }

        private Node Min(Node node)
        {
            if (node.left == null) return node;
            return Min(node.left);
        }
        #endregion

        #region 向下取整
        public Key Floor(Key key)
        {
            Node node = floor(root, key);
            if (node == null) return default(Key);
            return node.key;
        }

        private Node floor(Node node,Key key)
        {
            if (node == null) return null;
            int cmp = Compare(key, node.key);
            if (cmp < 0) return floor(node.left,key);
            if (cmp == 0) return node;
            Node t = floor(node.right,key);
            if (t == null) return node;
            else return t;
        }

        #endregion

        #region 向上取整

        public Key Celling(Key key)
        {
            Node node = celling(root, key);
            if (node == null) return default(Key);
            return node.key;
        }

        private Node celling(Node node, Key key)
        {
            if (node == null) return null;
            int cmp = Compare(key, node.key);
            if (cmp > 0) return celling(node.right, key);
            if (cmp == 0) return node;
            Node t = celling(node.left, key);
            if (t == null) return node;
            else return t;
        }
        #endregion

        #region 根据排名返回键

        /// <summary>
        /// 得到某个键的排名
        /// </summary>
        /// <param name="mark"></param>
        /// <returns></returns>
        public Key Select(int mark)
        {
            if (mark > root.N) { Console.WriteLine("有序符号表中没有这样的数"); return default(Key); }
            Node node = select(root,mark);
            return node.key;
        }

        private Node select(Node node,int mark)
        {
            if (node == null) { Console.WriteLine("没有这样的数"); return null; }
            int t = size(node.left);
            if (mark > t+1) return select(node.right, mark - t- 1);
            else if (mark < t+1) return select(node.left, mark);
            else  return node;
        }
        #endregion

        #region 获取键的排名
        /// <summary>
        /// 获取某一个键的排名
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public int Rank(Key key)
        {
            int r = rank(root,key);
            return r;
        }
        private int rank(Node node,Key key)
        {
            if (node == null) 
                return 0;
            int cmp = Compare(key,node.key);
            if (cmp < 0) return rank(node.left, key);
            else if (cmp > 0) return rank(node.right, key)+size(node.left)+1;
            else return size(node.left)+1;

        }
        #endregion

        #region 删除最小键
        public void DeletedMin()
        {
            deletedMin(root);
        }

        private Node deletedMin(Node node)
        {
            if (node.left == null) return node.right;
            node.left = deletedMin(node.left);
            node.N = size(node.left) + size(node.right)+1;
            return node; 
        }
        #endregion

        #region 删除最大键
        public void DeletedMax()
        {
            deletedMax(root);
        }
        private Node deletedMax(Node node)
        {
            if (node.right == null) return node.left;
            node.right = deletedMax(node.right);
            node.N = size(node.right)+size(node.left)+1;
            return node;
        }
        #endregion

        #region 删除键
        public bool Deleted(Key key)
        {
            Node node = deleted(root,key);
            if (node == null) return false;
            return true;
        }

        private Node deleted(Node node,Key key)
        {
            if (node == null) return null;
            int cmp = Compare(key,node.key);
            if (cmp < 0) node.left = deleted(node.left, key);
            else if (cmp > 0) node.right = deleted(node.right,key);
            else
            {
                if (node.left == null) return node.right;
                if (node.right == null) return node.left;
                Node min = Min(node.right);
                min.right = deletedMin(node.right);
                min.left = node.left;
                node = min;
            }
            node.N = size(node.left) + size(node.right)+1;
            return node;
        }

        #endregion

        #region 范围输出
        public Queue<Key> Keys()
        {
            Queue<Key> queue = new Queue<Key>();
            keys(Min(),Max(),root,queue);
            return queue;
        }

        public Queue<Key> Keys(Key lo, Key hi)
        {
            Queue<Key> queue = new Queue<Key>();
            keys(lo, hi, root,queue);
            return queue;
        }

        private void keys(Key lo, Key hi, Node node, Queue<Key> queue)
        {
            if (node == null) return;
            int cmpLo = Compare(lo,node.key);
            int cmpHi = Compare(hi,node.key);
            if (cmpLo < 0) keys(lo,hi,node.left,queue);
            if (cmpLo <= 0 && cmpHi >= 0) 
                queue.Enqueue(node.key);
            if (cmpHi > 0) keys(lo, hi, node.right,queue);
        }

        #endregion

    }
}
