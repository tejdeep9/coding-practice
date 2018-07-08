public abstract class Website {
	
		protected List<Page> pages = new ArrayList<>();
		
		public List<Page> getPages(){
			return pages;
		}
		
		public Website(){
			this.createWebsite();
		}
		
		public abstract void createWebsite();
}

public enum WebsiteType {
		BLOG,SHOP;
}

public void class Blog extends Website {

		@Override
		public void createWebsite(){
			pages.add(new PostPage());
			pages.add(new AboutPage());
			pages.add(new CommentPage());
			pages.add(new ContactPage());
		}
}


public void class Shop extends Website {

		@Override
		public void createWebsite(){
			pages.add(new CartPage());
			pages.add(new ItemPage());
			pages.add(new SearchPage());
		}
}

public class WebsiteFactory {
				public static Website getWebSite(WebsiteType siteType){
					switch(siteType)
					{
						case BLOG : {
							return new Blog();
						}
						case SHOP : {
							return new Shop();
						}
						default : {
							return null;
						}
					}
				}
}				
						
public class FactoryDemo {
	public static void main(string[] args){
		 website site= WebsiteFactory.getWebsite(WebsiteType.BLOG);
		 System.out.println(site.getPages());
		 
		 site= WebsiteFactory.getWebsite(WebsiteType.SHOP);
		 System.out.println(site.getPages());
	 }
}
							