import java.util.*;
import java.math.*;

class JULKA {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    while( in.hasNextLine())
    {
      BigInteger A = new BigInteger(in.nextLine());
      BigInteger B = new BigInteger(in.nextLine());

      System.out.println( (A.add(B)).divide(new BigInteger("2")));
      System.out.println( (A.subtract(B)).divide(new BigInteger("2")));
    }
  }
}
