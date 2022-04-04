package ch04.com.dao;

public class GuGuDan {
	private int[] ans=new int[9];
	
	public int[] process(int n) {
		
		for(int i=0;i<9;i++) {
			ans[i]=n*(i+1);
		}
		return ans;
	}
	
}
