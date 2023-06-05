import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;import java.io.*;

public class loginsystem {
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

        if (email.equalsIgnoreCase("admin") && password.equalsIgnoreCase("123123")) {
        	System.out.println("Logged in Successfuly!");
        }
        else {
        	adminlogin();
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
    
    /*
    static void authentication(char a, char b) {
    	int i;
    	    for (i = 0; i <= marker; i++)
    	    {
    	        if (strcmp(x, lg[i].email) == 0 && strcmp(y, lg[i].pass) == 0)
    	        {
    	            return 1;
    	        }
    	    }

    	    return 0;
    	
    }
    
    static int locate() {
    	//
    }
*/
    static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    
    
    
    

}

