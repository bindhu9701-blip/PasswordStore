#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Passwords.h"

int checkUser(char *username)
{
    // Check whether username exists or not
    char *user = malloc(MAX);
    char *pwd = malloc(MAX);
    FILE *fptr = fopen("users.csv", "r");
    while (fscanf(fptr, "%s%s", user, pwd) == 2)
    {
        if (strcmp(user, username) == 0)
        {
            free(user);
            free(pwd);
            fclose(fptr);
            return 1;
        }
    }
    free(user);
    free(pwd);
    fclose(fptr);
    return 0;
}
int CheckLoginDetails(char *username, char *pwd)
{
    // If pwd and username matches return 1;
    FILE *fptr = fopen("users.csv", "r");
    char *id = malloc(MAX);
    char *pass = malloc(MAX);
    while (fscanf(fptr, "%s%s", id, pass) == 2)
    {
        char *hash_pwd = malloc(65);
        hashPassword(pwd, hash_pwd);
        if (strcmp(username, id) == 0 && strcmp(pass, hash_pwd) == 0)
        {
            fclose(fptr);
            free(id);
            free(pass);
            free(hash_pwd);
            return 1;
        }
        free(hash_pwd);
    }
    fclose(fptr);
    free(id);
    free(pass);
    return 0;
}
int signup()
{
    // Signup for new users
    FILE *fptr = fopen("users.csv", "a");
    printf("Enter Username : ");
    char id[MAX], pwd[MAX];
    scanf("%s", id);
    int isfound = checkUser(id);
    if (!isfound)
    {
        printf("Enter Password: ");
        scanf("%s", pwd);
        char *hash_pwd = malloc(65);
        hashPassword(pwd, hash_pwd);
        fprintf(fptr, "%s %s\n", id, hash_pwd);
        printf("----SigUp Completed!!----\n");
        free(hash_pwd);
    }
    else
        printf("This Username already exists !!\n");
    fclose(fptr);
    return 1;
}
int login(char *username)
{
    // To get credentials
    printf("Enter your details: \nUsername: ");
    char *pwd = malloc(MAX);
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", pwd);
    char *file = malloc(MAX);
    strcpy(file, "users.csv");
    FILE *fptr = fopen(file, "a");
    if (fptr == NULL)
    {
        perror("FILE IS NOT CREATED\n");
        exit(1);
    }
    int isfound = CheckLoginDetails(username, pwd);
    free(pwd);
    free(file);
    if (isfound)
        return 1;
    return 0;
}
void Logout(char *username)
{
    // To delete their account
    char *file = malloc(MAX);
    char *temp = malloc(MAX);
    printf("Type your Username :");
    scanf("%s", username);
    strcpy(file, "users.csv");
    sprintf(temp, "temp.csv");
    char *id = malloc(MAX);
    char *pwd = malloc(MAX);
    FILE *fptr = fopen(file, "r");
    FILE *ftmp = fopen(temp, "w");
    while (fscanf(fptr, "%s%s", id, pwd) == 2)
    {
        if (strcmp(username, id) != 0)
            fprintf(ftmp, "%s %s\n", id, pwd);
    }
    char *userfile = malloc(MAX);
    char *userbackupfile = malloc(MAX);
    sprintf(userfile, "users_%s.csv", username);
    sprintf(userbackupfile, "./backup/users_%s.bak", username);
    fclose(fptr);
    fclose(ftmp);
    remove(userfile);
    remove(userbackupfile);
    remove(file);
    rename(temp, file);
    free(file);
    free(id);
    free(pwd);
    free(temp);
    free(userbackupfile);
    free(userfile);
}
