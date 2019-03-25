//
//  Training.cpp
//  ExTestApp
//
//  Created by Linyi Ni on 3/10/19.
//  Copyright © 2019 Leo. All rights reserved.
//

#include "Training.hpp"
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// 364. Nested List Weight Sum II
/*
 Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 
 Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
 Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 
 Example 1:
 
 Input: [[1,1],2,[1,1]]
 Output: 8
 Explanation: Four 1's at depth 1, one 2 at depth 2.
 Example 2:
 
 Input: [1,[4,[6]]]
 Output: 17
 Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
 */
//class Solution {
//public:
//    int depthSumInverse(vector<NestedInteger>& nestedList) {
//
//    }
//};



// 277. Find the Celebrity
/*
 Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
 
 Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
 
 You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
 
 Input: graph = [
 [1,1,0],
 [0,1,0],
 [1,1,1]
 ]
 Output: 1
 Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
 
 Input: graph = [
 [1,0,1],
 [1,1,0],
 [0,1,1]
 ]
 Output: -1
 Explanation: There is no celebrity.
 
 Note:
 
 The directed graph is represented as an adjacency matrix, which is an n x n matrix where a[i][j] = 1 means person i knows person j while a[i][j] = 0 means the contrary.
 Remember that you won't have direct access to the adjacency matrix.
 */
//bool knows(int a, int b);
//
//class Solution {
//public:
//    int findCelebrity(int n) {
//
//    }
//};



// 149. Max Points on a Line
/*
 
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 
 Example 1:
 
 Input: [[1,1],[2,2],[3,3]]
 Output: 3
 Explanation:
 ^
 |
 |        o
 |     o
 |  o
 +------------->
 0  1  2  3  4
 Example 2:
 
 Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 Output: 4
 Explanation:
 ^
 |
 |  o
 |     o        o
 |        o
 |  o        o
 +------------------->
 0  1  2  3  4  5  6
 */
//class Solution {
//public:
//    int maxPoints(vector<Point>& points) {
//
//    }
//};



// 647. Palindromic Substrings
/*
 Given a string, your task is to count how many palindromic substrings in this string.
 
 The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 
 Example 1:
 
 Input: "abc"
 Output: 3
 Explanation: Three palindromic strings: "a", "b", "c".
 
 
 Example 2:
 
 Input: "aaa"
 Output: 6
 Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
 
 Note:
 
 The input string length won't exceed 1000.
 */
//class Solution {
//public:
//    int countSubstrings(string s) {
//
//    }
//};



// 65. Valid Number
/*
 Validate if a given string can be interpreted as a decimal number.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 " -90e3   " => true
 " 1e" => false
 "e3" => false
 " 6e-1" => true
 " 99e2.5 " => false
 "53.5e93" => true
 " --6 " => false
 "-+3" => false
 "95a54e53" => false
 
 Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
 
 Numbers 0-9
 Exponent - "e"
 Positive/negative sign - "+"/"-"
 Decimal point - "."
 Of course, the context of these characters also matters in the input.
 
 Update (2015-02-10):
 The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
 */
//class Solution {
//public:
//    bool isNumber(string s) {
//
//    }
//};



// 57. Insert Interval
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 
 Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 Output: [[1,5],[6,9]]
 Example 2:
 
 Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 Output: [[1,2],[3,10],[12,16]]
 Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
    }
};


// 244. Shortest Word Distance II
/*
 Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters.
 
 Example:
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 
 Input: word1 = “coding”, word2 = “practice”
 Output: 3
 Input: word1 = "makes", word2 = "coding"
 Output: 1
 Note:
 You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */
/*
 word1 : [i1, i2, i3], ascending max - max min - min min - max min - max
 word2 : [i5, i6], ascending
 =>
 what is the shortest distance between the two arrays
 edge case: same word?
 */
//class WordDistance {
//    unordered_map<string, vector<int>> mp;
//public:
//    WordDistance(vector<string> words) {
//        for (int i = 0; i < words.size(); ++i) {
//            mp[words[i]].push_back(i);
//        }
//    }
//
//    int shortest(string word1, string word2) {
//        vector<int> &dists1 = mp[word1];
//        vector<int> &dists2 = mp[word2];
//        int d1 = abs(dists1.front() - dists2.front());
//        int d2 = abs(dists1.back() - dists2.back());
//        int d3 = abs(dists1.front() - dists2.back());
//        int d4 = abs(dists1.back() - dists2.front());
//        return max(d1, max(d2, max(d3, d4)));
//    }
//};
