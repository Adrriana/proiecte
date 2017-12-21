package Petri;

import java.util.ArrayList;
//import java.util.HashMap;
import java.util.List;

public class CoffePetriNet extends PetriNet
{
   public CoffePetriNet(List<Tranzitie> transition, Arc arc) { 
		super();
		// TODO Auto-generated constructor stub
	}

public void CoffePetriNet(List<Arc>arc,ArrayList<Tranzitie>transition)
   {
       Tranzitie tranzitie1,tranzitie2,tranzitie3,tranzitie4; 
       Arc a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
       Locatie locatieS0,locatieS1,locatieS2,locatieS3;
      
       locatieS0=new Locatie("0",1); //tag si jetoane
       a1=new Arc(1,"out",locatieS0); //creez arcul cu capacitatea, directia si locatie
       a2=new Arc(1,"out",locatieS0);  
       a8=new Arc(1,"out",locatieS0);

       locatieS1=new Locatie("5",0);
       a2=new Arc(1,"in",locatieS1);
       a3=new Arc(1,"out",locatieS1);
       a4=new Arc(1,"out",locatieS1);
       a9=new Arc(1,"out",locatieS1);
       a10=new Arc(1,"out",locatieS1);

       locatieS2=new Locatie("C10",0);
       a4=new Arc(1,"in",locatieS2);
       a5=new Arc(1,"out",locatieS2);
       a6=new Arc(1,"out",locatieS2);

       locatieS3=new Locatie("C15",0);
       a6=new Arc(1,"in",locatieS3);
       a7=new Arc(1,"in",locatieS3);
       a10=new Arc(1,"in",locatieS3);

       arc=new ArrayList<Arc>(); 
       arc.add(a1); 
       arc.add(a2);
       tranzitie1=new Tranzitie("tranzitie1",arc); //arcul meu se duce in tranzitie1

       arc=new ArrayList<Arc>();
       arc.add(a3);
       arc.add(a4);
       tranzitie2=new Tranzitie("tranzitie2",arc);

       arc=new ArrayList<Arc>();
       arc.add(a5);
       arc.add(a6);
       tranzitie3=new Tranzitie("tranzitie3",arc);

       arc=new ArrayList<Arc>();
       arc.add(a7);
       arc.add(a8);
       tranzitie4=new Tranzitie("tranzitie4",arc);

       transition.add(tranzitie1); 
       transition.add(tranzitie2);
       transition.add(tranzitie3);
       transition.add(tranzitie4);


   }
}
