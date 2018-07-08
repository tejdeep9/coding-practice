public class CreditCard {
	private string number;
	private string date;
	private string cvv;
	private ValidationStartegy strategy;
	
	public CreditCard(ValidationStrategy strategy) {
		this.strategy=strategy;
	}

	public boolean isValid() {
		return strategy.isValid(this);
	}
	
	public string getNumber(){
		return number;
	}
	
	public void setNumber(string number){
		this.number=number;
	}
	
	public string getDate() {
		return date;
	}
	
	public setDate(string date){
		this.date=date;
	}
	
	public string getCvv(){
		return cvv;
	}
	
	public void setCvv(string cvv){
		this.cvv=cvv;
	}
}

public abstract class ValidationStrategy {
	public abstract boolean isValid(CreditCard creditCard);
	
	//checks whether the credit card is valid or not - its a Luhn algorithm
	public boolean passesLuhn(string ccNumber){
		int sum=0;
		boolean alternate =false;
		for(int i=ccNumber.length()-1; i>=0; i--){
			int n=Integer.parseInt(ccNumber.substring(i,i+1));
			if(alternate){
				n*=2;
				if(n > 9){
					n=(n%10)+1;
				}
			}
			sum+=n;
			alterante=!alternate;
		}
		return (sum%10 == 0);
	}
}

public class AmexStrategy extends ValidationStrategy {
	@Override
	public boolean isValid(CreditCard creditCard){
		boolean isValid=true;
		isValid =creditCard.getNumber().startsWith("37") || creditCard.getNumber().startsWith("34");
		
		if(isValid){
			isValid =creditCard.getNumber().length()==15;
		}
		
		if(isValid){
			isValid =passesLuhn(creditCard.getNumber());
		}
		return isValid;
	}
}

public class VisaStrategy extends ValidationStrategy {
	@Override
	public boolean isValid(CreditCard creditCard){
		boolean isValid=true;
		isValid =creditCard.getNumber().startsWith("4");
		
		if(isValid){
			isValid =creditCard.getNumber().length()==16;
		}
		
		if(isValid){
			isValid =passesLuhn(creditCard.getNumber());
		}
		return isValid;
	}
}


public class StrategyDemo {
	public static void main(string args[]) {
		CreditCard amexCard = new CreditCard(new AmexStrategy());
		amexCard.setNumber("379185883464283");
		amexCard.setDate("04/2020");
		amexCard.setCvv("123");
		System.out.println("Is Amex valid: "+amexCard.isValid());
		
		CreditCard visaCard = new CreditCard(new VisaStrategy());
		visaCard.setNumber("4539589763663402");
		visaCard.setDate("05/2018");
		visaCard.setCvv("324");
		System.out.println("Is Visa valid: "+visaCard.isValid());
	}
}