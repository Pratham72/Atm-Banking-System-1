#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 150

int withdraw(float balance);
int deposit(float balance);
int show_balance(float balance);
void new_atm();
void process();
float balance = 30000.98;

int main()
{
    int choice;
    int password;
    char buf[LEN];
    time_t curtime;
    struct tm *loc_time;
    printf("*********************************************************************************************************************\n");
    printf("                                         Welcome to ATM Banking System                                               \n");
    printf("*********************************************************************************************************************\n");
    printf("Enter your atm pin here: ");
    scanf("%d",&password);
    if(password==6534)
    {
         printf("Access granted\n\n");
         printf(" 1.Amount Withdraw\n 2.Show Available Balance\n 3.Registration of new ATM card\n 4.Deposit\n 5.Exit\n");
         printf("\n\nEnter what you want to perform: ");
         scanf("%d",&choice);
    }
    else
    {
        printf("Access denied\n\n");
        exit(0);
    }

    switch(choice)
    {
    case 1:
            system("CLS");
            balance = withdraw(balance);
            printf("\n\n");
            process();
          break;
    case 2:
            system("CLS");
            balance = show_balance(balance);
            printf("\n\n");
            process();
        break;
    case 3:
            system("CLS");
            new_atm();
            printf("\n\n");
            process();
            break;
    case 4:
            system("CLS");
            balance = deposit(balance);
            printf("\n\n");
            process();
        break;
    case 5:
        printf("******************************Please Collect you receipt****************************\n\n");
        curtime = time (NULL);
        loc_time = localtime (&curtime);
        printf("%s", asctime (loc_time));
        strftime (buf, LEN, "Today is %A, %b %d.\n", loc_time);
        fputs (buf, stdout);
        strftime (buf, LEN, "Time is %I:%M %p.\n", loc_time);
        fputs (buf, stdout);
        exit(0);
        break;
    }
    return 0;
}

int withdraw(float balance)
{
    float withdraw;
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);
    if (withdraw < balance)
    {
        balance -= withdraw;
        printf("\n$$$$Your withdrawing money is:  $%.2f\n", withdraw);
        printf("****Your New Balance is:   $%.2f\n\n", balance);
    }
    else
    {
        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("****Your Balance is:   $%.2f\n\n", balance);
    }
    return balance;
}
 int show_balance(float balance)
 {
     printf("Available balance: %f",balance);
 }

 void new_atm()
 {
     int otp;
     int pin1,pin2;
     printf("Enter the 4 digit OTP: ");
     scanf("%d",&otp);
     printf("Enter new PIN: ");
     scanf("%d",&pin1);
     printf("Re-enter the PIN: ");
     scanf("%d",&pin2);
     if(pin1==pin2)
        printf("Registration successful\n");
     else
     {
        printf("PIN doesn't match\n");
        printf("Please try again\n\n");
     }
 }

 int deposit(float balance)
 {
    float deposit;
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);
    balance += deposit;
    printf("\n****Your New Balance is:   $%.2f\n\n", balance);
    return balance;
 }

 void process()
 {
     char choice;
     printf("Do you want to continue the process? (y/n): ");
     fflush(stdin);
     scanf("%c",&choice);
     if(choice=='Y' || choice=='y')
     {
         system("CLS");
         main();
     }
     else
        exit(0);
 }
