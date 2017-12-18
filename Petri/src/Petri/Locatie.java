package Petri;

public class Locatie {

	String tag;
	int jetoane;
	
	public Locatie(String tag, int jetoane)
	{
		this.tag = tag;
		this.jetoane = jetoane;
	}
	
	 public int getJetoane()
	    {
	        return jetoane; 
	    }
	    public void SetNumarJetoane(int capacitate)
	    {
	        jetoane = jetoane - capacitate; 
	    }
}
