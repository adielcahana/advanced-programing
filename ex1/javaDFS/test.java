import java.util.Stack;

public class test {

	public static void main(String[] args) {
		Node rightleft = new Node(new Point(4,3), null ,null);
		Node left = new Node(new Point(7,2), null, rightleft);
		Node leftright = new Node(new Point(0,0), null, null);
		Node right = new Node(new Point(6,8), leftright, null);
		BT bt = new BT(new Node(new Point(5,3), left, right));
		Stack<Node> stack = new Stack<Node>();
		bt.DFSscan(stack, bt.root);
	}
}
