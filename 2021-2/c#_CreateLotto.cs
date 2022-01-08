using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ch4_배열
{
    class 로또번호생성기
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            Console.WriteLine("로또번호 생성기");
            for (int kkk = 0; kkk < 20; kkk++)
            {
                //초기화
                int resultNum = 0;
                int n = 0;
                int[] lotto = new int[] { 0, 0, 0, 0, 0, 0 }; 
                while (true)//번호 무한 생성
                {
                    if (lotto[5] != 0) break; //만약 번호 6개를 다 뽑았으면
                    resultNum = rand.Next(1, 46);
                    for (int i = 0; i < 6; i++)
                    {
                        if (lotto[i] == resultNum) { break; } //같은 번호가 있으면
                        if (i == 5) //끝까지 검사를 완료했을 때
                        {
                            lotto[n] = resultNum;
                            n++;
                        }
                    }
                }
                for (int i = 0; i < 6; i++) Console.Write("{0}\t", lotto[i]);//번호 출력
                Console.WriteLine();
            }
        }
    }
}
