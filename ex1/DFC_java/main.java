/*
 * Main class.
 * Get the number of leaves and create the full binary tree.
 * Scan the tree with DFS algorithm.
 */
public class main {

	public static void main(String[] args) {
		int leaves = Integer.parseInt(args[0]);
		BT bt = new BT(0);
		bt.createBT(leaves);
		long startTime = System.currentTimeMillis();
		bt.DFSscan();
		long estimatedTime = System.currentTimeMillis() - startTime;
		System.out.println("time passed is: " +(double) estimatedTime / 1000 + " seconds");
	}
}