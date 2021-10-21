using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//로또 번호 자동 생성기로서 한 조에 6개의 숫자를 랜덤하게 생성하여 중복 된 것이 있으면 중복 제거 후에 오름차순으로 정렬하여 출력하시오.
//단 5번을 반복하여 출력하며,  중복제거전의 데이터(정렬하기 전)와 중복 제거 후의 오름차순으로 정렬된 데이터를 출력한다.

namespace mhy506
{
    class 문제2
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            for(int test = 0; test < 5; test++)
            {
                //초기화
                int[] lotto = new int[] { 0, 0, 0, 0, 0, 0 };
                int[] array = new int[46];//중복 제거를 위한 배열

                Console.WriteLine("중복 제거 전 랜덤 값");
                int resultNum;
                int n=0;
                while (true)//번호 무한 생성
                {
                    if (lotto[5] != 0) break; //만약 번호 6개를 다 뽑았으면
                    resultNum = rand.Next(1, 46);
                    Console.Write("{0}\t", resultNum);
                    array[resultNum] = 1;
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

                for (int i = 0; i < 5; i++)
                {
                    for(int j = 0; j < 5; j++)
                    {
                        if (lotto[j] > lotto[j + 1])
                        {
                            int tmp = lotto[j];
                            lotto[j] = lotto[j + 1];
                            lotto[j + 1] = tmp;
                        }
                    }
                }
                Console.WriteLine("\n중복 제거 후 오름차순으로 정렬");
                for (int i = 0; i < 46; i++)
                {
                    if (array[i] == 1)
                    {
                        Console.Write("{0}\t", i);
                    }
                }
                Console.WriteLine("\n");
            }
        }
    }
}
