// huffcode.hpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2019

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <queue>

struct minHeapNode
{
    char _data;
    int _weight;

    std::shared_ptr<minHeapNode> _left, _right;
    minHeapNode( char data, int weight)
    {
        _left= _right= NULL;
        _data = data;
        _weight = weight;
    }
};
struct compare
{
    //Try to do shared_ptr here, but it really didn't like it.
    bool operator()(std::shared_ptr<minHeapNode> & left , std::shared_ptr<minHeapNode> & right)
    {
        return(left->_weight > right -> _weight);
    }
};


// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:



    void setWeights(const std::unordered_map<char, int> & theweights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

// ***** HuffCode: data members *****
private:
    void storeCodes(std::shared_ptr<minHeapNode> root, std::string str);
    std::priority_queue<std::shared_ptr<minHeapNode>, std::vector<std::shared_ptr<minHeapNode>>, compare> _minHeap;
    std::unordered_map<char, std::string> _mapper;
};  // End class HuffCode


#endif //#ifndef FILE_HUFFCODE_H_INCLUDED

