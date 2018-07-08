    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) return nullptr;
		int sizeA = 0;
		ListNode *currentA = headA;
		while(currentA) {
			sizeA++;
			currentA = currentA->next;
		}
		int sizeB = 0;
		ListNode *currentB = headB;
		while(currentB) {
			sizeB++;
			currentB = currentB->next;
		}
		currentA = headA;
		currentB = headB;
		while(sizeA > sizeB) {
			sizeA--;
			currentA = currentA->next;
		}
		while(sizeB > sizeA) {
			sizeB--;
			currentB = currentB->next;
		}
		while(currentA != currentB) {
			currentA = currentA->next;
			currentB = currentB->next;
		}
		return currentA;
    }