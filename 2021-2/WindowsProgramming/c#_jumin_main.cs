using System;
using System.Collections.Generic;
using Jumin_DLL;

namespace ch7_연습
{
    class Jumin
    {
        static void Main(string[] args)
        {
            string jumin = "";
            Console.Write("주민번호 13자리를 입력하세요( '-' 제외) : ");
            jumin = Console.ReadLine();
            Console.WriteLine("년도는: {0}", Jumin_DLL.Cal.Year(jumin));
            Console.WriteLine("월은: {0}", Jumin_DLL.Cal.Month(jumin));
            Console.WriteLine("일은: {0}", Jumin_DLL.Cal.Day(jumin));
            Console.WriteLine("올해 나이는: {0}", Jumin_DLL.Cal.Age(jumin));
            Console.WriteLine("성별은: {0}", Jumin_DLL.Cal.Sex(jumin));
        }
    }
}
