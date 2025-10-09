#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class clsString
{



public:

	
	class clsStr_Change_Letter_UpperLower_Fun
	{
	

	private:

		string _Text;
		char _Letter;
	public:

		clsStr_Change_Letter_UpperLower_Fun(string _Text, char _Letter)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;

		}
		clsStr_Change_Letter_UpperLower_Fun()
		{
		

			this->_Text = "";
			this->_Letter = 0;

		}

		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}

	void PrintFirstLetter()
		{

			bool IsFirstLetter = true;

			for (short i = 0; i < _Text.length(); i++)
			{

				if (_Text[i] != ' ' && IsFirstLetter)
				{
					cout << _Text[i] << endl;

				}

				IsFirstLetter = (_Text[i] == ' ') ? true : false;
			}

		}
	void ChangeStringToUpper_FirstLetter()
	{

		bool IsFirstLetter = true;

		for (short i = 0; i < _Text.length(); i++)
		{

			if (_Text[i] != ' ' && IsFirstLetter)
			{

				_Text[i] = toupper(_Text[i]);
			}

			IsFirstLetter = (_Text[i] == ' ') ? true : false;
		}

	}
	void ChangeStringToLower_FirstLetter()
	{

		bool IsFirstLetter = true;

		for (short i = 0; i < _Text.length(); i++)
		{

			if (_Text[i] != ' ' && IsFirstLetter)
			{

				_Text[i] = tolower(_Text[i]);
			}

			IsFirstLetter = (_Text[i] == ' ') ? true : false;
		}

	}
	void ChangeStringToUpper()
	{

		bool IsFirstLetter;

		for (short i = 0; i < _Text.length(); i++)
		{
			IsFirstLetter = (_Text[i] != ' ') ? true : false;

			if (_Text[i] != ' ' && IsFirstLetter)
			{

				_Text[i] = toupper(_Text[i]);
			}


		}

	}
	void ChangeStringToLower()
	{

		bool IsFirstLetter = true;

		for (short i = 0; i < _Text.length(); i++)
		{

			IsFirstLetter = (_Text[i] != ' ') ? true : false;

			if (_Text[i] != ' ' && IsFirstLetter)
			{

				_Text[i] = tolower(_Text[i]);
			}

		}

	}



		__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;

	
	};
    class clsStr_SwitchString_Fun
	{
	private:

		string _Text;
		char _Letter;
	public:

		clsStr_SwitchString_Fun(string _Text, char _Letter)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;

		}
		clsStr_SwitchString_Fun()
		{
			this->_Text = "";
			this->_Letter = 0;

		}

		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}


    void Switch_CharLetter_Upper_OR_Lower()
	{


		if (isupper(_Letter))
		{
			_Letter = tolower(_Letter);
		}
		else
		{
			_Letter = toupper(_Letter);
		}


	}
	char GetCharAfterSwitch()
	{
		char CharEmpatyNew = 0;

		Switch_CharLetter_Upper_OR_Lower();
		CharEmpatyNew = _Letter;
		Switch_CharLetter_Upper_OR_Lower();
		return CharEmpatyNew;


	}//
	void ConvertLettersCase()
	{

		for (short i = 0; i < _Text.length(); i++)
		{

			if (_Text[i] != ' ')
			{
				_Letter = _Text[i];
				Switch_CharLetter_Upper_OR_Lower();
				_Text[i] = _Letter;
			}

		}

	}



		__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;

	
};
	class clsStr_Count_LowerUpper_Fun
	{
	
	private:

		string _Text;
		char _Letter;
	public:

		clsStr_Count_LowerUpper_Fun(string _Text, char _Letter)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;

		}
		clsStr_Count_LowerUpper_Fun()
		{
			_Text = "";
			_Letter = 0;
		
		}


		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}

	short CountLengthString()
	{



		return _Text.length();

	}
	short CountCapitalLetter()
	{

		short CountCapital = 0;
		for (short i = 0; i < _Text.length(); i++)
		{
			if (_Text[i] != ' ' && isupper(_Text[i]))
			{

				CountCapital++;

			}


		}


		return CountCapital;

	}
	short CountLowerLetter()
	{

		short CountCapital = 0;
		for (short i = 0; i < _Text.length(); i++)
		{
			if (_Text[i] != ' ' && islower(_Text[i]))
			{

				CountCapital++;

			}


		}


		return CountCapital;

	}
	short CountLetterInString()
	{
		short CountLetter = 0;
		for (short i = 0; i < _Text.length(); i++)
		{

			if (_Letter == _Text[i])
			{

				CountLetter++;

			}

		}
		return CountLetter;


	}
	short CountUpperAndLowerLetter()
	{
		short  Counter = 0;

		_Letter = tolower(_Letter);
		Counter = CountLetterInString();

		_Letter = toupper(_Letter);
		Counter += CountLetterInString();

		return Counter;

	}



		__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;

	};
	class clsStr_Vowels_Fun
	{
	private:

		string _Text;
		char _Letter;
		string _TemporaryText;
		char _TemporaryLetter;


	public:

		clsStr_Vowels_Fun(string _Text, char _Letter,string _TemporaryText  = "",char _TemporaryLetter = 0)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;
			this->_TemporaryText = _TemporaryText;
			this->_TemporaryLetter = _TemporaryLetter;

		}
		clsStr_Vowels_Fun()
		{
			_Text = "";
			_Letter = 0;
			_TemporaryText = "";
			_TemporaryLetter = 0;
		}



		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}




bool CheckFromCharIfVowelLetter()
	{

		char Array[5] = { 'a','e','i','o','u' };

		for (int i = 0; i < 5; i++)
		{

			if (Array[i] == _Letter)
			{
				return true;
			}

		}

		return false;


	}
bool CountVowel_LettersInString(char TemporaryLetter = 0)
{

	char Array[5] = { 'a','e','i','o','u' };

	for (short i = 0; i < 5; i++)
	{

		if (Array[i] == tolower(TemporaryLetter))
		{
			return true;
		}

	}

	return false;


}
void IsVowel()
{

	if (CheckFromCharIfVowelLetter())
	{
		cout << "Yes letter '" << _Letter << "' Vowel" << endl;
		return;

	}
	else
	{
		cout << "No letter '" << _Letter << "' is Not Vowel!!" << endl;
		return;

	}

}
void GetNumberOfVowelsInString()
{

	short Counter = 0;

	for (short i = 0; i < _Text.length(); i++)
	{

		if (CountVowel_LettersInString(_Text[i]))
		{

			Counter++;

		}

	}


	cout << "Number of vowels is: " << Counter;

}
void PrintAllVowelsLettersString()
{


	for (short i = 0; i < _Text.length(); i++)
	{

		if (CountVowel_LettersInString(_Text[i]))
		{
			cout << _Text[i] << "    ";

		}

	}

}
void PrintEachWordFromString()
{

	string space = " ";
	short POS = 0;
	string Word = "";
	_TemporaryText = _Text;

	cout << "Your string words are:\n\n";
	while (((POS = _TemporaryText.find(space)) != std::string::npos))
	{


		Word = _TemporaryText.substr(0, POS);
		cout << Word << endl;
		_TemporaryText.erase(0, POS + 1);



	}

	if (_TemporaryText != "")
	{
		Word = _TemporaryText.substr(0, POS);
		cout << Word << endl;
		_TemporaryText.erase(0, POS);

	}

}


		__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;

	};
	
	
	
	class clsStr_Splits_Fun {
	
	private:

		string _Text;
		char _Letter;
		string _TemporaryText;
		char   _TemporaryLetter;


	public:


		clsStr_Splits_Fun(string _Text, char _Letter,string _TemporaryText= "", char _TemporaryLetter = 0)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;
			this->_TemporaryText = _TemporaryText;
			this->_TemporaryLetter = _TemporaryLetter;

		}
		clsStr_Splits_Fun()
		{
			_Text = "";
			_Letter = 0;
			_TemporaryText = "";
			_TemporaryLetter = 0;
		}





		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}
__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;



short CountEachWordFromString()
		{

			string space = " ";
			short POS = 0;
			string Word = "";
			short TempCounterNumber = 0;
			_TemporaryText = _Text;

			while (((POS = _TemporaryText.find(space)) != std::string::npos))
			{


				Word = _TemporaryText.substr(0, POS);
				TempCounterNumber++;
				_TemporaryText.erase(0, POS + 1);



			}

			if (_TemporaryText != "")
			{
				Word = _TemporaryText.substr(0, POS);
				TempCounterNumber++;
				_TemporaryText.erase(0, POS);

			};

			return TempCounterNumber;




};
vector<string> SplitStringRecord(string space = "#//#")
{


	vector <string> vStringVector;
	short POS = 0;
	string Word = "";
	_TemporaryText = _Text;

	while (((POS = _TemporaryText.find(space)) != std::string::npos))
	{


		Word = _TemporaryText.substr(0, POS);
		vStringVector.push_back(Word);
		_TemporaryText.erase(0, POS + 1);



	}

	if (_TemporaryText != "")
	{
		Word = _TemporaryText.substr(0, POS);
		vStringVector.push_back(Word);
		_TemporaryText.erase(0, POS);

	}


	return vStringVector;

}

		
		
static vector<string> SplitStringRecord(string Line,string space = "#//#")
{


	vector <string> vStringVector;
	short POS = 0;
	string Word = "";
	
	while (((POS = Line.find(space)) != std::string::npos))
	{


		Word = Line.substr(0, POS);
		vStringVector.push_back(Word);
		Line.erase(0, POS + 4);



	}

	if (Line != "")
	{
		Word = Line.substr(0, POS);
		vStringVector.push_back(Word);
		Line.erase(0, POS +4);

	}


	return vStringVector;

}








	};






	class clsStr_TrimString_Fun
	{
	
		string _Text;
		char _Letter;

	public:


		clsStr_TrimString_Fun(string _Text, char _Letter)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;

		}
		clsStr_TrimString_Fun()
		{
			_Text = "";
			_Letter = 0;

		}



		void TrimLeft()
		{

			for (short i = 0; i < _Text.length(); i++)
			{

				if (_Text[0] == ' ')
				{

					_Text.erase(0, 1);

				}
				else
				{
					return;
				}


			}


		}
		void TrimRight()
		{
			short CounterLengthString = _Text.length();

			for (short i = 0; i < _Text.length(); i++)
			{

				if (_Text[CounterLengthString - 1] == ' ')
				{


					_Text.erase(CounterLengthString - 1, CounterLengthString);
					CounterLengthString = _Text.length();
				}
				else
				{
					return;
				}


			}


		}
		void Trim()
		{

			TrimLeft();
			TrimRight();

		}
	};
	class clsStr_JoinString_Fun
	{
	private:

		string _Text;
		char _Letter;
	public:

		clsStr_JoinString_Fun(string _Text, char _Letter)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;

		}
		clsStr_JoinString_Fun()
		{
			_Text = "";
			_Letter = 0;

		}



		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}

		string JoinString(vector <string> vInfo, string Delemter)
		{
			string Record = "";
			for (string GetInfo : vInfo)
			{

				Record += GetInfo + Delemter;

			}

			return Record;
		}
		string JoinString(string arrInfo[], short Length, string Delemter)
		{
			string Record = "";


			for (short i = 0; i < Length; i++)
			{

				Record += arrInfo[i] + Delemter;

			}



			return Record;
		}


		__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;
		
	};
    class clsStr_ReplaceWord_Fun
	{
	
	private:

		string _Text;
		char _Letter;
	public:


		clsStr_ReplaceWord_Fun(string _Text, char _Letter)
		{
			this->_Text = _Text;
			this->_Letter = _Letter;

		}
		clsStr_ReplaceWord_Fun()
		{
			_Text = "";
			_Letter = 0;

		}



		void SetString(string _Text)
		{

			this->_Text = _Text;

		}
		void SetChar(char Letter)
		{

			this->_Letter = _Letter;

		}
		string GetString()
		{



			return _Text;

		}
		char GetChar()
		{

			return _Letter;


		}


	string ReversString()
	{
		clsStr_Splits_Fun Split_1;

		vector <string> GetInfo = Split_1.SplitStringRecord();
		string ReversText = "";
		for (short i = GetInfo.size(); i > 0; i--)
		{

			ReversText += GetInfo[i - 1] + " ";

		}

		return ReversText;

	}
	string ReplaceString(string ChangeThis, string GetNewReplace)
	{

		short CounterLen = ChangeThis.length();
		string NewString = "";
		NewString = (_Text.replace(_Text.find(ChangeThis), CounterLen, GetNewReplace));

		return NewString;

	}
	string ReplaceStringWithoutLib(string ChangeThis, string GetNewReplace)
	{

		clsStr_Splits_Fun Split_1;

		vector <string> GetInfo = Split_1.SplitStringRecord();
		short Timer = 0;
		for (string GetText : GetInfo)
		{
			clsStr_JoinString_Fun Join_1;

			if (GetText == ChangeThis)
			{

				GetInfo[Timer] = GetNewReplace;
				return Join_1.JoinString(GetInfo, " ");

			}
			Timer++;

		}

		return "";


	}
	string RemovePunctuationFromString()
	{

		string SNew = "";
		for (short i = 0; i < _Text.length(); i++)
		{


			if (!ispunct(_Text[i]))
			{
				SNew += _Text[i];
			}

		}
		return SNew;

	}


		__declspec(property(get = GetString, put = SetString)) string StringValue;
		__declspec(property(get = GetChar, put = SetChar)) char CharValue;

	};
	

















};


