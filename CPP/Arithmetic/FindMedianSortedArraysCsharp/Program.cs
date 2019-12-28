using System;
using System.ComponentModel.Design;
using System.Linq;

namespace FindMedianSortedArraysCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var num = FindMedianSortedArrays3(new int[] { 3 }, new int[] { -2, -1 });
        }


        public static double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {

            nums1 = nums1.Concat(nums2).ToArray();

            Array.Sort(nums1);

            if (nums1.Length % 2 == 1)
            {
                return nums1[nums1.Length / 2];
            }
            return (nums1[nums1.Length / 2] + nums1[nums1.Length / 2 - 1]) / 2.0;
        }


        public static double FindMedianSortedArrays1(int[] nums1, int[] nums2)
        {
            int[] nums = new int[nums1.Length + nums2.Length];
            nums1.CopyTo(nums, 0);
            nums2.CopyTo(nums, nums1.Length);
            Array.Sort(nums);
            if (nums.Length % 2 == 1)
            {
                return nums[nums.Length / 2];
            }

            return (nums[nums.Length / 2] + nums[nums.Length / 2 - 1]) / 2.0;

        }



        public static double FindMedianSortedArrays2(int[] A, int[] B)
        {
            int m = A.Length;
            int n = B.Length;

            if (m > n) return FindMedianSortedArrays2(B, A); // 保证 m <= n

            int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
            while (iMin <= iMax)
            {
                int i = (iMin + iMax) / 2;
                int j = halfLen - i;

                // i 需要增大
                if (i < iMax && B[j - 1] > A[i]) iMin = i + 1;

                // i 需要减小
                else if (i > iMin && A[i - 1] > B[j]) iMax = i - 1;


                // 达到要求，并且将边界条件列出来单独考虑
                else
                {
                    int maxLeft;

                    // A 分成的leftA(空集) 和 rightA (A的全部)
                    // 所以 leftPart = leftA (空集) + leftB,
                    // 故 maxLeft = B[j-1];
                    if (i == 0) maxLeft = B[j - 1];

                    // B分成的leftB(空集) 和 rightB(B的全部)
                    // 所以leftPart = leftA + leftB(空集)，
                    // 故maxLeft = A[i-1];
                    else if (j == 0) maxLeft = A[i - 1];

                    // 排除上述两种情况正常比较
                    else maxLeft = Math.Max(A[i - 1], B[j - 1]);

                    // 奇数，中位数正好是maxLeft
                    if ((m + n) % 2 == 1) return maxLeft;

                    // 偶数
                    int minRight;

                    // A分成的leftA (A的全部) 和 rightA(空集)
                    // 所以 rightPart = rightA(空集)+rightB,
                    // 故minRight = B[j].
                    if (i == m) minRight = B[j];

                    // B分成的leftB(B的全部) 和 rightB(空集)
                    // 所以 rightPart = rightA + rightB(空集)，
                    // 故 minRight = A[i];
                    else if (j == n) minRight = A[i];

                    // 排除上述两种特殊情况，正常比较
                    else minRight = Math.Min(B[j], A[i]);

                    return (maxLeft + minRight) / 2.0;
                }
            }
            return 0.0;
        }


        public static double FindMedianSortedArrays3(int[] nums1, int[] nums2)
        {
            int m = nums1.Length, n = nums2.Length;

            if (m > n) return FindMedianSortedArrays3(nums2, nums1);

            int lMax1 = 0, lMax2 = 0, rMin1 = 0, rMin2 = 0, c1, c2, lo = 0, hi = 2 * m;
            while (lo <= hi)
            {
                c1 = (lo + hi) / 2;
                c2 = m + n - c1;

                lMax1 = (c1 == 0) ? int.MinValue : nums1[(c1 - 1) / 2];
                rMin1 = (c1 == 2 * m) ? int.MaxValue : nums1[c1 / 2];
                lMax2 = (c2 == 0) ? int.MinValue : nums2[(c2 - 1) / 2];
                rMin2 = (c2 == 2 * n) ? int.MaxValue : nums2[c2 / 2];

                if (lMax1 > rMin2) hi = c1 - 1;
                else if (lMax2 > rMin1) lo = c1 + 1;
                else break;
            }
            return (Math.Max(lMax1, lMax2) + Math.Min(rMin1, rMin2)) / 2.0;


        }
    }
}
