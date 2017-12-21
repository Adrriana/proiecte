package Petri;

import java.util.Scanner;

public class Main {

	public static void main(String[] args)
    {
        try
        {
            CoffePetriNet coffe=new CoffePetriNet(null, null); 
            ProducatorConsumator PC = new ProducatorConsumator(5,2,7);
            ReaderWriter RW = new ReaderWriter(5);
            Scanner scanner  = new Scanner(System.in); 
            String input;
            input = scanner .next();
            while (!input.equals("q"))
            {
                coffe.exec(input);
            	PC.exec(input);
            	RW.exec(input);
                System.out.println("");
                System.out.println("Introduceti optiunea: ");
                input = scanner .next();
            }
        } catch (Exception e)
        {
            System.err.println(e);
        }
    }
}