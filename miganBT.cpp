#include <bits/stdc++.h> 
#include <windows.h>
using namespace std;

int main(int argc, char* argv[]){
	//ios::sync_with_stdio(false);
	for(int i=0;i<40;i++) cout<<" "; 
	cout<<"蜜柑计划 种子批量导出器\n\n";
	
	//下载rss 
	char migan[3253]={0},key[610]={0};
	//char deskpath[255]=	{"E:\\OneDrive\\桌面\\"};
	char deskpath[255]={"\%userprofile\%\\desktop\\"};
	cout<<"键入关键词:";
	cin>>key;
	sprintf(migan,"powershell (new-object System.Net.WebClient).DownloadFile( \'https://mikanani.me/RSS/Search?searchstr=%s\',\'%stemp.xml\')",key,deskpath);//set migan, migan+=key		
	system(migan);	
	
	//读入及写入连接 
	freopen("temp.xml", "r", stdin);
	freopen("temp.txt", "w", stdout);
	
	//内容检索 
	string link;
	int times=0;
	while(cin>>link){
		if(link.rfind("url=",0)==0){ //搜索内容 "url="
			link.erase(0,5);//删除前5位字符 
			replace(link.begin(),link.end(),'\"','\0');	//替换"号 
			cout<<link<<'\n';
			times++;
		}
		if(link.rfind("</rss>",0)==0)//判断结束读入 
			break;
	}	
	
	//断开文件连接 
	fclose(stdin);
	fclose(stdout);
	
	//删除xml文件 
	char del[255]={0};
	sprintf(del,"del \"%stemp.xml\"",deskpath);	
	system(del);
	
	//搜索结果为空时 删除空文件 
	if(times==0){
		sprintf(del,"del \"%stemp.txt\"",deskpath);	
		system(del);
		return 0;
	}
	
	//修改文件名
	char rename[255]={0};
	sprintf(rename,"ren \"%stemp.txt\" %s.txt\"",deskpath,key);
	cout<<rename; 
	system(rename);	
	return 0;
} 
