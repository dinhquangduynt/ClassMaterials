public class NhapXuat {
	public static void main(String[] args) {
		try {
			File f = new File("D:\\java\\hello.java");
			Scanner sc = new Scanner(f);
			
			File f2 = new File("D:\\java\\hellocopy.java");
			FileOutputStream fos = new FileOutputStream(f2);
			BufferedOutputStream bof= new BufferedOutputStream(fos);
			DataOutputStream dos = new DataOutputStream(fos);
			
			while(sc.hasNextLine()) {
				dos.writeUTF(sc.nextLine());
				System.out.println(sc.nextLine());
			}
			dos.close();
		}catch(Exception e) {
			
		};
	}

}
