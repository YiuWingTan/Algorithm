using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 平衡二叉查找树
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            string str = "kjnjfglvs;pw[eprtgopiehvndg244556gdfg9vi0934oitr983rb23i";
            Random random = new Random(244545);
            RedBalckBST<string, int> redBlackBST = new RedBalckBST<string, int>();
            redBlackBST.Compare = compare;
            foreach(var n in str)
            {
                redBlackBST.Put(n.ToString(),random.Next()%100);
            }
            redBlackBST.Show();
            Console.ReadLine();

            Console.Clear();
            Console.WriteLine("在还没有删除最小节点之前，红黑树为");
            redBlackBST.Show();

            Console.WriteLine("在删除最小节点后，红黑树为");
            redBlackBST.deletedMin();
            redBlackBST.Show();
            Console.ReadLine();

            Console.Clear();
            Console.WriteLine("在删除最大键之前,红黑树为");
            redBlackBST.Show();

            Console.WriteLine("在删除最大键之后，红黑树为");
            redBlackBST.deletedMax();
            redBlackBST.Show();
            Console.ReadLine();

            Console.Clear();
            Console.Write("请输入您要进行删除的键: ");
            string key = Console.ReadLine();
            Console.WriteLine("在还没有进行删除之前，红黑树为");
            redBlackBST.Show();

            redBlackBST.deleted(key);
            Console.WriteLine("在进行节点删除之后红黑树的结构变为： ");
            redBlackBST.Show();

            Console.ReadLine();
        }

        private static int compare(string s1,string s2)
        {
            return s1[0] - s2[0];
        }
    }


    /// <summary>
    /// 红黑树
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    public class RedBalckBST<Key,Value>
    {
        /// <summary>
        /// 比较的泛型方法
        /// </summary>
        private Func<Key, Key, int> compare;

        public Func<Key, Key, int> Compare
        {
            set { compare = value; }
        }

        private bool RED = true; //节点为红色的标识

        private bool BLACK = false;//节点为黑色的标识

        private Node root;//红黑树的根节点

        private class Node
        {
            public Key key;
            public Value value;
            public int N;
            public Node left, right;
            public bool Color;

            public Node(Key key,Value value,int N,bool Color)
            {
                this.key = key;
                this.value = value;
                this.Color = Color;
                this.N = N;
            }
        }

        public RedBalckBST()
        {
            root = null;
        }

        public bool isEmpty()
        {
            if (size(root) == 0) return true;
            return false;
        }

        /// <summary>
        /// 判断树中的节点是不是红节点
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private bool isRed(Node node)
        {
            if (node == null) return false;
            return node.Color == RED;
        }

        /// <summary>
        /// 节点的向左旋转
        /// </summary>
        /// <param name="h"></param>
        /// <returns></returns>
        private Node rotateLeft(Node h)
        {
            Node x = h.right;
            h.right = x.left;
            x.left = h;
            h.Color = RED;
            x.N = h.N;
            h.N = size(h.left)+size(h.right)+1;
            return x;
        }

        /// <summary>
        /// 让节点向右旋转
        /// </summary>
        /// <param name="h"></param>
        /// <returns></returns>
        private Node rotateRight(Node h)
        {
            Node x = h.left;
            h.left = x.right;
            x.right = h;
            h.Color = RED;
            x.N = h.N;
            h.N = size(h.left)+size(h.right)+1;
            return x;
        }

        public int Size()
        {
            return size(root);
        }

        /// <summary>
        /// 返回节点的下属节点个数
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private int size(Node node)
        {
            if (node == null) return 0;
            return node.N;
        }

        /// <summary>
        /// 颜色转换
        /// </summary>
        /// <param name="node"></param>
        private void flipColors(Node node)
        {
            node.Color = RED;
            node.left.Color = BLACK;
            node.right.Color = BLACK;
        }

        /// <summary>
        /// 把节点的颜色和它的左右子节点的颜色进行反转
        /// </summary>
        /// <param name="node"></param>
        private void newflipColors(Node node)
        {
            node.Color = !node.Color;
            node.left.Color = !node.left.Color;
            node.right.Color = !node.right.Color;
        }

        /// <summary>
        /// 在删除节点之后使红黑树回溯进行自我的修复
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private Node fixup(Node node)
        {
            if (isRed(node.right)) node = rotateLeft(node);
            if (isRed(node.left) && isRed(node.left.left)) node = rotateRight(node);
            if (isRed(node.left) && isRed(node.right)) flipColors(node);
            return node;
        }

       

        #region 插入节点的方法
        public void Put(Key key,Value value)
        {
            root =  put(root,key,value);
        }

        private Node put(Node node,Key key,Value value)
        {
            if (node == null) return new Node(key,value,1,RED);

            int cmp = compare(key,node.key);
            if (cmp < 0) node.left = put(node.left, key, value);
            else if (cmp > 0) node.right = put(node.right, key, value);
            else node.value = value;
            //进行大小检测


            if (!isRed(node.left) && isRed(node.right)) node = rotateLeft(node); //保证了红节点一定只在节点的左边才会存在
            //下面这两条语句保证了把一个临时的4-节点的中节点往上移动
            if (isRed(node.left) && isRed(node.left.left))  node = rotateRight(node);
            if (isRed(node.left) && isRed(node.right)) flipColors(node);
            node.N = size(node.left)+size(node.right)+1;

            return node;
        }
        #endregion


        #region 获取键的方法组

        public Value get(Key key)
        {
            Node target = get(root,key);
            if (target == null)
            {
                Console.WriteLine("红黑树中不存在这样的键");
                return default(Value);
            }
            return target.value;
        }

        private Node get(Node node,Key key)
        {
            if (node == null) return null;
            int cmp = compare(node.key,key);
            if (cmp < 0) return get(node.right, key);
            else if (cmp > 0) return get(node.left, key);
            else return node;
        }

        #endregion

        #region 展示树的方法组
        public void Show()
        {
            show(root);
        }

        private void show(Node node)
        {
            if (node == null) return;
            show(node.left);
            Console.WriteLine("节点 "+node.key+"    值为"+node.value);
            show(node.right);
        }
        #endregion

        #region 删除方法组
        public void deleted(Key key)
        {
            if (!isRed(root.left) && !isRed(root.right))
                root.Color = RED;

            root = deleted(root,key);
            if (!isEmpty()) root.Color = BLACK;
        }
        
        private Node deleted(Node node, Key key)
        {
            int cmp = compare(key,node.key);
            if(cmp<0)
            {
                if (node.left == null) { Console.WriteLine("红黑树中不存在这样的键"); return node; }
                if (!isRed(node.left) && !isRed(node.left.left))
                    moveRedLeft(node);
                node.left = deleted(node.left,key);
            }else
            {
                if (node.right == null) { Console.WriteLine("红黑树中不存在这样的键"); return node; }
                if (isRed(node.left))
                    node = rotateRight(node);
                if (cmp == 0 && node.right == null) return null;
                if (!isRed(node.right) && !isRed(node.right.left))
                    moveRedRight(node);
                if (cmp == 0)
                {
                    Node target = get(node.right, Min(node.right).key);
                    node.value = target.value;
                    node.key = target.key;
                    node.right = deletedMin(node.right);
                }
                else
                    node.right = deleted(node.right,key);
                    
            }
            //使节点再次变成平衡的
            return fixup(node);
        }

        #endregion

        #region 删除最小键的方法组
        /// <summary>
        /// 删除红黑树中的最小键
        /// </summary>
        public void deletedMin()
        {
            if (!isRed(root.left) && !isRed(root.right))
                root.Color = RED;
            root = deletedMin(root);
            if (!isEmpty()) root.Color = BLACK;
        }

        private Node deletedMin(Node node)
        {
            if (node.left == null) return null;

            if (!isRed(node.left) && !isRed(node.left.left))
                node = moveRedLeft(node);
            node.left = deletedMin(node.left);
            return fixup(node); ;
        }

        /// <summary>
        /// 在删除最小节点时对所有不合格的做节点进行修正，使当前的做节点绝对不是3-节点
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private Node moveRedLeft(Node node)
        {
            newflipColors(node);
            //进行节点的颜色反转之后当前的2-节点就会变成一个4-节点
            if (isRed(node.right.left))
            {
                node.right = rotateRight(node.right);
                node = rotateLeft(node);
                newflipColors(node);
            }
            return node;
        }

        #endregion

        #region 删除最大键的方法组

        public void deletedMax()
        {
            if (!isRed(root.left) && isRed(root.right))
                root.Color = RED;
            root = deltedMax(root);
            if (!isEmpty()) root.Color = BLACK;
        }

        private Node deltedMax(Node node)
        {
            //如果检测到节点的左边是一个红节点，就马上进行有旋转
            if (isRed(node.left)) node = rotateRight(node);

            if (node.right == null) return null;

            if (!isRed(node.right) && !isRed(node.right.left))
                node = moveRedRight(node);
            node.right = deltedMax(node.right);

            return fixup(node) ;
        }

        private Node moveRedRight(Node node)
        {
            //先预先把节点后它的左右节点都转换成一个4-节点
            newflipColors(node);

            if(isRed(node.left.left)) //如果左节点的左节点是一个红节点的话就在左节点后此节点中各拿出一个节点来给右节点来组成一个4-节点
            {
                node = rotateRight(node);
                newflipColors(node);
            }
            return node;
        }

        #endregion

        #region Max方法组
        public Key Max()
        {
            if (Size() == 0)
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
            if (Size() == 0) return default(Key);
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

        private Node floor(Node node, Key key)
        {
            if (node == null) return null;
            int cmp = compare(key, node.key);
            if (cmp < 0) return floor(node.left, key);
            if (cmp == 0) return node;
            Node t = floor(node.right, key);
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
            int cmp = compare(key, node.key);
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
            Node node = select(root, mark);
            return node.key;
        }

        private Node select(Node node, int mark)
        {
            if (node == null) { Console.WriteLine("没有这样的数"); return null; }
            int t = size(node.left);
            if (mark > t + 1) return select(node.right, mark - t - 1);
            else if (mark < t + 1) return select(node.left, mark);
            else return node;
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
            int r = rank(root, key);
            return r;
        }
        private int rank(Node node, Key key)
        {
            if (node == null)
                return 0;
            int cmp = compare(key, node.key);
            if (cmp < 0) return rank(node.left, key);
            else if (cmp > 0) return rank(node.right, key) + size(node.left) + 1;
            else return size(node.left) + 1;

        }
        #endregion

    }
}
