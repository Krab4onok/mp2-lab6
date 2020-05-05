#include <conio.h>
#include <iostream>
#include <string>
#include "TText.h"
#include <clocale>


using namespace std;

TTextMem TTextLink::MemHeader;

void TextMenu(TText& txt) {
	string st;
	string com;
	setlocale(LC_CTYPE, "Russian");

	do {
		cout << "введите 'help' чтобы увидить список команд" << endl;
		cin >> com;
		if (com == "exit") {
		}
		if (com == "print") {
			txt.ConsolePrint();
		}
		if (com == "printit") {
			cout << endl << "printing iterator" << endl;
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
				cout << txt.GetLine() << endl;
			}
		}
		if (com == "first") {
			txt.GoFirstLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "down") {
			txt.GoDownLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "next") {
			txt.GoNextLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "prev") {
			txt.GoPrevLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "deleted") {
			txt.DelDownLine();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "deleten") {
			txt.DelNext();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "insertdl") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownLine(st);
		}
		if (com == "insertds") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownSection(st);
		}
		if (com == "insertnl") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextLine(st);
		}
		if (com == "insertns") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextSection(st);
		}
		if (com == "free") {
			TTextLink::PrintFreeLink();
		}

		if (com == "help") {
			cout << "print - печать текста с отступами" << endl;
			cout << "printit - печать текста без отстутпов по итератору" << endl;
			cout << "first -перейти в начало текста" << endl;
			cout << "next - перейти на следующую строку" << endl;
			cout << "down - перейти на строку в глубь" << endl;
			cout << "prev - перейти на предыдущую" << endl;
			cout << "deleted - удалить строку на уровень ниже" << endl;
			cout << "deleten - удалить следующую строку" << endl;
			cout << "insertdl - добавить строку на уровень ниже" << endl;
			cout << "insertds - добавить секцию на уровень ниже" << endl;
			cout << "insertnl - добавить строку на место следующей" << endl;
			cout << "insertns - добавить секцию на место следующей" << endl;
			cout << "free -показать свободную память" << endl;
			cout << "exit - закрыть программу" << endl;
		}
	} while (com != "exit");
}

int main() {
	TTextLink::InitMemSystem(100);
	TText t;
	t.Read("../textin.txt");
	//t.Write("../textout.txt");

	TextMenu(t);
	t.Write("../textout.txt");

	TTextLink::MemCleaner(t);
	TTextLink::PrintFreeLink();
}