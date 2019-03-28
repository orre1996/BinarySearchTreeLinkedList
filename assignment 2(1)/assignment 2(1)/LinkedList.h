//LinkedListTemplate.h
#include <memory>

#pragma once

template<typename T>
class LinkedList
{
private:
	struct Node;

public:
	LinkedList() : m_root(nullptr) {};
	~LinkedList() {};

	void push_front(const T &p_data);
	void push_back(const T &p_data);
	void pop_front();
	void pop_back();
	void clear();
	bool find(const T &p_data);
	void print();
	const unsigned int size();
	const T front();
	const T back();


private:
	std::shared_ptr<Node> m_root;
	std::shared_ptr<Node> m_current;
};

template<typename T>
struct LinkedList<T>::Node
{
	Node(const T &p_data) : m_data(p_data), m_next(nullptr) {};
	T m_data;
	std::shared_ptr<Node> m_next;
};

template<typename T>
void LinkedList<T>::push_front(const T &p_data)
{
	if (m_root == nullptr) {
		m_root = std::make_shared<Node>(p_data);
	}
	else {
		m_current = m_root;
		m_root = std::make_shared<Node>(p_data);
		m_root->m_next = m_current;
	}
};
template<typename T>
void LinkedList<T>::push_back(const T &p_data) {
	if (m_root != nullptr) {
		if (m_current == nullptr) {
			m_current = m_root;
			push_back(p_data);
		}
		else if (m_current->m_next != nullptr) {
			m_current = m_current->m_next;
			push_back(p_data);
		}
		else {
			m_current->m_next = std::make_shared<Node>(p_data);
		}
	}
	else{
		m_root = std::make_shared<Node>(p_data);
	}
	m_current = nullptr;
};
template<typename T>
void LinkedList<T>::pop_front() {
	if (m_root != nullptr) {
		if (m_current == nullptr) {
			m_current = m_root;
			pop_front();
		}
		else if (m_root->m_next == nullptr) {
			m_root = nullptr;
		}
		else {
			m_root = m_root->m_next;
		}
		m_current = nullptr;
	}
};
template<typename T>
void LinkedList<T>::pop_back() {
	if (m_root != nullptr) {
		if (m_current == nullptr) {
			m_current = m_root;
			pop_back();
		}
		else if (m_current->m_next->m_next == nullptr) {
			m_current->m_next = nullptr;
		}
		else if (m_current->m_next == nullptr) {
			m_root = nullptr;
		}
		else {
			m_current = m_current->m_next;
			pop_back();
		}
	}
	m_current = nullptr;
};
template<typename T>
void LinkedList<T>::clear() {
	if (m_root != nullptr) {
		if (m_current == nullptr) {
			m_current = m_root;
			clear();
		}
		else if (m_root->m_next == nullptr) {
			m_root = nullptr;
			clear();
		}
		else {
			m_root = m_root->m_next;
			clear();
		}
		m_current = nullptr;
	}
};

template<typename T>
bool LinkedList<T>::find(const T &p_data) {
	int i = 0;
	if (m_root != nullptr) {
		m_current = m_root;
		while (m_current != nullptr) {
			if (p_data == m_current->m_data) {
				i++;
				std::cout << "The number you we're trying to find is in the list " << endl;
				return true;
			}
			else if (m_current != nullptr) {
				std::cout << "The number you we're searching for is not in the list" << endl;
				return false;
			}
			else {
				m_current = m_current->m_next;
				i++;
			}
		}
	}
	m_current = nullptr;
	return false;
};

template<typename T>
void LinkedList<T>::print() {
	m_current = m_root;
	while (m_current != nullptr) {
		std::cout << m_current->m_data << endl;
		m_current = m_current->m_next;
	}
	std::cout << "le size of le list is: " << size() << std::endl;
	m_current = nullptr;
};

template<typename T>
const unsigned int LinkedList<T>::size() {
	int i = 0;
	if (m_root == nullptr) {
		return 0;
	}
	else {
		i++;
		auto m_current = m_root;
		while (m_current->m_next != nullptr) {
			m_current = m_current->m_next;
			i++;
		}
	}
	return i;
};


template<typename T>
const T LinkedList<T>::front() {
	if (m_root != nullptr) {
		return m_root->m_data;
	}
	else {
		cout << "There is no data in the list" << endl;
		throw std::exception();
	}
};

template<typename T>
const T LinkedList<T>::back() {
	if (m_root != nullptr) {
		m_current = m_root;
		while (m_current->m_next != nullptr) {
			m_current = m_current->m_next;
		}
		return m_current->m_data;
	}
	else {
		throw std::exception();
	}
};

