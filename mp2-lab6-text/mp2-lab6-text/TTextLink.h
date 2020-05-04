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

//value object class for lines of text
class TTextLink {

protected:
	TTextLink* pNext, * pDown;
	static TTextMem MemHeader; //memory management system
	friend class TText;
public:

	TStr str;
	int recD;
	static void InitMemSystem(int size = MemSize); //memory initialization
	static void PrintFreeLink(void); //printing of free links
	void* operator new (size_t size); //link allocation
	void operator delete (void* pM); //link release
	static void MemCleaner(TText& txt); //garbage collection

	//Constructor
	TTextLink(const TStr c = NULL, TTextLink* pn = NULL, TTextLink* pd = NULL) {
		recD = 0;
		pNext = pn;
		pDown = pd;
		if (c == NULL)
			str[0] = '\0';
		else
			strcpy_s(str, c);
	}

	//Destructor
	~TTextLink() {
		///
	}
};