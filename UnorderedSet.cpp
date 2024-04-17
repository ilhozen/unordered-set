#include "UnorderSet.h"

UnorderedSet::UnorderedSet() :head(nullptr)
{
}

UnorderedSet::UnorderedSet(const UnorderedSet& other)
{
	if (other.head == nullptr) {
		this->head = nullptr;
		return;
	}
	head = new Node(other.head->data);
	Node* w = other.head->next;
	Node* last = head;
	while (w != nullptr) {
		last->next = new Node(w->data);
		last = last->next;
		w = w->next;
	}
}

UnorderedSet::~UnorderedSet()
{
	Node* p;
	while (head != nullptr) {
		p = head;
		head = head->next;
		delete p;
	}
}

bool UnorderedSet::contains(int value) const {
	Node* w = head;
	while (w != nullptr) {
		if (w->data == value) {
			return true;
		}
		w = w->next;
	}
	return false;
}

void UnorderedSet::printSet() const {
	cout << *this << endl;
}

void UnorderedSet::pop_front()
{
	Node* p;
	p = head;
	head = head->next;
	delete p;
}

void UnorderedSet::insert(int value) {
	if (this->contains(value)) {
		cout << "Set already contains this element!\n" << endl;
	}
	else {
		Node* p = new Node(value);
		p->next = head;
		head = p;
	}
}

void UnorderedSet::remove(int value)
{
	if (head == nullptr) {
		cout << "The set is empty!\n" << endl;
		return;
	}
	else {
		Node* w = head;
		Node* prev = nullptr;
		while (w != nullptr) {
			if (w->data == value) {
				break;
			}
			prev = w;
			w = w->next;
		}
		if (w == nullptr) {
			cout << "Element was not found in the set!\n" << endl;
			return;
		}
		prev->next = w->next;
		delete w;
		cout << "Element removed from set!\n" << endl;
	}
}

void UnorderedSet::clear()
{
	while (head != nullptr) {
		this->pop_front();
	}
}

int UnorderedSet::size() const
{
	Node* w = head;
	int cnt = 0;
	while (w != nullptr) {
		w = w->next;
		cnt++;
	}
	return cnt;
}

bool UnorderedSet::isEmpty() const {
	return head == nullptr;
}

UnorderedSet UnorderedSet::intersection(const UnorderedSet& other) const {
	UnorderedSet result;
	if (this->isEmpty() || other.isEmpty()) {
		return result;
	}
	else {
		Node* w = head;
		while (w != nullptr) {
			if (other.contains(w->data)) {
				result.insert(w->data);
			}
			w = w->next;
		}
		return result;
	}
}

UnorderedSet UnorderedSet::setUnion(const UnorderedSet& other) const {
	UnorderedSet result;
		Node* w = head;
		Node* w_other = other.head;
		while (w != nullptr) {
			result.insert(w->data);
			w = w->next;
		}
		while (w_other != nullptr) {
			if (!(this->contains(w_other->data))) {
				result.insert(w_other->data);
			}
			w_other = w_other->next;
		}
	return result;
}

UnorderedSet UnorderedSet::setDifference(const UnorderedSet& other) const {
	UnorderedSet result;
	if (this->isEmpty() || other.isEmpty()) {
		return result;
	}
	else {
		Node* w = head;
		while (w != nullptr) {
			if (!(other.contains(w->data))) {
				result.insert(w->data);
			}
			w = w->next;
		}
		return result;
	}
}

bool UnorderedSet::operator==(const UnorderedSet& lhs) const
{
	if (this->size() != lhs.size()) {
		return false;
	}
	Node* w = this->head;
	Node* w_lhs = lhs.head;
	while (w != nullptr) {
		if (w->data != w_lhs->data) {
			return false;
		}
		w = w->next;
		w_lhs = w_lhs->next;
	}
	return true;
}

ostream& operator<<(ostream& out, const UnorderedSet& set) {
	Node* w = set.head;
	while (w != nullptr) {
		out << w->data << " ";
		w = w->next;
	}
	return out;
}