/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-11-05 15:56:20
 	Problem       : problem
************************************************ */
#include <stdio.h>
#include <string.h>

void reverseWords(char *s) {
	while(*s == ' ') s++;
    char *p1, *p2, *ret;
    ret = p1 = p2 = s;
    while(*s) {
    	if(*s == ' ') {
    		while(p1 <= p2){
    			char  tmp;
    			tmp = *p1, *p1= *p2, *p2 = tmp;
    			p1++, p2--;
    		}
    		p1 = p2 = s+1;
    	}
    	else p2 = s;
    	s++;
    }
    while(p1 <= p2){
    	char tmp; 
    	tmp = *p1; *p1 = *p2; *p2 = tmp; 
    	p1++; p2--;
    }
    s--;
    char *ss = ret;
    while(ss <= s){
    	char tmp; 
    	tmp = *ss; *ss = *s; *s = tmp;
    	ss ++; s--;
    }
    while(*ret == ' ') ret ++;
    s = ret;
}