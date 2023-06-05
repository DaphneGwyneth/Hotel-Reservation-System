
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class loginsystem2 {
	public static int choice; 
	public static Scanner sc = new Scanner(System.in);
	
	
    public static void main (String [] args){
    	
         adminlogin();
            while (true) {
                clearScreen();

                switch (displayMenu()) {
                    case 1:
                        System.out.print("\tYou are now Logged in " +
                                "and can now make a reservation!\n");
                        sc.nextLine();
                        sc.nextLine();
                        break;
                    case 2:
                      //  hotelInformation();
                        break;
                    case 3:
                        clearScreen();
                        System.out.print("+============================================+\n");
                        System.out.print("|\t             AVAILABILITY               |\n");
                        System.out.print("+============================================+\n");
                      //  availability();
                        sc.nextLine();
                        sc.nextLine();
                        break;
                    case 4:
                     //   makeReservation();
                        break;
                    case 5:
                        System.out.print("\t  Thank you for visiting our site!\n");
                        break;
                    default:
                        System.out.print("Invalid choice!\n");
                        sc.nextLine();
                        sc.nextLine();
                }      
            }
        }    

    

    static void adminlogin(){
        //User b;
      clearScreen();
        System.out.println("+===============================================================+");
        System.out.println("|\t            Hotel Picadili Travels      \t\t|");
        System.out.println("+=============+===============================================================+=============+");
        System.out.println("----------------------------------");
        System.out.println("       Picadili Registration");
        System.out.println("----------------------------------");
        System.out.print("Enter Email: ");  String email = sc.nextLine();       
        System.out.print("Enter Password: ");  String password = sc.nextLine();
        //System.out.print("----------------------------------");
        //System.out.print("|                                  |");
        //System.out.print("----------------------------------");
        
        
        try {
        BufferedReader reader = new BufferedReader(new FileReader("admin.txt"));
        String line;
        while ((line = reader.readLine()) != null) {
        	StringTokenizer stn = new StringTokenizer (line);
        	String username = stn.nextToken();
        	String pass = stn.nextToken();
        	
        //	 System.out.print(username + pass); 
        	 if (email.equalsIgnoreCase("admin") && password.equalsIgnoreCase("123123")) {
             	System.out.println("Logged in Successfuly!");
             } 
        	 else {
             	adminlogin();
             }
        }
        reader.close();
        }catch(IOException e) {
        	System.out.print("File not found");
        }
        }
    

    static int displayMenu() {
		System.out.println("+===============================================+");
		System.out.println("|\t       Hotel Picadili Travels    \t|");
		System.out.println("+===============================================+");
		System.out.println("|\t\t\t\t\t\t|");
		System.out.println("|\t    [1] : Hotel Information     \t|");
		System.out.println("|\t    [2] : Availability       \t\t|");
		System.out.println("|\t    [3] : Reservation       \t\t|");
		System.out.println("|\t    [4] : Exit       \t\t\t|");
		System.out.println("|\t\t\t\t\t\t|");
		System.out.println("+===============================================+");
		
		   System.out.print("| Enter your choice:       \t\t\t|\n");
           System.out.print("+============================================+\n");
          choice = sc.nextInt();
          
          return choice;
	}
    
   
    static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    
    
    
    

}

