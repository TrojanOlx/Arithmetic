using System;
using System.Collections.Generic;
using System.Linq;

namespace LengthOfLongestSubstringCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = LengthOfLongestSubstring2("bbbbb");
        }


        public static int LengthOfLongestSubstring(string s)
        {
            if (s.Length == 0) return 0;
            Queue<char> queue = new Queue<char>();
            int maxStr = 0;
            int left = 0;
            for (int i = 0; i < s.Length; i++)
            {
                while (queue.Contains(s[i]))
                {
                    queue.Dequeue();
                    left++;
                }
                maxStr = Math.Max(maxStr, i - left + 1);
                queue.Enqueue(s[i]);
            }

            return maxStr;
        }

        public static int LengthOfLongestSubstring1(string s)
        {
            int[] hash = new int[128];
            int ans = 0;
            for (int startIndex = 0, i = 0; i < s.Length; i++)
            {
                startIndex = Math.Max(hash[s[i]], startIndex);
                hash[s[i]] = i + 1;
                ans = Math.Max(ans, i - startIndex + 1);
            }
            return ans;
        }

        public static int LengthOfLongestSubstring2(string s)
        {
            int[] arr = new int[255];
            int left = 0;
            int temp = 0, max = 0;
            for (int right = 0; right < s.Length; right++)
            {
                if (arr[s[right]] == 0)
                {
                    arr[s[right]] = right + 1;
                    temp++;
                }
                else
                {
                    left = left > arr[s[right]] ? left : arr[s[right]];
                    arr[s[right]] = right + 1;
                    temp = right - left + 1;
                }
                max = max > temp ? max : temp;
            }
            return max;
        }
    }
}
