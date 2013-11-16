import java.util.*;
import java.math.*;

class BISHOPS {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    while( in.hasNextLine())
    {
      BigInteger A = new BigInteger(in.nextLine());

      if( A.equals( new BigInteger("1")))
        System.out.println("1");
      else
        System.out.println( (A.multiply(new BigInteger("2"))).subtract(new BigInteger("2")));
    }
  }
}
