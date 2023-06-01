import java.util.Scanner;
public class HRM {
	
	 private static final int MAX = 30; // number of users
	    private static final int MAX_ROOMS = 10; // reduced for simplicity's sake
	    private static final int MAX_NAME_LENGTH = 50;
	    private static final int MAX_EMAIL_LENGTH = 31;
	    private static final int MAX_PASSWORD_LENGTH = 31;
	    private static final int MAX_DATE_LENGTH = 10;
	    private static final int MAX_TYPE_LENGTH = 10;

	    static class Reservation {
	        String name;
	        String date;
	        String type;
	        int roomNum;
	        float bill;
	    }

	    static class User {
	        String email;
	        String pass;
	        int numReservations;
	        Reservation[] reservations = new Reservation[MAX_ROOMS];
	    }

	    static User[] lg = new User[MAX];
	    static Room[] rooms = new Room[MAX_ROOMS];
	    static int numRooms = 0;
	    static int numReservations = 0;
	    static final String reservationFile = "reservations.txt";
	    static int x, y, marker, i, counter, z;

	    static class Room {
	        int id;
	        String type;
	        float price;
	        int availableRooms;
	        String isReserved;
	    }


	public static void main(String[] args) {

		/*  init();
	        retrieveData();
	        User a = new User();   */
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
				           // makeReservation();
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

	static void displayMenu() {
		System.out.println("+===============================================+");
		System.out.println("|\t       Hotel Picadili Travels    \t|");
		System.out.println("+===============================================+");
		System.out.println("|\t\t\t\t\t\t|");
		System.out.println("|\t    [1] : Registration       \t\t|");
		System.out.println("|\t    [2] : Hotel Information     \t|");
		System.out.println("|\t    [3] : Availability       \t\t|");
		System.out.println("|\t    [4] : Reservation       \t\t|");
		System.out.println("|\t    [5] : Exit       \t\t\t|");
		System.out.println("|\t\t\t\t\t\t|");
		System.out.println("+===============================================+");
	}

	static void availability() // AVAILABILITY
	{
		Scanner scan = new Scanner(System.in);
		String newDate;
		String newType;
		int available_rooms = 0;

		System.out.println("\n\t\t\tEnter the desired date (MM/DD/YY): ");
		newDate = scan.nextLine();
		System.out.println("\t\t\tEnter the desired room type (Standard/Deluxe/Suite): ");
		newType = scan.nextLine();

		// Check availability for each room
		for (int i = 0; i < MAX_ROOMS; i++) // I changed this from num_rooms to MAX_ROOMS, this was the main reason why it won't print more than one
		{
			// printf("%s (to show how many rooms)\n", rooms[i].type); //  This is the debugging thing
			if (rooms[i].type == newType)
			{
				if (rooms[i].isReserved != newDate)
				{
					available_rooms++;
				}
			}
		}

		if (available_rooms == 0)
			System.out.println("\n\t\t\tThere are no available rooms of type " + newType + "on the requested date " + newDate);
		else
			System.out.println("\n\t\t\t "+ vailable_rooms +  "Rooms is/are available for type" + newType);
	}

	void room_Update(String newDate, String newType, int roomAmount) // room update for availability
	{
		int roomFlag = 0;
		String aab = "NA/NA/NA";
		for (int i = 0; i < MAX_ROOMS; i++)
		{
			if (rooms[i].type == newType)
			{
				if (rooms[i].isReserved == aab)
				{
					rooms[i].isReserved = newDate;
					roomFlag++;
					if(roomFlag == roomAmount)
						i = MAX_ROOMS;
				}
			}
		}
	}

	    static void clearScreen() {
	        System.out.print("\033[H\033[2J");
	        System.out.flush();
	    }
	
	
}
