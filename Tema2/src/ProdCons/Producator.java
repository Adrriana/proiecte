package ProdCons;

import java.util.List;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Producator implements Runnable{
	List<Integer> queue = null;
	final int MAX_SIZE = 5;  //marimea maxima
	private int item = 0;
	private final Lock mutex = new ReentrantLock(true);
	
	Semaphore semFree;
	Semaphore semFull;
	

	public Producator(List<Integer> queue, Semaphore semFree, Semaphore semFull ) {   //constructor
		this.queue = queue;
		this.semFree = semFree;
		this.semFull = semFull;
	}
	@Override
public void run() {
		
		while(true) { //atat timp cat este adevarat am nevoie pentru a apela metoda de productie
			try {
			semFree.acquire();
				enqueue(item++); //produc
		} catch(InterruptedException exception) {
			
		} 
			semFree.release();
			
		}
		
	}
	
	public void enqueue(int item) throws InterruptedException{
		mutex.lock();
        queue.add(item);
        System.out.println("Produce produced element" + item);
        mutex.unlock();
}

}
