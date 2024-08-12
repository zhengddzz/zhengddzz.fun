#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
char inw[105],outw[105];
string csdwj;
/*---------------------------------------------------------*/
void rintf(string str)//输出优化
{
	int cd=str.length();
	for(int i=0;i<cd;i++)
	{
		if(str[i]==char(92)&&str[i+1]=='n')
		{
			cout<<endl;
			i+=2;
		}
		else cout<<str[i];
		Sleep(5);
	}
}
/*---------------------------------------------------------*/
//标准答案程序运行区
void main1(int l)
{
	std::string sz = std::to_string(l);
	std::string runCommand = "data.exe < " + sz + ".in > " + sz + ".out";
	std::cout<<runCommand<<std::endl;
	int runResult = system(runCommand.c_str());
	
	if (runResult == 0) {
		std::cout<< "data.exe 执行成功，输出已保存到 " << sz << ".out" << std::endl;
	} else {
		std::cerr << "运行文件时出错" << std::endl;
		return ;
	}
}
bool css() {
	// 编译 data.cpp
	std::string compileCommand = "g++ -o data.exe data.cpp";
	int compileResult = system(compileCommand.c_str());
	if (compileResult != 0) {
		std::cerr << "编译 data.cpp 失败" << std::endl;
		return 0;
	}
	else std::cout <<"data.cpp 编译成功" << std::endl;
	return 1;
}
/*---------------------------------------------------------*///文件选择

namespace fs = std::filesystem;

std::vector<std::string> getCppFilesInDirectory(const std::string& directory) {
	std::vector<std::string> cppFiles;
	
	for (const auto& entry : fs::directory_iterator(directory)) {
		if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
			cppFiles.push_back(entry.path().filename().string());
		}
	}
	
	return cppFiles;
}

std::string selectCppFile(const std::vector<std::string>& cppFiles) {
	if (cppFiles.empty()) {
		std::cout << "当前目录中没有 .cpp 文件。" << std::endl;
		return "";
	}
	
	std::cout << "请选择一个 .cpp 文件（输入对应的数字），或按 't' 退出：" << std::endl;
	for (size_t i = 0; i < cppFiles.size(); ++i) {
		std::cout << i + 1 << ". " << cppFiles[i] << std::endl;
	}
	
	while (true) {
		std::cout << "请输入你的选择（1-" << cppFiles.size() << "）或 't' 退出: ";
		
		std::string input;
		std::getline(std::cin, input);
		
		if (input == "t" || input == "T") {
			return "";  // 用户选择退出
		}
		
		try {
			size_t choice = std::stoi(input);
			if (choice >= 1 && choice <= cppFiles.size()) {
				return cppFiles[choice - 1];
			}
		} catch (const std::exception&) {
			// 转换失败，继续循环
		}
		
		std::cout << "无效的选择，请重试。" << std::endl;
	}
}

void xz() {
	std::string currentPath = fs::current_path().string();
	
	std::cout << "当前目录: " << currentPath << std::endl;
	
	std::vector<std::string> cppFiles = getCppFilesInDirectory(currentPath);
	
	if (cppFiles.empty()) {
		std::cout << "当前目录中没有 .cpp 文件。" << std::endl;
		return ;
	}
	
	std::cout << "当前目录中的 .cpp 文件：" << std::endl;
	for (const auto& file : cppFiles) {
		std::cout << file << std::endl;
	}
	
	std::string selectedFile = selectCppFile(cppFiles);
	
	if (!selectedFile.empty()) {
		std::cout << "你选择的 .cpp 文件是: " << selectedFile << std::endl;
	} else {
		std::cout << "你选择退出程序。" << std::endl;
	}
}
/*---------------------------------------------------------*/
void cs()
{
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);
	GetConsoleMode(hOut, &dwOutMode);
	dwInMode |= 0x0200;
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);
	SetConsoleMode(hOut, dwOutMode);
}

void color(int wr,int wg,int wb,int br,int bg,int bb){printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm",wr,wg,wb,br,bg,bb);}
struct file
{
	int bc1,bc2,bc3,zc1,zc2,zc3;
}file;
void saveGame()
{
	ofstream file("file.dat", ios::out|ios::binary);
	file.write((char*)&file, sizeof(file));
	file.close();
}
void readGame()
{
	ifstream file("file.dat", ios::in|ios::binary);
	if(!file) return;
	file.read((char*)&file, sizeof(file));
	file.close();
}
/*---------------------------------------------------------*/
//文件读写
long long scn,scm,scn_,_scn,scm_,_scm,sck,sck_,_sck;
long long sca_,_sca,scb_,_scb;
char sclx,sclx2;
/*---------------------------------------------------------*/
//生成输入文件
void sc(int lx)
{
	ofstream out(inw);
	if(lx==1||lx==2||lx==3||lx==4||lx==-1||lx==-2||lx==-3)
	{
		scn=rand()%(_scn-scn_+1)+scn_;
		out<<scn<<' ';
	}
	if(lx==2||lx==3||lx==4||lx==-2||lx==-3)
	{
		scm=rand()%(_scm-scm_+1)+scm_;
		out<<scm<<' ';
	}
	if(lx==-3)
	{
		sck=rand()%(_sck-sck_+1)+sck_;
		out<<scm<<' ';
	}
	if(lx==1||lx==2||lx==3||lx==4) out<<endl;
	if(lx==1||lx==2||lx==3||lx==4)
		for(long long i=1;i<=scn;i++) out<<rand()%(_sca-sca_+1)+sca_<<' ';
	out<<endl;
	if(lx==4)
		for(long long i=1;i<=scm;i++) out<<rand()%(_scb-scb_+1)+scb_<<' ';
	out<<endl;
	out.close();
}
/*---------------------------------------------------------*/
void hellosc()
{
	long long sl;
	while(1)
	{
		rintf("请输入测试点文件生成数量（1-1000个）：");
		cin>>sl;
		if(sl>1000)//修复
		{
			Sleep(500);
			rintf("超出规定数量（为了你的电脑着想）！");
			Sleep(1000);
			system("cls");
			rintf("是否仍然继续（y/n）");
			char l;
			l=char(getch());
			if(l=='y')
			{
				rintf("确认（y/n）？我们对您电脑的受损不承担相应责任！");
				l=char(getch());
				if(l=='y') break;
				Sleep(1000);
				system("cls");
			}
		}
		else break;
	}
	long long bbh;
	while(1)
	{
		rintf("请输入测试点文件开始编号：（-1000~1000）");
		cin>>bbh;
		if(bbh>1000||bbh<-1000)
		{
			Sleep(500);
			rintf("超出规定数值！");
			Sleep(1000);
			system("cls");
		}
		else break;
	}
	for(int i=bbh;i<sl+bbh;i++)
	{
		string ins=to_string(i)+".in";
		string outs=to_string(i)+".out";
		strcpy(inw,ins.c_str());
		strcpy(outw,outs.c_str());
		sc(sclx-'0');main1(i);
	}
	rintf("生成已完成！\n");
	Sleep(500);
	cout<<"按任意键继续……";
	_getch();
	system("cls");
}
void sr(int ll)//测试点范围录入
{
	if(ll==1||ll==2||ll==3||ll==4||ll==-1||ll==-2||ll==-3)
	{
		while(1)
		{
			rintf("请输入n的范围（最小值 最大值）\n");
			cin>>scn_>>_scn;
			if(scn_>_scn)
			{
				Sleep(500);
				rintf("最小值大于最大值！");
				Sleep(1000);
				system("cls");
			}
			else break;
		}
	}
	Sleep(100);
	if(ll==2||ll==3||ll==4||ll==-2||ll==-3)
	{
		while(1)
		{
			rintf("请输入m的范围（最小值 最大值）\n");
			cin>>scm_>>_scm;
			if(scm_>_scm)
			{
				Sleep(500);
				rintf("最小值大于最大值！");
				Sleep(1000);
				system("cls");
			}
			else break;
		}
	}
	Sleep(100);
	if(ll==1||ll==2||ll==3||ll==4)
	{
		while(1)
		{
			rintf("请输入a数组的范围（最小值 最大值）\n");
			cin>>sca_>>_sca;
			if(sca_>_sca)
			{
				Sleep(500);
				rintf("最小值大于最大值！");
				Sleep(1000);
				system("cls");
			}
			else break;
		}
	}
	if(ll==4)
	{
		while(1)
		{
			rintf("请输入b数组的范围（最小值 最大值）\n");
			cin>>scb_>>_scb;
			if(scb_>_scb)
			{
				Sleep(500);
				rintf("最小值大于最大值！");
				Sleep(1000);
				system("cls");
			}
			else break;
		}
	}
	if(ll==-3)
	{
		while(1)
		{
			rintf("请输入k的范围（最小值 最大值）\n");
			cin>>sck_>>_sck;
			if(sck_>_sck)
			{
				Sleep(500);
				rintf("最小值大于最大值！");
				Sleep(1000);
				system("cls");
			}
			else break;
		}
	}
	Sleep(500);
	rintf("输入已完成！\n");
	Sleep(1000);
	system("cls");
}
bool hello1()///欢迎界面
{
	Sleep(500);
	cx:;
	system("cls");
	cout<<"            生成测试点界面"<<endl;
	cout<<"+------+----------------------------+\n";
	cout<<"| 编号 |            格式            |\n";
	cout<<"+------+----------------------------+\n";
	cout<<"|  01  | n;                         |\n";
	cout<<"|      | a[1],a[2],……,a[n-1],a[n]   |\n";
	cout<<"+------+----------------------------+\n";
	cout<<"|  02  | n,m;                       |\n";
	cout<<"|      | a[1],a[2],……,a[n-1],a[n]   |\n";
	cout<<"+------+----------------------------+\n";
	cout<<"|  03  | n,m;                       |\n";
	cout<<"|      | a[1],a[2],……,a[m-1],a[m]   |\n";
	cout<<"+------+----------------------------+\n";
	cout<<"|  04  | n,m;                       |\n";
	cout<<"|      | a[1],a[2],……,a[n-1],a[n]   |\n";
	cout<<"|      | b[1],b[2],……,b[m-1],b[m]   |\n";
	cout<<"+------+----------------------------+\n";
	cout<<"退出请按t,进入无数组测试点生成界面请按 - （减号）\n";
	Sleep(1000);
	rintf("请输入测试点输入文件生成类型（编号）");
	sclx=char(getch());
	Sleep(500);
	system("cls");
	if(sclx=='1')
	{
		rintf("测试点生成类型（编号）：01\n");
		cout<<"+-----------------------------+\n";
		cout<<"| n;                          |\n";
		cout<<"| a[1],a[2],……,a[n-1],a[n]    |\n";
		cout<<"+-----------------------------+\n";
	}
	else if(sclx=='2')
	{
		rintf("测试点生成类型（编号）：02\n");
		cout<<"+------+----------------------------+\n";
		cout<<"|  02  | n,m;                       |\n";
		cout<<"|      | a[1],a[2],……,a[n-1],a[n]   |\n";
		cout<<"+------+----------------------------+\n";
	}
	else if(sclx=='3')
	{
		rintf("测试点生成类型（编号）：03\n");
		cout<<"+------+----------------------------+\n";
		cout<<"|  03  | n,m;                       |\n";
		cout<<"|      | a[1],a[2],……,a[m-1],a[m]   |\n";
		cout<<"+------+----------------------------+\n";
	}
	else if(sclx=='4')
	{
		rintf("测试点生成类型（编号）：04\n");
		cout<<"+------+----------------------------+\n";
		cout<<"|  04  | n,m;                       |\n";
		cout<<"|      | a[1],a[2],……,a[n-1],a[n]   |\n";
		cout<<"|      | b[1],b[2],……,b[m-1],b[m]   |\n";
		cout<<"+------+----------------------------+\n";
	}
	else if(sclx=='t'||sclx=='T')
	{
		rintf("已退出！");
		Sleep(500);
		return 0;
	}
	else if(sclx=='-')
	{
		Sleep(500);
		ccx:;
		system("cls");
		cout<<"            生成测试点界面"<<endl;
		cout<<"+------+----------------------------+\n";
		cout<<"| 编号 |            格式            |\n";
		cout<<"+------+----------------------------+\n";
		cout<<"|  01  | n;                         |\n";
		cout<<"+------+----------------------------+\n";
		cout<<"|  02  | n,m;                       |\n";
		cout<<"+------+----------------------------+\n";
		cout<<"|  03  | n,m,k;                     |\n";
		cout<<"+------+----------------------------+\n";
		cout<<"退出请按t\n";
		Sleep(1000);
		rintf("请输入测试点输入文件生成类型（编号）");
		sclx2=char(getch());
		Sleep(500);
		system("cls");
		if(sclx2=='1')
		{
			rintf("测试点生成类型（编号）：01\n");
			cout<<"+-----------------------------+\n";
			cout<<"| n;                          |\n";
			cout<<"+-----------------------------+\n";
		}
		if(sclx2=='2')
		{
			rintf("测试点生成类型（编号）：02\n");
			cout<<"+----------------------------+\n";
			cout<<"| n,m;                       |\n";
			cout<<"+----------------------------+\n";
		}
		if(sclx2=='3')
		{
			rintf("测试点生成类型（编号）：03\n");
			cout<<"+-----------------------------+\n";
			cout<<"| n,m,k;                      |\n";
			cout<<"+-----------------------------+\n";
		}
		else if(sclx2=='t'||sclx2=='T')
		{
			rintf("已退出！");
			Sleep(500);
			return 0;
		}
		else
		{
			rintf("请不要输入其他字符（编号前缀0不需要输入）！");
			Sleep(1000);
			goto ccx;
		}
	}
	else
	{
		rintf("请不要输入其他字符（编号前缀0不需要输入）！");
		Sleep(1000);
		goto cx;
	}
	Sleep(1000);
	system("cls");
	return 1;
}
/*---------------------------------------------------------*/
//设置
void gx()
{
	cx:
	cout<<"1.外观"<<endl;
	cout<<"2.安全"<<endl;
	cout<<"3.退出个性化设置"<<endl;
	char lxx;
	lxx=char(getch());
	Sleep(500);
	system("cls");
	if(lxx=='1')
	{
		cout<<"1.背景颜色"<<endl;
		cout<<"2.字体颜色"<<endl;
		cout<<"3.退出外观设置"<<endl;
		char lxxx;
		lxxx=char(getch());
		Sleep(500);
		system("cls");
		if(lxxx=='1')
		{
			
		}
		
	}
	else if(lxx=='2')
	{
		
	}
	else if(lxx=='3')
	{
		rintf("已退出！");
		Sleep(500);
		return;
	}
	else
	{
		rintf("请不要输入其他字符！");
		Sleep(1000);
		goto cx;
	}
}
void gy()
{
	
}
void sz()
{
	cx:
	cout<<"1.个性化"<<endl;
	cout<<"2.关于此应用"<<endl;
	cout<<"3.退出设置"<<endl;
	char lxx;
	lxx=char(getch());
	Sleep(500);
	system("cls");
	if(lxx=='1')
	{
		gx();
	}
	else if(lxx=='2')
	{
		gy();
	}
	else if(lxx=='3')
	{
		rintf("已退出！");
		Sleep(500);
		return;
	}
	else
	{
		rintf("请不要输入其他字符！");
		Sleep(1000);
		goto cx;
	}
}
/*---------------------------------------------------------*/
int main()
{
	SetConsoleTitle("测试点生成软件");
	cs();
	readGame();
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(),GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	while(1)
	{
		system("cls");
		cout<<"1.加载标准程序"<<endl;
		cout<<"2.生成测试点"<<endl;
		cout<<"3.设置(手搓中)"<<endl;
		cout<<"4.退出软件"<<endl;
		char l;
		l=char(getch());
		if(l=='1')
		{
			Sleep(500);
			system("cls");
			rintf("请将标准程序复制到程序目录中并将程序命名为data.cpp\n");
			Sleep(2000);
			cout<<"按任意键继续……\n";
			_getch();
			if(css()) cout<<"加载成功！"<<endl;
			else cout<<"加载失败！请重新尝试！"<<endl;
			Sleep(1000);
		}
		if(l=='2')
		{
			if(hello1())
			{
				if(sclx=='-') sr(sclx2-'0'-(sclx2-'0')-(sclx2-'0'));
				else sr(sclx-'0');
				hellosc();
			}
		}
		//if(l=='3') sz();
		if(l=='4') break;
		system("cls");
	}
	system("cls");
	cout<<"欢迎再次使用此软件!"<<endl;
	return 0;
}
