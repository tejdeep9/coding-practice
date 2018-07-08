
// **************************** CREATING A STATIC SINGLETON ********************************************************************
public class DbSingleton {
	public static DbSingleton instance = new DbSingleton();
	
	private DbSingleton() {} //declare the constructor as private because other people cant create the instance except the class
	
	public static DbSingleton getInstance(){
		return instance;
	}
}
public static class  DbSingletonDemo {
	
		public static void  main(String arg[])
		{
			DbSingleton instance = DbSingleton.getInstance();
			System.out.println(instnace);
			DbSingleton anotherInstance = DbSingleton.getInstance();
			System.out.println(anotherInstance); // both the objects are same.
		}
}


//****************************** MAKING SINGLETON LAZY LOADED ****************************************************************
//lazy loading the instance into the memory (get the resources only when you need), it helps to increase the performance
public class DbSingleton {
	public static DbSingleton instance = null;
	
	private DbSingleton() {} //declare the constructor as private because other people cant create the instance except the class
	
	public static DbSingleton getInstance(){
		if(instance == null)
		{
			instance = new DbSingleton();  //lazy loading the instance into the memory 
		}
		return instance;
	}
}

//*************************** MAKING SINGLETON CLASS THREAD SAFE ***************************************************************

public class DbSingleton {
	public static DbSingleton instance = null;
	
	private DbSingleton() {} //declare the constructor as private because other people cant create the instance except the class
	
	public static DbSingleton getInstance(){
		if(instance == null) //if instance is not null we will move on  because synchronization will definitely slow your class
		{
			synchronized(DbSingleton.class){             //making it thread safe just like a lock to avoid race condition
				if(instance == null){
					instance = new DbSingleton();  //lazy loading the instance into the memory 
			}
		}
		return instance;
	}
}