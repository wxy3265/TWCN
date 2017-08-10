#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

int main (int argc, char *argv[]) //argv[1]为文件地址
{
	
	if (argv[1] == NULL) {
		cerr << "未指明文件地址" << endl;
		return 1;
	}//错误处理

	string a; //创建储存字符串的变量a
	char c; //创建直接性储存输入字符的临时过渡变量c
	int i;
	int hlong;//用于储存字符串长度
	
	const string FILE_NAME = argv[1];//文件名

	//创建输入输出流
	ifstream fin;
	ofstream fout;

	//打开文件
	fin.open(FILE_NAME);

	if(! fin.is_open()) {
		cerr << "打开文件出错" << endl;
		return 1;
	} //错误处理

	char ch;//用于储存输入字符

	while(fin.read(&ch, 1))	{
		//fin.read(&ch, 1);
		a += ch;
	}//读取文件至string类变量a
	
	//打印文件内容
	cout << a;

	while(1) {
		
		c = getch(); //输入字符
		
		if (c == '\e') //如果输入"ESC"则结束
			break;
			
		else if (c == 13) //如果输入"ENTER"则换行
			c = '\n';

		if (c == '\b'){
			
			hlong = a.size() - 1;
			
			if (a.back() == '\n') {
				a.erase(hlong); //删除a中的最后一个字符
				system("cls");
				cout << a;
			}

			else { //如果光标不是位于本行第一个字符则执行向前去位
				cout << "\b \b";
				a.erase(hlong);//删除a中的最后一个字符
			}
			
		}

		else { //如果不是特殊字符则直接将字符加入到变量a中并打印
			a += c;
			cout << c;
		}

	} 
	
//删除原有未修改文件
	DeleteFile(FILE_NAME.c_str());
//创建空白文件
	fout.open(FILE_NAME, ios::out);
//将已更改的文字内容写入文件
	fout << a;
//关闭已使用的文件
	fout.close();
	fin.close();
	
	return 0;

}

/*
Log:
	~2017/8/3 18:50	创建项目
	~2017/8/3 20:50 完成基本文输入
	~2017/8/5 21:15 完成GitHub库的创建与上传
	~2017/8/10 9:28 修复bug*2
*/
