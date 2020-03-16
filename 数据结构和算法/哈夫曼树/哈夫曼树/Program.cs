using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 哈夫曼树
{
    class Program
    {
        static void Main(string[] args)
        {

            List<int> nodes = new List<int>();

            int mark = -1;

            while((mark = Convert.ToInt32(Console.ReadLine()))!=0)
            {
                nodes.Add(mark);
            }

            HaFuManTree<int> hafumanTree = new HaFuManTree<int>(nodes.ToArray());

            hafumanTree.Compare = compare;

            hafumanTree.AddTreeNumber = addTreeNumber;

            hafumanTree.Add = Add;

            hafumanTree.createTree();

            hafumanTree.Show();

            Console.WriteLine("哈夫曼树的wpl值为 "+hafumanTree.WPL());

            Console.ReadLine();
        }

        /// <summary>
        /// 比较大小
        /// </summary>
        /// <param name="l"></param>
        /// <param name="r"></param>
        /// <returns></returns>
        public static int compare(int l,int r)
        {
            return l - r;
        }

        public static HaFuManTree<int>.Node Add(int l,int r)
        {
            HaFuManTree<int>.Node node = new HaFuManTree<int>.Node(l+r,false);

            return node;
        }

        public static int addTreeNumber(int data)
        {
            return data;
        }
    }

    public class HaFuManTree<T>
    {
        public class Node
        {
            public T data;

            public Node left, right;

            public bool isNode;

            public Node(T data, Node left, Node right, bool isNode)
            {
                this.left = left;

                this.right = right;

                this.isNode = isNode;

                this.data = data;

            }

            public Node(T data, bool isNode)
            {
                this.data = data;

                this.isNode = isNode;

            }
        }

        private List<Node> nodes;

        private Node root;

        private Func<T, T,int> compare;

        public Func<T, T, int> Compare
        {
            set { compare = value; }
        }

        private Func<T, T, Node> add;

        public Func<T,T,Node> Add
        {
            set { add = value; }
        }

        private Func<T, int> addTreeNumber;

        public Func<T,int> AddTreeNumber
        {
            set { addTreeNumber = value; }
        }

        private int TreeNumber;

        public HaFuManTree(T[] nodes)
        {
            this.nodes = new List<Node>();
            foreach(var n in nodes)
            {
                Node node = new Node(n,true);

                this.nodes.Add(node);
            }


        }

        public void createTree()
        {
            Node smallest = null;

            Node smaller = null;

            while(nodes.Count>1||smaller!=null||smallest!=null)
            {

                Node mark = nodes[0];

                for (int i = 0; i < nodes.Count; i++)
                {
                    if (compare(nodes[i].data, mark.data) < 0)
                    {
                        mark = nodes[i];
                    }
                }

                if(smallest==null)
                {
                    smallest = mark;

                    nodes.Remove(smallest);
                    
                }else if(smaller==null)
                {
                    smaller = mark;

                    nodes.Remove(smaller);
                }

                if(smaller!=null&&smallest!=null)
                {
                    Node node = add(smallest.data,smaller.data);

                    node.left = smaller;

                    node.right = smallest;
                    //Console.Write(nodes.Count);

                    nodes.Add(node);

                    smallest = null;

                    smaller = null;

                    
                }
            }
            root = nodes[0];
        }

        public int WPL()
        {
            wpl(root);

            return TreeNumber;
        }

        public void wpl(Node node)
        {
            if (node == null) return;

            if (!node.isNode) TreeNumber += addTreeNumber(node.data);

            wpl(node.right);

            wpl(node.left);
        }

        public void Show()
        {
            Console.Write("中序输出为");

            show(root);

            Console.WriteLine();
        }
        private void show(Node node)
        {
            if (node == null) return;

            show(node.left);

            Console.Write(node.data+" ");

            show(node.right);
        }
    }
}
