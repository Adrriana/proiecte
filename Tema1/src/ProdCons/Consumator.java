package ProdCons;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Consumator implements Runnable{

	List<Integer> queue = null;
	private final Lock mutex = new ReentrantLock(true);
	
	public Consumator(List<Integer> queue) {   //constructor
		this.queue = queue;
	}
	
	
	public void run() {
		
		while(true) { 
			try {
				Thread.sleep(100);
			    consume(); 
		} catch(InterruptedException exception) {
			
		}	
		}
		
	}
	
	public void consume() throws InterruptedException {
		mutex.lock();
		synchronized (queue){ 
		while(queue.isEmpty()) { 
			 System.out.println("Queue is empty ... waiting for the producer to produce the object");
			 queue.wait();
			}
		}
			  
		synchronized (queue){
			 System.out.println("Consumed the element" + queue.remove(0)); 
			 mutex.unlock();
			 queue.notify(); 
	}
	}
}
