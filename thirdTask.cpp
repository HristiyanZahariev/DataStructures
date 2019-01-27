#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int data;
	vector<TreeNode*> children;

	TreeNode(int data, vector<TreeNode*> children = vector<TreeNode*>()) {
		this->data = data;
		this->children = children;
	}
};

bool search(vector<int> v1, int element) {
	return find(v1.begin(), v1.end(), element) != v1.end();
}

bool isIsomorphic(TreeNode* first_root, TreeNode* second_root) {
	if (first_root->children.size() == 0 && 
		second_root->children.size() == 0) {
		return true;
	} else if (first_root->children.size() != second_root->children.size()) {
		return false;
	}
	bool isomorphicFirst = true;
	bool isomorphicSecond = false;
	vector<int> coupledSubTrees;

	for (int i=0; i < first_root->children.size(); i++) {
		isomorphicSecond = false;
		for (int j=0; j < first_root->children.size(); j++) {
			if (search(coupledSubTrees, j)) {
				continue;
			}
			if (isIsomorphic(first_root->children[i], second_root->children[j])) {
				isomorphicSecond = true;
				coupledSubTrees.push_back(j);
				break;
			}
		}
		isomorphicFirst &= isomorphicSecond;
	}
	return isomorphicFirst;
}

int main() {
	TreeNode* fourNode = new TreeNode(4);
	TreeNode* twelveNode = new TreeNode(12);
	TreeNode* fourthytwoNode = new TreeNode(42);

	vector<TreeNode*> firstChilds;

	firstChilds.push_back(fourNode);
	firstChilds.push_back(fourthytwoNode);
	firstChilds.push_back(twelveNode);

	TreeNode* nineNode = new TreeNode(9);

	TreeNode* oneNode = new TreeNode(1, firstChilds);

	vector<TreeNode*> secondChilds;

	secondChilds.push_back(nineNode);
	secondChilds.push_back(oneNode);

	TreeNode* five = new TreeNode(5, secondChilds);


	TreeNode* sevenNode = new TreeNode(7);
	TreeNode* tenNode = new TreeNode(10);
	TreeNode* eightNode = new TreeNode(8);

	vector<TreeNode*> firstChildsSecond;

	firstChildsSecond.push_back(sevenNode);
	firstChildsSecond.push_back(tenNode);
	firstChildsSecond.push_back(eightNode);

	TreeNode* fiftheenthNode = new TreeNode(15, firstChildsSecond);

	TreeNode* threeNode = new TreeNode(3);

	vector<TreeNode*> secondChildsSecond;

	secondChildsSecond.push_back(threeNode);
	secondChildsSecond.push_back(fiftheenthNode);

	TreeNode* sevenIsoToFive = new TreeNode(7, secondChildsSecond);

	cout << isIsomorphic(five, sevenIsoToFive) << endl;

	threeNode->children.push_back(eightNode);

	cout << isIsomorphic(five, sevenIsoToFive) << endl;

}