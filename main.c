#include <unistd.h>  // for sleep function or delay
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX_ROOMS 100
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
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;
int num_reservations = 0;
char reservation_file[] = "reservations.txt";
char room_file[] = "rooms.txt";
int x, y; //for gotoxy
// wala yung user kasi gumagawa sya sarili nyang file per new user

void display_menu()
{
    printf("-------------------------------------------------\n");
    printf("|\t    Hotel --- Reservation       \t|\n");
    printf("-------------------------------------------------\n");
    printf("|\t\t\t\t\t\t|\n");
    printf("|\t    1. Registration       \t\t|\n");
    printf("|\t    2. Hotel Information       \t\t|\n");
    printf("|\t    3. Availability       \t\t|\n");
    printf("|\t    4. Reservation       \t\t|\n");
    printf("|\t    5. Exit       \t\t\t|\n");
    printf("-------------------------------------------------\n");


}


int main()
{
    retrieve_data(); // for retrieval
    int choice = 0;

    while (choice != 1){    //Registration or login verification
          system("cls");    //Users cannot make reservation unless they are registered.
          display_menu();
          printf("|\t    Enter your choice:       \t\t|\n");
          printf("-------------------------------------------------\n");
          gotoxy(31,10); scanf("%d", &choice);

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
           printf("\n\tPlease Login/Register first");
           getch();
        }
        }

  while (choice != 5)
        {
          system("cls");
          display_menu();
          printf("|\t    Enter your choice:       \t\t|\n");
          printf("-------------------------------------------------\n");
          gotoxy(31,10); scanf("%d", &choice);

          switch (choice)
          {
            case 1: printf("\tYou are now Logged in/ Registered ");
                    printf("and can now make a reservation!\n");
                    getch();
                    break;
            case 2: hotel_information(); // NEED TULONG 
                    break;
            case 3: printf("Availability:\n"); // WALA PA
                    hotel_information();
                    break;
            case 4: make_reservation(); // ON-GOING
                    break;
            case 5: printf("\n\tThank you for visiting our site!\n");
                    break;
            default: printf("Invalid choice!\n");
          }
        }

return 0;
}


void register_user()
{
    printf("\nREGISTRATION\n");
    User user;


    printf("Email: ");
    scanf("%s", user.email);

    printf("Password: ");
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
    printf("\nRegistration successful!\n");
    sleep(2);  // delay

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
    printf("\nHOTEL INFORMATION\n");
    printf("\nThis Hotel serves a 12hours reservation which is Day and Night\n");

    printf("Room ID\tType\tPrice\tAvailable Rooms\n");


    for (int i = 0; i < num_rooms; i++) {
        printf("%d\t%s\t%.2f\t%d/%d\n", rooms[i].id, rooms[i].type, rooms[i].price, rooms[i].available_rooms, rooms[i].total_rooms);
    }
    getch();
}


int make_reservation() // KAILANGAN AYUSIN GALING CHATGPT EH HAHAHAHA
{
    printf("\nMAKE A RESERVATION\n");

        // get reservation details
    Reservation reservation;
    printf("\nDate (MM/DD/YY): ");
    scanf("%s", reservation.date);

    printf("Room Type (Standard/Deluxe/Suite): ");
    scanf("%s", reservation.type);

    printf("Number of Rooms: ");
    scanf("%d", &reservation.room_num);



    // calculate bill
    float price;
    if (strcmp(reservation.type, "Standard") == 0)
        {
        price = 3000.0;
        printf("\nStandard = 3,000");
        }
    else if (strcmp(reservation.type, "Deluxe") == 0)
        {
        price = 6000.0;
        printf("\nDeluxe = 6,000");
        }
    else if (strcmp(reservation.type, "Suite") == 0)
        {
        price = 10000.0;
        printf("\nSuite = 10,000");
        }
    else{
        printf("\nInvalid room type. Please try again.\n");
        sleep(2); // delay
        return;
    }

    reservation.bill = price * reservation.room_num;


    // save reservation
    save_reservation(reservation);
    printf("\nReservation successful! Total Bill: %.2f\n", reservation.bill);
    display_reservation_details(reservation);
    sleep(5); // delay
}






void display_reservation_details(Reservation res)
{
    printf("Reservation Details\n");
    printf("Name: %s\n", res.name);
    printf("Date: %s\n", res.date);
    printf("Room Type: %s\n", res.type);
    printf("Room Number: %d\n", res.room_num);
    printf("Bill: $%.2f\n", res.bill);
}



void save_reservation(Reservation res) // saves in the reservations.txt
{
    FILE* file = fopen(reservation_file, "a"); // a = append
    fprintf(file, "%s %s %s %d %d %f\n", res.name, res.date, res.type, res.room_num, res.bill);
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
       sscanf(line, "%s %s %s %d %d %f", res.name, res.date, res.type, &res.room_num, &res.bill);
       display_reservation_details(res);
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

