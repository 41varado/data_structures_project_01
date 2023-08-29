#pragma once

#include "project.h"

struct NODE {
   PROJECT data;
   NODE *next_node;
   NODE *previous_node;
};

class circular_linked_list
{
	private:
		NODE *head_node,
			 *tail_node;

	public:
		circular_linked_list() : head_node(nullptr), tail_node(nullptr)
		{  }
		
		bool remove(const NODE&);
		NODE* find(const PROJECT&);
		void append(const PROJECT&);
		bool modify(const PROJECT& oldProject, const PROJECT& newProject);
};
