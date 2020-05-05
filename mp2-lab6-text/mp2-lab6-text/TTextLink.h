#pragma once
#define _TTextLink_h_
#include <string>

#define TTextLineLength 80
#define MemSize 100

class TText;
class TTextLink;

typedef char TStr[TTextLineLength];

struct TTextMem {
	TTextLink* pFirst; //указатель на первую строку
	TTextLink* pLast; //указатель на последнюю
	TTextLink* pFree; //указатель на свободную
	friend class TTextLink;
};


class TTextLink {

protected:
	TTextLink* pNext, * pDown;
	static TTextMem MemHeader; //система контроля памяти
	friend class TText;
public:

	TStr str;
	int recD;
	static void InitMemSystem(int size = MemSize); //инициализация памяти
	static void PrintFreeLink(void); //печать свободных строк
	void* operator new (size_t size); //переопределение new
	void operator delete (void* pM); //переопределение delete
	static void MemCleaner(TText& txt); //сборка мусора

	//Конструктор
	TTextLink(const TStr c = NULL, TTextLink* pn = NULL, TTextLink* pd = NULL) {
		recD = 0;
		pNext = pn;
		pDown = pd;
		if (c == NULL)
			str[0] = '\0';
		else
			strcpy_s(str, c);
	}

	//Деструктор
	~TTextLink() {
		///
	}
};