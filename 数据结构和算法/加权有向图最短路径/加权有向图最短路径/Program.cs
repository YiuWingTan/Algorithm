using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 加权有向图最短路径
{
    class Program
    {
        static void Main(string[] args)
        {
            EdgeWeightDigraph graph = null;

            TextDirectedWeightDiagrah(ref graph,args[0]);

            //TextDijkstraSP(graph);

            //TextAcylicSP(graph);

            //TextAcylicLP(graph);

            //TextCMP(args[0]);

            TextBellmanFord(graph);

            Console.ReadLine();
        }

        public static void TextDirectedWeightDiagrah(ref EdgeWeightDigraph graph,string str)
        {
            graph = new EdgeWeightDigraph(str);

            Console.WriteLine(graph.ToString());
        }
    
        public static void TextDijkstraSP(EdgeWeightDigraph graph)
        {
            DijkstraSP sp = new DijkstraSP(graph,5);

            for(int i = 0;i<graph.V();i++)
            {
                Console.Write("顶点0到顶点"+i+"的最短路径为 ");

                var edge = sp.PathTo(i);

                foreach (var e in edge) Console.Write(e.ToString()+" ");

                Console.WriteLine();
            }
        }

        public static void TextAcylicSP(EdgeWeightDigraph graph)
        {
            AcylicSP sp = new AcylicSP(graph,5);

            for (int i = 0; i < graph.V(); i++)
            {
                Console.Write("顶点0到顶点" + i + "的最短路径为 ");

                var edge = sp.PathTo(i);

                foreach (var e in edge) Console.Write(e.ToString() + " ");

                Console.WriteLine();
            }
        }

        public static void TextAcylicLP(EdgeWeightDigraph graph)
        {
            Console.WriteLine("图的最长路径为 ");

            AcylicLP lp = new AcylicLP(graph,5);

            for (int i = 0; i < graph.V(); i++)
            {
                Console.Write("顶点0到顶点" + i + "的最短路径为 ");

                var edge = lp.PathTo(i);

                foreach (var e in edge) Console.Write(e.ToString() + " ");

                Console.WriteLine();
            }
        }

        public static void TextCMP(string str)
        {
            Console.WriteLine("现在开始测试关键路径的算法");

            CPM cpm = new CPM(str);

            foreach (var e in cpm.CPMPath())
            {
                Console.Write(e.ToString());
            }

            Console.WriteLine("\n\n关键路径的长度为 "+cpm.DistTo());
        }

        public static void TextBellmanFord(EdgeWeightDigraph graph)
        {
            BellmanFordSP sp = new BellmanFordSP(graph,1);

            if (sp.negativeCycle() != null)
            {
                Console.Write("存在一个负权重的环 ");

                var cycle = sp.negativeCycle();

                foreach (var e in sp.negativeCycle())
                    Console.Write(""+e.ToString());

            }else
            {
                Console.WriteLine("最短路径为 ");

                for (int i = 0; i < graph.V(); i++)
                {
                    Console.Write("\n原点到顶点" + i + "的最短路径为");
                    foreach (var e in sp.PathTo(i))
                        Console.Write(e.ToString());
                }
                    
            }
                
        }


    }

    #region 加权有向图的边的数据结构
    /// <summary>
    /// 加权有向图的边的数据结构
    /// </summary>
    public class DirectedEdge
    {
        private double weight;

        private int form;

        private int to;

        /// <summary>
        /// 加权有向图边的数据结构的构造函数
        /// </summary>
        /// <param name="form">出度顶点</param>
        /// <param name="to">入度顶点</param>
        /// <param name="weight">边的权重</param>
        public DirectedEdge(int form,int to,double weight)
        {
            this.form = form;

            this.to = to;

            this.weight = weight;
        }

        /// <summary>
        /// 返回边的权重
        /// </summary>
        /// <returns></returns>
        public double Weight()
        {
            return weight;
        }

        /// <summary>
        /// 返回出度顶点
        /// </summary>
        /// <returns></returns>
        public int From()
        {
            return form;
        }

        /// <summary>
        /// 返回入度顶点
        /// </summary>
        /// <returns></returns>
        public int To()
        {
            return to;
        }

        /// <summary>
        /// 将边转化为string返回
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return form +"->" +to+"("+weight+")";
        }
    }

    #endregion

    #region 加权有向图的数据结构
    
    /// <summary>
    /// 加权有向图的实现
    /// </summary>
    public class EdgeWeightDigraph
    {
        private int v;

        private int e;

        private List<DirectedEdge>[] adj;

        private List<DirectedEdge> edges;//加权有向图的所有边

        private string str;//加权有向图的字符串表示

        public EdgeWeightDigraph(int V)
        {
            v = V;

            edges = new List<DirectedEdge>();

            adj = new List<DirectedEdge>[V];

            for (int i = 0; i < adj.Length; i++)
                adj[i] = new List<DirectedEdge>();
        }

        /// <summary>
        /// 通过标准格式进行构造
        /// </summary>
        /// <param name="In"></param>
        public EdgeWeightDigraph(string In)
        {
            string[] str = In.Split('\n');

            this.v = Int32.Parse(str[0]);

            edges = new List<DirectedEdge>();

            adj = new List<DirectedEdge>[v];

            for (int i = 0; i < adj.Length; i++)
                adj[i] = new List<DirectedEdge>();

            for (int i = 1; i < str.Length; i++)
            {
                string[] edge = str[i].Split('*');

                int form = Int32.Parse(edge[0]);

                int to = Int32.Parse(edge[1]);

                double weight = Double.Parse(edge[2]);

                AddEdge(form, to, weight);
            }
        }

        /// <summary>
        /// 返回顶点个数
        /// </summary>
        /// <returns></returns>
        public int V()
        {
            return v;
        }

        /// <summary>
        /// 返回边的个数
        /// </summary>
        /// <returns></returns>
        public int E()
        {
            return e;
        }

        /// <summary>
        /// 添加边的方法
        /// </summary>
        /// <param name="e"></param>
        public void AddEdge(DirectedEdge e)
        {
            int v = e.From();

            int w = e.To();

            if (v < 0 || v >= this.v) return;

            if (w < 0 || w >= this.v) return;

            adj[v].Add(e);

            edges.Add(e);

            str += "\n" + e.ToString();

            this.e++;
        }

        /// <summary>
        /// 添加边的方法
        /// </summary>
        /// <param name="form"></param>
        /// <param name="to"></param>
        /// <param name="weight"></param>
        public void AddEdge(int form,int to ,double weight)
        {
            if (form < 0 || form >= v) return;

            if (to < 0 || to >= v) return;

            DirectedEdge e = new DirectedEdge(form,to,weight);

            adj[form].Add(e);

            edges.Add(e);

            str += "\n" + e.ToString();

            this.e++;
        }

        /// <summary>
        /// 返回从顶点v指出的边
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public List<DirectedEdge> Adj(int v)
        {
            if (v < 0 || v >= this.v) return null;

            return adj[v];
        }

        /// <summary>
        /// 返回加权有向图的所有边
        /// </summary>
        /// <returns></returns>
        public List<DirectedEdge> Edges()
        {
            return edges;
        }

        /// <summary>
        /// 对象的字符串表示
        /// </summary>
        /// <returns></returns>
        public string ToString()
        {
            return str;
        }
    }

    #endregion

    #region 索引优先队列

    public class IndexMinPQ<T>
    {
        private int[] pq;//索引

        private int[] qp;//元素位置的索引

        private int N;//大小

        private T NULLMark;//空标志位

        private T[] Key;//元素的数组

        private Func<T, T, int> compare;//比较元素大小的方法
        public IndexMinPQ(Func<T, T, int> compare, T NullMark)
        {
            pq = new int[50];

            qp = new int[50];

            Key = new T[50];

            for (int i = 0; i < Key.Length; i++)
                Key[i] = NullMark;

            this.compare = compare;

            NULLMark = NullMark;
        }

        public IndexMinPQ(int Max, Func<T, T, int> compare, T NullMark)
        {
            pq = new int[Max];

            qp = new int[Max];

            Key = new T[Max];

            for (int i = 0; i < Key.Length; i++)
                Key[i] = NullMark;

            this.compare = compare;

            NULLMark = NullMark;
        }

        public void Insert(int k, T item)
        {
            if (++N >= pq.Length - 1) exband();

            if (k > Key.Length - 1) exbandKey(k);

            qp[k] = N;

            pq[N] = k;

            Key[k] = item;

            swim(N);
        }

        /// <summary>
        /// 改变k关联的值
        /// </summary>
        /// <param name="k"></param>
        /// <param name="item"></param>
        public void Change(int k, T item)
        {
            Key[k] = item;

            swim(qp[k]);

            sink(qp[k]);
        }

        /// <summary>
        /// 检查某个索引是否和某一个元素对应起来
        /// </summary>
        /// <param name="k"></param>
        /// <returns></returns>
        public bool Contains(int k)
        {
            if (k < 0 || k > Key.Length - 1) return false;

            return compare(Key[k], NULLMark) != 0;
        }

        /// <summary>
        /// 删除索引i及其对应的键值
        /// </summary>
        /// <param name="k"></param>
        public void Deleted(int k)
        {
            if (!Contains(k)) return;//如果不存在这样的键值的话不做任何操作

            int i = qp[k];

            exch(i, N);

            int j = pq[N];

            pq[N] = -1;

            qp[j] = 0;

            Key[j] = NULLMark;

            N--;

            sink(i);
        }

        /// <summary>
        /// 根据索引返回值
        /// </summary>
        /// <returns></returns>
        public T KeyOf(int k)
        {
            if (!Contains(k)) return NULLMark;


            return Key[pq[qp[k]]];
        }

        /// <summary>
        /// 删除索引优先队列中的最小值并返回其索引
        /// </summary>
        /// <returns></returns>
        public int PopMinIndex()
        {
            if (isEmpty()) return -1;

            int index = pq[1];

            Deleted(index);

            return index;
        }

        /// <summary>
        /// 返回索引优先队列中最小的值并删除它
        /// </summary>
        /// <returns></returns>
        public T PopMin()
        {
            if (isEmpty()) return NULLMark;

            T min = Key[pq[1]];

            Deleted(pq[1]);

            return min;
        }

        /// <summary>
        /// 返回最小的那个元素
        /// </summary>
        /// <returns></returns>
        public T Min()
        {
            if (isEmpty()) return NULLMark;

            return Key[pq[1]];
        }

        /// <summary>
        /// 返回最小的那个元素的索引
        /// </summary>
        /// <returns></returns>
        public int MinIndex()
        {
            return pq[1];
        }

        /// <summary>
        /// 索引优先队列是否为空
        /// </summary>
        /// <returns></returns>
        public bool isEmpty()
        {
            return N == 0;
        }

        /// <summary>
        /// 索引优先队列的大小
        /// </summary>
        /// <returns></returns>
        public int Size()
        {
            return N;
        }

        /// <summary>
        /// 把优先队列转化为一个索引数组并返回
        /// </summary>
        /// <returns></returns>
        public int[] ToIndexArray()
        {
            int[] Indexs = new int[N];

            for (int i = 0; i < N; i++)
            {
                Indexs[i] = pq[i + 1];
            }

            return Indexs;
        }

        /// <summary>
        /// 把优先队列的元素转化为一个数组并返回
        /// </summary>
        /// <returns></returns>
        public T[] ToValueArray()
        {
            T[] array = new T[this.Size()];

            for (int i = 0; i < N; i++)
            {
                array[i] = Key[pq[i + 1]];
            }

            return array;
        }

        /// <summary>
        /// 扩展数组方法
        /// </summary>
        private void exband()
        {
            int i = 0;

            int[] a = new int[pq.Length * 2];

            foreach (var n in pq)
                a[i++] = n;

            pq = a;
        }

        /// <summary>
        /// 扩展key数组
        /// </summary>
        private void exbandKey(int max)
        {
            int[] q = new int[max * 2];

            T[] a = new T[max * 2];

            for (int i = 0; i < Key.Length; i++)
            {
                q[i] = qp[i];

                a[i] = Key[i];
            }

            qp = q;

            Key = a;

        }

        /// <summary>
        /// 元素进行上游
        /// </summary>
        /// <param name="k"></param>
        private void swim(int k)
        {
            while (k / 2 >= 1 && compare(Key[pq[k / 2]], Key[pq[k]]) > 0)
            {
                exch(k, k / 2);

                k /= 2;
            }
        }

        /// <summary>
        /// 元素进行下称
        /// </summary>
        /// <param name="k"></param>
        private void sink(int k)
        {
            int mark = k;

            while (k * 2 <= N)
            {
                mark *= 2;

                if (k * 2 < N && compare(Key[pq[k * 2]], Key[pq[k * 2 + 1]]) > 0) mark++;

                if (compare(Key[pq[k]], Key[pq[mark]]) < 0) break;

                exch(k, mark);

                k = mark;
            }
        }

        /// <summary>
        /// 根据pq的编号来交换优先队列中的元素
        /// </summary>
        /// <param name="i"></param>
        /// <param name="j"></param>
        private void exch(int i, int j)
        {
            int k = pq[i];

            pq[i] = pq[j];

            pq[j] = k;

            qp[k] = j;

            qp[pq[i]] = i;
        }
    }

    #endregion

    #region 最短路径大的Difkstra算法

    /// <summary>
    /// 迪杰斯特拉最短路径算法
    /// </summary>
    public class DijkstraSP
    {
        private DirectedEdge[] edgeTo;

        private double[] distTo;

        private IndexMinPQ<double> pq;

        public DijkstraSP(EdgeWeightDigraph G,int s)
        {
            edgeTo = new DirectedEdge[G.V()];

            distTo = new double[G.V()];

            pq = new IndexMinPQ<double>(Compare,double.PositiveInfinity);

            for(int i = 1;i<distTo.Length;i++)
            {
                distTo[i] = double.PositiveInfinity;
            }

            distTo[s] = 0.0f;

            pq.Insert(s,0.0);

            while(!pq.isEmpty())
            {
                relax(G,pq.PopMinIndex());
            }

        }

        private int Compare(double v,double w)
        {
            if (v == w) return 0;

            return(int)(v - w);
        }

        /// <summary>
        /// 松弛方法
        /// </summary>
        public void relax(EdgeWeightDigraph G,int v)
        {
            foreach(var e in G.Adj(v))
            {
                int to = e.To();

                if(distTo[to]>distTo[v] + e.Weight())
                {
                    distTo[to] = distTo[v] + e.Weight();

                    edgeTo[to] = e;

                    if (pq.Contains(to)) 
                        pq.Change(to, distTo[to]);
                    else 
                        pq.Insert(to, distTo[to]);
                }
            }
        }

        /// <summary>
        /// 返回路径长度如果不存在这样的路径时返回正无穷大，输入发生错误时返回naN
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public double DistTo(int v)
        {
            if (v >= distTo.Length || v < 0) return double.NaN;

            return distTo[v];
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool HasPathTo(int v)
        {
            return distTo[v] != double.PositiveInfinity;
        }

        /// <summary>
        /// 返回原点到顶点v的路径
        /// </summary>
        /// <returns></returns>
        public Stack<DirectedEdge> PathTo(int v)
        {

            Stack<DirectedEdge> path = new Stack<DirectedEdge>();

            for(DirectedEdge e = edgeTo[v];e!=null;e = edgeTo[e.From()])
            {
                path.Push(e);
            }
            return path;
        }
    }
    #endregion

    #region 加权无环有向图的最短路径算法
    /// <summary>
    /// 加权无环有向图的最短路径的更优算法
    /// </summary>
    public class AcylicSP
    {
        private DirectedEdge[] edgeTo;

        private double[] distTo;

        /// <summary>
        /// 构造函数
        /// </summary>
        public AcylicSP(EdgeWeightDigraph G,int s)
        {
            edgeTo = new DirectedEdge[G.V()];

            distTo = new double[G.V()];

            for (int i = 0; i < distTo.Length; i++)
                distTo[i] = double.PositiveInfinity;

            distTo[s] = 0.0f;

            Toplogical logical = new Toplogical(G);

            var order = logical.Order();

            foreach (var n in order)
                relax(G,n);
        }

        /// <summary>
        /// 放松方法
        /// </summary>
        private void relax(EdgeWeightDigraph G,int v)
        {
            foreach(var e in G.Adj(v))
            {
                int to = e.To();

                if(distTo[to]>distTo[v]+e.Weight())
                {
                    distTo[to] = distTo[v] + e.Weight();

                    edgeTo[to] = e;
                }
            }
        }

        public double DistTo(int v)
        { 
            if(v<0||v>edgeTo.Length) return double.NaN;

            return distTo[v];
        }

        /// <summary>
        /// 检测是否存在从原点s到顶点v的最短路径
        /// </summary>
        /// <returns></returns>
        public bool HasPathTo(int v)
        {
            return edgeTo[v] != null;
        }

        /// <summary>
        /// 返回从原点到顶点v的最短路径
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public Stack<DirectedEdge> PathTo(int v)
        {
            Stack<DirectedEdge> edges = new Stack<DirectedEdge>();

            for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.From()])
                edges.Push(e);

            return edges;
        }
    }
    #endregion

    #region 最长路径算法

    /// <summary>
    /// 最长路径算法
    /// </summary>
    public class AcylicLP
    {
        private DirectedEdge[] edgeTo;

        private double[] distTo;

        public AcylicLP(EdgeWeightDigraph G,int s)
        {
            edgeTo = new DirectedEdge[G.V()];

            distTo = new double[G.V()];

            for(int i = 0;i<distTo.Length;i++)
            {
                distTo[i] = double.NegativeInfinity;
            }

            distTo[s] = 0.0;

            Toplogical logical = new Toplogical(G);

            var order = logical.Order();

            foreach(var n in order)
            {
                force(G, n);
            }
        }

        /// <summary>
        /// 边的拉伸算法
        /// </summary>
        private void force(EdgeWeightDigraph G,int v)
        {
            foreach(var e in G.Adj(v))
            {
                int w = e.To();

                if (w == 0)
                    Console.WriteLine("lll");

                if(distTo[w]<distTo[v]+e.Weight())
                {
                    distTo[w] = distTo[v] + e.Weight();

                    edgeTo[w] = e;
                }
            }
        }
        /// <summary>
        /// 返回从原点s到顶点v的最长路径长度
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public double DistTo(int v)
        {
            if(v<0||v>distTo.Length) return double.NaN;

            return distTo[v];
        }

        /// <summary>
        /// 判断是否存在路径从原点s到顶点v
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public bool HasPathTo(int v)
        {
            if (v < 0 || v > distTo.Length) return false;

            return edgeTo[v] != null;
        }

        /// <summary>
        /// 返回从顶点s到顶点v的最长路径
        /// </summary>
        /// <returns></returns>
        public Stack<DirectedEdge> PathTo(int v)
        {
            Stack<DirectedEdge> path = new Stack<DirectedEdge>();

            if (v < 0 || v > distTo.Length) return path;

            for(DirectedEdge e = edgeTo[v];e!=null;e = edgeTo[e.From()])
            {
                path.Push(e);
            }

            return path;
        }

    }

    #endregion

    #region 深度优先次序
    public class DepthFirstOrder
    {
        private bool[] marked;

        private Queue<int> pre;

        private Queue<int> post;

        private Stack<int> reversePost;

        public DepthFirstOrder(EdgeWeightDigraph G)
        {
            marked = new bool[G.V()];

            pre = new Queue<int>();

            post = new Queue<int>();

            reversePost = new Stack<int>();

            for(int i =0;i<marked.Length;i++)
            {
                if (!marked[i]) dfs(G,i);
            }
        }

        private void dfs(EdgeWeightDigraph G , int v)
        {
            marked[v] = true;

            pre.Enqueue(v);

            foreach(var n in G.Adj(v))
            {
                if (!marked[n.To()]) dfs(G,n.To());
            }

            post.Enqueue(v);

            reversePost.Push(v);
        }

        /// <summary>
        /// 返回前序
        /// </summary>
        /// <returns></returns>
        public Queue<int> Pre()
        {
            return pre;
        }

        public Queue<int> Post()
        {
            return post;
        }

        public Stack<int> ReversePost()
        {
            return reversePost;
        }
    }
    #endregion

    #region 拓扑排序
    public class Toplogical
    {
        private Stack<int> order;

        public Toplogical(EdgeWeightDigraph G)
        {
            DepthFirstOrder dfo = new DepthFirstOrder(G);

            order = dfo.ReversePost();
        }
        public Stack<int> Order()
        {
            return order;
        }
    }
    #endregion

    #region 平行任务调度问题的关键路径算法
    public class CPM
    {
        private Stack<DirectedEdge> []cpm;//保存完成每一个任务的关键路径

        private Stack<DirectedEdge> Cpm;//整个图的关键路径

        private double distToCpm;

        private double[] distTo;//保存每一个关键路径的长度

        /// <summary>
        /// 通过已有的关键路径图来进行计算关键路径
        /// </summary>
        /// <param name="G"></param>
        /// <param name="start"></param>
        /// <param name="end"></param>
        public CPM(EdgeWeightDigraph G,int start,int end)
        {
            cpm = new Stack<DirectedEdge>[G.V()];

            distTo = new double[G.V()];

            AcylicLP lp = new AcylicLP(G,start);

            for(int i = 0;i<G.V();i++)
            {
                cpm[i] = lp.PathTo(i);

                distTo[i] = lp.DistTo(i);
            }

            Cpm = lp.PathTo(end);
        }

        /// <summary>
        /// 传入普通的带权有向图来进行计算
        /// </summary>
        /// <param name="G"></param>
        public CPM(string str)
        {

            string[] vertex = str.Split('\n');

            EdgeWeightDigraph G = new EdgeWeightDigraph(int.Parse(vertex[0])*2+2);

            int start = int.Parse(vertex[0]) * 2, end = int.Parse(vertex[0]) * 2 + 1, N = int.Parse(vertex[0]);

            for(int i = 1;i<vertex.Length;i++)
            {
                string[] info = vertex[i].Split('-');

                G.AddEdge(start,i-1,0);

                G.AddEdge(i-1,(i-1)+N,double.Parse(info[0]));

                G.AddEdge(i-1+N,end,0);

                for(int j = 1;j<info.Length;j++)
                {
                    G.AddEdge((i - 1) + N, int.Parse(info[j]),0);
                }
            }

            AcylicLP lp = new AcylicLP(G,start);

            Cpm = lp.PathTo(end);

            distToCpm = lp.DistTo(end);
        }

        /// <summary>
        /// 返回是否存在关键路径
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public bool HasCPM(int v)
        {
            return cpm[v] != null;
        }

        /// <summary>
        /// 返回起始点到目标点的关键路径
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public Stack<DirectedEdge> CPMPath(int v)
        {
            return cpm[v];
        }

        /// <summary>
        /// 返回整个图的关键路径
        /// </summary>
        /// <returns></returns>
        public Stack<DirectedEdge> CPMPath()
        {
            return Cpm;
        }

        /// <summary>
        /// 某个顶点的关键路径的长度
        /// </summary>
        /// <returns></returns>
        public double DistTo(int v)
        {
            return distTo[v];
        }

        /// <summary>
        /// 整个图关键路径的长度
        /// </summary>
        /// <returns></returns>
        public double DistTo()
        {
            return distToCpm;
        }
        
    }
    #endregion

    #region 优先队列版BellmanFord最短路径算法

    public class BellmanFordSP
    {
        private double[] distTo;

        private DirectedEdge[] edgeTo;

        private bool []onQ;

        private Queue<int> queue;

        private Stack<DirectedEdge> cycle;//保存图中的负权重环

        private int cost;//记录relax方法的调用次数

        public BellmanFordSP(EdgeWeightDigraph G, int s)
        {
            distTo = new double[G.V()];

            for (int i = 0; i < distTo.Length; i++)
                distTo[i] = double.PositiveInfinity;

            distTo[s] = 0.0f;

            edgeTo = new DirectedEdge[G.V()];

            onQ = new bool[G.V()];

            queue = new Queue<int>();

            queue.Enqueue(s);

            while(queue.Count()!=0&&!this.hasNegativeCycle())
            {
                cost++;

                int v = queue.Dequeue();

                onQ[v] = false;

                relax(G,v);
            }
        }

        /// <summary>
        /// 放松的方法
        /// </summary>
        private void relax(EdgeWeightDigraph G,int v)
        {
            foreach(var e in G.Adj(v))
            {
                int w = e.To();

                if(distTo[w]>distTo[v]+e.Weight())
                {
                    if(!onQ[w])
                    {
                        queue.Enqueue(w);

                        onQ[w] = true;
                    }
                     

                    distTo[w] = distTo[v] + e.Weight();

                    edgeTo[w] = e;
                }

                if (cost++ % G.V() == 0)
                    FindNegative();

            }


        }

        /// <summary>
        /// 返回原点到顶点v的最短距离
        /// </summary>
        /// <returns></returns>
        public double DistTo(int v)
        {
            if (v < 0 || v >= distTo.Length) return double.NaN;

            return distTo[v];
        }

        /// <summary>
        /// 判断是否存在原点到顶点v的路径
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public bool HasPathTo(int v)
        {
            if (v < 0 || v >= distTo.Length) return false;

            return edgeTo[v] != null;

        }

        /// <summary>
        /// 返回从原点到顶点v的一条最短路径
        /// </summary>
        /// <returns></returns>
        public Stack<DirectedEdge> PathTo(int v)
        {
            Stack<DirectedEdge> edge = new Stack<DirectedEdge>();

            if(HasPathTo(v))
            {
                for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.From()])
                    edge.Push(e);
            }

            return edge;
        }

        /// <summary>
        /// 寻找负权重的环
        /// </summary>
        private void FindNegative()
        {
            EdgeWeightDigraph G = new EdgeWeightDigraph(distTo.Length);

            for (int i = 0; i < edgeTo.Length; i++)
                if (edgeTo[i] != null)
                    G.AddEdge(edgeTo[i]);

            DirectedWeightCycle C = new DirectedWeightCycle(G);

            cycle = C.Cycle();
        }

        /// <summary>
        /// 判断是否存在负权重的环
        /// </summary>
        /// <returns></returns>
        private bool hasNegativeCycle()
        {
            return cycle != null;
        }

        /// <summary>
        /// 返回一个负权重的环
        /// </summary>
        /// <returns></returns>
        public Stack<DirectedEdge> negativeCycle()
        {
            return cycle;
        }

    }

    #endregion


    #region 检测加权有向图是否有环

    /// <summary>
    /// 检测加权有向图是否有环的数据结构
    /// </summary>
    public class DirectedWeightCycle
    {
        private bool[] marked;

        private DirectedEdge[] edgeTo;

        private bool[] OnStack;

        private Stack<DirectedEdge> cycle;

        public DirectedWeightCycle(EdgeWeightDigraph G)
        {
            marked = new bool[G.V()];

            edgeTo = new DirectedEdge[G.V()];

            OnStack = new bool[G.V()];

            for (int i = 0; i < marked.Length; i++)
                if(!marked[i])
                dfs(G,i);
        }

        private void dfs(EdgeWeightDigraph G,int v)
        {
            marked[v] = true;

            OnStack[v] = true;

            foreach(var e in G.Adj(v))
            {
                if (HasCycle()) return;
                else if(!marked[e.To()])
                {
                    edgeTo[e.To()] = e;

                    dfs(G,e.To());
                }else if(OnStack[e.To()])
                {
                    cycle = new Stack<DirectedEdge>();

                    cycle.Push(e);

                    DirectedEdge edge;

                    for (edge = edgeTo[e.From()]; edge.From() != e.To(); edge = edgeTo[edge.From()])
                        cycle.Push(edge);

                    cycle.Push(edge);
                }
            }

            OnStack[v] = false;
        }

        /// <summary>
        ///判断图中是否存在环 
        /// </summary>
        /// <returns></returns>
        public bool HasCycle()
        {
            return cycle != null;
        }

        /// <summary>
        /// 返回图中的环
        /// </summary>
        /// <returns></returns>
        public Stack<DirectedEdge> Cycle()
        {
            return cycle;
        }
    }

    #endregion
}
 