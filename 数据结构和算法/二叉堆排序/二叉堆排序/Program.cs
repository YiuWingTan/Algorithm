using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二叉堆排序
{
    class Program
    {
        static void Main(string[] args)
        {
            MaxPQ<int> PQ = new MaxPQ<int>();
            PQ.compare = (a, b) => (a < b);
            int data = 0;
            while (data != -1)
            {
                data = Convert.ToInt32(Console.ReadLine());
                PQ.insert(data);
            }

            if (!PQ.isEmpty())
            {
                PQ.delMax();
                PQ.Show();
            }
           
             Console.Read();
        }
    }

    public class MaxPQ<T>
    {
        private int size;
        //永远指着最后空出来的位置
        private T[] pq;
        private Func<T, T, bool> _compare;

        public Func<T, T, bool> compare
        {
            get { return _compare; }
            set { _compare = value; }
        }


        public MaxPQ()
        {
            size = 0;
            pq = new T[21];
        }

        public MaxPQ(int length)
        {
            size = 0;
            pq = new T[length+1];
        }

        public MaxPQ(T[] a)
        {
            size = 0;
            pq = new T[a.Length+1];
            for(int i = 1;i<=a.Length;i++)
            {
                pq[i] = a[i];
                size++;
                Swim(i);   
            }
        }

        public void insert(T key)
        {
            size++;
            if(size>pq.Length)
            {
                T[]a = new T[pq.Length*2];
                for(int i = 1;i<=pq.Length;i++)
                {
                    a[i] = pq[i];
                }
                pq = a;
            }
            pq[size] = key;
            Swim(size);
        }

         public T Max()
        {
            return pq[1];
           
        }
        //返回最大元素

        public T delMax()
        {
            T max = pq[1];
            pq[1] = pq[size];
            size--;
            Sink(1);
            return max;
        }
        //删除并返回最大元素

        public void Show()
        {
            Console.WriteLine("二叉堆中的数据为：");
            for(int i =1;i<=size;i++)
            {
                Console.WriteLine(pq[i]);
            }
        }

        public bool isEmpty()
        {
            return size <= 0;
        }

        public int Size()
        {
            return size;
        }

        private bool less(int i, int j)
        {
            return compare(pq[i],pq[j]);
        }

        private void exch(int i,int j)
        {
            T middle = pq[i];
            pq[i] = pq[j];
            pq[j] = middle;
        }

        private void Swim(int k)
        {
            while(k>1&&less(k/2,k))
            {
                exch(k,k/2);
                k = k/2;
            }
        }
        //使二叉堆中的数据从下往上进行平稳转换


        private void Sink(int k)
        {
            while(k*2<=size)
            {
                int j = 2 * k;
                if (j<size&&less(j, j + 1)) j++;
                if (!less(k, j)) break;
                exch(k,j);
                k = j;
            }
        }
        //使二叉堆中的数据从上往下进行平稳转换


        
    }
}
