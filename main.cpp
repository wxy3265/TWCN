#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

int main (int argc, char *argv[]) //argv[1]Ϊ�ļ���ַ
{
	
	if (argv[1] == NULL) {
		cerr << "δָ���ļ���ַ" << endl;
		return 1;
	}//������

	string a; //���������ַ����ı���a
	char c; //����ֱ���Դ��������ַ�����ʱ���ɱ���c
	int i;
	int hlong;//���ڴ����ַ�������
	
	const string FILE_NAME = argv[1];//�ļ���

	//�������������
	ifstream fin;
	ofstream fout;

	//���ļ�
	fin.open(FILE_NAME);

	if(! fin.is_open()) {
		cerr << "���ļ�����" << endl;
		return 1;
	} //������

	char ch;//���ڴ��������ַ�

	while(fin.read(&ch, 1))	{
		//fin.read(&ch, 1);
		a += ch;
	}//��ȡ�ļ���string�����a
	
	//��ӡ�ļ�����
	cout << a;

	while(1) {
		
		c = getch(); //�����ַ�
		
		if (c == '\e') //�������"ESC"�����
			break;
			
		else if (c == 13) //�������"ENTER"����
			c = '\n';

		if (c == '\b'){
			
			hlong = a.size() - 1;
			
			if (a.back() == '\n') {
				a.erase(hlong); //ɾ��a�е����һ���ַ�
				system("cls");
				cout << a;
			}

			else { //�����겻��λ�ڱ��е�һ���ַ���ִ����ǰȥλ
				cout << "\b \b";
				a.erase(hlong);//ɾ��a�е����һ���ַ�
			}
			
		}

		else { //������������ַ���ֱ�ӽ��ַ����뵽����a�в���ӡ
			a += c;
			cout << c;
		}

	} 
	
//ɾ��ԭ��δ�޸��ļ�
	DeleteFile(FILE_NAME.c_str());
//�����հ��ļ�
	fout.open(FILE_NAME, ios::out);
//���Ѹ��ĵ���������д���ļ�
	fout << a;
//�ر���ʹ�õ��ļ�
	fout.close();
	fin.close();
	
	return 0;

}

/*
Log:
	~2017/8/3 18:50	������Ŀ
	~2017/8/3 20:50 ��ɻ���������
	~2017/8/5 21:15 ���GitHub��Ĵ������ϴ�
	~2017/8/10 9:28 �޸�bug*2
*/
