using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jumin_DLL
{
    public class Cal
    {
        public static int Year(string jumin)
        {
            int year = Convert.ToInt16(jumin.Substring(0, 2));
            int gubun = Convert.ToInt16(jumin.Substring(6, 1));

            if (gubun == 1 || gubun == 2) year = year + 1900;
            else if (gubun == 3 || gubun == 4) year = year + 2000;
            return year;
        }
        public static int Age(string jumin)
        {
            int year = Convert.ToInt16(jumin.Substring(0, 2));
            int time = Convert.ToInt16(DateTime.Now.ToString("yyyyMMddhhmmss").Substring(0, 4));
            return time - year;
        }
        public static string Sex(string jumin)
        {
            int gubun = Convert.ToInt16(jumin.Substring(6, 1));
            if (gubun == 1 || gubun == 3) return "남자";
            else return "여자";
        }
        public static int Month(string jumin)
        {
            return  Convert.ToInt16(jumin.Substring(2, 2));
        }
        public static int Day(string jumin)
        {
            return Convert.ToInt16(jumin.Substring(4, 2));
        }
    }
}
