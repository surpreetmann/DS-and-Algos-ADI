class MinimumPlatformsStation {
	public static void main(String args[]){
		String[] arrival={"10:00","10:15","10:30","10:40"};
		String[] departure={"10:20","10:25","15:00","10:55"};
		
		String[][] total=new String[8][2];
		for(int i=0;i<4;i++)
		{
			total[i][0]=arrival[i];
			total[i][1]="A";
		}
		for(int i=0;i<4;i++)
		{
			total[i+4][0]=departure[i];
			total[i+4][1]="D";
		}
		
		for(int i=0;i<7;i++){
			for(int j=0;j<7-i;j++){
				if(total[j][0].compareTo(total[j+1][0])>0){
					String temp=total[j][0];
					total[j][0]=total[j+1][0];
					total[j+1][0]=temp;
					
					temp=total[j][1];
					total[j][1]=total[j+1][1];
					total[j+1][1]=temp;
				}
			}
		}
		int counter=0;
		int max=0;
		for(int i=0;i<8;i++){
			if(total[i][1]=="A"){
				counter++;
				if(max<counter)
					max=counter;
			}
			else
				counter--;
		}
	
			System.out.println(max);
	}
}
