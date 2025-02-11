package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func AddNodes(pResult, first, second *ListNode) *ListNode {
	if first == nil && second == nil {
		return pResult
	}

	sum := 0
	if pResult != nil {
		sum += pResult.data
	}
	if first != nil {
		sum += first.data
	}
	if second != nil {
		sum += second.data
	}

	pNewNode := &ListNode{sum % 10, nil}
	if sum/10 != 0 {
		pResult = &ListNode{sum / 10, nil}
	} else {
		pResult = nil
	}
	if first != nil {
		first = first.next
	}
	if second != nil {
		second = second.next
	}

	pNewNode.next = AddNodes(pResult, first, second)
	return pNewNode
}

func AddTwoNumbers(firstList, secondList *ListNode) *ListNode {
	var pResult *ListNode = nil
	return AddNodes(pResult, firstList, secondList)
}

func main() {
	for {
		fmt.Print("Number of elements of list1 and list2: ")
		var count1, count2 int
		fmt.Scan(&count1, &count2)
		if count1 == 0 && count2 == 0 {
			break
		}

		vec := GetArrayFromInput(count1, "Please enter the first list: ")
		first := GetListFromArray(vec)

		vec = GetArrayFromInput(count2, "Please enter the second list: ")
		second := GetListFromArray(vec)

		result := AddTwoNumbers(first, second)

		fmt.Print("The sum of the two lists is ")
		result.Print()
	}
}
