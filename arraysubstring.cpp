/* 
One Plus IITB 2018

Count Number of substrings of a binary string containing K ones

Given a binary string of length N and an integer K, 
we need to find out how many substrings of this string exist which contains exactly K ones.

Symbols:
n	String length
k	Integer K (max no. of 1's allowed)
string	Actual binary string

Input:
n k
--string--

Example Input: 
5 1
10010

Example Output:
9


===== META DATA =====
Author: anuraag
Source:	https://www.geeksforgeeks.org/count-substrings-binary-string-containing-k-ones/
Complexity: O(n^2)
*/

#include <iostream>
using namespace std;

/* Change this to 1 to print DEBUG output */
#define DEBUG 0

int count_substrings(string s, int k){
    int n = s.size(), one_count = 0, substr_count = 0;
    for(int begin = 0; begin < n; begin++){
        one_count = 0;
        for(int end = begin; end < n; end++){
            if(s[end] == '1')
                one_count++;
            if(one_count == 1){
                DEBUG && cout << "Substring: " << s.substr(begin, end - begin + 1) << endl;
                substr_count++;
            }else if(one_count > 1){
                break;
            }
        }
    }

    return substr_count;
}

int count_substrings_order_n(string s, int k){
    int n = s.size(), one_count = 0, substr_count = 0;
    /* 
    sp - start pointer; 
    op - one pointer; 
    ep - end pointer 
    */
    int sp = 0, ep = -1, op = -1, op_prev = -1;
    
    while(sp < n && ep < n){
        ep++;
        if(ep < n){
            if(s[ep] == '1'){
                op_prev = op;
                op = ep;        // update one_pointer
                one_count++;    // increment one_count
            }
            if(one_count > 1){
                DEBUG && cout << "DBG: " << s.substr(sp, ep - sp) << endl;
                DEBUG && cout << "DBG: sp: " << sp << ", op_prev: " << op_prev << ", ep: " << ep  << endl;
                // think about it...
                substr_count += (op_prev - sp + 1)*(ep - op_prev);
                sp = op_prev + 1;
                --one_count;
                DEBUG && cout << "DBG: " << substr_count << endl;
                
            }else if( ep == n-1){
                /* end is now at the last element */
                DEBUG && cout << "DBG: " << s.substr(sp, ep - sp + 1) << endl;
                DEBUG && cout << "DBG: sp: " << sp << ", op: " << op << ", ep: " << ep  << endl;
                // think about it again...
                substr_count += (op - sp + 1)*(ep - op + 1);
                DEBUG && cout << "DBG: " << substr_count << endl;
            }
        }
    }
    
    return substr_count;
}

int main(){

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    cout << count_substrings(s, k) << endl;
    cout << count_substrings_order_n(s, k) << endl;

    return 0;
}
