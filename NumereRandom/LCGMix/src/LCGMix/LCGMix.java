package LCGMix;

import java.util.Scanner;

public class LCGMix {
	static long count = 1L;
	
	public static void main(String[] args) {
	
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the multiplier - a");
		int multiplier = scanner.nextInt();
		System.out.println("Enter the increment - c");
		int increment = scanner.nextInt();
		System.out.println("Enter the modulus - m");
		int modulus = scanner.nextInt();
		System.out.println("Enter the seed - x0");
		int seed = scanner.nextInt();
		scanner.close();
		
	    constructEquation( seed, multiplier, increment, modulus);		
	}

	private static void constructEquation( int seed, int multiplier, int increment, int modulus) {
		
		int eqResult = (multiplier*seed + increment) % modulus;
		System.out.println("Random number is" + eqResult);
		
		count++;
		
		if(count > 5_000L){
			return;
		} else {
			 constructEquation( eqResult, multiplier, increment, modulus);
		}	
	}
}
