#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	for(int i=0;i<40;i++) cout<<" "; 
	cout<<"蜜柑计划 种子批量导出器\n\n";
	char migan[255]={0},key[255]={0};
	cout<<"键入关键词:";
	cin>>key;
	cout<<"\n请将弹出页面右键另存为a.xml,并置于本程序相同目录下\n"; 
	sprintf(migan,"start https://mikanani.me/RSS/Search?searchstr=%s",key);//set migan, migan+=key
	system(migan);
	cout<<"\n输出文件名为a.txt\n";
	system("pause");
	freopen("a.xml", "r", stdin);
	freopen("a.txt", "w", stdout);
	string link;
	while(cin>>link){
		if(link.rfind("url=",0)==0){ //搜索内容 "url="
			link.erase(0,5);//删除前5位字符 
			replace(link.begin(),link.end(),'\"','\0');	//替换"号 
			cout<<link<<'\n';
		}
	}
	return 0;
} 
