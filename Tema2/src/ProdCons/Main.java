package ProdCons;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;

public class Main {
    public static void main(String[] args) {
    	List<Integer> queue = new ArrayList<Integer>();
    	
    	int N = 0;
		Semaphore semFree = new Semaphore(N);
    	Semaphore semFull = new Semaphore(0);
    	
    	Thread Producator = new Thread(new Producator(queue, null, semFull));
    	Thread Consumator = new Thread(new Consumator(queue, semFull), null);
    	
    	Producator.start();
    	Consumator.start();
    }
}