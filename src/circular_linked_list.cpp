#include <iostream>

#include "circular_linked_list.h"
#include "project.h"

using namespace std;

bool circular_linked_list::remove(const NODE& node)
{
	if (head_node == nullptr) {
		return false;  
	}

	NODE* current_node 	= head_node;
	NODE* previous_node = nullptr;

	do {
		if (current_node->data == node.data) {
			if (current_node == head_node) {
				if (current_node->next_node == head_node) {
					delete current_node;
					head_node = tail_node = nullptr;
				} else {
					head_node = current_node->next_node;
					tail_node->next_node = head_node;
					delete current_node;
				}
			} else if (current_node == tail_node) {
				tail_node = previous_node;
				head_node->previous_node = tail_node;
				previous_node->next_node = head_node;
				delete current_node;
			} else {
				previous_node->next_node = current_node->next_node;
				delete current_node;
			}

			return true;  
		}

		previous_node = current_node;
		current_node = current_node->next_node;
	} while (current_node != head_node);

	return false; 
}

NODE* circular_linked_list::find(const PROJECT& project)
{
	NODE* current_node = head_node;

	if (head_node) {
		do {
			if (current_node->data == project) {

				return current_node;
			}
			current_node = current_node->next_node;
		} while (current_node != head_node);
	}

	return nullptr;
}

void circular_linked_list::append(const PROJECT& project)
{
	NODE* new_node = new NODE();
	new_node->data = project;

	if (!head_node) {
		head_node = tail_node = new_node;
		head_node->next_node = head_node->previous_node = head_node;
	} else {
		head_node->previous_node = new_node;
		tail_node->next_node = new_node;

		new_node->next_node = head_node;
		new_node->previous_node = tail_node;
		tail_node = new_node;
	}
}
