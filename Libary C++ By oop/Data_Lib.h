#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class clsDate_Lib
{

	string _StrDate;
	struct _sDate
	{

		int _Day = 0;
		short _Month = 0;
		int  _Year = 0;



	};
	_sDate sDate;
	_sDate Temp_sDate;



	_sDate  GetDateFromDayOrderInYear(short NumOption = 0) {

		short GetDaysFromBegin = 0;
		if (NumOption == 0) {

			GetDaysFromBegin = NumberOfDaysFromTheBeginingOfTheYear();

		}
		else
		{
			GetDaysFromBegin = NumOption;
		}


		sDate._Month = 1;
		short varDaysInMonth = DaysInMonth();

		while (true)
		{

			varDaysInMonth = DaysInMonth();


			if (GetDaysFromBegin > varDaysInMonth)
			{
				GetDaysFromBegin -= varDaysInMonth;
				sDate._Month++;

			}
			else
			{
				sDate._Day = GetDaysFromBegin;
				break;

			}


		}

		return sDate;

	}

	_sDate GetSystemDate() {

		_sDate GetDateLive;

		time_t t = time(0);
		tm* Now = localtime(&t);

		GetDateLive._Year = Now->tm_year + 1900;
		GetDateLive._Month = Now->tm_mon + 1;
		GetDateLive._Day = Now->tm_mday;


		return GetDateLive;

	}
	void PrintCalendar(short Month_Name, short d) {

		short Days = 0;
		short Counter_d = d;
		for (short i = 0; i <= Month_Name + d; i++)
		{

			if (i < d)
			{
				cout << setw(5) << "";
			}

			if (i > d)
			{

				Counter_d++;
				Days++;
				(Days < 10) ? cout << setw(1) << Days << setw(4) << "" :
					cout << setw(2) << Days << setw(3) << "";

				Counter_d == 7 ? (cout << endl) ? Counter_d = 0
					: 0
					: 0;

			}


		}



	}
enum eMonths
	{
		January = 31,
		February = 28, // يتغير إلى 29 إذا السنة كبيسة
		March = 31,
		April = 30,
		May = 31,
		June = 30,
		July = 31,
		August = 31,
		September = 30,
		October = 31,
		November = 30,
		December = 31
	};
public:


	clsDate_Lib()
	{
		sDate = GetSystemDate();
		Temp_sDate._Day = 0;
		Temp_sDate._Month = 0;
		Temp_sDate._Year = 0;

	}
	
	
	clsDate_Lib(string Date)
	{
	
		_StrDate = Date;
		sDate._Day = 0;
		sDate._Month = 0;
		sDate._Year = 0;
		Temp_sDate._Day = 0;
		Temp_sDate._Month = 0;
		Temp_sDate._Year = 0;

	}

	clsDate_Lib(short _Day, short _Month, int _Year)
	{
	
		this->sDate._Day = _Day;
		this->sDate._Month = _Month;
		this->sDate._Year = _Year;
		Temp_sDate._Day = 0;
		Temp_sDate._Month = 0;
		Temp_sDate._Year = 0;

	}

	clsDate_Lib(short Days,int Year)
	{
	
		sDate._Day = 1;
		sDate._Year = Year;
		sDate = GetDateFromDayOrderInYear(Days);
		Temp_sDate._Day = 0;
		Temp_sDate._Month = 0;
		Temp_sDate._Year = 0;


	}
	

	int GetDay()
	{
	
	
		return sDate._Day;
	
	}
	int GetMonth()
	{


		return sDate._Month;

	}
	int GetYear()
	{


		return sDate._Year;

	}


	int NumberOfYears()
	{

		return IsLeapYear() ? 366 : 365;

	}
	int  HoursInYear() {



		return 24 * NumberOfYears();
	}
	int  MinutesInYear()
	{
		return   HoursInYear() * 60;
	}
	int  SecondsYear() {



		return MinutesInYear() * 60;

	}

	
	int DaysInMonth() {

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (sDate._Month == 2) ? ((IsLeapYear() == true) ? 29 : 28) : NumberOfDays[sDate._Month - 1];

	}
	int  HoursInMonth() {



		return 24 * DaysInMonth();
	}
	int  MinutesInMonth()
	{
		return   HoursInMonth() * 60;
	}
	int  SecondsMonth() {



		return MinutesInMonth() * 60;

	}

	
	short GetDayOrder()
	{

		int a = (14 - sDate._Month) / 12;
		int y = sDate._Year - a;
		int m = sDate._Month + 12 * a - 2;

		int q = sDate._Day;

		int d = (q + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

		return (short)d;

	}
	string GetDayName()
	{

		string TextArray[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

		return TextArray[GetDayOrder()];

	}
	void PrintDate()
	{
		cout << "\nDate: " << sDate._Day << "/" << sDate._Month << "/" << sDate._Year << endl;
	}
	

	string GetMonthName() {


		string MonthsName[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };


		return MonthsName[sDate._Month - 1];



	}
	void PrintDayName() {


		string DayName[] = { "Sun","Mon","Tue","Wed","The","Fri","Sat" };
		short i = 0;

		for (i = 0; i < 7; i++)
		{

			cout << DayName[i] << setw(5);

		}
		cout << endl;



	}

	void ShowCalendar()
	{

		cout << "\n___________" << GetMonthName() << "_________________\n";

		PrintDayName();
		PrintCalendar(DaysInMonth(), GetDayOrder());

	}
	void PrintAllMonth() {

		
		short TempMonth = sDate._Month;
		
		
		sDate._Month = 1;

		for (sDate._Month; sDate._Month <= 12; sDate._Month++)
		{

			ShowCalendar();
			cout << "\n";
		}
		cout << endl;
		
		sDate._Month = TempMonth;

	}



	short NumberOfDaysFromTheBeginingOfTheYear() {

		short TotalDays = 0;
		Temp_sDate._Month = sDate._Month;
		short* i = &Temp_sDate._Month;

		for (sDate._Month = 1; sDate._Month <= *i - 1; sDate._Month++)
		{
			

			TotalDays += DaysInMonth();



		}


		TotalDays += sDate._Day;
		sDate._Month = *i;
		return TotalDays;

	}



	
	void PrintNewDate(int Days,_sDate GetDate)
	{
	

		cout << "Date after adding [" << Days << "] days is: " << GetDate._Day << "/" << GetDate._Month << "/" << GetDate._Year << endl;



	}
	void GetNewDate() {
		
		short i = sDate._Day + 1;
		short getMonthDay = 0;
		short SaveDays;
		getMonthDay = DaysInMonth();
		int Days = ReadFromUserDays();
		SaveDays = Days;

		while (Days != 0) {

			if (i == 27)
			{
				getMonthDay = DaysInMonth();
			}

			if (i <= getMonthDay)
			{


				if (sDate._Month == 12 && i == getMonthDay)
				{
					sDate._Year++;
					sDate._Month = 1;
					i = 0;
				}
				else
				{

					(i == getMonthDay) ? sDate._Month++ : 0;
					(i == getMonthDay) ? i = 1 : i++;
				}

			}
			Days--;

			if (Days == 0)
			{
				sDate._Day = i;

				break;
			}


		}


		PrintNewDate(SaveDays, sDate);


	}
	


    int ReadFromUserDays() {

		int Days = 0;
		cout << "\nEnter Day: ";

		cin >> Days;
		return Days;




	}
	short ReadFromUserMonth() {

		short Month = 0;
		cout << "\nEnter Month: ";
		cin >> Month;
		return Month;




	}
	short ReadFromUserYear() {

		short Year = 0;
		cout << "\nEnter Year: ";
		cin >> Year;
		return Year;




	}
	_sDate ReadAll()
	{
		_sDate Date;

		Date._Day = ReadFromUserDays();
		Date._Month = ReadFromUserMonth();
		Date._Year = ReadFromUserYear();


		return Date;
	}











	//---------------------------------------------

	bool IsLeapYear() {




		return (sDate._Year % 400 == 0 && sDate._Year % 100 != 0) || (sDate._Year % 4 == 0);




	}
	bool IsDate1BeforeDate2(_sDate Date1, _sDate Date2)
	{
		return  (Date1._Year < Date2._Year) ? true
			: ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true
				: (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);


	}
	bool IsDate1_EqualToDate2(_sDate Date1, _sDate Date2) {



		return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day) ? true : false;



	}
	bool IsFirstMonth(_sDate Date1)
	{

		return (Date1._Month == 1) ? true : false;




	}
	bool IsFirstDay(_sDate Date1) {

		return (Date1._Day == 1) ? true : false;



	}
	bool IsLastDay(_sDate Date1) {




		return (DaysInMonth() == Date1._Day) ? true : false;
	}
	bool IsLastMonth(_sDate Date1) {



		return (Date1._Month == 12) ? true : false;

	}
	bool IsEndOFWeek(short DayName){



	
	return (DayName == 6) ? true : false;

}
    bool IsWeekEnd(short DayName) {




	
	return (DayName == 5) ? true : false;


}
    bool IsBusinessDay(short DayName) {



	return !IsWeekEnd(DayName);

}
  


	bool IsSystemDateBeforeDate2(clsDate_Lib SystemDate, clsDate_Lib Date2)
	{
	


		if (SystemDate.GetYear() != Date2.GetYear())
		{

			if (SystemDate.GetYear() < Date2.GetYear())
				return true;
			else
				return false;



		}
		else if (SystemDate.GetMonth() != Date2.GetMonth())
		{
			if (SystemDate.GetMonth() < Date2.GetMonth())
				return true;
			else
				return false;



		}
		else if (SystemDate.GetDay() != Date2.GetDay())
		{

			if (SystemDate.GetDay() < Date2.GetDay())
				return true;
			else
				return false;

		}
		else
		{
			return true;
		}





	}
  bool IsSystemDateAfterDate2(clsDate_Lib D1, clsDate_Lib D2) {




		 return (!IsSystemDateBeforeDate2(D1, D2) && !IsDate1_EqualToDate2(D1, D2));




	 }

	bool IsDate1_EqualToDate2(clsDate_Lib Date1, clsDate_Lib Date2) {



		return Date1.GetYear() == Date2.GetYear()
			&& Date1.GetMonth() == Date2.GetMonth()
		 	&& Date1.GetDay() == Date2.GetDay() ? true : false;



	}
	//bool IsSystemDateAfterStartDate(clsDate_Lib D1, clsDate_Lib D2) {




	//	return (!IsSystemDateBeforeStartDate(D1, D2) && !IsDate1_EqualToDate2(D1, D2));




	//}
	
	bool IsDayInValidRange(short Day, short Month, short Year) {



		 short Days = DaysInMonth();
		 return (Day > Days || Day < 1) ? false : true;
	 }
	bool IsMonthInValidRange(short Month) {



		 return (Month < 1 || Month > 12) ? false : true;

	 }
	bool IsValidDate(_sDate MyDateInfo) {


		 if (IsDayInValidRange(MyDateInfo._Day, MyDateInfo._Month, MyDateInfo._Year))
		 {

			 if (IsMonthInValidRange(MyDateInfo._Month))
			 {
				 return true;
			 }
			 else
			 {
				 return false;
			 }

		 }
		 else
		 {
			 return false;
		 }


	 }
	bool IsValidDate(clsDate_Lib MyDateInfo) {


		if (IsDayInValidRange(MyDateInfo.GetDay(), 0, 0))
		{

			if (IsMonthInValidRange(MyDateInfo.GetMonth()))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}


	};

	
	//---------------------------------------------

	_sDate IncreacesDateByOneDay(_sDate Date1) {


		if (IsLastDay(Date1) == true)
		{

			Temp_sDate._Day = 1;

			if (IsLastMonth(Date1))
			{
				Temp_sDate._Month = 1;
				Temp_sDate._Year++;
			}
			else
			{
				Temp_sDate._Month++;
			}

		}
		else
		{
			Temp_sDate._Day++;
		}



		return Temp_sDate;


	}

	void SwapDate(_sDate& Date1, _sDate& Date2) {

		_sDate Swab;

		Swab._Day = Date1._Day;
		Swab._Month = Date1._Month;
		Swab._Year = Date1._Year;


		Date1._Day = Date2._Day;
		Date1._Month = Date2._Month;
		Date1._Year = Date2._Year;

		Date2._Day = Swab._Day;
		Date2._Month = Swab._Month;
		Date2._Year = Swab._Year;




	}
	int GetDifferencesInDays(bool Optional = true) {
		cout << "add date to get Fiffernces:\n";
		_sDate Date2 = ReadAll();
		Temp_sDate = sDate;

		short OneNeg = 1;
		int Days = 0;
		if (!IsDate1BeforeDate2(Temp_sDate, Date2))
		{
			SwapDate(Temp_sDate, Date2);
			OneNeg = -1;

		}


		
		while (IsDate1BeforeDate2(Temp_sDate, Date2)) {

			Days++;
			Temp_sDate = IncreacesDateByOneDay(Temp_sDate);
			
		}

		return Optional == true ? Days * OneNeg : ++Days * OneNeg;




	}

	//---------------------------------------------

	void IncreaseDateByXDays(short X)
	{
		Temp_sDate = sDate;
		for (int i = 0; i < X; i++)
		{
			Temp_sDate = IncreacesDateByOneDay(Temp_sDate);

		}
		
		
		sDate = Temp_sDate;

	}
	void IncreaseByOneWeek() {

		Temp_sDate = sDate;
		for (int i = 1; i <= 7; i++)
		{


			Temp_sDate = IncreacesDateByOneDay(Temp_sDate);
		}


		sDate = Temp_sDate;

	}
	void IncreaseByXWeek( short X) {

		for (int i = 1; i <= X; i++)
		{

			 IncreaseByOneWeek();


		}

		 


	}
	void IncreaseByOneMonth() {

		Temp_sDate = sDate;
		if (Temp_sDate._Month == 12)
		{
			Temp_sDate._Year++;
			Temp_sDate._Month = 1;
		}
		else
		{
			Temp_sDate._Month++;
		}
		short NumberOfDaysInCorrentMonth = DaysInMonth();

		if (Temp_sDate._Day > NumberOfDaysInCorrentMonth)
		{
			Temp_sDate._Day = NumberOfDaysInCorrentMonth;
		}
		sDate = Temp_sDate;



	}
	void IncreaseByXMonth(short X) {


		Temp_sDate = sDate;

		for (int i = 1; i <= X; i++)
		{
			IncreaseByOneMonth();

		}

		
		sDate = Temp_sDate;


	}
	void IncreaseByOneYear() {




		sDate._Year++;



	}
	void IncreaseByXYear( short X) {




		for (int i = 1; i <= X; i++)
		{

			 IncreaseByOneYear();

		}


	}
	void IncreaseByXYear_Faster(short X) {




		for (int i = 1; i <= X; i++)
		{

			sDate._Year++;
		}


	}
	void IncreaseByOneDecade() {





		IncreaseByXYear_Faster(1 * 10);



	}
	void IncreaseByXDecade(short X) {





		for (int i = 1; i <= X; i++)
		{
			 IncreaseByOneDecade();

		}


	}
	void IncreaseByXDecade_Faster( short X) {




		short Decade = 1;
		for (int i = 1; i <= X; i++)
		{
			Decade *= 10;
			sDate._Year += Decade;
			Decade = 1;

		}


	}
	void IncreaseByOneCentury() {





		for (int i = 1; i <= 10; i++)
		{
			IncreaseByXDecade_Faster(1);

		}


	}
	void IncreaseByOneMillennium() {





		for (int i = 1; i <= 10; i++)
		{
		IncreaseByOneCentury();

		}


	}

	//---------------------------------------------

	void DecreaseDateByOneDay() {


		if (IsFirstDay(sDate))
		{

			if (IsFirstMonth(sDate))
			{
				sDate._Year--;
				sDate._Month = 12;
				sDate._Day = DaysInMonth();

			}
			else
			{
				sDate._Month--;
				sDate._Day = DaysInMonth();

			}

		}
		else
		{

			sDate._Day--;

		}

		

	}
	void DecreaseDateByXDay(int X) {




		for (short i = 1; i <= X; i++)
		{
			DecreaseDateByOneDay();

		}

		

	}
	void DecreaseByOneWeek() {



		DecreaseDateByXDay(7);



	}
	void DecreaseByXWeek( int X) {



		for (short i = 1; i <= X; i++)
		{
			DecreaseByOneWeek();
		}

		
	}
	void DecreaseByOneMonth() {

		if (IsFirstMonth(sDate))
		{
			sDate._Year--;
			sDate._Month = 12;
		}
		else
		{
			sDate._Month--;
		}

		short GetD = DaysInMonth();
		if (sDate._Day > GetD)
		{
			sDate._Day = GetD;
		}


	}
	void DecreaseByXMonth(short X) {


		for (short i = 1; i <= X; i++)
		{

		 DecreaseByOneMonth();

		}
		
	}
	void DecreaseByOneYear() {


		sDate._Year--;
		


	}
	void DecreaseByXYears(short X) {



		for (short i = 1; i <= X; i++)
		{
			DecreaseByOneYear();

		}
		
	}
	void DecreaseByXYears_Faster(short X) {



		sDate._Year -= X;
	


	}
	void DecreaseByOneDecade() {



		sDate._Year -= 10;
		


	}
	void DecreaseByXDecade(short X) {


		for (short i = 1; i <= X; i++)
		{

		DecreaseByOneDecade();

		}

		
	}
	void DecreaseByXDecade_Faster(short X) {



		X *= 10;
		sDate._Year -= X;
		

	}
	void DecreaseByOneCentury() {




		DecreaseByXDecade_Faster(10);


	}
	void DecreaseByOneMillennium() {



		for (short i = 1; i <= 10; i++)
		{

			DecreaseByOneCentury();

		}
		
	}

	//---------------------------------------------

  	 void PrintDayName(_sDate Info, short DayName) {

		
		
		cout << "It is " << GetDayName() << ": " << Info._Day << "/" << Info._Month << "/" << Info._Year << endl;

	}
	 void DayOFWeekOrder() {

		short NameDayOfWeek = GetDayOrder();
		PrintDayName(sDate, NameDayOfWeek);



		
	}
   



     short DayUntilTheEndWeek() {

	short Timer = 0;
	short i = GetDayOrder();

	for (i; i < 5; i++)
	{
		Timer++;
	}
	return Timer;
}
     short DayUntilTheEndMonth() {


	short endMonthDay = DaysInMonth();

	short Timer = 0;
	for (short i = sDate._Day; i < endMonthDay; i++)
	{
		Timer++;
	}

	return Timer;

}
     short DayUntilTheEndYear(){

	short GetDaysOfMonth = DaysInMonth();
	short Timer = 0;
	short i = sDate._Day;
	for (i; i <= GetDaysOfMonth; i++)
	{
		Timer++;
		if (i == GetDaysOfMonth)
		{
			


			(sDate._Month == 12 && i == GetDaysOfMonth) ? 0 : i = 0;
			(sDate._Month != 12) ? sDate._Month++ : 0;

			GetDaysOfMonth = DaysInMonth();


		}

		if(sDate._Month == 12 && i == GetDaysOfMonth){ 
			return Timer;
		
		}

	}



}



	 short CalculateVacationDays(_sDate From, _sDate To) {

		 short DayOrder = 0;
		 short Timer = 0;
		 while (IsDate1_EqualToDate2(From, To))
		 {
			 DayOrder = GetDayOrder();
			 From = IncreacesDateByOneDay(From);

			 (IsWeekEnd(DayOrder) == false) ? Timer++ : 0;



		 }
		 return Timer;


	 }


	 
	 _sDate ActucalVactionDay(_sDate From, short Vactions) {

		 short DayOrder = 0;
		 short Timer = 0;
		 while (Timer != Vactions)
		 {
			 DayOrder = GetDayOrder();

			 if (IsWeekEnd(DayOrder) == false) {
				 Timer++;

			 }

			 From = IncreacesDateByOneDay(From);


		 }
		 return From;


	 }


	














};

// مراجعه جميع 
// methods
// عند الانتهاء
// و نسوي test for all methods;




//
//
////ProgrammingAdivces.com
////Mohammed Abu-Hadhoud
//#pragma warning(disable : 4996)
//#pragma once
//
//#include<iostream>
//#include<string>
//#include "clsString.h"
//
//using namespace std;
//
//class clsDate
//{
//
//private:
//
//	short _Day = 1;
//	short _Month = 1;
//	short _Year = 1900;
//
//public:
//
//	clsDate()
//	{
//		time_t t = time(0);
//		tm* now = localtime(&t);
//		_Day = now->tm_mday;
//		_Month = now->tm_mon + 1;
//		_Year = now->tm_year + 1900;
//	}
//
//	clsDate(string sDate)
//	{
//
//		vector <string> vDate;
//		vDate = clsString::Split(sDate, "/");
//
//		_Day = stoi(vDate[0]);
//		_Month = stoi(vDate[1]);
//		_Year = stoi(vDate[2]);
//
//	}
//
//	clsDate(short Day, short Month, short Year)
//	{
//
//		_Day = Day;
//		_Month = Month;
//		_Year = Year;
//
//	}
//
//	clsDate(short DateOrderInYear, short Year)
//	{
//		//This will construct a date by date order in year
//		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
//		_Day = Date1.Day;
//		_Month = Date1.Month;
//		_Year = Date1.Year;
//	}
//
//	void SetDay(short Day) {
//		_Day = Day;
//	}
//
//	short GetDay() {
//		return _Day;
//	}
//	__declspec(property(get = GetDay, put = SetDay)) short Day;
//
//	void SetMonth(short Month) {
//		_Month = Month;
//	}
//
//	short GetMonth() {
//		return _Month;
//	}
//	__declspec(property(get = GetMonth, put = SetMonth)) short Month;
//
//
//	void SetYear(short Year) {
//		_Year = Year;
//	}
//
//	short GetYear() {
//		return _Year;
//	}
//	__declspec(property(get = GetYear, put = SetYear)) short Year;
//
//	void Print()
//	{
//		cout << DateToString() << endl;
//	}
//
//	static clsDate GetSystemDate()
//	{
//		//system date
//		time_t t = time(0);
//		tm* now = localtime(&t);
//
//		short Day, Month, Year;
//
//		Year = now->tm_year + 1900;
//		Month = now->tm_mon + 1;
//		Day = now->tm_mday;
//
//		return clsDate(Day, Month, Year);
//	}
//
//	static	bool IsValidDate(clsDate Date)
//	{
//
//		if (Date.Day < 1 || Date.Day>31)
//			return false;
//
//		if (Date.Month < 1 || Date.Month>12)
//			return false;
//
//		if (Date.Month == 2)
//		{
//			if (isLeapYear(Date.Year))
//			{
//				if (Date.Day > 29)
//					return false;
//			}
//			else
//			{
//				if (Date.Day > 28)
//					return false;
//			}
//		}
//
//		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
//
//		if (Date.Day > DaysInMonth)
//			return false;
//
//		return true;
//
//	}
//
//	bool IsValid()
//	{
//		return IsValidDate(*this);
//	}
//
//	static string DateToString(clsDate Date)
//	{
//		return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
//	}
//
//	string DateToString()
//	{
//		return  DateToString(*this);
//	}
//
//	static bool isLeapYear(short Year)
//	{
//
//		// if year is divisible by 4 AND not divisible by 100
//	  // OR if year is divisible by 400
//	  // then it is a leap year
//		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
//	}
//
//	bool isLeapYear()
//	{
//		return isLeapYear(_Year);
//	}
//
//	static short NumberOfDaysInAYear(short Year)
//	{
//		return  isLeapYear(Year) ? 365 : 364;
//	}
//
//	short NumberOfDaysInAYear()
//	{
//		return  NumberOfDaysInAYear(_Year);
//	}
//
//	static short NumberOfHoursInAYear(short Year)
//	{
//		return  NumberOfDaysInAYear(Year) * 24;
//	}
//
//	short NumberOfHoursInAYear()
//	{
//		return  NumberOfHoursInAYear(_Year);
//	}
//
//	static int NumberOfMinutesInAYear(short Year)
//	{
//		return  NumberOfHoursInAYear(Year) * 60;
//	}
//
//	int NumberOfMinutesInAYear()
//	{
//		return  NumberOfMinutesInAYear(_Year);
//	}
//
//	static int NumberOfSecondsInAYear(short Year)
//	{
//		return  NumberOfMinutesInAYear(Year) * 60;
//	}
//
//	int NumberOfSecondsInAYear()
//	{
//		return  NumberOfSecondsInAYear();
//	}
//
//	static short NumberOfDaysInAMonth(short Month, short Year)
//	{
//
//		if (Month < 1 || Month>12)
//			return  0;
//
//		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
//
//	}
//
//	short NumberOfDaysInAMonth()
//	{
//		return NumberOfDaysInAMonth(_Month, _Year);
//	}
//
//	static short NumberOfHoursInAMonth(short Month, short Year)
//	{
//		return  NumberOfDaysInAMonth(Month, Year) * 24;
//	}
//
//	short NumberOfHoursInAMonth()
//	{
//		return  NumberOfDaysInAMonth(_Month, _Year) * 24;
//	}
//
//	static int NumberOfMinutesInAMonth(short Month, short Year)
//	{
//		return  NumberOfHoursInAMonth(Month, Year) * 60;
//	}
//
//	int NumberOfMinutesInAMonth()
//	{
//		return  NumberOfHoursInAMonth(_Month, _Year) * 60;
//	}
//
//	static int NumberOfSecondsInAMonth(short Month, short Year)
//	{
//		return  NumberOfMinutesInAMonth(Month, Year) * 60;
//	}
//
//	int NumberOfSecondsInAMonth()
//	{
//		return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
//	}
//
//	static short DayOfWeekOrder(short Day, short Month, short Year)
//	{
//		short a, y, m;
//		a = (14 - Month) / 12;
//		y = Year - a;
//		m = Month + (12 * a) - 2;
//		// Gregorian:
//		//0:sun, 1:Mon, 2:Tue...etc
//		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//	}
//
//	short DayOfWeekOrder()
//	{
//		return DayOfWeekOrder(_Day, _Month, _Year);
//	}
//
//	static string DayShortName(short DayOfWeekOrder)
//	{
//		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
//
//		return arrDayNames[DayOfWeekOrder];
//
//	}
//
//	static string DayShortName(short Day, short Month, short Year)
//	{
//
//		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
//
//		return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
//
//	}
//
//	string DayShortName()
//	{
//
//		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
//
//		return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
//
//	}
//
//	static string MonthShortName(short MonthNumber)
//	{
//		string Months[12] = { "Jan", "Feb", "Mar",
//						   "Apr", "May", "Jun",
//						   "Jul", "Aug", "Sep",
//						   "Oct", "Nov", "Dec"
//		};
//
//		return (Months[MonthNumber - 1]);
//	}
//
//	string MonthShortName()
//	{
//
//		return MonthShortName(_Month);
//	}
//
//	static void PrintMonthCalendar(short Month, short Year)
//	{
//		int NumberOfDays;
//
//		// Index of the day from 0 to 6
//		int current = DayOfWeekOrder(1, Month, Year);
//
//		NumberOfDays = NumberOfDaysInAMonth(Month, Year);
//
//		// Print the current month name
//		printf("\n  _______________%s_______________\n\n",
//			MonthShortName(Month).c_str());
//
//		// Print the columns
//		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
//
//		// Print appropriate spaces
//		int i;
//		for (i = 0; i < current; i++)
//			printf("     ");
//
//		for (int j = 1; j <= NumberOfDays; j++)
//		{
//			printf("%5d", j);
//
//
//			if (++i == 7)
//			{
//				i = 0;
//				printf("\n");
//			}
//		}
//
//		printf("\n  _________________________________\n");
//
//	}
//
//	void PrintMonthCalendar()
//	{
//		PrintMonthCalendar(_Month, _Year);
//	}
//
//	static void PrintYearCalendar(int Year)
//	{
//		printf("\n  _________________________________\n\n");
//		printf("           Calendar - %d\n", Year);
//		printf("  _________________________________\n");
//
//
//		for (int i = 1; i <= 12; i++)
//		{
//			PrintMonthCalendar(i, Year);
//		}
//
//		return;
//	}
//
//	void PrintYearCalendar()
//	{
//		printf("\n  _________________________________\n\n");
//		printf("           Calendar - %d\n", _Year);
//		printf("  _________________________________\n");
//
//
//		for (int i = 1; i <= 12; i++)
//		{
//			PrintMonthCalendar(i, _Year);
//		}
//
//		return;
//	}
//
//	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
//	{
//
//
//		short TotalDays = 0;
//
//		for (int i = 1; i <= Month - 1; i++)
//		{
//			TotalDays += NumberOfDaysInAMonth(i, Year);
//		}
//
//		TotalDays += Day;
//
//		return TotalDays;
//	}
//
//	short DaysFromTheBeginingOfTheYear()
//	{
//
//
//		short TotalDays = 0;
//
//		for (int i = 1; i <= _Month - 1; i++)
//		{
//			TotalDays += NumberOfDaysInAMonth(i, _Year);
//		}
//
//		TotalDays += _Day;
//
//		return TotalDays;
//	}
//
//	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
//	{
//
//		clsDate Date;
//		short RemainingDays = DateOrderInYear;
//		short MonthDays = 0;
//
//		Date.Year = Year;
//		Date.Month = 1;
//
//		while (true)
//		{
//			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
//
//			if (RemainingDays > MonthDays)
//			{
//				RemainingDays -= MonthDays;
//				Date.Month++;
//			}
//			else
//			{
//				Date.Day = RemainingDays;
//				break;
//			}
//
//		}
//
//		return Date;
//	}
//
//	void AddDays(short Days)
//	{
//
//
//		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
//		short MonthDays = 0;
//
//		_Month = 1;
//
//		while (true)
//		{
//			MonthDays = NumberOfDaysInAMonth(_Month, _Year);
//
//			if (RemainingDays > MonthDays)
//			{
//				RemainingDays -= MonthDays;
//				_Month++;
//
//				if (_Month > 12)
//				{
//					_Month = 1;
//					_Year++;
//
//				}
//			}
//			else
//			{
//				_Day = RemainingDays;
//				break;
//			}
//
//		}
//
//
//	}
//
//	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
//	{
//		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
//	}
//
//	bool IsDateBeforeDate2(clsDate Date2)
//	{
//		//note: *this sends the current object :-) 
//		return  IsDate1BeforeDate2(*this, Date2);
//
//	}
//
//	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
//	{
//		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
//	}
//
//	bool IsDateEqualDate2(clsDate Date2)
//	{
//		return  IsDate1EqualDate2(*this, Date2);
//	}
//
//	static bool IsLastDayInMonth(clsDate Date)
//	{
//
//		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
//
//	}
//
//	bool IsLastDayInMonth()
//	{
//
//		return IsLastDayInMonth(*this);
//
//	}
//
//	static bool IsLastMonthInYear(short Month)
//	{
//		return (Month == 12);
//	}
//
//	static clsDate AddOneDay(clsDate Date)
//	{
//		if (IsLastDayInMonth(Date))
//		{
//			if (IsLastMonthInYear(Date.Month))
//			{
//				Date.Month = 1;
//				Date.Day = 1;
//				Date.Year++;
//			}
//			else
//			{
//				Date.Day = 1;
//				Date.Month++;
//			}
//		}
//		else
//		{
//			Date.Day++;
//		}
//
//		return Date;
//	}
//
//	void AddOneDay()
//
//	{
//		*this = AddOneDay(*this);
//	}
//
//	static void  SwapDates(clsDate& Date1, clsDate& Date2)
//	{
//
//		clsDate TempDate;
//		TempDate = Date1;
//		Date1 = Date2;
//		Date2 = TempDate;
//
//	}
//
//	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
//	{
//		//this will take care of negative diff
//		int Days = 0;
//		short SawpFlagValue = 1;
//
//		if (!IsDate1BeforeDate2(Date1, Date2))
//		{
//			//Swap Dates 
//			SwapDates(Date1, Date2);
//			SawpFlagValue = -1;
//
//		}
//
//		while (IsDate1BeforeDate2(Date1, Date2))
//		{
//			Days++;
//			Date1 = AddOneDay(Date1);
//		}
//
//		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
//	}
//
//	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
//	{
//		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
//	}
//
//	static short CalculateMyAgeInDays(clsDate DateOfBirth)
//	{
//		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
//	}
//	//above no need to have nonstatic function for the object because it does not depend on any data from it.
//
//	static clsDate IncreaseDateByOneWeek(clsDate& Date)
//	{
//
//		for (int i = 1; i <= 7; i++)
//		{
//			Date = AddOneDay(Date);
//		}
//
//		return Date;
//	}
//
//	void IncreaseDateByOneWeek()
//	{
//		IncreaseDateByOneWeek(*this);
//	}
//
//	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
//	{
//
//		for (short i = 1; i <= Weeks; i++)
//		{
//			Date = IncreaseDateByOneWeek(Date);
//		}
//		return Date;
//	}
//
//	void IncreaseDateByXWeeks(short Weeks)
//	{
//		IncreaseDateByXWeeks(Weeks, *this);
//	}
//
//	clsDate IncreaseDateByOneMonth(clsDate& Date)
//	{
//
//		if (Date.Month == 12)
//		{
//			Date.Month = 1;
//			Date.Year++;
//		}
//		else
//		{
//			Date.Month++;
//		}
//
//		//last check day in date should not exceed max days in the current month
//		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
//		// be 28/2/2022
//		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
//		if (Date.Day > NumberOfDaysInCurrentMonth)
//		{
//			Date.Day = NumberOfDaysInCurrentMonth;
//		}
//
//		return Date;
//	}
//
//	void IncreaseDateByOneMonth()
//	{
//
//		IncreaseDateByOneMonth(*this);
//
//	}
//
//	clsDate IncreaseDateByXDays(short Days, clsDate& Date)
//	{
//
//		for (short i = 1; i <= Days; i++)
//		{
//			Date = AddOneDay(Date);
//		}
//		return Date;
//	}
//
//	void IncreaseDateByXDays(short Days)
//	{
//
//		IncreaseDateByXDays(Days, *this);
//	}
//
//	clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
//	{
//
//		for (short i = 1; i <= Months; i++)
//		{
//			Date = IncreaseDateByOneMonth(Date);
//		}
//		return Date;
//	}
//
//	void IncreaseDateByXMonths(short Months)
//	{
//		IncreaseDateByXMonths(Months, *this);
//	}
//
//	static clsDate IncreaseDateByOneYear(clsDate& Date)
//	{
//		Date.Year++;
//		return Date;
//	}
//
//	void IncreaseDateByOneYear()
//	{
//		IncreaseDateByOneYear(*this);
//	}
//
//	clsDate IncreaseDateByXYears(short Years, clsDate& Date)
//	{
//		Date.Year += Years;
//		return Date;
//
//	}
//
//	void IncreaseDateByXYears(short Years)
//	{
//		IncreaseDateByXYears(Years);
//	}
//
//	clsDate IncreaseDateByOneDecade(clsDate& Date)
//	{
//		//Period of 10 years
//		Date.Year += 10;
//		return Date;
//	}
//
//	void IncreaseDateByOneDecade()
//	{
//		IncreaseDateByOneDecade(*this);
//	}
//
//	clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
//	{
//		Date.Year += Decade * 10;
//		return Date;
//	}
//
//	void IncreaseDateByXDecades(short Decade)
//	{
//		IncreaseDateByXDecades(Decade, *this);
//	}
//
//	clsDate IncreaseDateByOneCentury(clsDate& Date)
//	{
//		//Period of 100 years
//		Date.Year += 100;
//		return Date;
//	}
//
//	void IncreaseDateByOneCentury()
//	{
//		IncreaseDateByOneCentury(*this);
//	}
//
//	clsDate IncreaseDateByOneMillennium(clsDate& Date)
//	{
//		//Period of 1000 years
//		Date.Year += 1000;
//		return Date;
//	}
//
//	clsDate IncreaseDateByOneMillennium()
//	{
//		IncreaseDateByOneMillennium(*this);
//	}
//
//	static clsDate DecreaseDateByOneDay(clsDate Date)
//	{
//		if (Date.Day == 1)
//		{
//			if (Date.Month == 1)
//			{
//				Date.Month = 12;
//				Date.Day = 31;
//				Date.Year--;
//			}
//			else
//			{
//
//				Date.Month--;
//				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
//			}
//		}
//		else
//		{
//			Date.Day--;
//		}
//
//		return Date;
//	}
//
//	void DecreaseDateByOneDay()
//	{
//		DecreaseDateByOneDay(*this);
//	}
//
//	static clsDate DecreaseDateByOneWeek(clsDate& Date)
//	{
//
//		for (int i = 1; i <= 7; i++)
//		{
//			Date = DecreaseDateByOneDay(Date);
//		}
//
//		return Date;
//	}
//
//	void DecreaseDateByOneWeek()
//	{
//		DecreaseDateByOneWeek(*this);
//	}
//
//	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
//	{
//
//		for (short i = 1; i <= Weeks; i++)
//		{
//			Date = DecreaseDateByOneWeek(Date);
//		}
//		return Date;
//	}
//
//	void DecreaseDateByXWeeks(short Weeks)
//	{
//		DecreaseDateByXWeeks(Weeks, *this);
//	}
//
//	static clsDate DecreaseDateByOneMonth(clsDate& Date)
//	{
//
//		if (Date.Month == 1)
//		{
//			Date.Month = 12;
//			Date.Year--;
//		}
//		else
//			Date.Month--;
//
//
//		//last check day in date should not exceed max days in the current month
//	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
//	   // be 28/2/2022
//		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
//		if (Date.Day > NumberOfDaysInCurrentMonth)
//		{
//			Date.Day = NumberOfDaysInCurrentMonth;
//		}
//
//
//		return Date;
//	}
//
//	void DecreaseDateByOneMonth()
//	{
//		DecreaseDateByOneMonth(*this);
//	}
//
//	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
//	{
//
//		for (short i = 1; i <= Days; i++)
//		{
//			Date = DecreaseDateByOneDay(Date);
//		}
//		return Date;
//	}
//
//	void DecreaseDateByXDays(short Days)
//	{
//		DecreaseDateByXDays(Days, *this);
//	}
//
//	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
//	{
//
//		for (short i = 1; i <= Months; i++)
//		{
//			Date = DecreaseDateByOneMonth(Date);
//		}
//		return Date;
//	}
//
//	void DecreaseDateByXMonths(short Months)
//	{
//		DecreaseDateByXMonths(Months, *this);
//	}
//
//	static clsDate DecreaseDateByOneYear(clsDate& Date)
//	{
//
//		Date.Year--;
//		return Date;
//	}
//
//	void DecreaseDateByOneYear()
//	{
//		DecreaseDateByOneYear(*this);
//	}
//
//	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
//	{
//
//		Date.Year -= Years;
//		return Date;
//	}
//
//	void DecreaseDateByXYears(short Years)
//	{
//		DecreaseDateByXYears(Years, *this);
//	}
//
//	static clsDate DecreaseDateByOneDecade(clsDate& Date)
//	{
//		//Period of 10 years
//		Date.Year -= 10;
//		return Date;
//	}
//
//	void DecreaseDateByOneDecade()
//	{
//		DecreaseDateByOneDecade(*this);
//	}
//
//	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
//	{
//
//		Date.Year -= Decades * 10;
//		return Date;
//	}
//
//	void DecreaseDateByXDecades(short Decades)
//	{
//		DecreaseDateByXDecades(Decades, *this);
//	}
//
//	static clsDate DecreaseDateByOneCentury(clsDate& Date)
//	{
//		//Period of 100 years
//		Date.Year -= 100;
//		return Date;
//	}
//
//	void DecreaseDateByOneCentury()
//	{
//		DecreaseDateByOneCentury(*this);
//	}
//
//	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
//	{
//		//Period of 1000 years
//		Date.Year -= 1000;
//		return Date;
//	}
//
//	void DecreaseDateByOneMillennium()
//	{
//		DecreaseDateByOneMillennium(*this);
//	}
//
//
//	static short IsEndOfWeek(clsDate Date)
//	{
//		return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
//	}
//
//	short IsEndOfWeek()
//	{
//		return IsEndOfWeek(*this);
//	}
//
//	static bool IsWeekEnd(clsDate Date)
//	{
//		//Weekends are Fri and Sat
//		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
//		return  (DayIndex == 5 || DayIndex == 6);
//	}
//
//	bool IsWeekEnd()
//	{
//		return  IsWeekEnd(*this);
//	}
//
//	static bool IsBusinessDay(clsDate Date)
//	{
//		//Weekends are Sun,Mon,Tue,Wed and Thur
//
//	   /*
//		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
//		return  (DayIndex >= 5 && DayIndex <= 4);
//	   */
//
//	   //shorter method is to invert the IsWeekEnd: this will save updating code.
//		return !IsWeekEnd(Date);
//
//	}
//
//	bool IsBusinessDay()
//	{
//		return  IsBusinessDay(*this);
//	}
//
//	static short DaysUntilTheEndOfWeek(clsDate Date)
//	{
//		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
//	}
//
//	short DaysUntilTheEndOfWeek()
//	{
//		return  DaysUntilTheEndOfWeek(*this);
//	}
//
//	static short DaysUntilTheEndOfMonth(clsDate Date1)
//	{
//
//		clsDate EndOfMontDate;
//		EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
//		EndOfMontDate.Month = Date1.Month;
//		EndOfMontDate.Year = Date1.Year;
//
//		return GetDifferenceInDays(Date1, EndOfMontDate, true);
//
//	}
//
//	short DaysUntilTheEndOfMonth()
//	{
//		return DaysUntilTheEndOfMonth(*this);
//	}
//
//	static short DaysUntilTheEndOfYear(clsDate Date1)
//	{
//
//		clsDate EndOfYearDate;
//		EndOfYearDate.Day = 31;
//		EndOfYearDate.Month = 12;
//		EndOfYearDate.Year = Date1.Year;
//
//		return GetDifferenceInDays(Date1, EndOfYearDate, true);
//
//	}
//
//	short DaysUntilTheEndOfYear()
//	{
//		return  DaysUntilTheEndOfYear(*this);
//	}
//
//	//i added this method to calculate business days between 2 days
//	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
//	{
//
//		short Days = 0;
//		while (IsDate1BeforeDate2(DateFrom, DateTo))
//		{
//			if (IsBusinessDay(DateFrom))
//				Days++;
//
//			DateFrom = AddOneDay(DateFrom);
//		}
//
//		return Days;
//
//	}
//
//	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
//	{
//		/*short Days = 0;
//		while (IsDate1BeforeDate2(DateFrom, DateTo))
//		{
//			if (IsBusinessDay(DateFrom))
//				Days++;
//
//			DateFrom = AddOneDay(DateFrom);
//		}*/
//
//		return CalculateBusinessDays(DateFrom, DateTo);
//
//	}
//	//above method is eough , no need to have method for the object
//
//	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
//	{
//
//		short WeekEndCounter = 0;
//
//		for (short i = 1; i <= VacationDays; i++)
//		{
//
//			if (IsWeekEnd(DateFrom))
//				WeekEndCounter++;
//
//			DateFrom = AddOneDay(DateFrom);
//		}
//		//to add weekends 
//		for (short i = 1; i <= WeekEndCounter; i++)
//			DateFrom = AddOneDay(DateFrom);
//
//		return DateFrom;
//	}
//
//	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
//	{
//		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
//
//	}
//
//	bool IsDateAfterDate2(clsDate Date2)
//	{
//		return IsDate1AfterDate2(*this, Date2);
//	}
//
//	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
//
//	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
//	{
//		if (IsDate1BeforeDate2(Date1, Date2))
//			return enDateCompare::Before;
//
//		if (IsDate1EqualDate2(Date1, Date2))
//			return enDateCompare::Equal;
//
//		/* if (IsDate1AfterDate2(Date1,Date2))
//			 return enDateCompare::After;*/
//
//			 //this is faster
//		return enDateCompare::After;
//
//	}
//
//	enDateCompare CompareDates(clsDate Date2)
//	{
//		return CompareDates(*this, Date2);
//	}
//
//
//
//};

