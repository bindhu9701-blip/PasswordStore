#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include "Passwords.h"
#include <string.h>

void hashPassword(const char *password, char output[65])
{
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256((unsigned char *)password, strlen(password), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }

    output[64] = '\0';
}
void EncryptDecrypt(unsigned char *pwd, int len, unsigned char *key, int key_len)
{

    for (int i = 0; i < len; i++)
        pwd[i] = pwd[i] ^ key[i % (strlen(key))];
}
void bytesToHex(unsigned char *data, int len, char *hex)
{
    for (int i = 0; i < len; i++)
    {
        sprintf(hex + (i * 2), "%02X", data[i]);
    }
    hex[len * 2] = '\0';
}
int hexToBytes(char *hex, unsigned char *data)
{
    int len = strlen(hex);
    int res = len / 2;

    for (int i = 0; i < res; i++)
    {
        sscanf(hex + (i * 2), "%2hhX", &data[i]);
    }

    return res;
}