public abstract class Subject {
	private List<Observer> observers = new ArrayList<>();
	abstract void setState(String state);
	abstract String getState();
	
	public void attach(Observer observer){
		observers.add(observer);
	}
	
	public void detach(Observer observer){
		observers.remove(observer);
	}
	
	public void notifyObservers(){
		for(Observer observer : observers) {
			observer.update();
		}
	}
}

public class MessageStream extends Subject {
	private Deque<string> messageHistory  = new ArrayDeque<>();
	
	@Override 
	void setState(String state){
		messageHistory.add(message);
		this.notifyObservers(); //notify observers
	}
	
	@Override getState() {
		return messageHistory.getLast();
	}
		
}
public abstract class Observer {
	protected Subject subject; //reference of the subject so we can get the state from it
	abstract void update(); //this is called from the subject
}

public class PhoneClient extends Observer {
	public PhoneClient(Subject subject)
	{
		this.subject = subject;
		subject.attach(this); //attach itself to the subject, similarly clients that are attaching to the same subject get notified by subject.
	}
	
	public void addMessage(String message) {
		subject.setState(message+"-sent from phone");
	}
	
	@Override
	void update() {
		System.out.println("Phone Stream: " + subject.getState());
	}
}

public class TabletClient extends Observer {
	public TabletClient(MessageStream subject) {
		this.subject =subject;
		subject.attach(this);
	}
	
	public void addMessage(String message) {
		subject.setState(message+"-sent from tablet");
	}
	
	@Override
	void update() {
		System.out.println("Tablet Stream: " + subject.getState());
	}
}
public class ObserverDemo {
	public static void main(String args[]) {
		Subject subject = new MessageStream();
		PhoneClient phoneClient = new PhoneClient(subject);
		TabletClient tabletMessage= new TabletClient(subject);
		
		phoneClient.addMessage("Here is a Message");
		tabletClient.addMessage("Another new Message!");
	}
}	