// including Everything
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// Decliaring all functions
void storing_customer_data();
void display_packages();
void billing();
void slip();
// declairing all necessery variables
char customer_name[30],
    customer_address[100],
    customer_phone_number[15],
    customer_email[30],
    customer_NID[20],
    marital_status[5],
    user_name[5],
    user_password[5],
    file_name[25],
    folder_path[200] = "C:/Users/salma/OneDrive/Desktop/Hotel_Management_System/App/Data/",
    package_selector;
int NID_serial_count, package_number;

// Decliring stucture for custom pakages
struct custom_packages
{
    int room_amount;
    int c_package_number;
    char food_service[5];
    char wifi_service[5];
    bool custom_package_active;
}c_packages;

// decliaring file pointer
FILE *NID_numbers, *counter, *customer_data, *billing_slip;

// main function
int main()
{   
    // designing intro
    printf("*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*    Hotel Management System    *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");

    // getting user name and password
    validity:
    printf("Enter User Name : ");
    gets(user_name);
    printf("Enter Password : ");
    gets(user_password);

    // cheaking validity
    if (user_name[0] == 'H' && user_name[1] == 'o' && user_name[2] == 't' && user_name[3] == 'e' && user_name[4] == 'l' && user_password[0] == 'M' && user_password[1] == 'o' &&  user_password[2] == 't' &&  user_password[3] == 'e' &&  user_password[4] == 'l' && user_password[5] == '\0' && user_name[5] == '\0')
    {
        // designing customer details intro
        printf("\n\n*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
        printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
        printf("*-*-*-*-*-*-*-*        Customer Details       *-*-**-*-*-*-*\n");
        printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
        printf("*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
        
        // calling storing_customer_data function
        storing_customer_data();

        // display Packages
        display_packages();

        // Billing info
        billing();

        // calling bill slip function
        slip();
    }
    else
    {
        // printing error username or password info
        printf("Please Enter The Correct User Name Or Password\n");
        goto validity;
    }
    
    // just wait for ending the pogramm
    getchar();
    return 0;
}

/*
A build in function storing_customer_data for getting user info 
and storing it into the customer_data.txt file
*/ 
void storing_customer_data()
{    
    // getting customer name
    printf("Customer Name : ");
    gets(customer_name);

    // getting customer address
    printf("Customer Address : ");
    gets(customer_address);

    // getting customer phone number
    printf("Customer Phone Number : ");
    gets(customer_phone_number);

    // getting customer e-mail
    printf("Customer E-mail : ");
    gets(customer_email);

    // getting customer NID
    printf("Customer NID : ");
    gets(customer_NID);

    // getting customer marital status
    printf("Marital Status : ");
    gets(marital_status);

    
    // creating file name as indivisuals
    strcpy(file_name, customer_NID);
    strcat(file_name, ".txt");

    // concataning specific folder path
    strcat(folder_path, file_name);

    // Creating file pointer
         counter = fopen("C:/Users/salma/OneDrive/Desktop/Hotel_Management_System/App/Root/counter.txt", "r"), 
         customer_data = fopen(folder_path, "a+");

    // Storing Data
    fprintf(customer_data, "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    fprintf(customer_data, "Name = %s\n", customer_name);
    fprintf(customer_data, "Address = %s\n", customer_address);
    fprintf(customer_data, "Phone = %s\n", customer_phone_number);
    fprintf(customer_data, "E-mail = %s\n", customer_email);
    fprintf(customer_data, "NID = %s\n", customer_NID);
    fprintf(customer_data, "Marital Status = %s\n", marital_status);

    // adding value to NID_serial_count
    fscanf(counter, "%d", &NID_serial_count);
    fclose(counter);

    // updating nid serial 
    NID_numbers = fopen("C:/Users/salma/OneDrive/Desktop/Hotel_Management_System/App/Data/NID_numbers.txt", "a+");
    NID_serial_count = NID_serial_count + 1;
    fprintf(NID_numbers, "NID_%d = %s\n", NID_serial_count, customer_NID);

    // updating new counter to the counter.txt
    counter = fopen("C:/Users/salma/OneDrive/Desktop/Hotel_Management_System/App/Root/counter.txt", "w");
    fprintf(counter, "%d", NID_serial_count);
    fclose(counter);

    // closing files
    fclose(NID_numbers);
    fclose(customer_data);
}

/*
display_packages() is a user defined package mannaging function 
only for displaying package and selecting as user want
*/
void display_packages()
{
    // designing customer details intro
    printf("\n\n*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*        Package Manager        *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
    printf("For build-in Package Hit >> 1\n");    
    printf("For Custom Package Hit >> 2\n");

    //Re directing for wrong answer 
    package:
    printf("Enter : ");
    scanf("%c",&package_selector);
    if (package_selector == '1' || package_selector == '2')
    {
        switch(package_selector)
        {
            case '1':
            {
                c_packages.custom_package_active = false;
                // first and second package 
                printf("*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\t\t*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
                printf("*-*-                               -*-*\t\t*-*-                               -*-*\n");
                printf("*-*-      Package 1: Standard      -*-*\t\t*-*-      Package 2: Student       -*-*\n");
                printf("*-*-                               -*-*\t\t*-*-                               -*-*\n");
                printf("*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\t\t*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
                printf("--Price: 400 Taka per night\t\t\t--Price: 600 Taka per night\n");
                printf("     ------Includes:------\t\t\t\t------Includes:------\n");
                printf("--One standard room\t\t\t\t--One deluxe room with ocean view\n");
                printf("--Complimentary breakfast\t\t\t--Complimentary breakfast\n");
                printf("--Access to fitness center\t\t\t--Access to fitness center and swimming pool\n");
                printf("--Free Wi-Fi\t\t\t\t\t--Free Wi-Fi\n");
                printf("\t\t\t\t\t\t--Complimentary bottle of wine on arrival\n\n");

                // first and second package 
                printf("*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\t\t*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
                printf("*-*-                               -*-*\t\t*-*-                               -*-*\n");
                printf("*-*-      Package 3: Family        -*-*\t\t*-*-      Package 4: Corporate     -*-*\n");
                printf("*-*-                               -*-*\t\t*-*-                               -*-*\n");
                printf("*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\t\t*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
                printf("--Price: 1500 Taka per night\t\t\t--Price: 2300 Taka per night\n");
                printf("     ------Includes:------\t\t\t------Includes:------\n");
                printf("--One executive suite with city view\t\t--Two connecting standard rooms\n");
                printf("--Complimentary breakfast\t\t\t--Complimentary breakfast for four people\n");
                printf("--Access to fitness center and swimming pool\t--Access to fitness center and swimming pool\n");
                printf("--Free Wi-Fi\t\t\t\t\t--Free Wi-Fi\n");
                printf("--Complimentary bottle of champagne\t\t--Complimentary fruit basket on arrival\n");
                printf("--Personalized butler service\n\n");
                
                printf("Hit 1 for Packages 1 >>> Standard\n");
                printf("Hit 2 for Packages 2 >>> Student\n");
                printf("Hit 3 for Packages 3 >>> Family\n");
                printf("Hit 4 for Packages 4 >>> Corporate\n");
                printf("Select the Number of package: ");
                scanf("%d", &package_number);
                printf("Booking Successfull\n");
                break;
            }
            case '2':
            {
                c_packages.custom_package_active = true;
                printf("Enter Custom Packeges Informations :\n");
                printf("Hit 1 for Packages 1 >>> Standard\n");
                printf("Hit 2 for Packages 2 >>> Student\n");
                printf("Hit 3 for Packages 3 >>> Family\n");
                printf("Hit 4 for Packages 4 >>> Corporate\n");
                printf("Select the Number of package: ");
                scanf("%d", &c_packages.c_package_number);
                printf("Number of room : ");
                scanf("%d", &c_packages.room_amount);
                printf("Food Service (y/n): ");
                scanf("%s", &c_packages.food_service);
                printf("WiFI plan (y/n): ");
                scanf("%s", &c_packages.wifi_service);
                printf("Booking Successfull\n");
                break;                   
            }
        }
    }
    else
    {
        printf("Sorry!! Enter 1 or 2 As Say Above\n");
        goto package;
    }
}

/*
billing is a user defined function only for making bill
*/
void billing()
{
    printf("\n\n*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*        Billing Info           *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-*                               *-*-**-*-*-*-*\n");
    printf("*-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
    printf("Here You Go\n");
    customer_data = fopen(folder_path, "a+");
    if (c_packages.custom_package_active == false)
    {
        printf("You have selected a build in package\n");
        printf("Name : %s \n", customer_name);
        printf("Address : %s\n", customer_address);
        printf("Phone Number : %s\n", customer_phone_number);
        printf("E-mail : %s\n", customer_email);
        printf("NID : %s\n", customer_NID);
        printf("Marital Status : %s\n", marital_status);
        if (package_number == 1)
        {
            printf("Package Number : %d (Standard)\n", package_number);
            fprintf(customer_data, "Build in Package Number : %d (Standard)\n", package_number);
            printf("You Have to pay : 400 taka only\n");
            fprintf(customer_data, "You Have to pay : 400 taka only\n");
            fclose(customer_data);
        }
        else if (package_number == 2)
        {
            printf("Package Number : %d (Student)\n", package_number);
            fprintf(customer_data, "Build in Package Number : %d (Student)\n", package_number);
            printf("Package Number : 600 taka only\n");
            fprintf(customer_data, "You have to pay : 600 taka only\n");
            fclose(customer_data);
        }
        else if (package_number == 3)
        {
            printf("Package Number : %d (Family)\n", package_number);
            fprintf(customer_data, "Build in Package Number : %d (Family)\n", package_number);
            printf("Package Number : 1500 taka only\n");
            fprintf(customer_data, "You have to pay : 1500 taka only\n");
            fclose(customer_data);
        }
        else
        {
            printf("Package Number : %d (Corporate)\n", package_number);
            fprintf(customer_data, "Build in Package Number : %d (Corporate)\n", package_number);
            printf("Package Number : 2300 taka only\n");
            fprintf(customer_data, "You have to pay : 2300 taka only\n");
            fclose(customer_data);
        }
    }
    else
    {
        printf("You have selected a Custom package\n");
        printf("Name : %s \n", customer_name);
        printf("Address : %s\n", customer_address);
        printf("Phone Number : %s\n", customer_phone_number);
        printf("E-mail : %s\n", customer_email);
        printf("NID : %s\n", customer_NID);
        printf("Marital Status : %s\n", marital_status);
        if (c_packages.c_package_number == 1)
        {
            printf("Custom Package Number : %d (Standard)\n", c_packages.c_package_number);
            fprintf(customer_data, "Custom Package Number : %d (Standard)\n", c_packages.c_package_number);
            printf("Number of room : %d\n", c_packages.room_amount);
            fprintf(customer_data, "Number of room : %d\n", c_packages.room_amount);
            printf("Food Service : %s\n", c_packages.food_service);
            fprintf(customer_data, "Food Service : %s\n", c_packages.food_service);
            printf("WiFI plan : %s\n", c_packages.wifi_service);
            fprintf(customer_data, "WiFI plan : %s\n", c_packages.wifi_service);
            printf("You Have to pay : 800 taka only\n");
            fprintf(customer_data, "You Have to pay : 800 taka only\n");
            fclose(customer_data);
        }
        else if (c_packages.c_package_number == 2)
        {
            printf("Custom Package Number : %d (Student)\n", c_packages.c_package_number);
            fprintf(customer_data, "Custom Package Number : %d (Student)\n", c_packages.c_package_number);
            printf("Number of room : %d\nn", c_packages.room_amount);
            fprintf(customer_data, "Number of room : %d\nn", c_packages.room_amount);
            printf("Food Service : %s\n", c_packages.food_service);
            fprintf(customer_data, "Food Service : %s\n", c_packages.food_service);
            printf("WiFI plan : %s\n", c_packages.wifi_service);
            fprintf(customer_data, "WiFI plan : %s\n", c_packages.wifi_service);
            printf("Package Number : 1000 taka only\n");
            fprintf(customer_data, "You have to pay : 1000 taka only\n");
            fclose(customer_data);
        }
        else if (c_packages.c_package_number == 3)
        {
            printf("Custom Package Number : %d (Family)\n", c_packages.c_package_number);
            fprintf(customer_data, "Custom Package Number : %d (Family)\n", c_packages.c_package_number);
            printf("Number of room : %d\n", c_packages.room_amount);
            fprintf(customer_data, "Number of room : %d\n", c_packages.room_amount);
            printf("Food Service : %s\n", c_packages.food_service);
            fprintf(customer_data, "Food Service : %s\n", c_packages.food_service);
            printf("WiFI plan : %s\n", c_packages.wifi_service);
            fprintf(customer_data, "WiFI plan : %s\n", c_packages.wifi_service);
            printf("Package Number : 2000 taka only\n");
            fprintf(customer_data, "You have to pay : 2000 taka only\n");
            fclose(customer_data);
        }
        else
        {
            printf("Custom Package Number : %d (Corporate)\n", c_packages.c_package_number);
            fprintf(customer_data, "Custom Package Number : %d (Corporate)\n", c_packages.c_package_number);
            printf("Number of room : %d\n", c_packages.room_amount);
            fprintf(customer_data, "Number of room : %d\n", c_packages.room_amount);
            printf("Food Service : %s\n", c_packages.food_service);
            fprintf(customer_data, "Food Service : %s\n", c_packages.food_service);
            printf("WiFI plan : %s\n", c_packages.wifi_service);
            fprintf(customer_data, "WiFI plan : %s\n", c_packages.wifi_service);
            printf("Package Number : 4000 taka only\n");
            fprintf(customer_data, "You have to pay : 4000 taka only\n");
            fclose(customer_data);
        }        
    }   
    customer_data = fopen(folder_path, "a+");
    fprintf(customer_data, "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n");
    fclose(customer_data);
}

/**
 * this is a function for making a payment slip for user
 * using hltm and css
 */
void slip()
{
    // creating slip file path
    char slip_path[100] = "C:/Users/salma/OneDrive/Desktop/Hotel_Management_System/App/Slip/";
    char slip_file_extention[8] = ".html";
    char ID[20];
    strcat(ID, customer_NID);
    strcat(customer_NID, slip_file_extention);
    strcat(slip_path, customer_NID);

    // oppenning file
    billing_slip = fopen(slip_path, "w");

    // writing css
    fprintf(billing_slip, "<head><style>body{font-family: Arial, sans-serif;display: flex;justify-content: center;align-items: center;height: 100vh;}.billing-slip{width: 400px;border: 1px solid #ccc;padding: 20px;background-color: #f9f9f9;}h4{text-align: center;}p{margin-bottom: 5px;}b{font-weight: bold;}.billing-slip p:last-child{margin-bottom: 0;}</style></head>");

    // writing a div with class billing-slip
    fprintf(billing_slip, "<div class=\"billing-slip\">");
    
    // writing all html
    fprintf(billing_slip, "<h4>___Billing Slip___</h4><p><b>Name : %s</b></p><p><b>Address : %s</b></p><p><b>Phone : %s</b></p><p><b>E-mail : %s</b></p><p><b>NID : %s</b></p>", customer_name, customer_address, customer_phone_number, customer_email, ID);
    
    // condition chk for pakage number and pay info
    if (c_packages.custom_package_active == false)
    {
        if (package_number == 1)
        {
            fprintf(billing_slip, "<p><b>Build in Package Number : %d (Standard)</b></p>", package_number);
            fprintf(billing_slip, "<p><b>You Have to pay : 400 taka only</b></p>");
            fclose(billing_slip);
        }
        else if (package_number == 2)
        {
            fprintf(billing_slip, "<p><b>Build in Package Number : %d (Student)</b></p>", package_number);
            fprintf(billing_slip, "<p><b>You have to pay : 600 taka only</b></p>");
            fclose(billing_slip);
        }
        else if (package_number == 3)
        {
            fprintf(billing_slip, "<p><b>Build in Package Number : %d (Family)</b></p>", package_number);
            fprintf(billing_slip, "<p><b>You have to pay : 1500 taka only</b></p>");
            fclose(billing_slip);
        }
        else
        {
            fprintf(billing_slip, "<p><b>Build in Package Number : %d (Corporate)</b></p>", package_number);
            fprintf(billing_slip, "<p><b>You have to pay : 2300 taka only</b></p>");
            fclose(billing_slip);
        }    
    }
    else
    {
        if (c_packages.c_package_number == 1)
        {
            fprintf(billing_slip, "<p><b>Custom Package Number : %d (Standard)</b></p>", c_packages.c_package_number);
            fprintf(billing_slip, "<p><b>Number of room : %d</b></p>", c_packages.room_amount);
            fprintf(billing_slip, "<p><b>Food Service : %s</b></p>", c_packages.food_service);
            fprintf(billing_slip, "<p><b>WiFI plan : %s</b></p>", c_packages.wifi_service);
            fprintf(billing_slip, "<p><b>You Have to pay : 800 taka only</b></p>");
            fclose(billing_slip);
        }
        else if (c_packages.c_package_number == 2)
        {
            fprintf(billing_slip, "<p><b>Custom Package Number : %d (Student)</b></p>", c_packages.c_package_number);
            fprintf(billing_slip, "<p><b>Number of room : %d</b></p>", c_packages.room_amount);
            fprintf(billing_slip, "<p><b>Food Service : %s</b></p>", c_packages.food_service);
            fprintf(billing_slip, "<p><b>WiFI plan : %s</b></p>", c_packages.wifi_service);
            fprintf(billing_slip, "<p><b>You Have to pay : 1000 taka only</b></p>");
            fclose(billing_slip);
        }
        else if (c_packages.c_package_number == 3)
        {
            fprintf(billing_slip, "<p><b>Custom Package Number : %d (Family)</b></p>", c_packages.c_package_number);
            fprintf(billing_slip, "<p><b>Number of room : %d</b></p>", c_packages.room_amount);
            fprintf(billing_slip, "<p><b>Food Service : %s</b></p>", c_packages.food_service);
            fprintf(billing_slip, "<p><b>WiFI plan : %s</b></p>", c_packages.wifi_service);
            fprintf(billing_slip, "<p><b>You Have to pay : 2000 taka only</b></p>");
            fclose(billing_slip);
        }
        else
        {
            fprintf(billing_slip, "<p><b>Custom Package Number : %d (Corporate)</b></p>", c_packages.c_package_number);
            fprintf(billing_slip, "<p><b>Number of room : %d</b></p>", c_packages.room_amount);
            fprintf(billing_slip, "<p><b>Food Service : %s</b></p>", c_packages.food_service);
            fprintf(billing_slip, "<p><b>WiFI plan : %s</b></p>", c_packages.wifi_service);
            fprintf(billing_slip, "<p><b>You Have to pay : 4000 taka only</b></p>");
            fclose(billing_slip);
        }           
    }
    
    
    

    // againg open file in appened mode
    fopen(slip_path, "a");

    // closing the div
    fprintf(billing_slip, "</div>");

    // closing the file
    fclose(billing_slip);
}