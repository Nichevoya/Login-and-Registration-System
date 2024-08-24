# Login and Registration System (LARS)

LARS is a simple system which allows the user to register an account and login with the registered credentials. It is a command line application and several commands are predefined.

- help - It explains the purpose of the application as well as displaying the available commands

- quit - Gracefully exit the application

## Registration

With the registration option, several steps will take place. The system will ask you a **username** and for a **password** and its verification.

- On successful registration, a text file will be created with the given credentials. You will then be returned to the main menu.

- On unsuccessful registration, you will be asked if you want to retry. Depending of your choice, you will either restart the registration process or return to the main menu.

## Login

With the login option, two simple steps will take place. The system will ask for your **registered** username and password.

- On successful login, the application will stop

- On unsuccessful login, you will be returned to the main menu

## How to run

```shell
./lars --help
Description:
  User credentials like usernames and passwords are asked from the user.
  If the registration of the user is successful, then with the given credentials a file will be created of a particular user in the database.
Usage:
  lars [OPTION...]

  -h, --help  Print usage and display the available options

```
