//
// Created by Ian Ferguson on 2019-12-06.
//


// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
// Finished 12/6/2019
// Ian Ferguson
// For CS411 Fall 2019


#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
#include <vector>
using std::string;
using std::vector;
#include <unordered_map>
using std::unordered_map;
using std::shared_ptr;
using std::pair;




void HuffCode::setWeights(const unordered_map<char, int> & theweights)
{
    //Base cases
    //size() == 0 works too, but CLion recommended empty instead
    if(theweights.empty())
    {
        return;
    }

    for(auto w: theweights)
    {
        _minHeap.emplace(std::make_shared<minHeapNode>(w.first, w.second));
    }
    while(_minHeap.size()!=1)
    {
        auto left = _minHeap.top();
        _minHeap.pop();

        auto right = _minHeap.top();
        _minHeap.pop();
        // '$" is a non leaft parent node
        auto root = std::make_shared<minHeapNode>('$', left->_weight + right ->_weight);

        root->_left = left;
        root ->_right = right;

        _minHeap.push(root);

    }
    storeCodes(_minHeap.top(), "");
}


string HuffCode::encode(const string & text) const
{
    // For each character in the text, search for the corresponding huffman code
    string encoder;
    for(auto letter:text)
    {
        encoder += _mapper.find(letter) -> second;
    }
    return encoder;
}


string HuffCode::decode(const string & codestr) const
{
    // code is the current huffman code
    string decoded, code;
    for(auto mapper: codestr)
    {
        //Add character to the current code
        code += mapper;
        for(auto key: _mapper)
        {
            //Check if the code matches one of our stored codes
            if (key.second == code)
            {
                //Add to the result and reset
                decoded += key.first;
                code = "";

            }
        }
    }
    return decoded;
}

void HuffCode::storeCodes(std::shared_ptr<minHeapNode> root, std::string str) {
    if(!root)
    {
        return;
    }

    //Store encoded string in a hash table
    if(root-> _data != '$')
    {
        _mapper[root -> _data] = str;
    }
    //Check the left and right branches
    storeCodes(root->_left, str+"0");
    storeCodes(root ->_right, str+ "1");
}