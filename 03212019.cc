/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (39.42%)
 * Total Accepted:    101.5K
 * Total Submissions: 257.5K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 14
 * Output: false
 *
 *
 *
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, h = num;
        while (l <= h) {
            int m = l + (h - l) / 2;
            int prod = m * m;
            if (prod == num) {
                return true;
            } else if (prod < num) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};

/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.00%)
 * Total Accepted:    280.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
 *
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, sLen = s.size();
        int j = 0, pLen = p.size();
        while (i < sLen && j < pLen) {
            if ((p[j] == '.' && j + 1 < pLen && p[j + 1] != '*') || p[j] == s[i]) {
                ++i;
                ++j;
            } else if (p[j] == '.' && j + 1 < pLen && p[j + 1] == '*') {
                // recur, .* can eat as many chars as it can
                for (int len = 0; len <= pLen - j; ++len) {
                    string newS = s.substr(0, i) + s.substr(i + len);
                    string newP = p.substr(0, j) + p.substr(j + 2);
                    if (isMatch(newS, newP)) {
                        return true;
                    }
                }
            } else if (p[j] != '.' && p[j] != s[i]) {
                return false;
            }
        }
        return i == sLen && j == pLen;
    }
};

/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (35.46%)
 * Total Accepted:    172.1K
 * Total Submissions: 483.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = head;
        while ((ListNode *kthNode = findKthNode(head, k))) {
            ListNode *oldHead = head, *oldTail = kthNode;
            ListNode *kthNodeNext = oldTail->next;
            reverse(oldHead, kthNodeNext);
            oldHead->next = kthNodeNext;
            if (newHead == head) {
                newHead = oldTail;
            }
            // advance
            head = kthNodeNext;
        }
        return newHead;
    }

    void reverse(ListNode *head, ListNode *until) {
        while (head != until) {
            ListNode *next = head->next;
            head->next->next = head;
            head = next;
        }
    }

    ListNode *findKthNode(ListNode *head, int k) {
        while (--k) {
            head = head->next;
        }
        return head;
    }
};

/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (39.76%)
 * Total Accepted:    543.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * Example 1:
 *
 *
 * Given nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 *
 * It doesn't matter what you leave beyond the returned length.
 *
 * Example 2:
 *
 *
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 *
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 *
 * It doesn't matter what values are set beyond the returned length.
 *
 *
 * Clarification:
 *
 * Confused why the returned value is an integer but your answer is an array?
 *
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 *
 * Internally you can think of this:
 *
 *
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 *
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 *
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (int num : nums) {
            if (index == 0 || num != nums[index]) {
                nums[index++] = num;
            }
        }
        return index;
    }
};
