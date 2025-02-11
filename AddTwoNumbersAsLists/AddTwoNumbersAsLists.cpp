// AddTwoNumbersAsLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

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

std::vector<int> GetArrayFromInput(int count, const std::string& prompt)
{
    if (count == 0)
        return std::vector<int>();

    std::cout << prompt;
    std::vector<int> vec(count, 0);
    for (int i = 0; i < count; ++i)
        std::cin >> vec[i];

    return vec;
}

ListNode* GetListFromArray(const std::vector<int>& vec)
{
    if (vec.size() == 0)
        return nullptr;

    ListNode* pHead = new ListNode(vec[0]);
    ListNode* pCur = pHead;
    for (size_t i = 1; i < vec.size(); ++i)
    {
        pCur->next = new ListNode(vec[i]);
        pCur = pCur->next;
    }

    return pHead;
}

ListNode* AddNode(ListNode* resultNode, ListNode* pFirstNode, ListNode* pSecondNode)
{
    if (pFirstNode == nullptr && pSecondNode == nullptr)
    {
        return resultNode;
    }

    int sum = 0;
    if (pFirstNode != nullptr)
    {
        sum += pFirstNode->data;
        pFirstNode = pFirstNode->next;
    }
    if (pSecondNode != nullptr)
    {
        sum += pSecondNode->data;
        pSecondNode = pSecondNode->next;
    }
    if (resultNode != nullptr)
    {
        sum += resultNode->data;
    }

    ListNode* pNewNode = new ListNode(sum % 10);
    if (resultNode != nullptr)
    {
        delete resultNode;
        resultNode = nullptr;
    }

    if (sum / 10 != 0)
    {
        resultNode = new ListNode(sum / 10);
    }

    pNewNode->next = AddNode(resultNode, pFirstNode, pSecondNode);
    return pNewNode;
}

ListNode* AddTwoNumbers(ListNode* firstList, ListNode* secondList)
{
    ListNode* pResult = nullptr;
    return AddNode(pResult, firstList, secondList);
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

        std::vector<int> vec = GetArrayFromInput(firstNumber, "Please enter the first list: ");
        ListNode* pFirstHead = GetListFromArray(vec);

        vec = GetArrayFromInput(secondNumber, "Please enter the second list: ");
        ListNode* pSecondHead = GetListFromArray(vec);

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
