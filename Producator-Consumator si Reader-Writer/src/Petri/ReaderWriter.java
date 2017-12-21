package Petri;

import java.util.ArrayList;
import java.util.List;

public class ReaderWriter extends PetriNet
{
    private int k;
    ReaderWriter(int valoarek)
    {
        Tranzitie tranzitie1,tranzitie2,tranzitie3,tranzitie4;
        Arc a1,a2,a3,a4,a5,a6,a7,a8;
        Locatie locatieS1,locatieS2,locatieS3;

        this.k=valoarek;
        List<Arc> arc;
        ArrayList<Tranzitie> transition = new ArrayList<Tranzitie>();

        locatieS1 =  new Locatie("Entitati",k);
        a8 = new Arc(1,"in",locatieS1);
        a4 = new Arc(k,"in",locatieS1);
        a5 = new Arc(1,"out",locatieS1);
        a1 = new Arc(k,"out",locatieS1);

        locatieS2 =  new Locatie("Writing",0);
        a2 = new Arc(1,"in",locatieS2);
        a3 = new Arc(1,"out",locatieS2);

        locatieS3 =  new Locatie("Reading",0);
        a6 = new Arc(1,"in",locatieS3);
        a7 = new Arc(1,"out",locatieS3);

        arc = new ArrayList<Arc>();
        arc.add(a1);
        arc.add(a2);
        tranzitie1 = new Tranzitie("SW",arc);

        arc = new ArrayList<Arc>();
        arc.add(a3);
        arc.add(a4);
        tranzitie2 = new Tranzitie("EW",arc);

        arc = new ArrayList<Arc>();
        arc.add(a5);
        arc.add(a6);
        tranzitie3 = new Tranzitie("SR",arc);

        arc = new ArrayList<Arc>();
        arc.add(a7);
        arc.add(a8);
        tranzitie4 = new Tranzitie("ER",arc);

        transition.add(tranzitie1);
        transition.add(tranzitie2);
        transition.add(tranzitie3);
        transition.add(tranzitie4);
    }

}