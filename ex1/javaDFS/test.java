public class test {

	public static void main(String[] args) {
		int leaves = Integer.parseInt(args[0]);
		BT bt = new BT(0);
		bt.createBT(leaves);
		bt.DFSscan();
	}
}