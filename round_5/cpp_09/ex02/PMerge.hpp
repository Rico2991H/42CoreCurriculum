#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>
#include <climits>
#include <cerrno>

class PMerge
{
	public:
		PMerge();
		//PMerge(int val);
		PMerge(const PMerge& other);
		PMerge& operator=(const PMerge& other);
		~PMerge();
		void				insertDeq(int num);
		void				insertVec(int num);
		std::deque<int> 	FindWinner();
		void				GenJSequence(unsigned long limit, unsigned long curJ, unsigned long prevJ);
		std::deque<int>		InsertLoser(std::deque<int> ret);
		std::deque<int> 	InsertTemp(std::deque<int> ret, int temp);
		std::vector<int> 	FindWinnerVec();
		std::vector<int>	InsertLoserVec(std::vector<int> ret);
		std::vector<int> 	InsertTempVec(std::vector<int> ret, int temp);
		void				Printvecbef();
		void				Printdeqbef();
		void				MeasureandExecVec(int i);
		void				MeasureandExecDeq(int i);


	private:
		std::deque<int> deqWinners;
		std::deque<int> deqLosers;
		std::vector<int> vecWinners;
		std::vector<int> vecLosers;
		std::vector<int> Jhall;

};

bool parseArg(const char* str, long& out);

#endif