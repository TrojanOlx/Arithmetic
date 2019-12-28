using System;
using System.Collections.Generic;
using System.Linq;

namespace OneHundredCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new[] { 2, 3, 4, 5, 6, 7 };
            Node[] nodes = new Node[10 + 1];

            // 初始化
            for (int i = 0; i < nodes.Length; i++)
            {
                nodes[i]= new Node() { NumList = new HashSet<int>() };
                if (nums[0]==i)
                {
                    nodes[i].Sum = i;
                    nodes[i].NumList.Add(0);
                }
            }

            // [][1][][][][][][][][]

            for (int i = 1; i < nums.Length; i++)
            {
                for (var j = nodes.Length - 1; j >= 0; j--)
                {
                    int sum = nodes[j].Sum + nums[i];

                    if (nodes[j].Sum == 0)
                    {
                        nodes[sum].Sum = sum;
                        nodes[sum].NumList.Add(0);
                    }
                    else
                    {
                        if (sum <= nodes.Length - 1)
                        {
                            nodes[sum].Sum = sum;
                            

                            nodes[sum].NumList.Add(nums[i]);
                        }
                    }
                }


                // 第一次循环过后
                //[][1][2][3][][][][][][]
                //()(0)(0)(1)()()()()()()()

                // 第二次循环过后
                //[][1][2][3][4][5][6][][][]
                //()(0)(0)(1)(3)(2)(3)()()()()
                //()(0)(0)(0)(1)()()()()()()

                // ......
            }



            // 找出最接近的那个数
            int start = -1;
            for (int i = nodes.Length - 1; i >= 0; i--)
            {
                if (nodes[i].Sum > 0)
                {
                    start = nodes[i].Sum;
                    break;
                }
            }


            if (start != -1)
            {

                var node = nodes[start];
                Console.Write(node.Sum + "=");
                while (node.NumList.FirstOrDefault() != 0)
                {
                    Console.Write(node.NumList.FirstOrDefault() + "+");
                    node = nodes[node.Sum - node.NumList.FirstOrDefault()];
                }
                Console.WriteLine(node.Sum);
            }
        }

    }
}


class Node
{
    public int Sum { get; set; }
    public HashSet<int> NumList { get; set; }
}

