import java.util.Stack;

public class BT {
	Node root;

	public BT(Node node) {
		this.root = node;
	}

	void DFSscan(Stack<Node> stack, Node node){
		stack.push(node);
		while(!(stack.isEmpty())){
			System.out.println(node.data.PrintPoint());
			stack.pop();
			if (node.left != null) {
				this.DFSscan(stack, node.left);
			} 
			if (node.right != null){
				this.DFSscan(stack, node.right);
			}
		}
	}
}