/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
    if(head ==NULL)
    {
        return;
    }
    ListNode * temp = tail;
    while(temp !=NULL)
    {
        tail = tail->prev;
        delete temp;
        temp = tail;
        length--;
    }
    temp = NULL;
    head = NULL;
    tail = NULL;

}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata)
{
    /// @todo Graded in MP3.1
    ListNode * temp = new ListNode(ndata);
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
    length++;
    temp = NULL;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack( const T & ndata )
{
    /// @todo Graded in MP3.1
    ListNode * temp = new ListNode(ndata);
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
    length++;
    temp = NULL;
}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode * & startPoint, ListNode * & endPoint )
{
    /// @todo Graded in MP3.1
   if (startPoint == NULL || endPoint == NULL)
    {
        return;
    }
    if (startPoint == endPoint)
    {
        return;
    }
    //std::cout << __LINE__ <<endl;
    ListNode * temp = NULL;
    ListNode * before = NULL;
    ListNode * after = NULL;
    ListNode * start = NULL;
    ListNode * end = NULL;

    start = startPoint;
    end = endPoint;
    if(startPoint->prev != NULL)
    {
        before = startPoint->prev;
        startPoint->prev = NULL;
        before->next =NULL;
    }
    if(endPoint->next != NULL)
    {
        after = endPoint->next;
        endPoint->next = NULL;
        after->prev = NULL;
    }
 
    while(startPoint !=NULL && startPoint != endPoint->next)
    {
        // std::cout << __LINE__ <<endl;
        temp =startPoint->prev;
        // std::cout << __LINE__ <<temp<<endl;
        startPoint->prev = startPoint->next;
        startPoint->next = temp;

        startPoint = startPoint->prev;        
    }
    startPoint = end;
    endPoint = start;
  

    if(before != NULL)
    {
        before->next = startPoint;
        startPoint->prev = before;
    }
    if(after != NULL)
    {
        after->prev = endPoint;
        endPoint->next= after;
    }

    temp = NULL;
    before = NULL;
    after = NULL;
    start = NULL;
    end = NULL;
    // delete temp;
    // delete before;
    // delete after;
    // delete start;
    // delete end;

    return;
}


/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth( int n )
{
    /// @todo Graded in MP3.1
   if(head == NULL || tail == NULL || n ==0 || n == 1)
    {
        return;
    }

    if (length <= n)
    {
        reverse(head,tail);
        return;
    }
    //cout<< "n:" <<n <<endl;
    //cout<< "length" <<length<<endl;
    int remain =0, loop = 0;
    remain = length%n;
    //cout<< "remain:"<<remain<<endl;
    loop = (length-remain)/n;
    //cout<<"loop:" << loop<<endl;
    //ListNode * start = new ListNode;
    //ListNode * end = new ListNode;
    ListNode * tempstart = NULL;
    ListNode * tempend = NULL;
    //start = head;
    //end = tail;
    tempstart = head;
    tempend = head;
    //std::cout << __LINE__ <<endl;
    for(int i =0; i<n-1; i++)
    {
        tempend = tempend->next;
    }
    reverse(tempstart,tempend);
    head = tempstart;
    //std::cout << __LINE__ <<endl;
    for(int i =0; i<loop-1;i++)
    {
        for(int j =0;j<n;j++)
        {
            tempstart = tempstart->next;
            tempend = tempend->next;
        }
        reverse(tempstart,tempend);
    }
    //last reverse

     //std::cout << __LINE__ <<endl;
     if(remain != 0)
     {   
        tempstart = tempend;
        tempstart = tempstart->next;
        while(tempend->next != NULL)
            {
                tempend = tempend->next;
            } 
        reverse(tempstart, tempend);
     }
     

    tail = tempend;
     
    //std::cout << __LINE__ <<endl;


    //clear
    tempstart =NULL;
    tempend = NULL;
    // delete tempstart;
    // delete tempend;
    return;
}


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1
     int count =1;
    ListNode * temp = head;
    ListNode * temp2 = NULL;

    while(temp != tail)
    {
        if(count %2 ==0)
        {
            temp2 = temp;
            temp = temp->next;
            temp-> prev = temp2->prev;
            temp2->prev->next = temp;
            temp2->prev = tail;
            tail->next = temp2;
            temp2->next = NULL;
            tail = temp2;
        }
        else
        {
            temp = temp->next;
        }
        count++;
    }
   temp = NULL;
   temp2 = NULL;



}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head)
    {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    }
    else
    {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL)
    {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint)
{
    /// @todo Graded in MP3.2
    return NULL; // change me!
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if(tail != NULL)
    {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode * second)
{
    /// @todo Graded in MP3.2
    return NULL; // change me!
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode * List<T>::mergesort(ListNode * start, int chainLength)
{
    /// @todo Graded in MP3.2
    return NULL; // change me!
}
