package MidleSquare;

import java.util.Random;



public class MidleSquare {

	public static void main(String[] args) {
		
		System.out.println("Final random number generated is " + randomNumberGeneratorMaster());
		
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
		
		double numberInTheMiddle = Double.parseDouble(numberInTheMiddleStr);
		
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
	
	public static double randomNumberGeneratorMaster(){
		double randomNumberFinal = 0.0;
		
		Random random = new Random();
		int randomNumber = (1000 + random.nextInt(9000));
		System.out.println("First random number generated " + randomNumber);
		
		long risenToTwoNumber = riseToThePowerOfTwo(randomNumber);
		int risenToTwoDigits = getNumberOfDigits(risenToTwoNumber);
		double numberInTheMiddle = getNumberInTheMiddle(risenToTwoDigits, risenToTwoNumber);
		
		randomNumberFinal = numberInTheMiddle / 10_000;
		
		return randomNumberFinal;
	}
	
}
