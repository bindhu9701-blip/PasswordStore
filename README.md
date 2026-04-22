# Password Manager in C

A command-line password manager written in C that allows users to securely store and manage credentials using basic encryption, hashing, and backup mechanisms.

## Features

- User Signup & Login system
- Password hashing using SHA-256 (OpenSSL)
- Master key-based encryption (XOR)
- Add, view, search, update, and delete credentials
- Automatic backup creation
- Data integrity check using checksum
- Restore data if corruption is detected

---
##  System Requirements
- GCC compiler (C11 or later recommended)  
- OpenSSL library (`-lssl -lcrypto`)  
- Linux / Unix-based system
- ---
## Build & Run

Make sure OpenSSL is installed.

```bash
make
./password_manager
```

or manually

```bash
gcc *.c -o password_manager -lssl -lcrypto
./password_manager
```
## Usage Flow
1.Start the program\
2.Choose Signup/Login\
3.Enter master key\
4.User menu:
```bash
1. Add Credential
2. View Credentials
3. Search Credential
4. Update Credential
5. Delete Credential
6. Logout
```
### Storage Details
  User file:
  ```bash
users_<username>.csv
```
  Backup:
  ```bash
backup/users_<username>.bak
```
Format:
```bash
website username encrypted_password
```
### Input Limits & Restrictions
```bash
Username length: max ~100 characters
Website name length: max ~100 characters
Password length: max ~100 characters
Master key length: max ~100 characters
```


