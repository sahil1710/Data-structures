import java.util.*;

public class Stacks {

    public static void main(String[] args){
        String s = "HELLO";
        Stack<Character> stack = new Stack<Character>();
        int i,n;
        n = s.length();
        for (i=0;i<n;i++){
            stack.push(s.charAt(i));
        }
        s = "";
        for(i=0;i<n;i++){
            s = s + stack.peek();
            stack.pop();
        }
        System.out.println(s);
    }
}

// output : OLLEH
