package ProdCons;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
    	List<Integer> queue = new ArrayList<Integer>();
    	
    	Thread Producator = new Thread(new Producator(queue));
    	Thread Consumator = new Thread(new Consumator(queue));
    	
    	Producator.start();
    	Consumator.start();
    }
}