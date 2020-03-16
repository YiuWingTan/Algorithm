using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace 符号图
{
    class Program
    {
        public static string path = "W:\\VS2013程序项目工程文件夹\\算法\\符号图\\符号图\\data.txt";

        static void Main(string[] args)
        {
            SymbolGraph symbolGraph = new SymbolGraph(path,' ');

            Graph G = symbolGraph.G();

            Console.WriteLine("请输入要进行度数查询的编号");

            int q = Convert.ToInt32(Console.ReadLine());

            int p = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("\n\n");

            Console.WriteLine("和编号 "+q+"相关联的字符串是 "+symbolGraph.Name(q));

            Console.WriteLine();

            Console.WriteLine("和编号 "+p+"相关联的字符串是 "+symbolGraph.Name(p));

            Console.WriteLine("");

            BreadFirstPaths breadFirstPaths = new BreadFirstPaths(G, q);


            int mark = 0;

            Console.WriteLine(symbolGraph.Name(q)+" 到 "+symbolGraph.Name(p)+" 的关系网为 ");

            foreach(var n in breadFirstPaths.PathTo(p))
            {
                if (n != p)
                    Console.Write(symbolGraph.Name(n) + " -> ");
                else
                    Console.WriteLine(symbolGraph.Name(n));

                mark++;
            }

            mark--;//度数的计算值会比实际的值大一

            Console.WriteLine('\n'+"从"+symbolGraph.Name(q)+" 到 "+symbolGraph.Name(p)+"的度数为 "+mark);


            Console.ReadLine();
        }
    }

    /// <summary>
    /// 无向图的数据结构
    /// </summary>
    public class Graph
    {
        private int V;

        private int E;

        private List<int>[] adj;

        public Graph(string str)
        {
            init();
        }


        public Graph(int V,int E)
        {
            this.V = V;

            this.E = E;

            init();
        }

        public Graph(int V)
        {
            this.V = V;

            init();
        }

        private void init()
        {
            adj = new List<int>[V];

            for(int i = 0;i<V;i++)
            {
                adj[i] = new List<int>();
            }
        }

        public int[] Adj(int v)
        {
            if (v > V - 1) return null;

            return adj[v].ToArray();
        }

        /// <summary>
        /// 添加边
        /// </summary>
        public void AddEdge(int p,int q)
        {
            if (p > V - 1 || q > V - 1) return; //越界返回

            if (p < 0 || q < 0) return;

            if (!adj[p].Contains(q)) adj[p].Add(q);

            if (!adj[q].Contains(p)) adj[q].Add(p);

            E++;
        }

        public int SizeV()
        {
            return V;
        }

        public int SizeE()
        {
            return E;
        }

        /// <summary>
        /// 显示图
        /// </summary>
        public void toString()
        {
            for (int i = 0; i < adj.Count(); i++)
            {
                foreach (var item in adj[i])
                {
                    Console.WriteLine(i + " -> " +item);
                }
            }
        }
        
       
        public void ToString_Point(int V)
        {
            if (V < 0 || V > this.V - 1) return;

            foreach (var item in adj[V])
            {
                Console.WriteLine(V+" -> "+item);
            }
        }

    }

    /// <summary>
    /// 符号表的数据结构
    /// </summary>
    public class SymbolGraph
    {
        private Graph graph;//无向图的数据结构

        private Dictionary<string, int> st;//数据结构使用的符号表

        private string[] keys;//保存键的数组

        public SymbolGraph(string str)
        {

        }

        /// <summary>
        /// 可拓展的构造方法，指定一个文件来进行构造
        /// </summary>
        /// <param name="fileName"></param>
        /// <param name="delim"></param>
        public SymbolGraph(string fileName,char delim)
        {
            StreamReader reader = new StreamReader(@fileName);

            st = new Dictionary<string, int>();

            while (!reader.EndOfStream)
            {
                string[] str = reader.ReadLine().Split(delim);

                foreach(var n in str)
                {
                    if (!st.ContainsKey(n)) st.Add(n,st.Count());
                }
            }

            keys = new string[st.Count()];

            foreach (var item in st.Keys)
            {
                int i = 0;
                st.TryGetValue(item,out i);

                keys[i] = item;
            }

            graph = new Graph(keys.Length);

            reader = new StreamReader(@fileName);

            while(!reader.EndOfStream)
            {
                string[] str = reader.ReadLine().Split(delim);

                int i = 0;
                int j = 0;

                st.TryGetValue(str[0],out i);

                st.TryGetValue(str[1],out j);

                graph.AddEdge(i,j);
            }

            graph.toString();
        }

        /// <summary>
        /// 判断一个顶点是否存在
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public bool Contains(string key)
        {
            return st.ContainsKey(key); ;
        }

        /// <summary>
        /// 返回一个顶点对应的编号
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public int Index(string key)
        {
            int index = -1;

            st.TryGetValue(key,out index);

            return index;
        }

        /// <summary>
        /// 根据编号返回顶点的名字
        /// </summary>
        /// <returns></returns>
        public string Name(int V)
        {
            if (V < 0 || V >= keys.Length) return "";

            return keys[V];
        }

        public Graph G()
        {
            return graph;
        }

    }

    /// <summary>
    /// 广度优先搜索
    /// </summary>
    public class BreadFirstPaths
    {
        private bool[] marked;

        private int[] edgeTo;

        private Graph G;

        private int S;

        public BreadFirstPaths(Graph G,int S)
        {
            this.G = G;

            this.S = S;

            marked = new bool[G.SizeV()];

            edgeTo = new int[G.SizeV()];

            bfp(G,S);
        }

        /// <summary>
        /// 广度优先搜索
        /// </summary>
        /// <param name="G"></param>
        /// <param name="S"></param>
        private void bfp(Graph G,int S)
        {
            Queue<int> queue = new Queue<int>();

            queue.Enqueue(S);

            while(queue.Count()!=0)
            {
                int mark = queue.Dequeue();

                foreach(var n in G.Adj(mark))
                {
                    if(!marked[n])
                    {
                        marked[n] = true;

                        edgeTo[n] = mark;

                        queue.Enqueue(n);
                    }
                }
            }
        }

        /// <summary>
        /// 检测是否拥有路径
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public bool HavePath(int v)
        {
            return marked[v];
        }



        /// <summary>
        /// 返回一个路径
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public Stack<int> PathTo(int n)
        {
            if (!marked[n]) return null;

            Stack<int> path = new Stack<int>();

            for(int w = n;w!=S;w = edgeTo[w])
            {
                path.Push(w);
            }
            path.Push(S);

            return path;
            
        }
 
    }
}
