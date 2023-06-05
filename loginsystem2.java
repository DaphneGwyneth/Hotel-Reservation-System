

import java.util.Scanner;
import java.util.StringTokenizer;

import javax.crypto.Cipher;

import java.io.BufferedReader;
import java.io.FileReader;
//import java.io.BufferedWriter;
//import java.io.FileWriter;
//import java.io.IOException;


public class loginsystem2 {
	public static int choice; 
	public static Scanner sc = new Scanner(System.in);
	static Cipher cipher;  
	

    public static void main (String [] args)  {
    	
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

    

   public static void adminlogin()  {
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
        
        //TEST
   /*     try {
            int key = 58;
            BufferedWriter writer = new BufferedWriter(new FileWriter("admin.txt"));
            String text = "admin";  String text1 = "123123";
            char [] chars = text.toCharArray();
            for(char c : chars) {
        		c+= key;
        		writer.write(c);
        		System.out.print(c);
        	}
        	writer.write("\t");
            char [] chara = text1.toCharArray();
        	
            	for(char c : chara) {
        	    	c+= key;
        	    	writer.write(c);
        		 System.out.print(c);
        	 }
                writer.close();
            	 }catch(IOException e) {
                 	System.out.print("File not found");
                 	}*/
        try {
        int key = 58;
        BufferedReader reader = new BufferedReader(new FileReader("admin.txt"));
        String line;
        while ((line = reader.readLine()) != null) {
        	 try {
                 
        	StringTokenizer stn = new StringTokenizer (line);
        	String username =  stn.nextToken();
        	String pass = stn.nextToken();
        	
        	char [] chars = username.toCharArray();
        	
        	String UN = "";
        	for(char c : chars) {
        		c-= key;
        		UN = UN + c;
        		
        	}
        	//System.out.print(UN);
        	
        	//System.out.print("    ");
        	String PW = "";
            char [] chara = pass.toCharArray();
        	
            	for(char c : chara) {
        	    	c-= key;
        	    	PW = PW + c;
        	 }
            //	System.out.print(PW);
            	
        	 if (email.equalsIgnoreCase(UN) && password.equalsIgnoreCase(PW)) {
             	System.out.println("Logged in Successfuly!");
             } 
        	 else {
             	adminlogin();
             }
        	 } catch (Exception ignored) {}
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
    


   
/*public static String decrypt(String encryptedText, SecretKey secretKey)
        throws Exception {
    Base64.Decoder decoder = Base64.getDecoder();
    byte[] encryptedTextByte = decoder.decode(encryptedText);
    cipher.init(Cipher.DECRYPT_MODE, secretKey);
    byte[] decryptedByte = cipher.doFinal(encryptedTextByte);
    String decryptedText = new String(decryptedByte);
    return decryptedText;
}
*/
	} 
    


