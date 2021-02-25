#include <bits/stdc++.h> 
#include <windows.h>
using namespace std;

int main(int argc, char* argv[]){
	//ios::sync_with_stdio(false);
	for(int i=0;i<40;i++) cout<<" "; 
	cout<<"蜜柑计划 种子批量导出器\n\n";
	char migan[3253]={0},key[610]={0};
	char ed[]={"\',\'\%userprofile\%\\desktop\\a.xml\')"};
	//char ed[]={"\',\'E:\\OneDrive\\桌面\\a.xml\')"};
	cout<<"键入关键词:";
	cin>>key;
	sprintf(migan,"powershell (new-object System.Net.WebClient).DownloadFile( \'https://mikanani.me/RSS/Search?searchstr=%s%s",key,ed);//set migan, migan+=key		
	system(migan);	
	freopen("a.xml", "r", stdin);
	freopen("a.txt", "w", stdout);
	string link;
	while(cin>>link){
		if(link.rfind("url=",0)==0){ //搜索内容 "url="
			link.erase(0,5);//删除前5位字符 
			replace(link.begin(),link.end(),'\"','\0');	//替换"号 
			cout<<link<<'\n';
		}
		if(link.rfind("</rss>",0)==0)
		break;
	}	
	fclose(stdin);
	fclose(stdout);
	char del[255]={0},deskpath[255]={"\"\%userprofile\%\\desktop\\a.xml\""};
	//char del[255]={0},deskpath[255]={"\"E:\\OneDrive\\桌面\\a.xml\""};	
	sprintf(del,"del %s",deskpath);//set migan, migan+=key		
	system(del);	
	return 0;
} 
