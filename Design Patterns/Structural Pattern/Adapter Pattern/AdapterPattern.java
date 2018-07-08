public class AdapterDemo {
	public static void main(string[] args){
		EmployeeClient client = new EmployeeClient();
		List<Employee> employees= client.getEmployeeList();
		System.out.println(employees);
	}
}
public interface Employee {
	public string getId();
	public string getFirstName();
	public string getLastName();
	public string getEmail();
}

public class EmployeeDB implements Employee {
	private string id;
	private string firstName;
	private string lastName;
	private string email;
	
	public EmployeeDB(string id, string firstName, string lastName, string email) {
		this.id=id;
		this.firstName=firstName;
		this.lastName=lastName;
		this.email;
	}
	
	public string getId(){
		return id;
	}
	public string getFirstName(){
		return firstName;
	}
	public string getLastName(){
		return lastName;
	}
	public string getEmail(){
		return email;
	}
}

//legacy code
public class EmployeeLdap{
	private string cn;
	private string surname;
	private string givenName;
	private string mail;
	
	public EmployeeLdap(string cn, string surname, string givenName, string mail){
		this.cn=cn;
		this.surname=surname;
		this.givenName=givenName;
		this.email=mail;
	}
	public string getCn(){
		return cn;
	}
	
	public string getGivenName(){
		return givenName;
	}
	
	public string getSurname(){
		return surname;
	}
	
	public string getEmail(){
		return email;
	}
}

//adapter to make legacy code compatibel with the new format employee
public class EmployeeAdapterldap implements Employee {
	private EmployeeLdap instance;
	
	public EmployeeAdapterLdap(EmployeeLdap instance) {
		this.instance=instance;
	}
	@Override
	public string getId(){
		return intance.getCn();
	}
	@Override
	public string getFirstName(){
		return instnace.getGivenName();
	}
	@Override
	public string getLastName(){
		return instance.getSurname();
	}
	@Override
	public string getEmail(){
		return instnace.getMail();
	}
}

public class EmployeeClient{
	public List<Employee> getEmployeeList() {
		List<Employee> employees = new ArrayList<>();
		Employee employeeFromDB = new EmployeeDB("1234", "john", "Wick", "john@wick.com");
		employees.add(employeeFromDB);
		//will not work! This is where adapter comes into play
		EmployeeLdap employeFromLdap = new Employee("chewie", "solo", "Han", "han@solo.com");
		employees.add(new EmployeeAdapterLdap(employeeFromLdap));
		
		return employees;
	}
}