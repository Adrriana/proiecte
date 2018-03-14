package ProdCons;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Producator implements Runnable{

	List<Integer> queue = null;
	final int MAX_SIZE = 5;  
	private int i = 0;
	private final Lock mutex = new ReentrantLock(true);
	
	public Producator(List<Integer> queue) {   
		this.queue = queue;
	}
	
	public void run() {
		
		while(true) { 
			try {
				Thread.sleep(1000); 
			    produce(i++); 
		} catch(InterruptedException exception) {
			
		}	
		}
		
	}
	public void produce (int i) throws InterruptedException {
		mutex.lock();
		synchronized (queue) {
		while(queue.size() == MAX_SIZE) { 
			 System.out.println("Queue is Full ... waiting for the consumer to consume");
			 queue.wait();
		}
	}
		
		synchronized (queue) {
			System.out.println("Produce produced element" + i);
			queue.add(i); 
			mutex.unlock();
			queue.notify(); 
	}
	}
}

