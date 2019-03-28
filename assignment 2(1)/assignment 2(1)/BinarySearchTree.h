//BinarySearchTreeTemplate.h

template<typename T>
class BinarySearchTree
{
private:
	struct Node;

public:
	void insert(const T &p_data);
	void clear();
	bool find(const T &p_data);
	int size();
	void traversal_in_order();
	const T Root();
	const T Highest();
	const T Lowest();
	const T HighestRecursive(std::shared_ptr<Node> p_node);
	const T LowestRecursive(std::shared_ptr<Node> p_node);
private:
	void insertRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	void clearRecursive(std::shared_ptr<Node> p_node);
	bool findRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	int sizeRecursive(std::shared_ptr<Node> p_node);
	int m_size = 0;
	void traversal_in_orderRecursive(std::shared_ptr<Node> p_node);																	
	std::shared_ptr<Node> m_root;
};

template<typename T>
struct BinarySearchTree<T>::Node
{
	Node(const T &p_data) : m_data(p_data), m_lesser(nullptr), m_greater(nullptr) {};
	T m_data;
	std::shared_ptr<Node> m_lesser; // Left
	std::shared_ptr<Node> m_greater; // Right
};

template<typename T>
void BinarySearchTree<T>::insert(const T &p_data) {
	if (m_root == nullptr) {
		m_root = std::make_shared<Node>(p_data);
	}
	else {
		insertRecursive(m_root, p_data);
	}
};

	template<typename T>
	void BinarySearchTree<T>::insertRecursive(std::shared_ptr<Node> p_node, const T &p_data)
	{
		if (p_node->m_data >= p_data) {
			if (p_node->m_lesser == nullptr) {
				p_node->m_lesser = std::make_shared<Node>(p_data);
			}
			else {
				p_node = p_node->m_lesser;
				insertRecursive(p_node, p_data);
			}
		}
		else if (p_node->m_data < p_data) {
			if (p_node->m_greater == nullptr) {
				p_node->m_greater = std::make_shared<Node>(p_data);
			}
			else  {
				p_node = p_node->m_greater;
				insertRecursive(p_node, p_data);
			}
		}
	};

	template<typename T>
	void BinarySearchTree<T>::clear() {
		m_root = nullptr;
	};

	template<typename T>
	bool BinarySearchTree<T>::find(const T &p_data) {
		if (m_root != nullptr) {
			return findRecursive(m_root, p_data);
		}
		else {
			return false;
		}
	};

		template<typename T>
		int BinarySearchTree<T>::size() {
			if (m_root != nullptr) {
				m_size = 1;
				return sizeRecursive(m_root);
			}
			else {
				return 0;
			}
		};

		template<typename T>
		void BinarySearchTree<T>::clearRecursive(std::shared_ptr<Node> p_node){
			m_root = nullptr;
		};

		template<typename T>
		bool BinarySearchTree<T>::findRecursive(std::shared_ptr<Node> p_node, const T &p_data) {
			if (p_node == nullptr) {
				std::cout << "There data you were looking for is not in the tree(Binary)" << endl;
				return false;
		}
			else if (p_node->m_data == p_data) {
				std::cout << "The data you were looking for is in the tree(Binary)" << endl;
				return true;
			}
			if (p_node->m_data < p_data) {
				p_node = p_node->m_greater;
				return findRecursive(p_node, p_data);
			}
			else if (p_node->m_data > p_data) {
				p_node = p_node->m_lesser;
				return findRecursive(p_node, p_data);
			}
			return false;
		};

		template<typename T>
		int BinarySearchTree<T>::sizeRecursive(std::shared_ptr<Node> p_node) {
			if (p_node->m_lesser != nullptr) {
				m_size++;
				sizeRecursive(p_node->m_lesser);
			}
			if (p_node->m_greater != nullptr) {
				m_size++;
				sizeRecursive(p_node->m_greater);
		}
			std::cout << p_node->m_data << endl;
			if (p_node->m_lesser == nullptr && p_node->m_greater == nullptr) {
				p_node = nullptr;
			}
			return m_size;
		};
		template<typename T>
		void BinarySearchTree<T>::traversal_in_order() {
			if (m_root != nullptr) {
				traversal_in_orderRecursive(m_root);
			}
			else {
				return;
			}
		};

		template<typename T>
		void BinarySearchTree<T>::traversal_in_orderRecursive(std::shared_ptr<Node> p_node) {
			if (p_node->m_lesser != nullptr) {
				traversal_in_orderRecursive(p_node->m_lesser);
			}
			std::cout << p_node->m_data << endl;
			if (p_node->m_greater != nullptr) {
				traversal_in_orderRecursive(p_node->m_greater);
			}
		};

		template<typename T>
		const T BinarySearchTree<T>::Root() {
			if (m_root != nullptr) {
				return m_root->m_data;
			}
			else {
				throw std::exception();
			} 
		};
		
		template<typename T>
		const T BinarySearchTree<T>::Highest() {
			if (m_root != nullptr){
				return HighestRecursive(m_root);
			}
			else {
				throw std::exception();
			}
		};
		
		template<typename T>
		const T BinarySearchTree<T>::Lowest() {
			if (m_root != nullptr) {
				return LowestRecursive(m_root);
			}
			else {
				throw std::exception();
			}
		};
		
		template<typename T>
		const T BinarySearchTree<T>::HighestRecursive(std::shared_ptr<Node> p_node) {
			while (p_node->m_greater != nullptr) {
				p_node = p_node->m_greater;
			}
			return p_node->m_data;
		};

		template<typename T>
		const T BinarySearchTree<T>::LowestRecursive(std::shared_ptr<Node> p_node) {
			while (p_node->m_lesser != nullptr) {
				p_node = p_node->m_lesser;
			}
			return p_node->m_data;
		}