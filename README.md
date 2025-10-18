# Bank Project by OOP

## Project Description
This project is written in **C++** using **Object-Oriented Programming (OOP)** concepts.  
**Note:** The project uses features specific to **Visual Studio 2022**, such as `__declspec(property)`, and will **not compile** with other compilers like g++.

## Requirements
- Visual Studio 2022 on Windows.

## How to Run
1. Open Visual Studio 2022.
2. Create a **new empty C++ project**.
3. Copy the contents of `Main.cpp` from this repository and **paste it into the main project file** in Visual Studio.
4. Copy all the header files (`.h`) from this repository into the project folder in Visual Studio.  
   - Place them in the **same folder as the project** or in a subfolder if you prefer.
5. Build the project.
6. Run the program.

## Project Files
- `Main.cpp`
- Header files (`.h`) such as:
  - `clsBankClient.h`
  - `clsBankUser.h`
  - `clsPerson.h`
  - `clsScreen.h`
  - `clsMainScreen.h`
  - `clsManageUserScreen.h`
  - `clsTransactionsScreen.h`
  - `ShowLoginScreen.h`
  - `UI_Operations_Client.h`
  - `UI_Operations_User.h`
  - `clsInputValidate.h`
  - `Global.h`
- Data files (`.txt`) such as `Clients.txt` and `Users.txt`.

## Notes
- Do **not** attempt to compile this project using g++ or other non-MSVC compilers.  
- Make sure all header files are **inside the project folder** or a subfolder included in the project.  
- After pasting `Main.cpp` and header files, **build and run the program in Visual Studio 2022**.

<<<<<<< HEAD
## Login
- To Login use
- Username: Admin
- Password: 12345
=======
## Login 
- To Login use 
- Username: Admin
- Password: 12345

README - Currency Rate Update

_________________________________________________
How to Enable Option 5 - Update All Currency Rate:

 ## 1. Get an API Key
   - Visit https://www.exchangerate-api.com.
   - Create a free account.
   - Copy your personal API Key.

## 2. Update the Code
   - Locate this line in the 'PYthon1EXEGEtRate.py':
     url = f"https://v6.exchangerate-api.com/v6/Your_Key/latest/{currency}"
   - Replace Your_Key with your actual API key, for example:
     url = f"https://v6.exchangerate-api.com/v6/1234567890abcdef/latest/{currency}"

## 3. Run the Currency Update Option
   - Start the program.
   - Choose Option 5 - Update Currency Rate.
   - The program will fetch the latest currency rates automatically using the API.

## Notes:
- Make sure you have an active internet connection when using this option.
- Free API keys may have a daily request limit. Check your account limits.
- If the update fails, verify that your API key is correct and the URL is properly formatted.

 ## Watch the Video:
 
[![Watch the Video](https://img.youtube.com/vi/6Y2wJ13BG0o/0.jpg)](https://youtu.be/6Y2wJ13BG0o?si=zan0HWLVOPJNqEjv)

______________________________________________________________________________________________
>>>>>>> 3d774c1 (Update banking headers, README, and add currency exchange files)
