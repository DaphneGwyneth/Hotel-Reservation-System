// GAMIT TAYO NG GOTOXY AH PARA MAGANDA SA DISPLAY
// WALA PANG GOTOXY ITO XDXDXD

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


int main()
{
    retrieve_data(); // for retrieval

    while(1)
        {
          switch (display_menu())
          {
            case 1: register_user();// ON-GOING
                    break;
            case 2: hotel_information(); // WALA PA
                    break;
            case 3: printf("Availability:\n"); // WALA PA
                    hotel_information();
                    break;
            case 4: make_reservation(); // KAILANGAN AYUSIN GALING CHATGPT EH AHAHA
                    break;
            case 5: printf("Thank you for visiting our site!\n");
                    break;
            default: printf("Invalid choice!\n");
          }
        }

return 0;
}


void display_menu()
{
    int choice;
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
    printf("|\t    Enter your choice:       \t\t|\n");
    printf("-------------------------------------------------\n");
    gotoxy(31,10); scanf("%d", &choice);
    return choice;


}



void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
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
    printf("Room ID\tType\tPrice\tAvailable Rooms\n");


    for (int i = 0; i < num_rooms; i++) {
        printf("%d\t%s\t%.2f\t%d/%d\n", rooms[i].id, rooms[i].type, rooms[i].price, rooms[i].available_rooms, rooms[i].total_rooms);
    }
}


int make_reservation() // KAILANGAN AYUSIN GALING CHATGPT EH HAHAHAHA
{
    printf("\nMAKE A RESERVATION\n");
    Reservation res;

    printf("Name: ");
    scanf("%s", res.name);
    printf("Date of Reservation (mm-dd-yyyy): ");
    scanf("%s", res.date);
    printf("Room Type (standard/deluxe/suite): ");
    scanf("%s", res.type);


    int room_num = -1;
    for (int i = 0; i < num_rooms; i++)
        {
    if (strcmp(res.type, rooms[i].type) == 0 && rooms[i].available_rooms > 0)
    {
         room_num = rooms[i].id;
         rooms[i].available_rooms--;
         rooms[i].total_rooms--;
         break;
      }
    }
     if (room_num == -1) {
     printf("Sorry, no rooms of this type are available at the moment.\n");
      return 0;
        }
    res.room_num = room_num;

    float bill = rooms[room_num - 1].price; // NOT FINAL
    res.bill = bill;
    printf("Your Bill is: $%.2f\n", bill);
    printf("Reservation Successful!\n");
    printf("Your Reservation Number is: %d\n", num_reservations + 1);
    display_reservation_details(res);
    save_reservation(res); // to save the reservation of the user in txt file
    num_reservations++;

      return 1;
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

}

void retrieve_reservations() // retrieval for reservations
{

}

void retrieve_data() // retrieval
{
    retrieve_rooms();
    retrieve_reservations();
}


