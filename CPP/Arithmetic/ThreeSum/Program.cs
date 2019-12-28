using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;

namespace ThreeSum
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }

        public IList<IList<int>> ThreeSum(int[] nums)
        {
            var results = new List<IList<int>>();

            if (nums == null || nums.Length < 3)
            {
                return results;
            }
            // 排序
            Array.Sort(nums);
            for (int i = 0; i < nums.Length - 2; i++)
            {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
                {
                    // 二分法 也可称为 夹逼查找
                    int left = i + 1, right = nums.Length - 1, sum = 0 - nums[i];
                    while (left < right)
                    {
                        //找到满足条件元素，添加到返回结果队列
                        if (nums[left] + nums[right] == sum)
                        {
                            results.Add(new List<int> { nums[i], nums[left], nums[right] });
                            //防止重复元素
                            while (left < right && nums[left] == nums[left + 1]) left++;
                            while (left < right && nums[right] == nums[right - 1]) right--;
                            left++; right--;
                        }
                        else if (nums[left] + nums[right] < sum) left++;
                        else right--;
                    }
                }
            }
            return results;

        }
    }
}
