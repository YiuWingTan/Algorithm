using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 有向图
{
    class Program
    {
        static void Main(string[] args)
        {
            Digraph Graph = null;

            CreateGraph(ref Graph,args[0]);

            TextDFS(Graph);

            TextBFS(Graph);

            TextDirectedCycle(Graph);

            TextDepthFirstOrder(Graph);

            TextToPoLogical(Graph);

            TextKosarajuSCC(Graph);

            Console.ReadLine();
        }

        public static void CreateGraph(ref Digraph graph)
        {
            Console.WriteLine("请输入图中的顶点个数");

            int v = Convert.ToInt32(Console.ReadLine());

            graph = new Digraph(v);

            while(true)
            {
                Console.Clear();

                Console.WriteLine("现在进行有向图中的边的创建，当你输入-1时停止进行边的创建");

                int V = Convert.ToInt32(Console.ReadLine());

                int W = Convert.ToInt32(Console.ReadLine());

                if (V == -1 || W == -1) break;

                graph.AddEdge(V,W);

                
            }

            graph.ToString();

        }

        public static void CreateGraph(ref Digraph graph,string str)
        {
            graph = new Digraph(str);

            graph.ToString();


        }

        public static void TextDFS(Digraph graph)
        {
            DirectedDFS dfs = new DirectedDFS(graph,2);

            Console.Write("2点可达的点为: ");

            for(int i = 0;i<graph.VSize();i++)
            {
                if (dfs.Marked(i)) Console.Write(i+" ");
            }
        }

        public static void TextBFS(Digraph graph)
        {
            DirectedBFS bfs = new DirectedBFS(graph,2);
 
            for(int i = 0;i<graph.VSize();i++)
            {
                if (i == 2) continue;

                Console.Write("2到点"+i+"的最短路径为 ");

                Stack<int> path = bfs.PathTo(i);

                while(path!=null&&path.Count!=0)
                {
                    if (path.Count == 1)
                        Console.Write(path.Pop());
                    else
                        Console.Write(path.Pop()+" -> ");
                }

                Console.WriteLine();
            }
        }

        public static void TextDirectedCycle(Digraph graph)
        {
            DirectedCycle cycle = new DirectedCycle(graph);

            if(cycle.HasCycle())
            {
                int[] path = cycle.Cycle();

                Console.Write("有向图中存在一条回路：");

                foreach(var n in path)
                {
                    Console.Write(n+"  ");
                }
                
            }
        }

        public static void TextDepthFirstOrder(Digraph graph)
        {
            DepthFirstOrder order = new DepthFirstOrder(graph);

            var pre = order.Pre();

            var post = order.Post();

            var reversePost = order.ReversePost();

            Console.Write("\n有向图的深度优先前序为 ");
            foreach(var n in pre)
            {
                Console.Write(n+"  ");
            }

            Console.Write("\n有向图的深度优先后序为 ");
            foreach(var n in post)
            {
                Console.Write(n+"  ");
            }

            Console.Write("\n有向图的深度优先逆后序为 ");
            foreach(var n in reversePost)
            {
                Console.Write(n+" ");
            }
        }

        public static void TextToPoLogical(Digraph graph)
        {
            Topological logical = new Topological(graph);

            Console.Write("\n有向图的拓扑序列为 ");

            var order = logical.Order();
            if(order!=null)
            foreach(var n in order)
            {
                Console.Write(n+" ");
            }
        }

        public static void TextKosarajuSCC(Digraph graph)
        {
            KosarajuSCC scc = new KosarajuSCC(graph);

            scc.ToString();
        }
    }


    #region 保存有向图的数据结构
    /// <summary>
    /// 保存有向图的数据结构
    /// </summary>
    public class Digraph
    {
        private int E;//边的总数

        private int V;//顶点的总数

        private MyList []adj;

        /// <summary>
        /// 根据顶点的个数来进行有向图的构建
        /// </summary>
        /// <param name="V"></param>
        public Digraph(int V)
        {
            adj = new MyList[V];

            for(int i = 0;i<V;i++)
            {
                adj[i] = new MyList(V);
            }

            this.V = V;

            E = 0;
        }

        /// <summary>
        /// 根据用户输入的string类型有向图数据来构建一个有向图的数据结构
        /// </summary>
        /// <param name="In"></param>
        public Digraph(string In)
        {
            string[] stringGraph = In.Split('\n');

            V = Int32.Parse(stringGraph[0]);

            adj = new MyList[V];

            for (int i = 0; i < V; i++)
            {
                adj[i] = new MyList(V);
            }

            for(int i = 1;i<stringGraph.Length;i++)
            {
                string[] str = stringGraph[i].Split('-');

                int v = Int32.Parse(str[0]);

                int w = Int32.Parse(str[1]);

                AddEdge(v,w);
            }
        }

        /// <summary>
        /// 在顶点v和顶点w之间添加一个有向边
        /// </summary>
        /// <param name="v"></param>
        /// <param name="w"></param>
        public void AddEdge(int v,int w)
        {
            if (v < 0 || v >= V) return;

            if (w < 0 || w >= V) return;

            bool success = adj[v].Add(w);

            if (success) E++;//如果边添加成功的话就递增边数
        }

        /// <summary>
        /// 返回由顶点v指出的所有边链接的顶点
        /// </summary>
        /// <param name="v"></param>
        public List<Node> Adj(int v)
        {
            if (v < 0 || v >= V) return null;

            return adj[v].ToList();
        }

        /// <summary>
        /// 返回以该图和基础图的反向图
        /// </summary>
        /// <returns></returns>
        public Digraph Reverse()
        {
            Digraph reverseGraph = new Digraph(V);

            for (int i = 0; i < V;i++ )
            {
                List<Node> List = adj[i].ToList();

                foreach(var node in List)
                {
                    reverseGraph.AddEdge(node.value,i);
                }
            }

                return reverseGraph;
        }

        /// <summary>
        /// 以标准输出的方式对有向图进行输出
        /// </summary>
        public new void ToString()
        {
            for(int i = 0;i<V;i++)
            {
                List<Node> List = adj[i].ToList();

                foreach(var node in List)
                {
                    Console.WriteLine(i+"->"+node.value);
                }
                Console.WriteLine();
            }
        }

        /// <summary>
        /// 返回顶点数
        /// </summary>
        /// <returns></returns>
        public int VSize()
        {
            return V;
        }

        /// <summary>
        /// 返回边数
        /// </summary>
        /// <returns></returns>
        public int ESize()
        {
            return E;
        }

    }

    #endregion

    #region 自定义链接链表

    /// <summary>
    /// 节点类型的数据结构
    /// </summary>
    public class Node
    {
        public int value;

        public Node next;

        public Node(int value)
        {
            this.value = value;

            next = null;
        }
    }

    /// <summary>
    /// 邻接链表的数据类型
    /// </summary>
    public class MyList
    {
        public Node head;//头节点

        public int Size
        {
            get { return N; }
        } //返回邻接链表的节点个数

        private int N;//链表中数据的个数

        private bool[] Inside;//标记某个节点是否已经再邻接链表中

        private List<Node> List;//邻接链表的普通链表形态,可以考虑一下继承问题

        public MyList(int V)
        {
            head = new Node(-1);

            Inside = new bool[V];
        }

        /// <summary>
        /// 往链表中添加节点
        /// </summary>
        public bool Add(int V)
        {

            if (Inside[V]) return false;//表示该顶点已经存在于这个邻接表中了

            Node node = new Node(V);

            node.next = head.next;

            head.next = node;

            N++;

            return true;
        }

        /// <summary>
        /// 删除邻接链表中的某一个节点
        /// </summary>
        public void Remove(int V)
        {
            if (!Inside[V]) return;

            //顶点存在这个邻接链表中的时候执行一下方法

            Node target = head;

            while(target.next!=null)
            {
                if (target.next.value == V)
                {
                    Node node = target.next.next;

                    target.next = node;

                    N--;

                    break;
                }

                target = target.next;
            }
        }

        /// <summary>
        /// 判断某个节点是否在邻接表链表中
        /// </summary>
        /// <param name="V">表示顶点表示的int值</param>
        /// <returns></returns>
        public bool Contain(int V)
        {
            return Inside[V];
        }

        /// <summary>
        /// 以标准输出的形式展示邻接链表的数据
        /// </summary>
        public new void ToString()
        {
            Node node = head.next;

            while(node!=null)
            {
                Console.WriteLine(node.value);

                node = node.next;
            }
        }

        /// <summary>
        /// 将邻接链表转化为普通链表
        /// </summary>
        /// <returns></returns>
        public List<Node> ToList()
        {
            if (List != null) return List;

            List = new List<Node>();

            Node node = head.next;

            while(node!=null)
            {
                List.Add(node);

                node = node.next;
            }

            return List;
        }
    }
    #endregion


    #region 深度优先算法 
    /// <summary>
    /// 有向图的深度优先搜索
    /// </summary>
    public class DirectedDFS
    {
        private bool[] marked;

        private Digraph G;//保存当前路径信息的相关图

        private int markedNumber;//被标记的顶点数

        public DirectedDFS(Digraph G,int S)
        {
            this.G = G;

            marked = new bool[G.VSize()];

            dfs(S);
        }

        public DirectedDFS(Digraph G,int[]sources)
        {
            this.G = G;

            marked = new bool[G.VSize()];

            foreach (var n in sources)
                dfs(n);
        }

        /// <summary>
        /// 深度优先算法
        /// </summary>
        private void dfs(int v)
        {

            marked[v] = true;

            //markedNumber++;

            foreach(var n in  G.Adj(v))
            {
                if(!marked[n.value]) 
                    dfs(n.value);
                //if (markedNumber == marked.Length) return;
            }
        }
        
        /// <summary>
        /// 判断某个点是否可达
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public bool Marked(int v)
        {
            return marked[v];
        }
    }

    #endregion

    #region 广度优先算法
    /// <summary>
    /// 有向图的广度优先算法
    /// </summary>
    public class DirectedBFS
    {
        private bool[] marked;

        private int[] Path;

        private Digraph G;//保存当前路径信息的相关图

        private int S;//标定点

        public DirectedBFS(Digraph G,int S)
        {
            this.G = G;

            this.S = S;

            marked = new bool[G.VSize()];

            Path = new int[G.VSize()];

            for (int i = 0; i < Path.Length; i++)
                Path[i] = i;

                bfs(S);
        }

        /// <summary>
        /// 广度优先算法
        /// </summary>
        private void bfs(int v)
        {
            Queue<int> queue = new Queue<int>();

            marked[v] = true;

            queue.Enqueue(v);

            while(queue.Count!=0)
            {
                int w = queue.Dequeue();

                foreach(var n in G.Adj(w))
                {
                    if(!marked[n.value])
                    {
                        marked[n.value] = true;

                        Path[n.value] = w;

                        queue.Enqueue(n.value);
                    }
                }
            }
        }
        
        /// <summary>
        /// 判断某个点是否可达
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public bool Marked(int v)
        {
            return marked[v];
        }

        /// <summary>
        /// 找出点v到标定点的最短路径
        /// </summary>
        /// <returns></returns>
        public Stack<int> PathTo(int v)
        {
            if (!marked[v]) return null;

            Stack<int> path = new Stack<int>();

            path.Push(v);

            while(Path[v]!=S)
            {
                v = Path[v];

                path.Push(v);
            }

            path.Push(S);

            return path;
        }
    }
    #endregion

    #region 检测有向无环图
    /// <summary>
    /// 检测有向图是否存在回路的类
    /// </summary>
    public class DirectedCycle
    {
        private bool []marked;

        private int[] edgeTo;

        private bool[] onStack;

        private Stack<int> cycle;

        public DirectedCycle(Digraph G)
        {
            marked = new bool[G.VSize()];

            edgeTo = new int[G.VSize()];

            onStack = new bool[G.VSize()];

            for(int i = 0;i<G.VSize();i++)
            {
                if(!marked[i]) dfs(G,i);
            }
        }
        /// <summary>
        /// 深度优先搜索
        /// </summary>
        private void dfs(Digraph G,int v)
        {
            marked[v] = true;

            onStack[v] = true;
            
            foreach(var n in G.Adj(v))
            {
                if (HasCycle()) return;//当已经存在回路时直接返回
                else if(!marked[n.value])//如果是一个没有标记过的节点时走这一条路
                {
                    edgeTo[n.value] = v;

                    dfs(G,n.value);

                }else if(onStack[n.value])//如果是一条标记过的节点时就要检查它是否能构成回路
                {
                    cycle = new Stack<int>();

                    for(int i = v;i!=n.value;i = edgeTo[i])
                        cycle.Push(i);

                    cycle.Push(n.value);

                    cycle.Push(v);
                }

            }
            onStack[v] = false;
        }

        /// <summary>
        /// 判断图中是否存在回路
        /// </summary>
        /// <returns></returns>
        public bool HasCycle()
        {
            return cycle!=null;
        }

        /// <summary>
        /// 返回一条回路
        /// </summary>
        /// <returns></returns>
        public int[] Cycle()
        {
            if (!this.HasCycle()) return null;

            return cycle.ToArray();
        }
    }
    #endregion

    #region 深度优先次序
    /// <summary>
    /// 深度优先次序
    /// </summary>
    public class DepthFirstOrder
    {
        private bool[] marked;

        private Queue<int> pre;//前序

        private Queue<int> post;//后序

        private Stack<int> reversePost;//逆后序

        public DepthFirstOrder(Digraph G)
        {
            post = new Queue<int>();

            reversePost = new Stack<int>();

            pre = new Queue<int>();

            marked = new bool[G.VSize()];

            for (int i = 0; i < G.VSize(); i++)
                if (!marked[i]) dfs(G,i);
        }

        private void dfs(Digraph G,int v)
        {
            marked[v] = true;

            pre.Enqueue(v);

            foreach(var n in G.Adj(v))
            {
                if(!marked[n.value])
                {
                    dfs(G,n.value);
                }
            }

            post.Enqueue(v);

            reversePost.Push(v);
        }

        /// <summary>
        /// 获取前序序列
        /// </summary>
        /// <returns></returns>
        public Queue<int> Pre()
        {
            return pre;
        }
        /// <summary>
        /// 获取前序序列
        /// </summary>
        /// <returns></returns>
        public Queue<int> Post()
        {
            return post;
        }
        /// <summary>
        /// 获取逆后序序列
        /// </summary>
        /// <returns></returns>
        public Stack<int> ReversePost()
        {
            return reversePost;
        }
    }
    #endregion

    #region 拓扑排序
    /// <summary>
    /// 拓扑排序
    /// </summary>
    public class Topological
    {
        private Stack<int> order;//顶点顺序的拓扑排序
        public Topological(Digraph G)
        {
            //先判断有向图是否是回路
            DirectedCycle cycle = new DirectedCycle(G);

            if(!cycle.HasCycle())
            {
                DepthFirstOrder depthFirstOrder = new DepthFirstOrder(G);

                order = depthFirstOrder.ReversePost();
            }
        }

        /// <summary>
        /// 判断一个有向图是否DAG图
        /// </summary>
        /// <returns></returns>
        public bool isDAG()
        {
            return false;
        }

        /// <summary>
        /// 返回拓扑路径
        /// </summary>
        /// <returns></returns>
        public Stack<int> Order()
        {
            return order;
        }
    }
    #endregion

    #region 强连通分量
    public class KosarajuSCC
    {
        private bool[] marked;

        private int[] id;

        private int count;

        public KosarajuSCC(Digraph G)
        {
            marked = new bool[G.VSize()];

            id = new int[G.VSize()];

            DepthFirstOrder depthFirstOrder = new DepthFirstOrder(G.Reverse());

            Stack<int> reverseOrder = depthFirstOrder.ReversePost();

            foreach(var n in reverseOrder)
            {
                if (!marked[n]) 
                {
                    dfs(G,n);

                    count++;
                }
            }
        }

        private void dfs(Digraph G,int v)
        {
            marked[v] = true;

            id[v] = count;

            foreach(var node in G.Adj(v))
                if (!marked[node.value]) dfs(G,node.value);
            
        }

        /// <summary>
        /// 判断顶点v和顶点w是否强连通
        /// </summary>
        /// <returns></returns>
        public bool StrongConnected(int v,int w)
        {
            return id[v]==id[w];
        }

        /// <summary>
        /// 返回强连通分量的个数
        /// </summary>
        /// <returns></returns>
        public int Count()
        {
            return count;
        }

        /// <summary>
        /// 返回节点V所在的强连通分量ID号
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        public int ID(int v)
        {
            return id[v];
        }

        /// <summary>
        /// 输出所有的强连通分量
        /// </summary>
        public new void ToString()
        {
            for(int i = 0;i<count;i++)
            {
                Console.Write("有向图中第"+i+"个强连通分量为 ");
                for(int j = 0;j<id.Length;j++)
                {
                    if (id[j] == i) Console.Write(j+" ");
                }
                Console.WriteLine();
            }
        }
    }
    #endregion

    #region 顶点对可达性
    /// <summary>
    /// 顶点对可达性
    /// </summary>
    public class TransitiveClosure
    {
        private DirectedDFS[] all;

        public TransitiveClosure(Digraph G)
        {
            all = new DirectedDFS[G.VSize()];

            for(int i = 0;i<all.Length;i++)
            {
                all[i] = new DirectedDFS(G,i);
            }
        }

        /// <summary>
        /// 判断顶点v是否可达顶点w
        /// </summary>
        /// <param name="v"></param>
        /// <param name="w"></param>
        /// <returns></returns>
        public bool Reachable(int v,int w)
        {
            return all[v].Marked(w);
        }
    }
    #endregion
}
