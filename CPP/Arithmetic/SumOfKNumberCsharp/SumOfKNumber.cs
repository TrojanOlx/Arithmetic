using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SumOfKNumberCsharp
{
    public class SumOfKNumber<T> where T : struct
    {
        private readonly List<decimal> _nums;
        private readonly decimal _sum;
        private readonly bool _lessThan;
        public List<List<decimal>> NumList;
        private readonly decimal[] _res;
        private int k = 0;
        private decimal _max = 0;
        /// <summary>
        /// 求最接近的那个值
        /// </summary>
        /// <param name="numEnums">数组</param>
        /// <param name="sum">和为多少</param>
        /// <param name="lessThan">是否小于这个和</param>
        public SumOfKNumber(IEnumerable<T> numEnums, T sum, bool lessThan = false)
        {
            _nums = numEnums.Select(s => (decimal)(dynamic)s).ToList();

            _sum = (decimal)(dynamic)sum;
            _lessThan = lessThan;
            _res = new Decimal[_nums.Count];
            NumList = new List<List<decimal>>();
        }

        /// <summary>
        /// 获取列表枚举
        /// </summary>
        /// <returns></returns>
        public IEnumerable<IEnumerable<T>> GetNumList()
        {
            Sum(_nums, _nums.Count, (decimal)(dynamic)GetListMax());
            return NumList.Select(s => s.Select(ss => (T)(dynamic)ss));
        }

        //获取最大值
        private void Sum(IReadOnlyList<decimal> numEnums, int n, decimal sum)
        {
            if (n <= 0) return;

            if (sum.Equals(0))
            {
                if (n < numEnums.Count && numEnums[n].Equals(_sum))
                {
                    //Console.WriteLine(_sum + " = " + numEnums[n]);
                    NumList.Add(new List<decimal>() { numEnums[n] });
                }
                return;
            }

            if (k > 0)
            {
                if (sum.Equals(numEnums[n - 1]))
                {
                    var list = new List<decimal>();
                    //Console.Write(_sum + " = ");
                    for (var i = k - 1; i >= 0; --i)
                    {
                        //Console.Write(_res[i] + "+");
                        list.Add(_res[i]);
                    }
                    list.Add(numEnums[n - 1]);
                    //Console.WriteLine(numEnums[n - 1]);
                    NumList.Add(list);
                }
            }

            _res[k++] = numEnums[n - 1];
            Sum(numEnums, n - 1, sum - numEnums[n - 1]);
            k--;
            // ReSharper disable once TailRecursiveCall
            Sum(numEnums, n - 1, sum);

        }


        /// <summary>
        /// 获取最大值
        /// </summary>
        /// <returns></returns>
        public T GetListMax()
        {
            if (_max != 0)
            {
                return (T)(dynamic)_max;
            }
            HashSet<decimal> hashSet = new HashSet<decimal>() { 0 };

            foreach (var num in _nums)
            {
                int count = hashSet.Count - 1;
                var list = hashSet.ToArray();
                for (int i = count; i >= 0; --i)
                {
                    hashSet.Add(list[i] + num);
                }
            }

            if (_lessThan)
            {
                // 小于等于 100
                var enumerable = hashSet.ToList().Where(w => w <= _sum);
                _max = enumerable.Max();
            }
            else
            {
                // 找最符合的那个数
                var enumerable = hashSet.ToList();
                enumerable.Sort();
                decimal flag = Decimal.MaxValue;
                foreach (var item in enumerable)
                {
                    var abs = Math.Abs(_sum - item);

                    if (abs < flag)
                    {
                        flag = abs;
                        _max = item;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return (T)(dynamic)_max;
        }
    }
}
