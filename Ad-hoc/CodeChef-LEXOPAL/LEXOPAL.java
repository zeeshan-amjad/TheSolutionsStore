    import java.util.*;
    import java.lang.*;
    import java.io.*;
     
    class Codechef
    {
    	public static void main (String[] args) throws java.lang.Exception
    	{
    		Scanner sc = new Scanner (System.in);
    		String s;
    		int t;
    		t = sc.nextInt();
    		while (t > 0) {
    		    s = sc.next();
    		    int l = s.length();
    		    char temp[] = s.toCharArray();
    		    boolean flag = true;
    		    for (int i = 0; i < l; ++i) {
    		        if (temp[i] != temp[l -i - 1] && temp[i] != '.' && temp[l - i - 1] != '.') {
    		            flag = false;
    		            break;
    		        }
    		        if (temp[i] == '.' && temp[l - i - 1] == '.')
    		            temp[i] = temp[l - i - 1] = 'a';
    		        else if (temp[i] == '.' && temp[l - i - 1] != '.')
    		            temp[i] = temp[l - i - 1];
    		        else
    		            temp[l - i - 1] = temp[i];
    		    }
    		    
    		    String ans = String.valueOf (temp);
    		    if (flag)
    		        System.out.println (ans);
    		    else
    		        System.out.println (-1);
    		    t--;
    		}
    	}
    } 
