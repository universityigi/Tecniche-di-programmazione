#pragma once

struct ListNode {
  int info;
  struct ListNode* next;
};

ListNode* erase(ListNode* list, int index);

