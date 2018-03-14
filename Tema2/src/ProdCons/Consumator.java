package ProdCons;

import java.util.List;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


public class Consumator implements Runnable {

	List<Integer> queue = null;
	private final Lock mutex = new ReentrantLock(true);
	
	Semaphore semFull;
	Semaphore semFree;
	
	public Consumator(List<Integer> queue, Semaphore semFull) {   //constructor
		this.queue = queue;
		this.semFull = semFull;
	}
	@Override
	public void run() {
		while(true) { //atat timp cat este adevarat am nevoie pentru a apela metoda de consum
			try {
				semFull.acquire();
				dequeue(); //consum
		} catch(InterruptedException exception) {
			
		}
			semFull.release();
	}
	}
	
	public void dequeue() throws InterruptedException{
		mutex.lock();
        Object item = null;
		queue.remove(item);
        System.out.println("Consumed the element");
        mutex.unlock();
		
}
}
