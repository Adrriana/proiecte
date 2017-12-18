package Petri;

import java.util.List;
import java.util.ArrayList;

public class PetriNet {

	 List<Tranzitie> transitionList = new ArrayList<>();
	    List<Tranzitie> currentTransitions = new ArrayList<>();
	    public void exec(String actiune){
	        Tranzitie transition;
	        for(int i=0; i < transitionList.size(); i++){
	            transition = transitionList.get(i);
	            if(transition.tag == actiune && transition.isValid()){
	               currentTransitions.add(transition);
	            }
	        }
	        
	        for(int i=0; i < currentTransitions.size(); i++){
	        	currentTransitions.get(i).update();
	        }
	    }
}
