package Petri;

import java.util.List;
import java.util.ArrayList;

public class Tranzitie {

	public String tag;
	public List<Arc> arc = new ArrayList<Arc>();

	public Tranzitie(String tag, List<Arc> arc)
	{
		this.tag = tag;
		this.arc = arc;
	}
	
	 public String GetTag() {
	        return this.tag;
	    }
	 
	public boolean  isValid()
	{
		for (int i = 0; i < arc.size(); i++) {
            if (!arc.get(i).isValid())  //verific daca arcele nu sunt valide
                return false;
        }
        return true;
	    }
		
	
	public void update()
	{
		for (int i = 0; i < arc.size(); i++) {
			arc.get(i).update(); //daca e bun arcul
	}
}
	
}