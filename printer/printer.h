#ifndef _PRINTER_H_
#define _PRINTER_H_


#include <Windows.h>
#include <commdlg.h>
#include <string>

//#include <iostream>

#define LINE_OFFSET 5
#define SAMPLE_DOC_NAME L"Sample Docuemnt"



void printTextFile(HDC hdc, const std::wstring& textToPrint);
void printDocument(const std::wstring& textToPrint);


#endif