import java.util.Scanner;
public class kk {
	static int a=0; 
	int s(int n){
		if(n>1){
			for(int i=2;i<=n;i++)
			if(n%i==0)	
				 s(n/i);
		    return 	a++;  }		      
		else 
			return 0;		
	}
	public static void main(String[] args) {
		int x;
		Scanner y=new Scanner(System.in);
		System.out.print("请输入一个大于1的正整数，否则输入其他数将产生错误:");
		x=y.nextInt();
		kk w=new kk();
		w.s(x);
		 System.out.println("输出分解式个数："+a);
	}

}