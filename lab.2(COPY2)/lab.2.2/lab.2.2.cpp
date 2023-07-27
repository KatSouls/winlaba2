#include <iostream>
#include <windows.h>
//#include "stdafx.h"
//2
using namespace std;


void writeFile(HANDLE desc, std::string strText) {
	// Write data to the file
	//strText = "Hello World!"; // For C use LPSTR (char*) or LPWSTR (wchar_t*)

	DWORD bytesWritten;
	WriteFile(
		desc,            // Handle to the file
		strText.c_str(),  // Buffer to write
		strText.size(),   // Buffer size
		&bytesWritten,    // Bytes written
		nullptr);         // Overlapped
}

int main(int argc, char* argv[])
{
	setlocale(0, "ru");
	//STARTUPINFO si;// структура,чтобы определить оконный терминал, рабочий стол, стандартный дескриптор и внешний вид основного окна дл¤ нового процесса.
	//ZeroMemory(&si, sizeof(si));// перед запуском консольного процесса все пол¤ структуры си должны быть заполнены 0 и это делаетс¤ в данной строке 
	//si.cb = sizeof(si);//выводит окно с размером по умолчанию
	//PROCESS_INFORMATION pi; //информаци¤ о недавно созданном процессе и его первичном потоке. 

	cout << "\t\nпод процесс запущен\n" << endl;
	for (int i = 0; i < argc; i++) {
		cout << "\t дескриптор(int): " << argv[i] << endl;
	}
	
	//конфиг
	TCHAR path1[] = L"C:\\Windows\\notepad.exe";
	TCHAR path2[] = L"C:\\Users\\нищий на знания\\Desktop\\винда лабы\\lab.2(COPY2)\\log.txt";
	TCHAR path3[] = L"C:\\Users\\нищий на знания\\Desktop\\винда лабы\\lab.2(COPY2)\\lab.2.2\\Debug\\lab.2.2.exe";


	setlocale(0, "ru");
	cout << "главный процесс запущен" << endl;

	//структура безопасности - для доступа к дескриптору созданных процессов +---------
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- 
	//notepad.exe

	STARTUPINFO si1;// структура,чтобы определить оконный терминал, рабочий стол, стандартный дескриптор и внешний вид основного окна для нового процесса.
	ZeroMemory(&si1, sizeof(si1));// перед запуском консольного процесса все поля структуры си должны быть заполнены 0 и это делается в данной строке 
	si1.cb = sizeof(si1);//выводит окно с размером по умолчанию
	PROCESS_INFORMATION pi1; //информация о недавно созданном процессе и его первичном потоке. 

	HANDLE desc1;
	HANDLE desc2 = NULL;
	desc1 = (HANDLE)atoi(argv[0]);
	if (argc == 2) //проверка дл¤ отсутстви¤ 2-ого агрумента
		desc2 = (HANDLE)atoi(argv[1]);


	//cout << "\t" << REALTIME_PRIORITY_CLASS << endl;

	cout << "\t\n";
	int menu = 1;
	while (menu > 0) {
		cout << "\t\n»зменить приоретет:\n\t1 - запустить процесс,\n\t2 - продолжить процесс,\n\t3 - завершить процесс,\n\t0 - выход из управл¤ющего процесса (под-процесса): ";
		cin >> menu;
		cout << "\n";
		switch (menu)
		{
		case 1:
			cout << "\tзапустить процесс\n";
			if (!CreateProcess(
				path1,
				NULL, //cmd -123
				&sa, //!!! указ. на структуру безоп. (атрибуты безопасности) +---------
				NULL, //тоже но поток
				FALSE, // флаг наследование текущ. процесса
				0,     // флаги способа созд. процесса
				NULL, // указ. на блок среды
				NULL, // текущ. диск (адрес)
				&si1, // указ. на струтуру сис. инфо.
				&pi1)) // указ на структ. проц. инфо.
			{
				cerr << "Процесс блокнот вернул ошибку: " << GetLastError() << endl;
			}
			else cout << "процесс блокнот запущен: ";
			break;
		case 2:
			cout << "\tустановлен нормальный приоритет\n";
			break;
		case 3:
			cout << "\tустановлен высокий приоритет\n";
			break;
		case 0:
			break;
		default:
			menu = 100;
			break;
		}
	}


	cout << "под процесс закрыт" << endl;
	system("pause");
	if (argc == 2) //проверка для отсутстви¤ 2-ого агрумента
		CloseHandle(desc1);
	

}


