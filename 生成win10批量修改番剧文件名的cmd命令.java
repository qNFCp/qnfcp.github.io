public static void main(String[] args) {
		//ren 原文件名 新文件名
		System.out.println("chcp 65001\r\n" + "pause"); //cmd编码切换为UTF-8 防乱码
		int temp=0;
		for(int i=1;i<=26;i++) { //控制集数
			//原文件名
			System.out.print("ren \"魔法科高校的劣等生S1 E"); //精准文件名
			//System.out.print("ren *");  //非精准
			if(i<10)
				System.out.print(0);
			System.out.print(i + ".mp4\"");//文件格式
			//System.out.print(i + "*.mp4 "+"\"番名 E");//非精准
			
			//新文件名
			System.out.print(" \"S01 E");//精准文件名前缀
			if(i<10)
				System.out.print(0);
			System.out.println(i+".mp4\"");//精准文件名后戳
		}
		/*
		for(int i=1;i<=25;i++) { 
			System.out.print("ren \"S03 E"); 
			if(i<10)
				System.out.print(0);
			System.out.print(i + ".sc.ass\"");
			
			System.out.print(" \"S01 E");
			if(i<10)
				System.out.print(0);
			System.out.println(i+".sc.ass\"");
		}
		
		for(int i=1;i<=25;i++) { 
			System.out.print("ren \"S03 E"); 
			if(i<10)
				System.out.print(0);
			System.out.print(i + ".tc.ass\"");
			
			System.out.print(" \"S01 E");
			if(i<10)
				System.out.print(0);
			System.out.println(i+".tc.ass\"");
		}
		*/
		
		System.out.print("pause");
	}
