using System;
using System.Globalization;
using System.Linq;

namespace ConvertCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Convert1("A", 1);
        }

        public static string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;

            string[] rows = new string[Math.Min(s.Length, numRows)];
            int curRow = 0;
            bool goingDown = false;
            foreach (var c in s)
            {
                rows[curRow] += c;
                if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
                curRow += goingDown ? 1 : -1;
            }

            return rows.Aggregate("", (current, row) => current + row);
        }

        public static string Convert1(string s, int numRows)
        {

            int temp = numRows * 2 - 2;
            string str = "";
            int n = s.Length;
            for (int i = 0; i < numRows; i++)
            {
                for (int j = 0; j + i < n; j += temp)
                {
                    str += s[j + i];
                    if (i != 0 && i != numRows - 1 && j + temp - i < n)
                    {
                        str += s[j + temp - i];
                    }
                }
            }

            return str;

        }
    }
}
