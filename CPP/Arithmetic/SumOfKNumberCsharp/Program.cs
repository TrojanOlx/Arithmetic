using System;
using System.Collections.Generic;
using System.Linq;

namespace SumOfKNumberCsharp
{
    class Program
    {

        static void Main(string[] args)
        {
            var nums = new List<float>() { 10, 10.2f, 20, 30, 40, 50, 60, 70, 80, 90, 100 };



            Console.WriteLine("===========test1==========");
            var test1 = new SumOfKNumber<float>(nums, 100.2f);

            var max1 = test1.GetListMax();

            var list1 = test1.GetNumList();

            Print(list1, max1);


            Console.WriteLine("===========test2==========");
            var test2 = new SumOfKNumber<float>(nums, 100.2f, true);

            var max2 = test2.GetListMax();

            var list2 = test2.GetNumList();

            Print(list2, max2);


        }


        static void Print<T>(IEnumerable<IEnumerable<T>> list, T max) where T : struct
        {
            foreach (var items in list)
            {

                var nums = items.ToList();
                Console.Write(max + " = ");
                for (int i = 0; i < nums.Count(); i++)
                {
                    if (i == items.Count() - 1)
                    {
                        Console.Write(nums[i]);
                    }
                    else
                    {
                        Console.Write(nums[i] + "+");
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
