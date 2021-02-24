	public static void main(String[] args) {
		//输出例 ffmpeg -i 01.mkv -i 01.tc.ass -c copy in01.mkv
		//ffmpeg -i 01.mkv -i 01.ass -c copy in1.mkv
		//ffmpeg -i "[Sakurato.Sub] Darwin's Game - 01 (HEVC-10Bit-2160P AAC).mkv" -i "[Sakurato.Sub] Darwin's Game - 01 (HEVC-10Bit-2160P AAC).tc.ass" -c copy 1.mkv
		Scanner input =new Scanner(System.in);
		System.out.print("Strat: ");
		int Start=input.nextInt();
		System.out.print("Times: ");
		int times=input.nextInt();
		System.out.println();
		for(int i=Start;i<=times;i++) {
			System.out.print("ffmpeg -i ");
			if(i<10)System.out.print(0);
			System.out.print(i +".mkv -i ");
			if(i<10)System.out.print(0);
			System.out.print(i +".tc.ass -c copy in");
			if(i<10)System.out.print(0);
			System.out.print(i+".mkv\n");
		}
	}
