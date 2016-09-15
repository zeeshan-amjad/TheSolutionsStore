    import java.util.*;
    import java.lang.*;
    import java.io.*;
     
    class Codechef
    {
    	public static void main (String[] args) throws java.lang.Exception
    	{
    		Scanner sc = new Scanner (System.in);
    		int t, points[] = {0, 0, 0, 0, 1, 2, 4};
    		t = sc.nextInt();
    		while (t > 0) {
    		    int n, max = -1, ans = 1;
    		    n = sc.nextInt();
    		    boolean tie = false;
    		    
    		    for (int i = 1; i <= n; ++i) {
    		        int c = sc.nextInt();
    		        int cookies[] = new int[7];
    		        for (int j = 0; j < c; ++j) {
    		            int p = sc.nextInt();
    		            cookies[p] += 1;
    		        }
    		        Arrays.sort (cookies);
    		        int score = c + cookies[1] * 4 + (cookies[2] - cookies[1]) * 2 + cookies[3] - cookies[2]; 
    		        if (score > max) {
    		            max = score;
    		            ans = i;
    		            tie = false;
    		        }
    		        else if (score == max) 
    		            tie = true;
    		        
    		    }
    		    
    		    if (tie)
    		        System.out.println ("tie");
    		    else if (ans == 1)
    		        System.out.println ("chef");
    		    else
    		        System.out.println (ans);
    		    
    		    t--;
    		}
    	}
    } 
