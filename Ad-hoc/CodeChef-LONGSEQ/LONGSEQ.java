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
    	    int l = s.length(), count = 0;
    	    for (char c : s.toCharArray())
    		      if (c == '0')
    		          count += 1;
    		      String ans = "No";
    		      if (count == 1 || count == l - 1)
    		          ans = "Yes";
    		      System.out.println (ans);
    		      t--;
    	}
  }
} 
