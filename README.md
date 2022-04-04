# My Clinic
It's a console application of a clinic management system. It can be used to manage records of doctors, patients, medical services, and medical appointments of a clinic.

## How it works
When you build and open the program, you'll get a login screen that requires a username and a password. You can enter the default credentials as following, username: `admin` and password: `1234`. Once you login, you'll get a welcome screen with a list of available options that you can use by name or number. Each option has a specific function. Enter the option name or number in the console to take an action. Here's a list of the available options that you can use:

- `1. display doctors`: display a list of all doctors added to the database.

- `2. display doctor`: display a specific doctor's info based on a given id that you can get from displaying all doctors.

- `3. add doctor`: add a new doctor's info to the database.

- `4. edit doctor`: to edit a specific doctor's info based on a given id.

- `5. delete doctor`: to delete a specific doctor based on a given id.

- `6. display patients`: display a list of all patients added to the database.

- `7. display patient`: display a specific patient's info based on a given id that you can get from displaying all patients.

- `8. add patient`: add a new patient's info to the database.

- `9. edit patient`: to edit a specific patient's info based on a given id.

- `10. delete patient`: to delete a specific patient based on a given id.

- `11. display services`: display a list of all services added to the database.

- `12. display service`: display a specific service details based on a given id that you can get from displaying all services.

- `13. add service`: add a new service details to the database.

- `14. edit service`: to edit a specific service details based on a given id.

- `15. delete service`: to delete a specific service based on a given id.

- `16. display appointments`: display a list of all appointments added to the database.

- `17. display appointment`: display a specific appointment details based on a given id that you can get from displaying all appointments.

- `18. add appointment`: add a new appointment details to the database.

- `19. edit appointment`: to edit a specific appointment details based on a given id.

- `20. delete appointment`: to delete a specific appointment based on a given id.

- `21. edit account password`: to change the default password to a new one.

- `22. help`: to display this menu of available options.

- `23. clear`: to clear the console screen.

- `24. exit`: to logout of the program.

## The project structure
- `include/`: this is for the project header files.

- `src/`: this is for the project source files.

## Dependencies
- `sqlite3`: It's the library or engine that's used for handling the database file that `My Clinic` uses for storing its data. Make sure you download the amalgamation version of it from here: [sqlite-amalgamation-3380200.zip](https://www.sqlite.org/2022/sqlite-amalgamation-3380200.zip). After downloading the file and unzipping it, get the header file *"sqlite3.h"* and add it to the directory *"include/"*, then get the source file *"sqlite3.c"* and add it to the directory *"src/"*.

## Environment where tested
- `IDE`: Visual Studio 2019.

- `C++ Language Standard`: ISO C++20 Standard (/std:c++20)

- `Operating system`: Windows 10, 64-bit.

## You can improve it
You can use the source code as you like. If you have any suggestions or ideas for improving the project, don't hesitate to share them with us.
