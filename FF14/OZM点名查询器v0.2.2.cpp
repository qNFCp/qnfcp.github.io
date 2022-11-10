#include <iostream>
#include <string> 
#include <algorithm>
#include <Windows.h>
using namespace std;

// |37AE|  加速度炸弹爆炸  22|
// |0000|0000|0039|0000|0000|0000| 陨石点名    27|
string data[29999999];

char del[255];
void dell(string temp){ //delete
	char delpath[255];
	temp.copy(delpath,temp.length(),0);
	*(delpath+temp.length())='\0';
	sprintf(del,"@del \"%s\" /s /q",delpath);
	system(del);
}

string Name[8],Time,Acceleration_Bomb,Acceleration_Bomb_old;
int main(){
	dell("OZM.txt");
	system("cls");
    cout<<"\t\t\tFF14 BA OZM点名查询器  测试版本0.2.2\n\n";
    cout<<"使用说明：将待测log文件重命名为ba.log并将其与本文件放置于同一文件夹下\n\n\n";
    cout<<"\t将输出到“OZM.txt”文件中（运行时间视文件大小而定）\n";
    cout<<"当前可用：\n\t1.陨石点名检测\n\t2.加速度炸弹爆炸检测";
    cout<<"\n\t注：Acceleration Bomb Explosion 加速度炸弹爆炸\t\tMeteorite 陨石点名\n";
	
    std::ios::sync_with_stdio(false);//关闭C++/C输出流兼容 
	std::cin.tie(0);//关闭cin/cout关联 

	freopen("ba.log", "r", stdin);
    
    freopen("OZM.txt", "w", stdout);
    int i=0,ans=0,abe=0;//ans 陨石计数  abe 加速度炸弹引爆计数 
    
    string temp,flag;
	string::size_type position;
	
	int first=0,end=0,num=0;
	
	int z=1;
	
    while(cin>>data[i]){//读入数据行
		
		if (data[i].find("|37AE|")!=data[i].npos){
			Acceleration_Bomb=data[i];
			Acceleration_Bomb.erase(0,14);//删除前0-14位字符
			Acceleration_Bomb.erase(12,Acceleration_Bomb.length());
			Time=Acceleration_Bomb;
			Acceleration_Bomb=data[i];
			Acceleration_Bomb.erase(0,46);
			Acceleration_Bomb.erase(Acceleration_Bomb.find("|"),Acceleration_Bomb.length());
			if(Acceleration_Bomb!=Acceleration_Bomb_old){
				cout<<"\nAcceleration Bomb Explosion AT ("<<Time<<") by: ["<<Acceleration_Bomb<<"]\n";
				abe++; 
			} 
			Acceleration_Bomb_old=Acceleration_Bomb;
			i++;
			continue;
		}else if (data[i].find("|0000|0000|0039|0000|0000|0000|")!=data[i].npos){
	        	if(z==1)
	        		cout<<"===========================================\n";
				temp=data[i];
	        	temp.erase(0,14);//删除前0-14位字符
	        	temp.erase(12,temp.length());
				//cout<<"TIME: "<<temp<<endl; 
				Time=temp;
				
				temp=data[i];
				temp.erase(0,46);
				temp.erase(temp.find("|"),temp.length());
				Name[z]=temp; 
				//cout<<temp<<endl;
	        	
				ans++; 
	        	i++;
	        	z++; 
	        	if(z>6){
	        		cout<<"TIME:\t"<<Time<<endl;
	        		cout<<"Meteorite:\t\t";
	        		for(int yyy=1;yyy<=6;yyy++){
	        			cout<<Name[yyy]<<"\t";
						Name[yyy]=" ";
					}
					cout<<"\n"; 
					Time=" ";
					z=1;
				}
		}else{
			i++;
		}
		
        if(i>29999997){
        	fclose(stdout);
            cout<<"log file exceeds size limit";
            return 0;
        }
    }
    
	cout<<"===========================================\nTotal number of meteorites: "
		<<ans<<"\nNumber of acceleration bombs exploded: "<<abe; 
	fclose(stdout);
	system("start OZM.txt");
    return 0;
}//by NFC 
