#pragma once

#include "project.h"

struct NODE {
   PROJECT data;
   NODE *next_node;
   NODE *previous_node;
};

class circular_doubly_linked_list
{
	private:
		NODE *head_node,
			 *tail_node;

	public:
		circular_doubly_linked_list() : head_node(nullptr), tail_node(nullptr)
		{  }
		
		bool remove(const NODE&);
		bool modify(const PROJECT& oldProject, const PROJECT& newProject);
		NODE* find(const PROJECT&);
		void append(const PROJECT&);
		void displayForward();
		void displayBackwards();

};
