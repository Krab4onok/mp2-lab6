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
		cout << "������� 'help' ����� ������� ������ ������" << endl;
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
			cout << "print - ������ ������ � ���������" << endl;
			cout << "printit - ������ ������ ��� ��������� �� ���������" << endl;
			cout << "first -������� � ������ ������" << endl;
			cout << "next - ������� �� ��������� ������" << endl;
			cout << "down - ������� �� ������ � �����" << endl;
			cout << "prev - ������� �� ����������" << endl;
			cout << "deleted - ������� ������ �� ������� ����" << endl;
			cout << "deleten - ������� ��������� ������" << endl;
			cout << "insertdl - �������� ������ �� ������� ����" << endl;
			cout << "insertds - �������� ������ �� ������� ����" << endl;
			cout << "insertnl - �������� ������ �� ����� ���������" << endl;
			cout << "insertns - �������� ������ �� ����� ���������" << endl;
			cout << "free -�������� ��������� ������" << endl;
			cout << "exit - ������� ���������" << endl;
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