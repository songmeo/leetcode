import java.util.*;

public class Puzzle {
   private static HashSet<Character> all = null; //all characters
   private static HashSet<Character> not_zeros = null; //leading characters which shouldn't be zeros
   private String args[] = null;
   private int solutions = 0; //numbers of solutions
   private boolean printed = false;
   /**
    * Solve the word puzzle.
    *
    * @param args three words (addend1 addend2 sum)
    */
   public static void main(String[] args) {
      if(args.length != 3) {
         throw new IllegalArgumentException("There should be 3 arguments");
      }

      all = new HashSet<>();
      not_zeros = new HashSet<>();

      String addend1 = args[0];
      String addend2 = args[1];
      String sum = args[2];

      for (String s : args) {
         not_zeros.add(s.charAt(0));
         for (char c : s.toCharArray())
            all.add(c);
      }

      //must have at most 10 unique characters
      if (all.size() > 10) {
         throw new IllegalArgumentException("Too many characters");
      }

      //check if 2 addends are larger than sum
      if (Math.max(addend1.length(), addend2.length()) > sum.length()) {
         throw new IllegalArgumentException("elements couldn't be larger than sum");
      }

      HashMap<Character, Integer> solution = new HashMap<>();

      if (sum.length() > Math.max(addend1.length(), addend2.length())) {
         solution.put(sum.charAt(0), 1); // because even when addend1, addend2 are 99, the first num of sum is 1.
      }

      Puzzle p = new Puzzle();
      p.args = args;
      p.solutions = 0;
      p.solutions(solution, 0, false);
      System.out.println(p.solutions + " solutions");
   }

   public boolean check_solution(HashMap<Character, Integer> m) {
      long[] nums = new long[3];
      for(int j = 0; j < 3; j++) {
         for(int i = args[j].length() - 1; i >= 0; i--) {
            nums[j] += m.get(args[j].charAt(i))*(long) (Math.pow(10,args[j].length() - i - 1));
         }
      }
      for(Character c : not_zeros) {
         if(m.get(c) == 0) {
            return false;
         }
      }
      return nums[0] + nums[1] == nums[2];
   }

   public void solutions(HashMap<Character, Integer> m, int col, boolean carry) {
      if(m.size() == all.size()) {
         if(check_solution(m)) {
            solutions++;
            if(!printed) {
               print_solution(m);
               printed = true;
            }
         }
         return;
      }

      HashMap<Character, Integer> tmp = new HashMap<>(m); //to try new values without affecting found values

      //check how many values we have known
      char[] values = {0,0,0}; //values that are actually used to add
      int known = 0;
      for(int i = 0; i < 3; i++) {
         int index = args[i].length() - 1 - col;
         if(index >= 0) {
            values[i] = args[i].charAt(index);
         }
         if(m.containsKey(args[i].charAt(index))) {
            known |= 1 << i;
         }
      }
      boolean c = false;
      //if we know both addends
      if(known == 3) {
         //int sum  = m.get(args[0].charAt(col)) + m.get(args[1].charAt(col)); //then we could infer the sum
         int sum = tmp.get(values[0]) + tmp.get(values[1]);
         if(carry) { //if there is a carry from the other last position
            sum += 1;
         }
         if(sum >= 10) { //if sum is >= 10 then only stores the last digit and remembers carry
            sum -= 10;
            c = true;
         }
         if(tmp.containsValue(sum)) { //if the value already exists in the map then the solution is wrong
            return;
         }
         tmp.put(values[2], sum);
         solutions(tmp, col+1, c); //continue with the next column
         return;
      }
      //we know all arguments
      if(known == 7) {
         //int sum  = m.get(args[0].charAt(col)) + m.get(args[1].charAt(col)); //then we could infer the
         int sum = tmp.get(values[0]) + tmp.get(values[1]);
         if(carry) { //if there is a carry from the other last position
            sum += 1;
         }
         if(sum >= 10) { //if sum is >= 10 then only stores the last digit and remembers carry
            sum -= 10;
            c = true;
         }
         if(sum == tmp.get(values[2])) {
            solutions(tmp, col + 1, c);
         }
         return;
      }
      //if we know second addend and sum
      if(known == 6) {
         //int a1 = m.get(args[2].charAt(col)) - m.get(args[1].charAt(col));
         int a1 = tmp.get(values[2]) - tmp.get(values[1]);
         if(carry) {
            a1 -= 1;
         }
         if(a1 < 0) {
            a1 += 10;
            c = true;
         }
         if(tmp.containsValue(a1)) {
            return;
         }
         tmp.put(values[0], a1);
         solutions(tmp, col + 1, c);
         return;
      }

      //if we know first addend and sum
      if(known == 5) {
         //int a2 = m.get(args[2].charAt(col)) - m.get(args[0].charAt(col));
         int a2 = tmp.get(values[2]) - tmp.get(values[0]);
         if(carry) {
            a2 -= 1;
         }
         if(a2 < 0) {
            a2 += 10;
            c = true;
         }
         if(tmp.containsValue(a2)) {
            return;
         }
         tmp.put(values[1], a2);
         solutions(tmp, col + 1, c);
         return;
      }

      //if we know only addend1
      if(known == 1) {
         for(int i = 0; i < 10; i++) {
            if(tmp.containsValue(i)) {
               continue;
            }
            tmp.put(values[1], i);
            solutions(tmp, col, carry);
         }
         return;
      }

      //if we know only addend2, or sum, or none
      for(int i = 0; i < 10; i++) {
         if(tmp.containsValue(i)) {
            continue;
         }
         tmp.put(values[0], i);
         solutions(tmp, col, carry);
      }
   }
   public void print_solution(HashMap<Character, Integer> m) {
      System.out.println(args[0] + "+" + args[1] + "=" + args[2]);
      for(Character c : args[0].toCharArray()) {
         System.out.print(m.get(c));
      }
      System.out.print("+");
      for(Character c : args[1].toCharArray()) {
         System.out.print(m.get(c));
      }
      System.out.print("=");
      for(Character c : args[2].toCharArray()) {
         System.out.print(m.get(c));
      }
      System.out.println();
   }
}



