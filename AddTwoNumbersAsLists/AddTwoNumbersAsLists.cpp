// AddTwoNumbersAsLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

void PrintList(ListNode* pHead)
{
    if (!pHead)
        return;
    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }

    std::cout << std::endl;
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* MakeReversedListWithNumber(int num)
{
    ListNode* pNode = nullptr;
    ListNode* pCurrentNode = nullptr;
    while (num != 0)
    {
        ListNode* pNewNode = new ListNode(num % 10);
        if (pNode == nullptr)
        {
            pNode = pNewNode;
            pCurrentNode = pNode;
        }
        else
        {
            pCurrentNode->next = pNewNode;
            pCurrentNode = pCurrentNode->next;
        }
        num = num / 10;
    }

    return pNode;
}

int GetNumberFromList(ListNode* pNode)
{
    int num = 0;
    int premium = 1;
    while (pNode != nullptr)
    {
        num = pNode->data * premium + num;
        pNode = pNode->next;
        premium *= 10;
    }

    return num;
}

ListNode* AddTwoNumbers(ListNode* firstList, ListNode* secondList)
{
    int first = GetNumberFromList(firstList);
    int second = GetNumberFromList(secondList);

    return MakeReversedListWithNumber(first + second);
}

int main()
{
    while (true)
    {
        int firstNumber = 0;
        int secondNumber = 0;
        std::cout << "Enter the two numbers: ";
        std::cin >> firstNumber >> secondNumber;

        if (firstNumber == 0 && secondNumber == 0)
            break;

        ListNode* pFirstHead = MakeReversedListWithNumber(firstNumber);
        ListNode* pSecondHead = MakeReversedListWithNumber(secondNumber);

        ListNode* pSumHead = AddTwoNumbers(pFirstHead, pSecondHead);

        std::cout << "The two lists to be added: " << std::endl;
        PrintList(pFirstHead);
        PrintList(pSecondHead);
        std::cout << "The sum of the two lists: " << std::endl;
        PrintList(pSumHead);

        FreeList(pFirstHead);
        FreeList(pSecondHead);
        FreeList(pSumHead);
    }

    return 0;
}
