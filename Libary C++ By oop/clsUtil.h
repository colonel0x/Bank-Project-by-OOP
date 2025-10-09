#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
class clsUtility
{

 
public: 

   
    
  static  string EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }
  static  string DecryptText(string Text, short EncryptionKey)
    {
       for (int i = 0; i <= Text.length(); i++)
        {
           Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text; 
    }
  static  void Srand()
    {
        srand((unsigned)time(NULL));


    }
  static  int RandomNumber(int From, int To)
    {
        
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
  static  enum enCharType {
        SamallLetter = 1,    
        CapitalLetter = 2,   
        SpecialCharacter = 3,
        Digit = 4            
    };
  static  char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;  
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        }

        return '\0';
    }
  static  string GenerateWord(enCharType CharType, short Length)
    {
        string Word; 
    
        for (int i = 1; i <= Length; i++)
        {
           
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }
  static string  GenerateKey(enCharType CharType = CapitalLetter)
  {

      string Key = "";


      Key = GenerateWord(CharType, 4) + "-";
      Key = Key + GenerateWord(CharType, 4) + "-";
      Key = Key + GenerateWord(CharType, 4) + "-";
      Key = Key + GenerateWord(CharType, 4);


      return Key;
  }
  static  void GenerateKeys(short NumberOfKeys)
    {
      
        for (int i = 1; i <= NumberOfKeys; i++)
        {

            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }
  static  void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;  
       
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }
  static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
  {
      for (int i = 0; i < arrLength; i++)
          arr[i] = GenerateWord(CharType, Wordlength);

  }
  static  int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0; 
        for (int i = 0; i < arrLength; i++)
        {
          
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }
  static  int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];  // Initialize Min with the first element of the array.

        // Loop through the array to find the smallest element.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is less than the current minimum, update Min.
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;  // Return the minimum value found.
    }
  static  int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;  

        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }

        return Sum;  
    }
  static  float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }
  static  void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        // Loop through each element up to arrLength and copy from source to destination.
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }
  static  enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
  static  enPrimNotPrime CheckPrime(int Number)
    {
     
        int M = round(Number / 2);

       
        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
                return enPrimNotPrime::NotPrime;  
        }

        return enPrimNotPrime::Prime;
    }
  static  void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
    {
        int Counter = 0;  

        for (int i = 0; i < arrLength; i++)
        {
            if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;  
            }
        }

       
        arr2Lenght = --Counter;
    }
  static  void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i]; 
        }
    }
  static  void Swap(int& A, int& B)
    {
        int Temp;  
        Temp = A;  
        A = B;     
        B = Temp;  
    }
  static  void Swap(double& A, double& B)
  {
      double Temp;

      Temp = A;
      A = B;
      B = Temp;
  }
  static  void Swap(bool& A, bool& B)
  {
      bool Temp;

      Temp = A;
      A = B;
      B = Temp;
  }
  static  void Swap(char& A, char& B)
  {
      char Temp;

      Temp = A;
      A = B;
      B = Temp;
  }
  static  void Swap(string& A, string& B)
  {
      string Temp;

      Temp = A;
      A = B;
      B = Temp;
  }
  static  void ShuffleArray(int arr[100], int arrLength){
        
        for (int i = 0; i < arrLength; i++)
        {
          
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
         
            Swap(arr[index1], arr[index2]);
        }
    }
  static  void ShuffleArray(string arr[100], int arrLength)
  {

      for (int i = 0; i < arrLength; i++)
      {
          Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
      }

  }
  static  void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }
  static string  Tabs(short NumberOfTabs)
  {
      string t = "";

      for (int i = 1; i < NumberOfTabs; i++)
      {
          t = t + "\t";
          cout << t;
      }
      return t;

  }
  static  void FillArrayWithKeys(string arr[100], int arrLength)
    {


        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();


    }
  static  void PrintStringArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";

        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n"; 
    }
  static  short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i; 
        }

        // If the loop completes without finding the number, return -1.
        return -1;
    }
  static  bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {

        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }
  static string NumberToText(int Number)
  {

      if (Number == 0)
      {
          return "";
      }

      if (Number >= 1 && Number <= 19)
      {
          string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
      "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
        "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

          return  arr[Number] + " ";

      }

      if (Number >= 20 && Number <= 99)
      {
          string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
          return  arr[Number / 10] + " " + NumberToText(Number % 10);
      }

      if (Number >= 100 && Number <= 199)
      {
          return  "One Hundred " + NumberToText(Number % 100);
      }

      if (Number >= 200 && Number <= 999)
      {
          return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
      }

      if (Number >= 1000 && Number <= 1999)
      {
          return  "One Thousand " + NumberToText(Number % 1000);
      }

      if (Number >= 2000 && Number <= 999999)
      {
          return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
      }

      if (Number >= 1000000 && Number <= 1999999)
      {
          return  "One Million " + NumberToText(Number % 1000000);
      }

      if (Number >= 2000000 && Number <= 999999999)
      {
          return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
      }

      if (Number >= 1000000000 && Number <= 1999999999)
      {
          return  "One Billion " + NumberToText(Number % 1000000000);
      }
      else
      {
          return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
      }


  }
  static string Tab(short HowManyTap)
  {
      cout << "\n";
      for (short i = 0; i < HowManyTap; i++)
      {
          cout << "\t";
      }
      return "";
  }




};

