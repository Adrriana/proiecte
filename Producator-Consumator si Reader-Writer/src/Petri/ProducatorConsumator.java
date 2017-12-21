package Petri;

import java.util.ArrayList;
import java.util.List;

public class ProducatorConsumator extends PetriNet
{
    int m,n,k;
    ProducatorConsumator(int valoarem, int valoaren, int valoarek)
    {
    	  this.m=valoarem;
          this.n=valoaren;
          this.k=valoarek;
          
        Tranzitie tranzitie1,tranzitie2,tranzitie3,tranzitie4;
        Arc a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14 = null,a15,a16 = null;
        Locatie locatie1,locatie2,locatie3,locatie4,locatie5,locatie6,locatie7;

        List<Arc> arc;
        ArrayList<Tranzitie> transition = new ArrayList<Tranzitie>();

        locatie1 =  new Locatie("Producatori",n);
        a4 = new Arc(1,"in",locatie1);
        a1 = new Arc(1,"out",locatie1);

        locatie2 =  new Locatie("Consumatori",m);
        a9 = new Arc(1,"in",locatie2);
        a12 = new Arc(1,"out",locatie2);

        locatie3 =  new Locatie("Elemente gata pentru scriere",0);
        a2 = new Arc(1,"in",locatie3);
        a3 = new Arc(1,"out",locatie3);

        locatie4 =  new Locatie("Elementele sunt pregatite pentru citire",0);
        a11 = new Arc(1,"in",locatie4);
        a10 = new Arc(1,"out",locatie4);

        locatie5 =  new Locatie("Free spots",k);
        a14 = new Arc(1,"in",locatie5);
        a5 = new Arc(1,"out",locatie5);

        locatie6 =  new Locatie("Mutex",1);
        a16 = new Arc(1,"in",locatie6);
        a8 = new Arc(1,"in",locatie6);
        a7 = new Arc(1,"out",locatie6);
        a15 = new Arc(1,"out",locatie6);

        locatie7 =  new Locatie("Full spots",0);
        a6 = new Arc(1,"in",locatie7);
        a13 = new Arc(1,"out",locatie7);

        arc = new ArrayList<Arc>();
        arc.add(a1);
        arc.add(a2);
        tranzitie1 = new Tranzitie("Produce",arc);

        arc = new ArrayList<Arc>();
        arc.add(a10);
        arc.add(a9);
        tranzitie2 = new Tranzitie("Consuma",arc);

        arc = new ArrayList<Arc>();
        arc.add(a3);
        arc.add(a5);
        arc.add(a7);
        arc.add(a4);
        arc.add(a6);
        arc.add(a8);
        tranzitie3 = new Tranzitie("PUSH",arc);

        arc = new ArrayList<Arc>();
        arc.add(a12);
        arc.add(a13);
        arc.add(a15);
        arc.add(a11);
        arc.add(a14);
        arc.add(a16);
        tranzitie4 = new Tranzitie("POP",arc);

        transition.add(tranzitie1);
        transition.add(tranzitie2);
        transition.add(tranzitie3);
        transition.add(tranzitie4);

    }
}