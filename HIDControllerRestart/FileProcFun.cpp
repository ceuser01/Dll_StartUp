#include  "FileProcFun.h"
#include "pch.h"






BOOL FileProcFun::Fun_IsFileExist(CString sPathName_x, HANDLE* h) //���� Ž�� �Լ�
{
	*h = CreateFile(sPathName_x, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	if (*h == INVALID_HANDLE_VALUE) {
		printf("BOOL DlgFileOpenTutorialFirst::IsFileExist(CString sPathName_x , HANDLE h) Error\n");
		//FIleOpenOutPut.SetWindowTextW(L"Setting���� ���� �����ϴ�. DlgFileOpenTutorialFirst::IsFileExist Error");//����� �޼���End
		printf("etting���� ���� �����ϴ�. DlgFileOpenTutorialFirst::IsFileExist Error");
		return FALSE;
	}
	return TRUE;
}

//fun_Find_Dir_size

BOOL FileProcFun::Fun_Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA* data) //���� Ž�� �Լ�
{
	HANDLE hFind = FindFirstFile(sPathName_x, data);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Error\n" << endl;
		return FALSE;
	}
	FindClose(hFind);
	return TRUE;
}

void FileProcFun::Fun_Read_Dir(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2) //���� Ž�� �Լ�
{
	LPDWORD checksum = 0;
	size_t size_x = data.nFileSizeLow + SAFETY; //������Ƽ�� ������ �� ����� ������ +1000���� �ؼ� ������ ���� �����
	Read = new char[size_x];
	memset(Read, NULL, (size_x) * sizeof(char));
	strUnicode2 = new wchar_t[size_x * 2 + SAFETY];
	memset(strUnicode2, 0, size_x * 2);
	while (true != ReadFile(*h, Read, size_x, checksum, 0)); //���� �Ҷ����� �Լ� ����ȣ��
	InTerrupt::HandleCheckSum_Close(*h);//�ڵ�Ŭ����
	MultiByteToWideChar(CP_ACP, 0, Read, strlen(Read), (LPWSTR)strUnicode2, size_x * 2);
	return;
}



void FileProcFun::Fun_Save_Dir(CString hFilePath, CString str) {
	//cout << "FileSave" << endl;
	HANDLE fd = CreateFile((LPCTSTR)hFilePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	InTerrupt::HandleCheckSum_x(fd);
	char* pMultibyte;
	ConversionLib::UniCodeConversion_mem_delete(pMultibyte, str);

	//UniCodeConversion_mem_delete
	if (!WriteFile(fd, pMultibyte, strlen(pMultibyte), NULL, NULL))
	{
		printf("����\n");
		return;
	}
	printf("���� ���� ����\n");
	InTerrupt::HandleCheckSum_Close(fd); //CloseHandle(fd);
}

BOOL FileProcFun::x_FindFiles(LPCTSTR path)
{
	DWORD dwAttrib = GetFileAttributes(path);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

BOOL FileProcFun::x_FindFilePath(CString& path)
{
	// ������ �̹� �����ϴ� ���, �ش� ��θ� ��ȯ
	if (FileProcFun::x_FindFiles(path)) {
		return TRUE;
	}

	// ��� ����� ���, ���� ���丮�� ���� ���丮�� ���� ���丮���� ������ ã��
	CString relativePath = path;
	if (relativePath.Find(_T(':')) < 0 && relativePath.Find('\\') < 0 && relativePath.Find('/') < 0) {
		TCHAR buffer[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, buffer);
		if (FileProcFun::x_FindFiles(CString(buffer) + _T('\\') + relativePath)) {
			path = CString(buffer) + _T('\\') + relativePath;
			return TRUE;
		}
		if (PathRemoveFileSpec(buffer)) {
			if (FileProcFun::x_FindFiles(CString(buffer) + _T('\\') + relativePath)) {
				path = CString(buffer) + _T('\\') + relativePath;
				return TRUE;
			}
		}
	}

	return FALSE;
}

#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <codecvt>
#pragma execution_character_set("utf-8")
#include <sstream>
#include <vector>


int FileProcFun::x_Fun_Read_Dir(int*& p_ptr, void*& p, char*& my_c_p_ReadData, int mode, int* p_dll_ptr) {
	int* P_dump_m;
	char** str_ptr;
	std::string unknown_str[50];// = "";
	int* P_dump_m_2;// = p_dll_ptr;
	int result = -1;
	switch (mode) {
	case POINTER_MODE:
		if (std::string(my_c_p_ReadData).find("erSize}=") != std::string::npos) {
			result = POINTER_MODE;
		}
		break;
	case TEXT_MODE:
		if (std::string(my_c_p_ReadData).find("ext}=") == std::string::npos || std::string(my_c_p_ReadData).size() < 5 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "XT") {
			result = TEXT_MODE;
		}
		break;
	case KEY_MODE_FRIST:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 4 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ey") {
			result = KEY_MODE_FRIST;
		}
		break;
	case KEY_MODE_SECOND:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 4 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ey") {
			result = KEY_MODE_SECOND;
		}
		break;
	case KEY_MODE_THIRD:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 3 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ze") {
			result = KEY_MODE_THIRD;
		}
		break;

	case KEY_MODE_FOURTH:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 3 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ze") {
			result = KEY_MODE_FOURTH;
		}
		break;
	case KEY_MODE_FIVE:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 3 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ze") {
			result = KEY_MODE_FIVE;
		}
		break;
	default:
		result = -1;
		break;
	}

	if (result == -1) {
		return result;
	}
	switch (result) {
	case POINTER_MODE: {
		size_t pos = std::string(my_c_p_ReadData).find("=");
		if (pos == std::string::npos)
			return -1;
		std::string substring = std::string(my_c_p_ReadData).substr(pos + 1);
		pos = substring.find(';');
		if (pos == std::string::npos)
			return -1;
		substring = substring.substr(0, pos);
		int pointer_size = std::stoi(substring, nullptr, 16);
		//p_dll_ptr = new int[pointer_size / sizeof(int)];
		//memset(p_dll_ptr, 0, pointer_size);
		//*p_dll_ptr = pointer_size;
		return mode;
	}
	case TEXT_MODE: {
		P_dump_m = p_dll_ptr;
		std::string str = std::string(my_c_p_ReadData);
		size_t pos = str.find("{loadText}=");
		if (pos != std::string::npos) {
			str = str.substr(pos + strlen("{loadText}="));
		}


		size_t start_pos = str.find("{");
		size_t end_pos = str.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str[debug] = str.substr(start_pos + 1, end_pos - start_pos - 1);
			//	std::cout << unknown_str[debug] << std::endl;
			start_pos = str.find("{", end_pos + 1);
			end_pos = str.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str[debug]);
			//std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str[i].size() + 1, unknown_str[i].c_str());
			char* char_ptr = str_ptr[i];

			memcpy(P_dump_m, char_ptr, 80);
			//	*P_dump_m = reinterpret_cast<int>(char_ptr); //�迭 ������ �ּ� �ֱ�
		//	printf("[%p]debug1\n", P_dump_m);
			P_dump_m = P_dump_m + 80 / 4;// ������ ������ ����
		}

		P_dump_m = p_dll_ptr; //���� �����ͷ� ������ ���� �ּ� ����.
		return mode;
	}
	case KEY_MODE_FRIST: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_FRIST;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key1dwButtons}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key1dwButtons}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			//std::cout << unknown_str[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str[debug]);
			//std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str[i].size() + 1, unknown_str[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str[i].size() + 1);
			//	printf("[%p]debug1\n", P_dump_m);
			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
	case KEY_MODE_SECOND: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_SECOND;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Setting_dll}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Setting_dll}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			//std::cout << unknown_str[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str[debug]);
			//	std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str[i].size() + 1, unknown_str[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str[i].size() + 1);
			//printf("[%p]debug1\n", P_dump_m);
			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}


	case KEY_MODE_THIRD: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_THIRD;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key3POV}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key3POV}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			//	std::cout << unknown_str[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str[debug]);
			//	std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str[i].size() + 1, unknown_str[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str[i].size() + 1);
			//	printf("[%p]debug1\n", P_dump_m);
			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
	case KEY_MODE_FOURTH: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_FOURTH;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key4dwSwitch}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key4dwSwitch}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			//std::cout << unknown_str[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str[debug]);
			//	std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str[i].size() + 1, unknown_str[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str[i].size() + 1);
			//	printf("[%p]debug1\n", P_dump_m);

			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
	case KEY_MODE_FIVE: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_FIVE;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key5JoySize}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key5JoySize}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			//std::cout << unknown_str[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str[debug]);
			//	std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str[i].size() + 1, unknown_str[i].c_str());
			char* char_ptr = str_ptr[i];
			//memcpy(P_dump_m, char_ptr, unknown_str[i].size() + 1);
		//	printf("[%p]debug1\n", P_dump_m);
			P_dump_m[i] = stoi(unknown_str[i]);
			//printf("zzz");
			//P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
					  break;
	default:
		return -1;
	}
	return result;
}



void FileProcFun::parseInfo(char* input, int* arr, size_t length) {
	std::istringstream ss(input);
	std::string line;
	int i = 0;

	while (getline(ss, line) && i < length) {
		std::string key = line.substr(0, line.find(":"));
		std::string value = line.substr(line.find(":") + 2);
		arr[i] = stoi(value);
		i++;
	}
}





#include <iostream>
#include <sstream>
#include <string>

using namespace std;





void FileProcFun::FileOn(LPVOID x_po) {
	int* p_dll_ptr;
	WIN32_FIND_DATA  filedata2; //���� ������ ��Ʈ����.
	int* p_ptr;// = (int*)x_po;
	int* p_dll_m = (int*)x_po;
	HANDLE hFile2;
	//CString  strpath2=L"C:\\Users\\BigPictures\\Desktop\\FristDll222222323\\FristDll\\Setting.txt";
	int num = 0;
	CString  strpath2 = L"CMS_Setting.ini";
	FileProcFun::x_FindFilePath(strpath2);
	int* switch_on_off2 = &num;
	char* my_c_p_ReadData = static_cast<char*>(static_cast<void*>(static_cast<int*>(x_po) + PARSER_OFFSET));
	wchar_t* str_p_Unicode2 = static_cast<wchar_t*>(static_cast<void*>(static_cast<int*>(x_po) + PARSER_OFFSET_UNICODE));

	InTerrupt::StruectureCheckSumFirst(*&switch_on_off2, str_p_Unicode2, my_c_p_ReadData); //������ �޸𸮸� ���ͺ� �ϴ� �Լ��̴�.

	FileProcFun::Fun_Find_Dir_size(strpath2, &filedata2);//strpath�� ��� �ȿ� filedata�� ��Ʈ��ó �����͸� ����ִ´�. size�� ����� ���� ��¥ ���� �����͸� �����´�.
	FileProcFun::Fun_IsFileExist(strpath2, &hFile2);//strpath�� ��� �ȿ� hFile�� hFile ũ����Ʈ���Ͼ� �����͸� �����´�.
	//��ο� hFile�ڵ� ������ �����´�. �ڵ� ������ &�� ���Ƽ� ������ó�� �����ҋ� ���ȯ �ϰ� �غ��Ѵ�. 
	FileProcFun::Fun_Read_Dir(*&my_c_p_ReadData, filedata2, &hFile2, *&str_p_Unicode2);
	//�ش� ����� �������� ������ �޸𸮿� �ø��� ĳ���Ѵ�. 
	InTerrupt::intTrue(*&switch_on_off2); //��Ȱ��ȭ ����ġ On
	void* pointersize;
	p_dll_ptr = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + PARSER_OFFSET_LOAD_DATA));

	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, POINTER_MODE, p_dll_ptr);
	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, TEXT_MODE, p_dll_ptr);
	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, KEY_MODE_FRIST, p_dll_ptr);
	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, KEY_MODE_SECOND, p_dll_ptr);
	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, KEY_MODE_THIRD, p_dll_ptr);
	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, KEY_MODE_FOURTH, p_dll_ptr);
	FileProcFun::x_Fun_Read_Dir(p_ptr, pointersize, *&my_c_p_ReadData, KEY_MODE_FIVE, p_dll_ptr);
	*p_dll_m = ENABLE;

}