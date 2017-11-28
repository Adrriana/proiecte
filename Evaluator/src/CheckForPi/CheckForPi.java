package CheckForPi;

import java.util.Random;
import java.util.Scanner;


public class CheckForPi {

	public static void main(String[] args) {
		int numberInsideCircle = 0;
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the multiplier - a");
		int multiplier = scanner.nextInt();
		System.out.println("Enter the increment - c");
		int increment = scanner.nextInt();
		System.out.println("Enter the modulus - m");
		int modulus = scanner.nextInt();
		scanner.close();
		
		for(int i = 0; i < 10_000 ; i++){
			//multiplier, increment, modulus
			double x = randomNumberGeneratorMidSquare();
			double y = randomNumberGeneratorMidSquare();
			if(x*x + y*y <= 1){
				numberInsideCircle++;
			}
		}
		System.out.println((double)numberInsideCircle/2500);
	}
	
	

	public static void constructEquationMix( int multiplier, int increment, long modulus) {
		Random random = new Random();
		int  seed = random.nextInt(50) + 1;
	
		long eqResult = (multiplier*seed + increment) % modulus;
		double result = (double)eqResult / modulus;
	
		System.out.println("Random number is" + result);
		
	}

	public static double randomNumberGeneratorMidSquare(){
		double randomNumberFinal = 0.0;
	    Random random = new Random();
	    int seed = random.nextInt();
		long risenToTwoNumber = riseToThePowerOfTwo(seed);
		int risenToTwoDigits = getNumberOfDigits(risenToTwoNumber);
		double numberInTheMiddle = getNumberInTheMiddle(risenToTwoDigits, risenToTwoNumber);
	
		randomNumberFinal = numberInTheMiddle / 10_000;
	
		return randomNumberFinal;
	}

	public static double getNumberInTheMiddle(int risenToTwoDigits, long risenToTwoNumber) {
		String numberInTheMiddleStr = "";
	
		int middlePosition = (risenToTwoDigits / 2) - 1;
	
		String risenToTwoNumberStr = Long.toString(risenToTwoNumber);
	
		for(int i = -1; i < 3; i++){
			char firstMiddleDigit = risenToTwoNumberStr.charAt(middlePosition + i);
			String firstMiddleDigitStr = Character.toString(firstMiddleDigit);
			numberInTheMiddleStr += firstMiddleDigitStr;
		}
	
		System.out.println("Middle number is " + numberInTheMiddleStr);
	
		double numberInTheMiddle = Integer.parseInt(numberInTheMiddleStr);
	
		return numberInTheMiddle;
	}
	
	public static long riseToThePowerOfTwo(long randomNumber) {
		randomNumber *= randomNumber;
		System.out.println("Number to the power of two is " + randomNumber);
		return randomNumber;
	}

	public static int getNumberOfDigits(long randomNumber){
		int numberOfDigits = 0;
		long temporary = 1; 
	
		while(temporary <= randomNumber){
			numberOfDigits++;
			temporary *= 10;	
		}
	
		System.out.println("Number of digits of the number to the power of two is " + numberOfDigits);

		return numberOfDigits;
	}
}
