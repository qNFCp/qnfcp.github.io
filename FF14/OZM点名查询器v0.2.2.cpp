#include <iostream>
#include <string> 
#include <algorithm>
#include <Windows.h>
using namespace std;

// |37AE|  ���ٶ�ը����ը  22|
// |0000|0000|0039|0000|0000|0000| ��ʯ����    27|
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
    cout<<"\t\t\tFF14 BA OZM������ѯ��  ���԰汾0.2.2\n\n";
    cout<<"ʹ��˵����������log�ļ�������Ϊba.log�������뱾�ļ�������ͬһ�ļ�����\n\n\n";
    cout<<"\t���������OZM.txt���ļ��У�����ʱ�����ļ���С������\n";
    cout<<"��ǰ���ã�\n\t1.��ʯ�������\n\t2.���ٶ�ը����ը���";
    cout<<"\n\tע��Acceleration Bomb Explosion ���ٶ�ը����ը\t\tMeteorite ��ʯ����\n";
	
    std::ios::sync_with_stdio(false);//�ر�C++/C��������� 
	std::cin.tie(0);//�ر�cin/cout���� 

	freopen("ba.log", "r", stdin);
    
    freopen("OZM.txt", "w", stdout);
    int i=0,ans=0,abe=0;//ans ��ʯ����  abe ���ٶ�ը���������� 
    
    string temp,flag;
	string::size_type position;
	
	int first=0,end=0,num=0;
	
	int z=1;
	
    while(cin>>data[i]){//����������
		
		if (data[i].find("|37AE|")!=data[i].npos){
			Acceleration_Bomb=data[i];
			Acceleration_Bomb.erase(0,14);//ɾ��ǰ0-14λ�ַ�
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
	        	temp.erase(0,14);//ɾ��ǰ0-14λ�ַ�
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
