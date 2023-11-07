#include <stdio.h>
#include <string.h>

struct user{
char username[20];
char pin[4];
char security_question[50];
char security_answer[20];
};

void view_pin(struct user u)
{
printf("Pin: %s\n", u.pin);
}

void view_security_question(struct user u)
{
printf("Security Question: %s\n", u.security_question);
}

void reset_password(struct user *u)
{
char new_password[20];
printf("Enter new password: \n");
scanf("%s", new_password);
strcpy(u->pin, new_password);
printf("Password reset successful.\n");
}

void reset_profile_password(struct user *u)
{
char new_security_answer[20];
printf("Enter new security answer: \n");
scanf("%s", new_security_answer);
strcpy(u->security_answer, new_security_answer);
printf("Security answer reset successful.\n");
}

int main()
{
int choice;
struct user current_user = {"John Doe", "1234", "What is your favorite color?", "Blue"};
printf("Welcome %s\n", current_user.username);
while(1){
printf("\n1. View Pin\n");
printf("2. View Security Question\n");
printf("3. Reset Password\n");
printf("4. Reset Profile Password\n");
printf("5. Exit\n");
printf("Enter your choice: \n");
scanf("%d", &choice);
switch(choice){
case 1:
view_pin(current_user);
break;
case 2:
view_security_question(current_user);
break;
case 3:
reset_password(&current_user);
break;
case 4:
reset_profile_password(&current_user);
break;
case 5:
return 0;
default:
printf("Invalid choice. Please try again.\n");
break;
}
}
return 0;
}