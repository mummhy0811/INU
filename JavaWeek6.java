package week6;
import java.util.Scanner;
public class Fraction {
	int numerator; //분자 필드
	int denominator; //분모 필드
	public Fraction() { //분자 분모를 1로 지정하는 생성자
		numerator=1; denominator=1;
	}
	public Fraction(int d) { //분자는 1로 지정, 분모는 d로 지정하는 생성자
		numerator=1; denominator=d;
	}
	public Fraction(int n, int d) { //분자는 n, 분모는 d로 지정하는 생성자
		numerator=n; denominator=d;
	}
	public void addFraction(Fraction sec, Fraction ans) {
		ans.numerator=(numerator*sec.denominator)+(sec.numerator*denominator);
		ans.denominator=denominator*sec.denominator;
	}
	public void subFraction(Fraction sec, Fraction ans) {
		ans.numerator=(numerator*sec.denominator)-(sec.numerator*denominator);
		ans.denominator=denominator*sec.denominator;
	}	
	public void mulFraction(Fraction sec, Fraction ans) {
		ans.numerator=numerator*sec.numerator;
		ans.denominator=denominator*sec.denominator;
	}
	public void divFraction(Fraction sec, Fraction ans) {
		ans.numerator=numerator*sec.denominator;
		ans.denominator=denominator*sec.numerator;
	}
	public void devide() { //약분
		int n= numerator<denominator? numerator:denominator; //분모, 분자 중 더 작은 수
		int max=1;
		if (n<0) {
			n=-n;
		}
		for(int i=1;i<=n;i++) {
			if((numerator%i==0)&&(denominator%i==0)) 
				max=i;
		}
		numerator=numerator/max;
		denominator=denominator/max;
	}
	public void printFraction() { //출력메소드
		System.out.println(numerator+"/"+denominator);
	}
	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		System.out.println("분수1(분자 분모) 입력: ");
		int a=scanner.nextInt();
		int b=scanner.nextInt();
		System.out.println("분수2(분자 분모) 입력: ");
		int c=scanner.nextInt();
		int d=scanner.nextInt();
		Fraction frac_one=new Fraction(a, b);
		Fraction frac_two=new Fraction(c, d);
		Fraction ans=new Fraction();
		System.out.println("-----------------------------");
		frac_one.addFraction(frac_two, ans);
		ans.devide();
		System.out.print(a+"/"+b+"+"+c+"/"+d+"=");ans.printFraction();
		frac_one.subFraction(frac_two, ans);
		ans.devide();
		System.out.print(a+"/"+b+"-"+c+"/"+d+"=");ans.printFraction();
		frac_one.mulFraction(frac_two, ans);
		ans.devide();
		System.out.print(a+"/"+b+"*"+c+"/"+d+"=");ans.printFraction();
		frac_one.divFraction(frac_two, ans);
		ans.devide();
		System.out.print(a+"/"+b+"/"+c+"/"+d+"=");ans.printFraction();
		scanner.close();
	}

}
