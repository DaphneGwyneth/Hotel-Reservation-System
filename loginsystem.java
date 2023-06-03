public class loginsystem {
    public static void main (String [] args){

        int choice = 0;
        try (Scanner sc = new Scanner(System.in)) {
            while (choice != 1) {
                clearScreen();
                displayMenu();
                System.out.println("| Enter your choice:       \t\t\t|");
                System.out.println("+===============================================+");
                choice = sc.nextInt();

                if (choice == 1) {
                  //  registerUser(a);
                    break;
                } else if (choice == 2) {
                 //   hotelInformation();
                } else if (choice == 5) {
                    System.exit(0);
                } else {
                    System.out.print("\t  Please Login/Register first");
                    sc.nextLine();
                    sc.nextLine();
                }
            }

            while (choice != 5) {
                clearScreen();
                displayMenu();
                System.out.print("| Enter your choice:       \t\t\t|\n");
                System.out.print("+============================================+\n");
                choice = sc.nextInt();

                switch (choice) {
                    case 1:
                        System.out.print("\tYou are now Logged in/Registered " +
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
                        makeReservation();
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

    }

    static void login(){
        User b;
        char eme[], password[];
        system("cls");
        System.out.print("+===============================================================+");
        System.out.print("|\t            Hotel Picadili Travels      \t\t|");
        System.out.print("+=============+===============================================================+=============+");
        System.out.print("----------------------------------");
        System.out.print("       Picadili Registration");
        System.out.print("----------------------------------");
        System.out.print("Enter Email: ");
        System.out.print("Enter Password: ");
        //System.out.print("----------------------------------");
        //System.out.print("|                                  |");
        //System.out.print("----------------------------------");
        eme = sc.nextInt();

        int i = 0;
        gotoxy(62,12);
        while (1)
        {
            char ch = getch();
            if (ch == '\r' || ch == '\n') { // enter key
                break;
            } else if (ch == '\b') { // backspace key
                if (i > 0) {
                    i--;
                    System.out.print("\b \b");
                }
            } else {
                if (i < MAX_PASSWORD_LENGTH) {
                    password[i] = ch;
                    i++;
                    System.out.print("*"); // password privacy
                }
            }
        }
        password[i] = '\0';
    
        if (authentication(eme, password) == 1)
        {
            System.out.print("      Login Successful!"); sleep(2);
        }
        else if (authentication(eme, password) == 0)
        {
            String email = String.valueOf(eme);
            encrypt_password(password, 0xFACA);
            String pass = String.valueOf(password);

            /*  strcpy(a->email, &eme);
             encrypt_password(password, 0xFACA);
             strcpy(a->pass, &password);
             addAccount(a);
    
              for (int i = 0; i <= marker; i++)
            {
                          encrypt_password(password, 0xFACA);
                          System.out.print("%s", password);
            }
            getch();*/
    
             save_user();
              System.out.print("      Registration Successful!\n");
        sleep(2);  // delay
    
        }
    }

    static void displayMenu() {
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
	}

    static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

}