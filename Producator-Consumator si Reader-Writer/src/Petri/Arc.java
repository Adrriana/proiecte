package Petri;

public class Arc {

	private int capacitate;
	private String directie; 
	Locatie locatie; 
	
	Arc(int capacitate, String directie, Locatie locatie)
	{
		this.capacitate = capacitate; 
		this.directie = directie;
		this.locatie = locatie;
	}
	
	public boolean isValid()
	{
		
		if(directie == "IN")
	       {
	            if(locatie.getJetoane()>=capacitate)
	                return true;
	       }
	       else 
	             return true;
		
		return false;
	      
    }
		
	
	
	public void update()
	{
		 if (directie == "IN")
		 {
			    locatie.SetNumarJetoane(locatie.getJetoane()-capacitate);
	        }
	        else
	        {
	            locatie.SetNumarJetoane(locatie.getJetoane()+capacitate);
	        }
	    }
	}


