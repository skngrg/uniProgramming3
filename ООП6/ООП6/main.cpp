#include "deque.h"
#include "mixfraction.h"
#include "resfraction.h"
#include "MyException.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	vector < fraction > v;
	vector < resfraction > vres;
	vector < mixfraction > vmix;
	deque D;

	for (;;) {
		try {
			system("cls");
			cout << "1. �������� �����" << endl;
			cout << "2. ������� �����" << endl;
			cout << "3. ������� �� ������ ������" << endl;
			cout << "4. �������� �����" << endl;
			cout << "5. ��������� ������ �� ������" << endl;
			cout << "6. ������� ������ ���� ������" << endl;
			cout << "7. ��������� ����� �� �����" << endl;
			cout << "8. ������� ��� ����� � ����" << endl;
			cout << "9. ������� ��� ����� � �������� ����" << endl;
			cout << "10. ������ ����� �� ��������� �����" << endl;

			cout << endl;

			cout << "11. �������� ����� � �����������" << endl;
			cout << "12. ������� ����� � �����������" << endl;
			cout << "13. ������� �� ������ ������ � �����������" << endl;
			cout << "14. �������� ����� � �����������" << endl;
			cout << "15. ��������� ������ �� ������ � �����������" << endl;
			cout << "16. ������� ������ ���� ������ � �����������" << endl;

			cout << endl;

			cout << "17. �������� ��������� �����" << endl;
			cout << "18. �������  ��������� �����" << endl;
			cout << "19. ������� ��  ��������� ������ ������ ���������" << endl;
			cout << "20. �������� ��������� �����" << endl;
			cout << "21. ������� ������ ���� ��������� ������" << endl;

			cout << endl;

			cout << "22. �������� ����� � ����� ����" << endl;
			cout << "23. �������� ����� � ������ ����" << endl;
			cout << "24. �������� ��������� ����� � ����� ����" << endl;
			cout << "25. �������� ��������� ����� � ������ ����" << endl;
			cout << "26. �������� ����� � ����������� � ����� ����" << endl;
			cout << "27. �������� ����� � ����������� � ������ ����" << endl;
			cout << "28. ������� ����� �� ������ ����" << endl;
			cout << "29. ������� ��� � �������" << endl;
			cout << "30. ������� ��� � �������� ����" << endl;
			cout << "31. ������ ��� �� ��������� �����" << endl;
			cout << "32. ������� getBeginPtr()" << endl;
			cout << "33. ������� ���������� �� ������� �����" << endl;
			int a, b, c;

			cin >> c;
			system("cls");

			switch (c)
			{
			case 0: return 0;
			case 1: {
				cout << "���� �����\n";
				fraction F;
				cin >> F;
				v.push_back(F);
				break;
			}
			case 2:
				cout << "��������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				v.push_back(v[a] + v[b]);
				cout << v.back().getStr();
				cout << endl;
				break;
			case 3:
				cout << "���������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				v.push_back(v[a] - v[b]);
				cout << v.back().getStr();
				cout << endl;
				break;
			case 4:
				cout << "���������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				v.push_back(v[a] * v[b]);
				cout << v.back().getStr();
				cout << endl;
				break;
			case 5:
				cout << "�������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				v.push_back(v[a] / v[b]);
				cout << v.back().getStr();
				cout << endl;
				break;
			case 6:
				for (auto i : v) cout << i << endl;
				cout << endl;
				break;
			case 7: {
				ifstream fin("in.txt", ios::in);

				if (!fin) {
					cout << "Input file stream error!" << endl;
					return 1;
				}

				while (!fin.eof()) {
					fraction F;
					fin >> F;
					v.push_back(F);
				}
				fin.close();
				break;
			}
			case 8: {
				ofstream fout("out.txt", ios::out | ios::binary);

				if (!fout) {
					cout << "Output file stream error!" << endl;
					return 1;
				}

				for (auto i : v) fout << i << endl;
				fout.close();
				break;
			}
			case 9: {
				ofstream bin("out.bin", std::ios::binary);
				for (auto i : v) i.writeBin(bin);
				bin.close();
				break;
			}
			case 10: {
				ifstream bin("out.bin", std::ios::binary);
				fraction F;
				while (F.readBin(bin)) v.push_back(F);
				bin.close();
				break;
			}
			case 11: {
				cout << "���� �����\n";
				resfraction F;
				cin >> F;
				vres.push_back(F);
				break;
			}
			case 12:
				cout << "��������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vres.push_back(vres[a] + vres[b]);
				cout << vres.back().getStr();
				cout << endl;
				break;
			case 13:
				cout << "���������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vres.push_back(vres[a] - vres[b]);
				cout << vres.back().getStr();
				cout << endl;
				break;
			case 14:
				cout << "���������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vres.push_back(vres[a] * vres[b]);
				cout << vres.back().getStr();
				cout << endl;
				break;
			case 15:
				cout << "�������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vres.push_back(vres[a] / vres[b]);
				cout << vres.back().getStr();
				cout << endl;
				break;
			case 16:
				for (auto i : vres) cout << i << endl;
				cout << endl;
				break;
			case 17: {
				cout << "���� �����\n";
				mixfraction F;
				cin >> F;
				vmix.push_back(F);
				break;
			}
			case 18:
				cout << "��������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vmix.push_back(vmix[a] + vmix[b]);
				cout << vmix.back().getUnit() << ' ' << vmix.back().getStr();
				cout << endl;
				break;
			case 19:
				cout << "���������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vmix.push_back(vmix[a] - vmix[b]);
				cout << vmix.back().getUnit() << ' ' << vmix.back().getStr();
				cout << endl;
				break;
			case 20:
				cout << "���������\n������� ������ ������ ����� ������: ";
				cin >> a >> b;
				vmix.push_back(vmix[a] * vmix[b]);
				cout << vmix.back().getUnit() << ' ' << vmix.back().getStr();
				cout << endl;
				break;
			case 21:
				for (auto i : vmix) cout << i << endl;
				cout << endl;
				break;
			case 22://�������� ����� � ����� ������
			{
				fraction F;
				cout << "������� �����\n";
				cin >> F;
				D.push_back(new fraction(F));
			}
			break;
			case 23://�������� ����� � ������ ������
			{
				fraction F;
				cout << "������� �����\n";
				cin >> F;
				D.push_front(new fraction(F));
			}
			break;
			case 24://�������� ��������� ����� � ����� ������
			{
				mixfraction F;
				cout << "������� �����\n";
				cin >> F;
				D.push_back(new mixfraction(F));
			}
			break;
			case 25://�������� ��������� ����� � ������ ������
			{
				mixfraction F;
				cout << "������� �����\n";
				cin >> F;
				D.push_front(new mixfraction(F));
			}
			break;
			case 26://�������� ����� � ����������� � ����� ������
			{
				resfraction F;
				cout << "������� �����\n";
				cin >> F;
				D.push_back(new resfraction(F));
			}
			break;
			case 27://�������� ����� � ����������� � ������ ������
			{
				resfraction F;
				cout << "������� �����\n";
				cin >> F;
				D.push_front(new resfraction(F));
			}
			break;
			case 28://������� ����� �� ������ ������
				delete D.pop_front();
				break;
			case 29://����� ���� � �������
				cout << D << endl;
				break;
			case 30://����� ���� � ��������
			{
				ofstream bin("out.bin", std::ios::binary);
				D.writeBin(bin);
				bin.close();
				break;
			}
			case 31://�� ���������
			{
				ifstream bin("out.bin", std::ios::binary);
				D.readBin(bin);
				bin.close();
				break;
			}
			case 32:
			{
				D.getBeginPtr();
				break;
			}
			case 33:
			{
				ifstream bin("out.bin", std::ios::binary);
				fraction F;
				//while (F.readBin(bin)) v.push_back(F);
				F.readBin(bin);
				bin.close();
				break;
			}
			default:
				break;
			}
		}
		catch (aut_of_range& ex)
		{
			cout << ex.get_name() << ':' << ex.what() << endl;
		}
		catch (deque_exception& ex)
		{
			cout << ex.get_name() << ':' << ex.what() << endl;
		}
		catch (file_exception& ex)
		{
			cout << ex.get_name() << ':' << ex.what() << endl;
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
		}
		catch (...)
		{
			cout << "����������� ������" << endl;
		}
		system("Pause");
	}
}