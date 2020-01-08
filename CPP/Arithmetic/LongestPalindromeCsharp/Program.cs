using System;
using System.Text;

namespace LongestPalindromeCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            //var str = LongestPalindrome("ccc");

            var s = Algorithm("cbcbccde");
        }


        public static string LongestPalindrome(string s)
        {
            int start = 0;
            int end = 0;

            int max = 0;
            for (int i = 0; i < s.Length; i++)
            {
                int l1 = CenterLen(s, i, i);
                int l2 = CenterLen(s, i, i + 1);
                int len = Math.Max(l1, l2);
                if (len > max)
                {
                    max = len;
                    start = i - (len - 1) / 2;
                }


            }

            return s.Substring(start, max);
        }


        private static int CenterLen(string s, int left, int right)
        {
            while (0 <= left && right < s.Length && s[left] == s[right])
            {
                left--;
                right++;
            }

            return right - left - 1;
        }


        /// <summary>
        /// 马拉车夫 字符串处理
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static string PreProcess(string s)
        {
            int n = s.Length;
            if (n == 0) return "^$";
            StringBuilder sb = new StringBuilder("^");

            foreach (var t in s)
            {
                sb.Append($"#{t}");
            }

            sb.Append("#$");
            return sb.ToString();
        }

        public static string Algorithm(string s)
        {
            string T = PreProcess(s);
            int n = T.Length;
            int[] P = new int[n];
            int C = 0, R = 0;
            for (int i = 1; i < n - 1; i++)
            {
                int iMirror = 2 * C - i;
                if (R > i)
                {
                    P[i] = Math.Min(R - i, P[iMirror]);// 防止超出 R
                }
                else
                {
                    P[i] = 0;// 等于 R 的情况
                }

                // 碰到之前讲的三种情况时候，需要利用中心扩展法
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                {
                    P[i]++;
                }

                // 判断是否需要更新 R
                if (i + P[i] > R)
                {
                    C = i;
                    R = i + P[i];
                }

            }

            // 找出 P 的最大值
            int maxLen = 0;
            int centerIndex = 0;
            for (int i = 1; i < n - 1; i++)
            {
                if (P[i] > maxLen)
                {
                    maxLen = P[i];
                    centerIndex = i;
                }
            }
            int start = (centerIndex - maxLen) / 2; //最开始讲的求原字符串下标
            return s.Substring(start, start + maxLen);
        }

    }
}
