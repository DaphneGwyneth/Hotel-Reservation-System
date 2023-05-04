#include <unistd.h>  // for sleep function or delay
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX 30// number of user
#define MAX_ROOMS 10 // reduced for simplicity sake
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 31
#define MAX_PASSWORD_LENGTH 31
#define MAX_DATE_LENGTH 10
#define MAX_TYPE_LENGTH 10


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal > clock());
}

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
    char pass[MAX_PASSWORD_LENGTH];
    int num_reservations;
    Reservation reservations[MAX_ROOMS];
} User;

User lg[30];

typedef struct
{
    int id; // for making of the room number ID
    char type[MAX_TYPE_LENGTH]; // for room types (standard,deluxe,suite)
    float price; // price per room (for 24hours)
    int available_rooms;
    char isReserved[MAX_DATE_LENGTH]; // added for availability, might have to take this into account when saving and retrieving
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;
int num_reservations = 0;
char reservation_file[] = "reservations.txt";
int x, y, marker, i, counter, z; //for gotoxy



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


void init_rooms() // to initialize which rooms are which
{
    int ab = 0;
    char aab[MAX_DATE_LENGTH] = "NA/NA/NA";
    while(ab <= MAX_ROOMS)
    {
        strcpy(rooms[ab].isReserved, aab);
        if (ab <= 2)
            strcpy(rooms[ab].type,"Suite");
        else if (ab <= 5)
            strcpy(rooms[ab].type,"Deluxe");
        else
            strcpy(rooms[ab].type,"Standard");
        ab++;
    }
}


int main()
{
    init(); // initialize
    retrieve_data();// for retrieval
    User a;
    int choice = 0;


    while (choice != 1){    //Registration or login verification
          system("cls");    //Users cannot make reservation unless they are registered.
          display_menu();
           gotoxy(35, 19);printf("| Enter your choice:       \t\t\t|\n");
           gotoxy(35, 20);printf("+============================================+\n");
           gotoxy(56, 19);printf; scanf("%d", &choice);

        if (choice == 1){
                register_user(&a);
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
            case 1:gotoxy(33, 22);printf("\tYou are now Logged in/ Registered ");
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


void init()
{
 marker = -1;
 init_rooms();
}


void welcome(){
    system("color B0");
    gotoxy(27, 10); printf("+===================================================================+");
    gotoxy(25, 11);printf("||\t\t                                                \t||");
    gotoxy(25, 12);printf("||\t\t               Welcome to                       \t||");
    gotoxy(25, 13);printf("||\t\t          Hotel Picadili Travels                \t||");
    gotoxy(25, 14);printf("||\t\t                                                \t||");
    gotoxy(27, 15);printf("+===================================================================+");
    startButton();
}



void register_user(User *a)     //DONE
{
    User b;
    char eme[31], password[31];
    system("cls");
    gotoxy(32, 3); printf("+===============================================================+");
    gotoxy(32, 4);printf("|\t            Hotel Picadili Travels      \t\t|");
    gotoxy(18, 5);printf("+=============+===============================================================+=============+");
    gotoxy(45,7); printf("----------------------------------");
    gotoxy(45,8); printf("       Picadili Registration");
    gotoxy(45,9); printf("----------------------------------");
    gotoxy(45,11); printf("Enter Email: ");
    gotoxy(45,12); printf("Enter Password: ");
    gotoxy(45,13); printf("----------------------------------");
    gotoxy(44,14); printf("|                                  |");
    gotoxy(45,15); printf("----------------------------------");
    gotoxy(62,11); scanf("%s", &eme);

   // printf("%s", eme); getch();

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

    if (authentication(eme, password) == 1)
    {
        gotoxy(45,14);printf("      Login Successful!"); sleep(2);
    }
    else if (authentication(eme, password) == 0)
    {
         strcpy(a->email, &eme);
         encrypt_password(password, 0xFACA);
         strcpy(a->pass, &password);
         addAccount(a);

      /*    for (int i = 0; i <= marker; i++)
        {
                      encrypt_password(password, 0xFACA);
                      printf("%s", password);
        }
        getch();*/

         save_user();
            gotoxy(45,14);printf("      Registration Successful!\n");
    sleep(2);  // delay

    }
}


int authentication(char *x, char *y)
{
    for (i = 0; i <= marker; i++)
    {
        if (strcmp(x, lg[i].email) == 0 && strcmp(y, lg[i].pass) == 0)
        {
            return 1;
        }
    }

    return 0;
}


void addAccount(User a)
{
    marker++;
    lg[marker] = a;

}



int isFull()
{
if (marker==MAX-1)
    return 1;
else
    return 0;
//return(marker==MAX-1);
}


void encrypt_password(char password[], int key)
{
    int i;
    for (i = 0;i<strlen(password); i++){
     password[i] = password[i] - key; // saves password in txt file (decrypted)
    }
}


void decrypt_password(char password[], int key)
{
    int i;
    for (i = 0;i<strlen(password); i++){
     password[i] = password[i] + key; // saves password in txt file (decrypted)
    }
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
    gotoxy(20, 11);printf("This Hotel serves a 24 hours reservation.");

    gotoxy(20, 13);printf("Amenities: Internet, Gym, Pools, Parking & Transportation, and 24 Hour Bar & Room service\n");

    gotoxy(20, 16);printf("Room Information: ");
    gotoxy(18, 17);printf("+=========================================================================================+");
    gotoxy(18, 18);printf("|\t Room Type  |\tInformation\t\t\t\t|   Price\t\t    |");
    gotoxy(18, 19);printf("+=========================================================================================+");
    gotoxy(18, 20);printf("|\t Standard   |\t40Sq-Meter, Table and Queen Bed \t|   3000/24 Hours           |");
    gotoxy(18, 21);printf("|\t Deluxe     |\t60Sq-M, Sofa, Table, and King Bed \t|   6000/24 Hours           |");
    gotoxy(18, 22);printf("|\t Suite      |\t2Rooms, 120Sq-M, Sofa and King Bed \t|  10000/24 Hours           |");
    gotoxy(18, 23);printf("+=========================================================================================+");


    getch();
}


void availability() // AVAILABILITY
{

    char date[MAX_DATE_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int available_rooms = 0;

    printf("\n\t\t\tEnter the desired date (MM/DD/YY): ");
    scanf("%s", date);
    printf("\t\t\tEnter the desired room type (Standard/Deluxe/Suite): ");
    scanf("%s", type);

    // Check availability for each room
    for (int i = 0; i < MAX_ROOMS; i++) // I changed this from num_rooms to MAX_ROOMS, this was the main reason why it won't print more than one
    {
       // printf("%s (to show how many rooms)\n", rooms[i].type); //  This is the debugging thing
        if (strcmp(rooms[i].type, type) == 0)
        {
            if (strcmp(rooms[i].isReserved, date) != 0)
            {
                available_rooms++;
               }
        }
    }

    if (available_rooms == 0)
        printf("\n\t\t\tThere are no available rooms of type %s on the requested date %s\n", type,date);
    else
        printf("\n\t\t\t%d Rooms is/are available for type %s.\n", available_rooms, type);
    getch();
}

void room_Update(char newDate[MAX_DATE_LENGTH], char newType[MAX_TYPE_LENGTH], int roomAmount) // room update for availability
{
    int roomFlag = 0;
    char aab[MAX_DATE_LENGTH] = "NA/NA/NA";
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        if (strcmp(rooms[i].type, newType) == 0)
        {
            if (strcmp(rooms[i].isReserved, aab) == 0)
            {
                strcpy(rooms[i].isReserved, newDate);
                roomFlag++;
                if(roomFlag == roomAmount)
                    i = MAX_ROOMS;
            }
        }
    }
}

int make_reservation()
{
    system("cls");

    gotoxy(35, 1);printf("+============================================+\n");
    gotoxy(35, 2);printf("|\t          MAKE A RESERVATION            |\n");
    gotoxy(35, 3);printf("+============================================+\n");

    Reservation reservation;
    Room room;

    gotoxy(35, 5);printf("Name: ");
    scanf("%s", reservation.name);

    gotoxy(35, 6);printf("Date (MM/DD/YY): ");
    scanf("%s", reservation.date);

    gotoxy(35, 7);printf("Room Type (Standard/Deluxe/Suite): ");
    scanf("%s", reservation.type);

    gotoxy(35, 8);printf("Number of Rooms: ");
    scanf("%d", &reservation.room_num);



    // calculate bill
    float price;
    if (strcmp(reservation.type, "Standard") == 0)
        {
        gotoxy(35, 9);price = 3000.0;
        printf("Standard = 3,000");
        }
    else if (strcmp(reservation.type, "Deluxe") == 0)
        {
        price = 6000.0;
        gotoxy(35, 9);printf("Deluxe = 6,000");
        }
    else if (strcmp(reservation.type, "Suite") == 0)
        {
        price = 10000.0;
        gotoxy(35, 9);printf("Suite = 10,000");
        }
    else{
        gotoxy(35, 10);printf("\t       Invalid room type. Please try again.\n");
        sleep(2); // delay
        return;
    }

    reservation.bill = price * reservation.room_num;

    srand(time(NULL));
    room.id = rand() % 100 + 1; // randomizing Reservation ID number from 1-100


    // save reservation
    save_reservation(reservation, room);
    gotoxy(35, 11);printf("\t       Reservation successful!");
    display_reservation_details(reservation, room);
    getch();
}




void display_reservation_details(Reservation res, Room room)
{
    gotoxy(35, 14);printf("+============================================+\n");
    gotoxy(35, 15);printf("|\t          RESERVATION DETAILS           |\n");
    gotoxy(35, 16);printf("+============================================+\n");
    gotoxy(35, 17);printf("| Room Type |   Date   | No. of Rooms| Price |");
    gotoxy(35, 18);printf("|--------------------------------------------|");
    gotoxy(35, 19);printf("| %8s  | %s | %11d | %2.0f  |", res.type,res.date,res.room_num,res.bill);
    gotoxy(35, 20);printf("|--------------------------------------------|");
    gotoxy(35, 21);printf("| Total Bill:                      %.2f   |",res.bill);
    gotoxy(35, 22);printf("+--------------------------------------------+");
    gotoxy(35, 23);printf("Reservation Room ID: %d",room.id);
    gotoxy(35, 25);printf("\t    Your reservation is complete.");
    gotoxy(35, 26);printf("\t    Get ready to relax and unwind!");
}



void startButton(){
    delay(250);
    for(x = 0; x < 3; x++){
        gotoxy(43, 17 + x);
        for(y = 0; y < 3; y++){
            gotoxy(43, 17 + y);
            if(x == 0){
                for(z = 0; z < 33; z++){
                    delay(3);
                    printf("%c", 178);
                }
            }
            else if(x == 1){
                for(z = 0; z < 33; z++){
                    delay(2);
                    printf("%c", 177);
                }
            }
            else{
                for(z = 0; z < 33; z++){
                    delay(2);
                    printf("%c", 176);
                }
            }
        }
    }
    gotoxy(45, 18);
    printf("%c PRESS ANY KEY TO CONTINUE %c", 176, 176);
    getch();
}



void save_reservation(Reservation res, Room room) // saves in the reservations.txt
{
    FILE* file = fopen(reservation_file, "a"); // a = append
    fprintf(file, "%s %s %s %d %.0f %d\n", res.name, res.date, res.type, res.room_num, res.bill, room.id);
    fclose(file);
    room_Update(res.date, res.type, res.room_num); // room update for availability
}



void save_user(){
 FILE *fp;

    fp = fopen("UsersAcc.txt", "w+");

    if (fp == NULL)
    {
        printf("File not found");
        system("pause");
    }

    else
    {
        for (int i = 0; i <= marker; i++)
        {
            fprintf(fp, "%s\t %s\t\n",lg[i].email,lg[i].pass);
        }
        fclose(fp);
    }

}


void retrieve_reservations() // retrieval for reservations
{
    FILE* file = fopen(reservation_file, "r");
    char line[MAX_NAME_LENGTH + MAX_DATE_LENGTH + MAX_TYPE_LENGTH + 26];

    while (fgets(line, sizeof(line), file))
    {
       Reservation res;
       Room room;
       sscanf(line, "%s %s %s %d %.0f %d", res.name, res.date, res.type, &res.room_num, &res.bill, &room.id);
       display_reservation_details(res, room);
       room_Update(res.date, res.type, res.room_num); // room update for availability
    }
     fclose(file);
}

void retrieve_data() // retrieval
{
    retrieve_user();
    retrieve_reservations();
}



void retrieve_user()
{
    FILE *fp;
    User c;

    fp = fopen("UsersAcc.txt", "r+");
    if (fp == NULL)
    {
       welcome(); //gotoxy(45, 25); printf("Press any key to continue."); getch();
    }
    else
    {
        welcome();
        while (!feof(fp))
        {
            fscanf(fp, "%s %s \n",&c.email,&c.pass);
             decrypt_password(c.pass, 0xFACA);
            addAccount(c);
           //  printf("%s %s \n",lg[0].email, lg[0].pass); getch();

        }
        fclose(fp);
    }
}




void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
