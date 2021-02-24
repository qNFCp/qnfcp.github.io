	public static void main(String[] args) {
		System.out.println("chcp 65001\r\n" + "pause"); //cmd编码切换为UTF-8 防乱码
		for(int i=58;i<=144;i++) { //控制集数
			//此处的格式为 *数字*.mp4 修改
			System.out.print("ren *"); 
			if(i<10)
				System.out.print(0);
			System.out.print(i + "*.mp4 "+"\"番名 E");
			if(i<10)
				System.out.print(0);
			System.out.println(i+".mp4\"");
		}
		System.out.print("pause");
	}
