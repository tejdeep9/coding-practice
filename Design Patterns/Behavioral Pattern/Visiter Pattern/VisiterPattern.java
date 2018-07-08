//******************** WITHOUT VISITOR *************************

public interface AtvPart {
	public double calculateShipping();
}
public class Fender implements AtvPart {
	@Override
	public double calculateShipping() {
		return 3;
	}
}
public class Oil implements AtvPart {
	@Override
	public double calculateShipping() {
		return 9;
	}
}
public class Wheel implements AtvPart {
	@Override
	public double calculateShipping() {
		return 12;
	}
}

public class PartsOrder implements AtvPart {
	private List<AtvPart> parts = new ArrayList<>();
	public PartsOrder() {
	}
	public void addPart(Atvpart atvPart) {
		parts.add(atvPart);
	}
	public List<AtvPart> getParts() {
		return Collections.unmodifiableList(parts);
	}
	
	public double calculateShipping(){
		double shippingCost=0;
		for(AtvPart atvpart: parts)
			shippingCost+=atvPart.calculateShipping();
		}
		return ShippingCost;
	}
		
}

public class VisitorDemo
{
	public static void main(String[] args) 
	{
		PartsOrder order = new PartsOrder();
		order.addPart(new Wheel());
		order.addPart(new Fender());
		order.addPart(new Oil());
		
		double shippingCost=order.calculateShipping();
		System.out.println(shippingCost);
	}

}

//************************************** VISITOR PATTERN ******************************
public interface AtvPart {
	public void accept(AtvPartVisitor visitor);
}
public class Fender implements AtvPart {
	@Override
	public void accept(AtvPartVisitor visitor){
		visitor.visit(this);
	}
}
public class Oil implements AtvPart {
	@Override
	public void accept(AtvPartVisitor visitor){
		visitor.visit(this);
	}
}
public class Wheel implements AtvPart {
	@Override
	public void accept(AtvPartVisitor visitor){
		visitor.visit(this);
	}
}

public interface AtvPartVisitor {
	void visit(Wheel wheel);
	void visit(Fender fender);
	void visit(Oil oil);
	void visit(PartsOrder partsOrder);
}
public class AtvPartShippingVisitor implements AtvPartVisitor {
	double shippingAmount = 0;
	@Override 
	public void visit(Wheel wheel){
		shippingAmount+=15;
		System.out.println("wheels are bulky and expensive to ship");
	}
	@Override 
	public void visit(Fender fender){
		shippingAmount+=3;
		System.out.println("fenders are light and cheap to ship");
	}
	@Override 
	public void visit(Oil oil){
		shippingAmount+=9;
		System.out.println("Oil is hazardous and has a fee to ship");
	}
	@Override 
	public void visit(PartsOrder partsOrder){
		System.out.println("If they bought more than 3 things we will give them a discount on shipping");
		List<AtvParts> parts=order.getParts();
		if(parts.size() > 3){
			shippingAmount-=5;
		}
		System.out.println("Shipping Amount is: "+ shippingAmount);
	}
}

public class AtvPartDisplayVisitor implements AtvPartVisitor {
	double shippingAmount = 0;
	@Override 
	public void visit(Wheel wheel){
		System.out.println("we have a Wheel");
	}
	@Override 
	public void visit(Fender fender){
		System.out.println("we have a fender");
	}
	@Override 
	public void visit(Oil oil){
		System.out.println("we have an oil");
	}
	@Override 
	public void visit(PartsOrder partsOrder){
		System.out.println("we have an oil");
	}
}

public class PartsOrder implements AtvPart {
	private List<AtvPart> parts = new ArrayList<>();
	public PartsOrder() {
	}
	public void addPart(Atvpart atvPart) {
		parts.add(atvPart);
	}
	public List<AtvPart> getParts() {
		return Collections.unmodifiableList(parts);
	}
	
	public double calculateShipping(){
		double shippingCost=0;
		for(AtvPart atvpart: parts)
			shippingCost+=atvPart.calculateShipping();
		}
		return ShippingCost;
	}
	
	@Override 
	public void accept(AtvPartVisitor visitor){
		for(AtvPart atvPart: parts){
			atvPart.accept(visitor);
		}
		visitor.visit(this);
	}
}

public class VisitorDemo
{
	public static void main(String[] args) 
	{
		PartsOrder order = new PartsOrder();
		order.addPart(new Wheel());
		order.addPart(new Fender());
		order.addPart(new Oil());
		
		order.accept(new AtvPartsShippingVisitor());
		order.accept(new AtvPartsDisplayVisitor());
		double shippingCost=order.calculateShipping();
		System.out.println(shippingCost);
	}

}