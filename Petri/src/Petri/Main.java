package Petri;

import java.util.Scanner;

public class Main {

	public static void main(String[] args)
    {
        try
        {
            CoffePetriNet coffe=new CoffePetriNet(null, null); 
            Scanner scanner  = new Scanner(System.in); 
            String input;
            input = scanner .next();
            while (!input.equals("Q"))
            {
                coffe.exec(input);
                System.out.println("Introduceti optiunea: ");
                input = scanner .next();
            }
        } catch (Exception e)
        {
            System.err.println(e);
        }
    }
}