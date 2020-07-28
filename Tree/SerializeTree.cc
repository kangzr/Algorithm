/*
 * 序列化二叉树
 *
 * 请实现两个函数，分别用来序列化和反序列化二叉树。
 *
 * [1,2,3,null,null,4,5] 空子节点用null表示
 *
 * */


/*思路一：
 *
 * 序列化：使用queue采用层序遍历序列化
 * 反序列化：使用vector，将层序序列存入vec中，再根据层序遍历特点
 * vec[i]->left = vec[i+1] vec[i]->right = vec[i+2] 构建树
 *
 * 需要用到O(n)空间
 * */

class Solution{
public:
	string Serialize(TreeNode* root){
		ostringstream out;
		queue<TreeNode*> q;
		q.push(root);
		while(q.size()){
			TreeNode* cur = q.front(); q.pop();
			if(cur){
				out << cur->val << " ";
				q.push(cur->left);
				q.push(cur->right);
			}
			else out << "null ";
		}
		return out.str();
	}

	TreeNode* Deserialize(string data){
		istringstream input(data);
		string val;
		vector<TreeNode*> vec;
		while(input >> val){
			// NULL不能使用emplace_back
			if(val == "null") vec.push_back(NULL);
			else vec.emplace_back(new TreeNode(stoi(val)));
		}
		int j = 1;
		for(int i = 0; j < vec.size(); i++){
			if(!vec[i]) continue;
			if(j < vec.size()) vec[i]->left = vec[j++];
			if(j < vec.size()) vec[i]->right = vec[j++];
		}
		return vec[0];
	}
};


// 剑指offer解法 前序遍历
void Serialize(TreeNode* root, ostream& stream){
	if(!root) stream << "$,";
	stream << root->val << ",";
	Serialize(root->left, stream);
	Serialize(root->right, stream);
}

void Deserialize(TreeNode **root, istream& stream){
	int num;
	if(ReadStream(stream, &num)){
		*root = new TreeNode(num);
		Deserialize(&((*root)->left), stream);
		Deserialize(&((*root)->right), stream);
	}
}

bool ReadStream(istream& stream, int *num){
	if(stream.eof()) return false;
	char buffer[32];
	buffer[0] = '\0';
	char ch;
	stream >> ch;
	int i = 0;
	while(!stream.eof() && ch != ' '){
		buffer[i++] = ch;
		stream >> ch;
	}
	bool isNum = false;
	if(i > 0 && buffer[0] != '$'){
		*num = atoi(buffer);
		isNum = true
	}
	return isNum;
}
