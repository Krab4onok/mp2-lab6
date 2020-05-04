#pragma once
#define _TText_h_

#include "TTextLink.h"
#include "TStack.h"
#include <string>

class TText
{
	TTextLink* pFirst;
	TTextLink* pCurr;
	TStack<TTextLink*> stack;

public:

	TText(); //констуктор
	void GoFirstLink(); //перейти в начало
	void GoDownLink(); //перейти в глубь
	void GoNextLink(); //перейти на следующую
	void GoPrevLink(); //перейти на предшествующую
	void SetLine(std::string astr); //вставить строку
	std::string GetLine(); //получить строку

	//МОДИФИКАЦИЯ ТЕКСТА

	void InsNextLine(std::string astr); //вставить следующую строку
	void InsNextSection(std::string astr); //добавить секцию
	void InsDownLine(std::string astr); //вставить строку на уровень ниже
	void InsDownSection(std::string astr); //вставить секцию на уровень ниже
	void DelNext(); //удалить следующую строку
	void DelDownLine(); //удалить строку на уровень ниже

	//ЧТЕНИЕ И ЗАПИСЬ

	void Read(std::string fn); //чтение файла
	TTextLink* ReadRec(std::ifstream& ifs); //считать строки из файла
	void Write(std::string fn); //запись в файл
	void WriteRec(std::ofstream& ofs, TTextLink* pWC); // рекурсивная версия записи
	void ConsolePrint(); //вывести в консоль
	void ConsolePrintRec(TTextLink* pWC); // рекурсивный вывод в консоль

	//НАВИГАЦИЯ ПО ТЕКСТУ

	int Reset(); //перейти на первую строку
	int IsEnd(); //проверка на конец
	int GoNext(); //переход на следующую строку
};
