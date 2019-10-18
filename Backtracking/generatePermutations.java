public static String swapString(String a, int i, int j) {  
        char[] b =a.toCharArray();  
        char ch;  
        ch = b[i];  
        b[i] = b[j];  
        b[j] = ch;  
        return String.valueOf(b);  
    }  
public static void generatePermutation(String str, int start, int end)  
 {  
        
        if (start == end-1)  
            System.out.println(str);  
        else  
        {  
            for (int i = start; i < end; i++)  
            {  
                
                str = swapString(str,start,i);  
                 
                generatePermutation(str,start+1,end);  
                
                str = swapString(str,start,i);  
            }  
        }  
    }  