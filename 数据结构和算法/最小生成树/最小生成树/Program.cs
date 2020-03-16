using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 最小生成树
{
    class Program
    {
        static void Main(string[] args)
        {
            EdgeWeightGraph graph = null;

            TextCreateGraph(ref graph, args[0]);

            //Console.WriteLine(double.PositiveInfinity - double.PositiveInfinity);

            //TextMinPQ();

            //TextIndexMinPQ();

            //TextLazyPrimMst(ref graph);

            TextPrimMST(ref graph);

            //TextUnionFind();

            //TextKruskal(ref graph);

            Console.ReadLine();

        }

        public static void TextCreateGraph(ref EdgeWeightGraph graph, string str)
        {
            graph = new EdgeWeightGraph(str);

            graph.ToString();
        }

        public static void TextMinPQ()
        {
            MinPQ<int> pq = new MinPQ<int>((i,j)=>(i-j),-1);

            int data = 0;
            while((data = Convert.ToInt32(Console.ReadLine()))!=-2)
            {
                pq.Insert(data);
            }
            
            while(!pq.isEmpty())
            {
                Console.Write(pq.Pop()+" ");
            }
        }

        public static void TextLazyPrimMst(ref EdgeWeightGraph graph)
        {
            LazyPrimMST mst = new LazyPrimMST(graph);

            Console.WriteLine("\n\n\n");

            Console.WriteLine("最小生成树的边为 ");

            foreach(var edge in mst.Edges())
            {
                Console.WriteLine(edge.ToString());
            }

            Console.Write("最小生成树的wpl为 "+mst.Weight());
        }

        public static void TextIndexMinPQ()
        {
            Console.WriteLine("现在开始测试索引优先队列,请输入相应的索引和数据,当用户输入的索引为-1时停止进行输入");

            IndexMinPQ<int> indexMinPQ = new IndexMinPQ<int>((i,j)=>(i-j),-2);

            int data;

            int index;

            while((index = Convert.ToInt32(Console.ReadLine()))!=-1)
            {
                //if (index == -1) Console.WriteLine("出现了-1");

                data = Convert.ToInt32(Console.ReadLine());

                indexMinPQ.Insert(index,data);
            }

            var array = indexMinPQ.ToIndexArray();

            var values = indexMinPQ.ToValueArray();

            Console.Write("优先队列的顺序为 ");
            foreach(var n in array)
            {
                Console.Write(indexMinPQ.KeyOf(n)+"("+n+")  ");
            }

            Console.WriteLine("\n请输入您要进行改变的那一个数的索引");

            index = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("请输入索引将要关联的新的值");

            int value = Convert.ToInt32(Console.ReadLine());

            indexMinPQ.Change(index,value);

            while(!indexMinPQ.isEmpty())
            {
                Console.Write(indexMinPQ.Min()+"("+indexMinPQ.PopMinIndex()+")"+"  ");
            }
        }

        public static void TextPrimMST(ref EdgeWeightGraph graph)
        {
            PrimMST mst = new PrimMST(graph);

            Console.WriteLine("最小生成树的边为 ");

            var edges = mst.Edges();

            foreach(var e in edges)
            {
                Console.WriteLine(e.ToString());
            }
        }

        public static void TextUnionFind()
        {
            Console.WriteLine("现在开始测试并查集数据结构的正确性 ");

            Console.Write("请输入并查集初始时的连通分量个数  ");

            int n = Convert.ToInt32(Console.ReadLine());

            UnionFind uf = new UnionFind(n);

            Console.Write("请输入您想要进行合并的连通分量的id号，输入-1停止 ");

            while((n = Convert.ToInt32(Console.ReadLine()))!=-1)
            {
                Console.Write("请输入您想要进行合并的连通分量的id号，输入-1停止 ");

                int m = Convert.ToInt32(Console.ReadLine());

                if (m == -1) break;

                uf.Union(n,m);

                Console.WriteLine("现在的连通分量个数为 "+uf.Count()+"\n 输入任意值继续");

                Console.ReadLine();

                Console.Clear();

                Console.Write("请输入您想要进行合并的连通分量的id号，输入-1停止");
            }
        }

        public static void TextKruskal(ref EdgeWeightGraph G)
        {
            KruskalMST mst = new KruskalMST(G);

            var edges = mst.Edges();

            foreach(var e in edges)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }

    #region 加权无向图边的数据结构
    /// <summary>
    /// 加权无向图边的数据结构
    /// </summary>
    public class Edge
    {
        private int v;

        private int w;

        private double weight;//权值

        public Edge(int v, int w, double weight)
        {
            this.v = v;

            this.w = w;

            this.weight = weight;
        }

        /// <summary>
        /// 返回边的权值
        /// </summary>
        /// <returns></returns>
        public double Weight()
        {
            return weight;
        }

        /// <summary>
        /// 返回两顶点之一
        /// </summary>
        /// <returns></returns>
        public int Either()
        {
            return v;
        }
        /// <summary>
        /// 返回与v对应的另一个顶点
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public int Other(int vertex)
        {
            if (vertex == v) return w;
            else if (vertex == w) return v;
            else throw new MethodAccessException("这个顶点不存在于这个边之中");
        }

        /// <summary>
        /// 比较两条边的权值的大小
        /// </summary>
        /// <param name="that"></param>
        /// <returns></returns>
        public int Compare(Edge that)
        {
            if (that.weight > this.weight) return -1;
            else if (that.weight < this.weight) return 1;
            else return 0;
        }

        /// <summary>
        /// 将边转化为v-w的字符串形式并进行输出
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return v + "-" + w + "权值为 " + weight + "\n";
        }
    }

    #endregion

    #region 加权无向图的数据结构

    /// <summary>
    /// 加权无向图
    /// </summary>
    public class EdgeWeightGraph
    {
        private int V;//顶点的总数

        private int E;//边的总数

        private List<Edge>[] adj;//无向加权图的邻接表

        public EdgeWeightGraph(int v)
        {
            V = v;

            this.E = 0;

            adj = new List<Edge>[V];

            for (int i = 0; i < adj.Length; i++)
                adj[i] = new List<Edge>();
        }

        public EdgeWeightGraph(string In)
        {

            string[] str = In.Split('\n');

            V = Int32.Parse(str[0]);

            adj = new List<Edge>[V];

            for (int i = 0; i < adj.Length; i++)
                adj[i] = new List<Edge>();

            for (int i = 1; i < str.Length; i++)
            {
                string[] edge = str[i].Split('-');

                int v = Int32.Parse(edge[0]);

                int w = Int32.Parse(edge[1]);

                double weight = Double.Parse(edge[2]);

                AddEdge(v, w, weight);
            }
        }

        /// <summary>
        /// 返回顶点的总数
        /// </summary>
        /// <returns></returns>
        public int VSize()
        {
            return V;
        }

        /// <summary>
        /// 返回边的总数
        /// </summary>
        /// <returns></returns>
        public int ESize()
        {
            return E;
        }

        /// <summary>
        /// 往图中添加边
        /// </summary>
        /// <param name="v"></param>
        /// <param name="w"></param>
        public void AddEdge(int v, int w, double weight)
        {
            if (v < 0 || v >= V) return;

            if (w < 0 || w >= V) return;

            Edge e = new Edge(v, w, weight);

            adj[v].Add(e);

            adj[w].Add(e);

            E++;

        }

        public List<Edge> Adj(int v)
        {
            if (v < 0 || v >= V) return null;
            return adj[v];
        }

        /// <summary>
        /// 返回图中所有的边
        /// </summary>
        /// <returns></returns>
        public List<Edge> Edges()
        {
            List<Edge> all = new List<Edge>();

            for (int v = 0; v < V; v++)
            {
                foreach (Edge e in Adj(v))
                {
                    if (e.Other(v) > v) all.Add(e);
                }
            }
            return all;
        }

        public new void ToString()
        {
            Console.WriteLine("无向带权图的结构为：");

            foreach (var link in adj)
            {
                string edges = "";
                foreach (var e in link)
                {
                    edges += e.ToString();
                }
                Console.WriteLine(edges);
            }
        }
    }
    #endregion

    #region 优先队列的实现
    /// <summary>
    /// 优先队列的实现
    /// </summary>
    public class MinPQ<T>
    {
        private T[] pq;//保存数据的数组

        private int N = 0;//保存堆中数据的个数

        private Func<T, T, int> compare;//比较函数

        private T NULLMark;//发生异常操作时的返回位

        /// <summary>
        /// 最小优先队列的构造函数
        /// </summary>
        /// <param name="maxN">表示最小优先队列可以容纳的最大元素数量</param>
        /// <param name="compare">一个保存比较堆中元素的方法</param>
        /// <param name="error">当用户有错误操作时返回的值需要用户指定</param>
        public MinPQ(int maxN, Func<T, T, int> compare, T NULLMark)
        {
            this.compare = compare;

            pq = new T[maxN];

            this.NULLMark = NULLMark;
        }

        /// <summary>
        /// 最小优先队列的构造函数
        /// </summary>
        /// <param name="compare">一个保存比较堆中元素的方法</param>
        /// <param name="error">当用户有错误操作时返回的值需要用户指定</param>
        public MinPQ(Func<T, T, int> compare, T NULLMark)
        {
            pq = new T[50];

            this.compare = compare;

            this.NULLMark = NULLMark;
        }

        /// <summary>
        /// 查看优先队列是否为空
        /// </summary>
        /// <returns></returns>
        public bool isEmpty()
        {
            return N == 0;
        }

        /// <summary>
        /// 往优先队列中插入元素
        /// </summary>
        /// <param name="v"></param>
        public void Insert(T v)
        {
            if (++N > pq.Length - 1) exband();

            pq[N] = v;

            swim(N);
        }

        /// <summary>
        /// 获取并删除优先队列中最小的元素
        /// </summary>
        /// <returns></returns>
        public T Pop()
        {
            if (isEmpty()) 
                return NULLMark;

            T min = pq[1];

            pq[1] = NULLMark;

            exch(1,N);

            N--;

            sink(1);

            

            return min;
        }

        /// <summary>
        /// 获取最小的元素但不进行删除
        /// </summary>
        /// <returns></returns>
        public T GetMin()
        {
            if (isEmpty()) return NULLMark;

            return pq[1];
        }

        /// <summary>
        /// 交换堆中两个元素
        /// </summary>
        private void exch(int i,int j)
        {
            T middle = pq[i];

            pq[i] = pq[j];

            pq[j] = middle;
        }

        /// <summary>
        /// 优先队列的上浮放方法
        /// </summary>
        private void swim(int k)
        {
            for(int i = k;i>1;i/=2)
            {
                if (compare(pq[i], pq[i / 2]) < 0) exch(i, i / 2);
                else break;
            }
        }

        /// <summary>
        /// 优先队列的下沉方法
        /// </summary>
        private void sink(int k)
        {
            int j = k;

            while(k*2<=N)
            {
                j = k * 2;

                if (j < N && compare(pq[j],pq[j+1]) > 0) j++;//找出最小的那个

                if (compare(pq[k], pq[j]) < 0) break;

                exch(k,j);

                k = j;
            }
        }

        /// <summary>
        /// 使堆的容量进行扩大
        /// </summary>
        private void exband()
        {
            T []a = new T[pq.Length*2];

            int i = 0;

            foreach(var n in pq)
            {
                a[i++] = n;
            }

            pq = a;
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
        public IndexMinPQ(Func<T,T,int> compare,T NullMark)
        {
            pq = new int[50];

            qp = new int[50];

            Key = new T[50];

            for (int i = 0; i < Key.Length; i++)
                Key[i] = NullMark;

            this.compare = compare;

            NULLMark = NullMark;
        }

        public IndexMinPQ(int Max,Func<T,T,int> compare,T NullMark)
        {
            pq = new int[Max];

            qp = new int[Max];

            Key = new T[Max];

            for (int i = 0; i < Key.Length; i++)
                Key[i] = NullMark;

                this.compare = compare;

            NULLMark = NullMark;
        }

        public void Insert(int k,T item)
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
        public void Change(int k,T item)
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

            exch(i,N);

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

            for(int i = 0;i<N;i++)
            {
                Indexs[i] = pq[i+1];
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

            int []a = new int[pq.Length*2];

            foreach (var n in pq)
                a[i++] = n;

            pq = a;
        }

        /// <summary>
        /// 扩展key数组
        /// </summary>
        private void exbandKey(int max)
        {
            int []q = new int[max*2];

            T []a = new T[max*2];

            for(int i = 0;i<Key.Length;i++)
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
            while(k/2>=1&&compare(Key[pq[k/2]],Key[pq[k]])>0)
            {
                exch(k,k/2);

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

            while(k*2<=N)
            {
                mark *= 2;

                if (k * 2 < N && compare(Key[pq[k * 2]], Key[pq[k * 2 + 1]]) > 0) mark++;

                if (compare(Key[pq[k]], Key[pq[mark]]) < 0) break;

                exch(k,mark);

                k = mark;
            }
        }

        /// <summary>
        /// 根据pq的编号来交换优先队列中的元素
        /// </summary>
        /// <param name="i"></param>
        /// <param name="j"></param>
        private void exch(int i,int j)
        {
            int k = pq[i];

            pq[i] = pq[j];

            pq[j] = k;

            qp[k] = j;

            qp[pq[i]] = i;
        }
    }

    #endregion

    #region Prim算法的延时实现
    public class LazyPrimMST
    {
        private bool[] marked;//顶点的标志位

        private Queue<Edge> mst;//保存最小生成树

        private MinPQ<Edge> pq;//保存横切边的优先队列

        private double wpl;//最小生成树的WPL

        public LazyPrimMST(EdgeWeightGraph G)
        {
            marked = new bool[G.VSize()];

            mst = new Queue<Edge>();

            pq = new MinPQ<Edge>(Compare,null);

            visit(G,0);

            while(!pq.isEmpty())
            {
                Edge e = pq.Pop();

                int v = e.Either(), w = e.Other(v);

                if (marked[v] && marked[w]) continue;

                mst.Enqueue(e);

                if (!marked[v]) visit(G, v);

                if (!marked[w]) visit(G,w);
            }
            
            //求最小生生成树的wpl
            foreach (var n in mst)
            {
                wpl += n.Weight();
            }

        }


        /// <summary>
        /// 比较两条边全职大小的方法
        /// </summary>
        /// <param name="e"></param>
        /// <param name="s"></param>
        /// <returns></returns>
        private int Compare(Edge e,Edge s)
        {
            return (int)(e.Weight() - s.Weight()); 
        }

        /// <summary>
        /// 标记顶点V并且把顶点v的所有邻接边全部添加到优先队列中
        /// </summary>
        /// <param name="G"></param>
        /// <param name="v"></param>
        private void visit(EdgeWeightGraph G,int v)
        {
            marked[v] = true;

            foreach(var edge in G.Adj(v))
            {
                pq.Insert(edge);
            }
        }

        /// <summary>
        /// 返回最小生成树边的队列
        /// </summary>
        /// <returns></returns>
        public Queue<Edge> Edges()
        {
            return mst;
        }

        /// <summary>
        /// 返回最小生成树的WPL
        /// </summary>
        /// <returns></returns>
        public double Weight()
        {
            return wpl;
        }

        
    }
    #endregion

    #region Prim算法的即时实现
    public class PrimMST
    {
        private Edge[] edgeTo;//距离最小生成树最近的边

        private double[] distTo;//距离最小生成树最近的边的权值

        private bool[] marked;//标记顶点是否被查看过

        private IndexMinPQ<double> indexMinPQ;//索引优先队列

        private double weight;//最小生成树的权重

        private List<Edge> edge;//list类型的最小生成的边的集合

        public PrimMST(EdgeWeightGraph G)
        {
            marked = new bool[G.VSize()];

            distTo = new double[G.VSize()];

            edgeTo = new Edge[G.VSize()];

            indexMinPQ = new IndexMinPQ<double>(Compare,double.PositiveInfinity);

            for(int i = 0;i<distTo.Length;i++)
            {
                distTo[i] = double.PositiveInfinity;//初始先设定所有顶点到最小生成树的最小距离为正无穷大
            }

            distTo[0] = double.NegativeInfinity;//设置顶点零到最小生成树的边的距离为负无穷大

            indexMinPQ.Insert(0,distTo[0]);//起初最小生成树中只有一个顶点

            while(!indexMinPQ.isEmpty())
            {
                int v = indexMinPQ.PopMinIndex();

                visit(G,v);
            }

            edge = new List<Edge>();

            for (int i = 1; i < distTo.Length; i++)
            {
                weight += distTo[i];

                edge.Add(edgeTo[i]);
            }
            
        }

        /// <summary>
        /// 比较两条边权值的大小
        /// </summary>
        /// <param name="v"></param>
        /// <param name="w"></param>
        /// <returns></returns>
        private int Compare(double v,double w)
        {
            if (v == w) return 0;

            return (int)(v- w);
        }

        /// <summary>
        /// 把顶点和它的邻接边进行操作的方法
        /// </summary>
        /// <param name="G"></param>
        /// <param name="v"></param>
        private void visit(EdgeWeightGraph G,int v)
        {
            marked[v] = true;

            int w = v;

            foreach(var edge in G.Adj(v))
            {
                w = edge.Other(v);

                if (!marked[w])//与顶点v相互邻接的顶点没有被标记过
                {
                    if (edge.Weight() < distTo[w])
                    {
                        edgeTo[w] = edge;

                        distTo[w] = edge.Weight();

                        if (indexMinPQ.Contains(w))//如果顶点已经在队列中了
                            indexMinPQ.Change(w, distTo[w]);//更新索引队列中相应的值
                        else 
                            indexMinPQ.Insert(w,distTo[w]);//否则就把该顶点添加到队列中
                    }
                }
            }
        }

        /// <summary>
        /// 返回最小生成树的所有边
        /// </summary>
        /// <returns></returns>
        public List<Edge> Edges()
        {
            return edge;
        }

        /// <summary>
        /// 返回最小生成树的WPL
        /// </summary>
        /// <returns></returns>
        public double Weight()
        {
            return weight;
        }
        
    }
    #endregion

    #region 简单并查集(Union-Find)的实现
        /// <summary>
        /// 并查集
        /// </summary>
        public class UnionFind
        {
            private int count;//连通分量的个数

            private int[] id;//id数组

            public UnionFind(int N)
            {
                count = N;

                id = new int[N];

                for(int i = 0;i<id.Length;i++)
                {
                    id[i] = i;
                }
            }

            /// <summary>
            /// 返回ID号
            /// </summary>
            /// <returns></returns>
            public int FindID(int v)
            {
                return id[v];
            }

            /// <summary>
            /// 判断是否链接
            /// </summary>
            /// <returns></returns>
            public bool Connected(int v,int w)
            {
                return id[v] == id[w];
            }

            /// <summary>
            /// 进行链接的方法
            /// </summary>
            public void Union(int p,int q)
            {
                int IDp = FindID(p);

                int IDq = FindID(q);

                if (IDp == IDq) return;

                for(int i = 0;i<id.Length;i++)
                {
                    if (id[i] == IDq) id[i] = IDp;
                }

                count--;
            }

            /// <summary>
            /// 返回并查集中连通分量的个数
            /// </summary>
            /// <returns></returns>
            public int Count()
            {
                return count;
            }
        }
    #endregion

    #region Kruskal算法的实现
        public class KruskalMST
        {
            private Queue<Edge> mst;

            private MinPQ<Edge> pq;

            private UnionFind uf;

            private double wpl;

            public KruskalMST(EdgeWeightGraph G)
            {
                mst = new Queue<Edge>();

                pq = new MinPQ<Edge>(Compare,null);

                var e = G.Edges();

                foreach (var n in e)
                    pq.Insert(n);

                uf = new UnionFind(G.VSize());

                int v,w;

                while(!pq.isEmpty()&&uf.Count()!=1)
                {
                    Edge adj = pq.Pop();

                    v = adj.Either();

                    w = adj.Other(v);

                    if (uf.Connected(v, w)) continue;

                    wpl += adj.Weight();

                    mst.Enqueue(adj);

                    uf.Union(v,w);
                }
            }

            /// <summary>
            /// 比较方法
            /// </summary>
            /// <param name="e"></param>
            /// <param name="w"></param>
            /// <returns></returns>
            private int Compare(Edge e,Edge w)
            {
                return (int)(e.Weight() - w.Weight());
            }

            /// <summary>
            /// 返回最小生成树
            /// </summary>
            /// <returns></returns>
            public Queue<Edge> Edges()
            {
                return mst;
            }

            /// <summary>
            /// 返回最小生成树的wpl
            /// </summary>
            /// <returns></returns>
            public double Weight()
            {
                return wpl;
            }
        }
    #endregion
}
