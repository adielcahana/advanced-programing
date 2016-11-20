public class BT {
	int data;
	BT left = null;
	BT right = null;
	static int number = 1;

	public BT(int data) {
		this.data = data;
	}

	public void createBT(int leaves){
		int height = (int) (Math.log(leaves) / Math.log(2));
		createFullTree(height);
	}

	private void createFullTree(int height) {
		this.data = number;
		number++;
		if (height == 0){
			return;
		}
		this.left = new BT(0);
		this.left.createFullTree(height - 1);
		this.right = new BT(0);
		this.right.createFullTree(height - 1);
	}

	public void DFSscan(){
		System.out.println(this.data);
		if(this.left != null){
			this.left.DFSscan();
		}
		if (this.right != null){
			this.right.DFSscan();
		}
	}
}