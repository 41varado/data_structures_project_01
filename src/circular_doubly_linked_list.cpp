#include <iostream>

#include "circular_doubly_linked_list.h"
#include "project.h"

using namespace std;

bool circular_doubly_linked_list::remove(const NODE& node)
{
	if (!head_node) {
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

NODE* circular_doubly_linked_list::find(const PROJECT& project)
{
	if (head_node) {
		NODE* current_node = head_node;
		
		do {
			if (current_node->data == project) {

				return current_node;
			}
		
			current_node = current_node->next_node;
		} while (current_node != head_node);
	}

	return nullptr;
}

void circular_doubly_linked_list::append(const PROJECT& project)
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

bool circular_doubly_linked_list::modify(const PROJECT& oldProject, const PROJECT& newProject)
{
    NODE* nodeToModify = find(oldProject);

    if (nodeToModify) {
        nodeToModify->data = newProject;
        return true;
    }

    return false;
}
