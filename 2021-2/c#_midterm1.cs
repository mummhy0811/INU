using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//전기요금 출력. 조건:반드시 private한 필드 사용, 속성 7단계로 짤 것.

namespace mhy506
{
    public class elec
    {
        private int _Kwh; //전력 사용량
        private double _tax; //전기요금
        
        public int Kwh
        {
            get { return _Kwh; }
            set { _Kwh = value; }
        }
        public double Tax
        {
            get {return Calc(_Kwh); }
        }
        private double Calc(int _Kwh) //요금 계산
        {
            if(_Kwh <= 100)
            {
                _tax = 410 + 60.7 * _Kwh;
            }
            else if (_Kwh <= 200)
            {
                _tax = 910 + 60.7 * 100 + 125.9 * (_Kwh - 100);
            }
            else if (_Kwh <= 300)
            {
                _tax = 1600 + 60.7 * 100 + 125.9 * 100 + 187.9*(_Kwh - 200);
            }
            else if (_Kwh <= 400)
            {
                _tax = 3850 + 60.7 * 100 + 125.9 *100 + 187.9*100 + 280.6*(_Kwh - 300);
            }
            else if (_Kwh <= 500)
            {
                _tax = 7300 + 60.7 * 100 + 125.9 * 100 + 187.9 * 100 + 280.6 * 100+417.7*(_Kwh - 400);
            }
            else
            {
                _tax=12940+ 60.7 * 100 + 125.9 * 100 + 187.9 * 100 + 280.6 * 100 + 417.7 *100+709.5*(_Kwh - 500);
            }
            return _tax;
        }
        
    }
    class 문제1
    {
        static void Main(string[] args)
        {
            Console.Write("전기 사용량 입력 단위(kwh) : ");
            int use = Convert.ToInt32(Console.ReadLine());
            elec user1 = new elec();
            user1.Kwh = use;
            Print(user1.Kwh, user1.Tax); //프린트 하는 함수

        }
        private static void Print(int use, double money)
        {
            Console.WriteLine("\n===============================");
            Console.WriteLine("사용 전력량\t전기요금");
            Console.WriteLine("{0} Kw/h\t{1} 원", use, money);
        }
    }
}
