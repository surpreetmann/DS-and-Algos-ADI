import java.util.Arrays;
import java.util.LinkedList;

class Interval implements Comparable<Interval>{
	public char id;
	public int start;
	public int end;
	public Interval(){
		
	}
	public Interval(char a,int b,int c){
		id=a;
		start=b;
		end=c;
	}
	
	public int compareTo(Interval j){
		if(end>j.end)
			return 1;
		else if(end==j.end)
			return 0;
		else
			return -1;
	}
}

class InterviewScheduling{
	
	
	public static void findIntervalSequence(Interval arr[],int n){

		Arrays.sort(arr);

		int i=arr[0].end;
		LinkedList<Interval>  res=new LinkedList<>();
		res.add(arr[0]);
		for(int j=1;j<n;j++){
			if(arr[j].start>=i){
				res.add(arr[j]);
				i=arr[j].end;
				
			}
		}
		for(Interval k : res)
			System.out.println(k.id);
	}
	
	public static void main(String args[]){
		Interval arr[]=new Interval[5];
		arr[0]=new Interval('A',0,6);
		arr[1]=new Interval('B',1,4);
		arr[2]=new Interval('C',3,5);
		arr[3]=new Interval('D',3,8);
		arr[4]=new Interval('E',4,7);
		findIntervalSequence(arr,5);
	}
}