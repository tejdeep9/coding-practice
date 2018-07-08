
//***************************** USING SETTERS  BEAN MODEL ****************************************
public class LunchOrderBean 
{
	private String bread;
	private String condiments;
	private string dressing;
	private string meat;
	
	public String getBread(){
		return bread;
	}
	
	public string getCondiments(){
		return condiments;
	}
	
	public string getDressing(){
		return dressing;
	}
	
	public string getMeat(){
		return meat;
	}
	
	public void setBread(string bread)
	{
		this.bread=bread;
	}
	
	public void setCondiments(string condiments)
	{
		this.condiments =condiments;
	}
	
	public void setDressing(String dressing)
	{
		this.dressing =dressing;
	}
	
	public void setMeat(string meat){
		this.meat = meat;
	}
}
//*************************** USING TELESCOPING **************************************

public class LunchOrderTele {
		private string bread;
		private string condiments;
		private string dressing;
		private sring meat;
		
		public LunhcOrderTele(string bread, string condiments)
		{
			this(bread);
			this.condiments = condiments;
		}
		public LunchOrderTele(string bread, string condiments, string dressing)
		{
			this(bread,condiments);
			this.dressing = dressing;
		}
		public LunchOrderTele(string bread, string condiments, string dressing, string meat)
		{
			this(bread,condiments,dressing);
			this.meat = meat;
		}
		
		public string getBread()
		{
			retrun bread;
		}
		
		public String getCondiments(){
			return condiments;
		}
		
		public string getDressing() {
			return dressing;
		}
		
		public string getMeat() {
			return meat;
		}
}

//*******************************  BUILDER PATTERN DEMO ***********************************
//it has benefit of bean pattern and Telescoping
public class LunchOrder {
	
	public static class Builder {
	
		private string bread;
		private string condiments;
		private string dressing;
		private sring meat;
		
		public Builder() {
		}
		
		public LunchOrder build() {
			retrun new LunchOrder(this);
		}
		
		public Builder bread(String bread){
			this.bread=bread;
		}
		
		public Builder condiments(String condiments){
			this.condiments=condiments;
		}
		
		public Builder dressing(String dressing){
			this.dressing=dressing;
		}
		
		public Builder meat(String meat){
			this.meat=meat;
		}
	}	
	
	private final string bread;
	private final string condiments;
	private final string dressing;
	private final sring meat;
	
	private LunchOrder(Builder builder)
		this.bread=builder.bread;
		this.condiments = builder.condiments;
		this.dressing = builder.dressing;
		this.meat =builder.meat;
	}
	
	public string getBread()
	{
		retrun bread;
	}
	
	public String getCondiments(){
		return condiments;
	}
	
	public string getDressing() {
		return dressing;
	}
	
	public string getMeat() {
		return meat;
	}
}

public class BuilderLunchOrderDemo {
	public static void main(String []){
		LunchOrder.Builder builder = new LunchOrder.Builder();
		builder.bread("Wheat").condiments("Lettuce").dressing("Mayo").meat("Turkey"); //enforcing immutability
		
		LunchOrder lunchOrder = builder.build();
		System.out.println(lunchOrder.getBread());
		System.out.println(lunchOrder.getCondiments());
		System.out.println(lunchOrder.getDressing());
		System.out.println(lunchOrder.getMeat());
	}
}
		