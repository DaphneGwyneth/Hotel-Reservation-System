#include <unistd.h>  // for sleep function or delay
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX_ROOMS 10 // reduced for simplicity sake
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_DATE_LENGTH 10
#define MAX_TYPE_LENGTH 10


typedef struct
{
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int room_num;
    float bill;
} Reservation;

typedef struct
{
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    Reservation reservations[MAX_ROOMS];
    int num_reservations;
} User;

typedef struct
{
    int id; // for making of the room number ID
    char type[MAX_TYPE_LENGTH]; // for room types (standard,deluxe,suite)
    float price; // price per room (for 12hours)
    int available_rooms;
    int total_rooms;
    char isReserved[MAX_DATE_LENGTH]; // added for availability, might have to take this into account when saving and retrieving
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;
int num_reservations = 0;
char reservation_file[] = "reservations.txt";
char room_file[] = "rooms.txt";
int x, y; //for gotoxy


void display_menu()
{
    gotoxy(35, 8);printf("+============================================+\n");
    gotoxy(35, 9);printf("|\t       Hotel Picadili Travels    \t|\n");
    gotoxy(35, 10);printf("+============================================+\n");
    gotoxy(35, 11);printf("|\t\t\t\t\t\t|\n");
    gotoxy(35, 12);printf("|\t    [1] : Registration       \t\t|\n");
    gotoxy(35, 13);printf("|\t    [2] : Hotel Information     \t|\n");
    gotoxy(35, 14);printf("|\t    [3] : Availability       \t\t|\n");
    gotoxy(35, 15);printf("|\t    [4] : Reservation       \t\t|\n");
    gotoxy(35, 16);printf("|\t    [5] : Exit       \t\t\t|\n");
    gotoxy(35, 17);printf("|\t\t\t\t\t\t|\n");
    gotoxy(35, 18);printf("+============================================+\n");


}


int main()
{
    retrieve_data(); // for retrieval
    int choice = 0;

    while (choice != 1){    //Registration or login verification
          system("cls");    //Users cannot make reservation unless they are registered.
          display_menu();
           gotoxy(35, 19);printf("| Enter your choice:       \t\t\t|\n");
           gotoxy(35, 20);printf("+============================================+\n");
           gotoxy(56, 19);printf; scanf("%d", &choice);

        if (choice == 1){
                register_user();
                break;
        }
        else if (choice == 2){
                hotel_information();
        }
        else if (choice == 5){
            exit(0);
        }
        else{
           gotoxy(35, 22); printf("\t  Please Login/Register first");
           getch();
        }
        }

  while (choice != 5)
        {
          system("cls");
          display_menu();
          gotoxy(35, 19);printf("| Enter your choice:       \t\t\t|\n");
           gotoxy(35, 20);printf("+============================================+\n");
           gotoxy(56, 19);printf; scanf("%d", &choice);

          switch (choice)
          {
            case 1: printf("\tYou are now Logged in/ Registered ");
                    printf("and can now make a reservation!\n");
                    getch();
                    break;
            case 2: hotel_information(); // DONE
                    break;
            case 3: // ON-GOING
                    system("cls");
                    gotoxy(35, 8);printf("+============================================+\n");
                    gotoxy(35, 9);printf("|\t             AVAILABILITY               |\n");
                    gotoxy(35, 10);printf("+============================================+\n");
                    availability();
                    break;
            case 4: make_reservation(); // DONE
                    break;
            case 5: gotoxy(35, 23);printf("\t  Thank you for visiting our site!\n");
                    break;
            default: printf("Invalid choice!\n");
          }
        }

return 0;
}


void register_user()
{
    gotoxy(35, 22);printf("\t       REGISTRATION\n");
    User user;


    gotoxy(35, 24);printf("Email: ");
    scanf("%s", user.email);

    gotoxy(35, 25);printf("Password: ");
    char password[MAX_PASSWORD_LENGTH + 1];

    int i = 0;

    while (1)
    {
        char ch = getch();
        if (ch == '\r' || ch == '\n') { // enter key
            break;
        } else if (ch == '\b') { // backspace key
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            if (i < MAX_PASSWORD_LENGTH) {
                password[i] = ch;
                i++;
                printf("*"); // password privacy
            }
        }
    }
    password[i] = '\0';
    encrypt_password(password);
    strcpy(user.password, password);
    save_user(user);
    gotoxy(35, 27);printf("\t       Registration successful!\n");
    sleep(3);  // delay

}


void encrypt_password(char* password)
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
     password[i] = password[i] + 0; // saves password in txt file (decrypted)
    }
}

void save_user(User user)
{
    char filename[MAX_NAME_LENGTH + 5];

    sprintf(filename, "%s.txt", user.email); // makes multiple txt file for new user using their email

    FILE* fp = fopen(filename, "w");
    fprintf(fp, "%s,%s,%d\n", user.email, user.password, user.num_reservations);
    fclose(fp);
}


void hotel_information() // HOTEL INFORMATION
{
    system("cls");
     gotoxy(32, 3); printf("+===============================================================+");
    gotoxy(32, 4);printf("|\t            Hotel Picadili Travels      \t\t|");
    gotoxy(18, 5);printf("+============+===============================================================+============+");
    gotoxy(20, 7);printf("Hotel Picadili Travels, is a 15 Storey hotel in a vibrant commercial area.");
    gotoxy(20, 8);printf("This sleek luxury hotel is 3 km from SM Mall of Asia, and 5 km from both World");
    gotoxy(20, 9);printf("Trade Center Metro Manila and Ninoy Aquino International Airport. ");
    gotoxy(20, 11);printf("This Hotel serves a 12hours reservation which is Day and Night");

    gotoxy(20, 13);printf("Amenities: Internet, Gym, Pools, Parking & Transportation, and 24 Hour Bar & Room service\n");

    gotoxy(20, 16);printf("Room Information: ");
    gotoxy(18, 17);printf("+=========================================================================================+");
    gotoxy(18, 18);printf("|\t Room Type  |\tInformation\t\t\t\t|   Price\t\t    |");
    gotoxy(18, 19);printf("+=========================================================================================+");
    gotoxy(18, 20);printf("|\t Standard   |\t40Sq-Meter, Table and Queen Bed \t|   3000/12 Hour            |");
    gotoxy(18, 21);printf("|\t Deluxe     |\t60Sq-M, Sofa, Table, and King Bed \t|   6000/12 Hour            |");
    gotoxy(18, 22);printf("|\t Suit       |\t2Rooms, 120Sq-M, Sofa and King Bed \t|   1000/12 Hour            |");
    gotoxy(18, 23);printf("+=========================================================================================+");


    getch();
}


void availability() // AVAILABILITY
{
    char availDate[50];
    gotoxy(35, 12);printf("Input date( MM/DD/YY): ");scanf("%s", availDate); // added for availdate
    gotoxy(35, 14);printf("Room ID\tType\tPrice\tAvailable Rooms\n");


    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].isReserved != availDate) // comparing the date if it is reserved
            gotoxy(35, 15);printf("%d\t%s\t%.2f\t%d/%d\n", rooms[i].id, rooms[i].type, rooms[i].price, rooms[i].available_rooms, rooms[i].total_rooms);
    }
    getch();

}

int make_reservation()
{
    system("cls");

    gotoxy(35, 4);printf("+============================================+\n");
    gotoxy(35, 5);printf("|\t          MAKE A RESERVATION            |\n");
    gotoxy(35, 6);printf("+============================================+\n");

    Reservation reservation;
    Room room;

    gotoxy(35, 8);printf("Name: ");
    scanf("%s", reservation.name);

    gotoxy(35, 9);printf("Date (MM/DD/YY): ");
    scanf("%s", reservation.date);

    gotoxy(35, 10);printf("Room Type (Standard/Deluxe/Suite): ");
    scanf("%s", reservation.type);

    gotoxy(35, 11);printf("Number of Rooms: ");
    scanf("%d", &reservation.room_num);



    // calculate bill
    float price;
    if (strcmp(reservation.type, "Standard") == 0)
        {
        gotoxy(35, 12);price = 3000.0;
        printf("Standard = 3,000");
        }
    else if (strcmp(reservation.type, "Deluxe") == 0)
        {
        price = 6000.0;
        gotoxy(35, 12);printf("Deluxe = 6,000");
        }
    else if (strcmp(reservation.type, "Suite") == 0)
        {
        price = 10000.0;
        gotoxy(35, 12);printf("Suite = 10,000");
        }
    else{
        gotoxy(35, 13);printf("\t       Invalid room type. Please try again.\n");
        sleep(2); // delay
        return;
    }

    reservation.bill = price * reservation.room_num;

    srand(time(NULL));
    room.id = rand() % 100 + 1; // randomizing Reservation ID number from 1-10


    // save reservation
    save_reservation(reservation, room);
    gotoxy(35, 14);printf("\t       Reservation successful!");
    gotoxy(35, 16);printf("Total Bill: %.2f\n", reservation.bill);
    gotoxy(35, 17);printf("Your Reservation ID is: %d", room.id);
    display_reservation_details(reservation, room);
    getch();
}






void display_reservation_details(Reservation res, Room room)
{
    gotoxy(35, 20);printf("+============================================+\n");
    gotoxy(35, 21);printf("|\t          RESERVATION DETAILS           |\n");
    gotoxy(35, 22);printf("+============================================+\n");
    gotoxy(35, 24);printf("Name: %s\n", res.name);
    gotoxy(35, 25);printf("Date: %s\n", res.date);
    gotoxy(35, 26);printf("Room Type: %s\n", res.type);
    gotoxy(35, 27);printf("Reservation ID Number: %d\n", room.id);
    gotoxy(35, 28);printf("Bill: %.2f\n", res.bill);

}



void save_reservation(Reservation res, Room room) // saves in the reservations.txt
{
    FILE* file = fopen(reservation_file, "a"); // a = append
    fprintf(file, "%s %s %s %d %d %f %d\n", res.name, res.date, res.type, res.room_num, res.bill, room.id);
    fclose(file);
}


void retrieve_rooms() // retrieval for available rooms
{
    FILE* file = fopen(room_file, "r");
    char line[MAX_TYPE_LENGTH + 2];
    while (fgets(line, sizeof(line), file))
    {
        Room room;
        sscanf(line, "%d %s %f %d %d", &room.id, room.type, &room.price, &room.available_rooms, &room.total_rooms);
        rooms[num_rooms] = room;
        num_rooms++;
    }
    fclose(file);
}

void retrieve_reservations() // retrieval for reservations
{
    FILE* file = fopen(reservation_file, "r");
    char line[MAX_NAME_LENGTH + MAX_DATE_LENGTH + MAX_TYPE_LENGTH + 26];

    while (fgets(line, sizeof(line), file))
    {
       Reservation res;
       Room room;
       sscanf(line, "%s %s %s %d %f %d", res.name, res.date, res.type, &res.room_num, &res.bill, &room.id);
       display_reservation_details(res, room);
    }
     fclose(file);
}

void retrieve_data() // retrieval
{
    retrieve_rooms();
    retrieve_reservations();
}

void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

