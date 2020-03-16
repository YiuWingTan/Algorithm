using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二叉树
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<char> binaryTree = new BinaryTree<char>();

            Console.WriteLine("请随意输入一段字符，来构造树");

            string str = Console.ReadLine();

            foreach(char n in str)
            {
                binaryTree.InsertNode(n);
            }


            Console.WriteLine();
            Console.WriteLine("请根据相应的提示来选择输出的方式:");

            Console.WriteLine("输入1表示进行中序输出");

            Console.WriteLine("输入2表示进行前序输出");

            Console.WriteLine("输入3表示进行后序输出");

            int mark = Convert.ToInt32(Console.ReadLine());

            if (mark == 1) { Console.WriteLine("中序输出为: "); binaryTree.Show_byMiddle(); }
            if (mark == 2) { Console.WriteLine("前序输出为: "); binaryTree.Show_byForward(); }
            if (mark == 3) { Console.WriteLine("后序输出为: "); binaryTree.Show_byBack(); }
            Console.ReadLine();

            Console.WriteLine("所有叶子节点到根结点的路径：");
            Console.WriteLine();
            binaryTree.showPath();

            Console.ReadLine();
        }
    }

    /// <summary>
    /// 二叉树
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class BinaryTree<T>
    {
        private Node[] tree;

        private int N;

        private class Node
        {
            public Node left, right;
            public T data;

            public Node(T data)
            {
                this.data = data;
            }
        }


        public BinaryTree()
        {
            N = 0;
            
            tree = new Node[10];
        }

        public BinaryTree(T[]datas)
        {
            tree = new Node[datas.Length+1];
            for(int i = 0;i<datas.Length;i++)
            {
                tree[i + 1] = new Node(datas[i]);
            }
        }

        /// <summary>
        /// 设置节点和他的父节点进行连接
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        private int getFatherNode(int i)
        {
            if ((i / 2) >= 1)
                return (i / 2);

            return 0;
        }

        /// <summary>
        /// 插入节点
        /// </summary>
        /// <param name="data"></param>
        public void InsertNode(T data)
        {
            Node node = new Node(data);

            if (N + 1 >= tree.Length) EnlargeTree();//扩增数组

            tree[N+1] = node;

            int father = getFatherNode(N+1);

            N++;

            if (father == 0) return; //如何节点没有父节点退出

            LinkFather(N,father);

           

        }

         /// <summary>
         /// 扩增数组
         /// </summary>
        private void EnlargeTree()
        {
            Node[] copy = tree;

            tree = new Node[tree.Length*2];
            for(int i = 1;i<copy.Length;i++)
                tree[i] = copy[i];
        }

        /// <summary>
        /// 把节点和它的父节点连接起来
        /// </summary>
        private void LinkFather(int number,int fatherNumber)
        {
            if(fatherNumber*2==number)
                tree[fatherNumber].left = tree[number];
            else tree[fatherNumber].right = tree[number];
        }

        #region 遍历方法组

        //中序遍历
        public void Show_byMiddle()
        {
            show_byMiddle(tree[1]);
        }

        private void show_byMiddle(Node node)
        {
            if (node == null) return;

            show_byMiddle(node.left);

            Console.Write(node.data+"  ");

            show_byMiddle(node.right);
        }

        //后序遍历
        public void Show_byBack()
        {
            show_byBack(tree[1]);
        }

        private void show_byBack(Node node)
        {
            if (node == null) return;

            show_byBack(node.left);

            show_byBack(node.right);

            Console.Write(node.data + "  ");
        }

        //前序遍历
        public void Show_byForward()
        {
            show_byForward(tree[1]);
        }

        private void show_byForward(Node node)
        {
            if (node == null) return;

            Console.Write(node.data + "  ");

            show_byForward(node.left);

            show_byForward(node.right);
        }
        #endregion

        /// <summary>
        /// 输出叶子的路劲
        /// </summary>
        public void showPath()
        {
            int mark = N;
            while(tree[mark].left==null&&tree[mark].right==null)
            {
                int n = mark;
                while (getFatherNode(n) != 0) { Console.Write(tree[mark].data.ToString() + "->" + tree[mark / 2].data+"->"); n = n / 2; }

                Console.WriteLine();
                Console.WriteLine();
                mark--;
            }
        }

    }
}
