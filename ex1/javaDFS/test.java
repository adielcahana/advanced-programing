public class test {

	public static void main(String[] args) {
	BT bt = new BT(0);
	bt.createBT(4096 * 64);
	bt.DFSscan();
	}
}