#include "PMerge.hpp"

PMerge::PMerge()
{
	//std::cout << "Constructor called\n";
}

/*PMerge::PMerge(int val)
{
	std::cout << "Constructor called\n";
}*/

PMerge::PMerge(const PMerge& other)
{
	//std::cout << "Copy consturctor called\n";
	*this = other;
}

PMerge& PMerge::operator=(const PMerge& other)
{
	//std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		this->vecLosers = other.vecLosers;
		this->deqLosers = other.deqLosers;
		this->vecWinners = other.vecWinners;
		this->deqWinners = other.deqWinners;
	}
	return (*this);
}

PMerge::~PMerge()
{
    //std::cout << "Destructor called\n";
}

std::deque<int> PMerge::InsertTemp(std::deque<int> ret, int temp)
{
	std::deque<int>::iterator pos = std::lower_bound(ret.begin(), ret.end(), temp);
	ret.insert(pos, temp);
	return (ret);
}

std::vector<int> 	PMerge::InsertTempVec(std::vector<int> ret, int temp)
{
	std::vector<int>::iterator pos = std::lower_bound(ret.begin(), ret.end(), temp);
	ret.insert(pos, temp);
	return (ret);
}

void			PMerge::Printvecbef()
{
	std::cout << "before: ";
	for (std::vector<int>::iterator it = vecWinners.begin(); it < vecWinners.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
void			PMerge::Printdeqbef()
{
	std::cout << "before: ";
	for (std::deque<int>::iterator it = deqWinners.begin(); it < deqWinners.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
void PMerge::GenJSequence(unsigned long limit, unsigned long curJ, unsigned long prevJ)
{
	unsigned long nextJ = curJ + 2 * prevJ; 
	if (nextJ < limit)
	{
		while(nextJ > curJ)
		{
			Jhall.push_back(nextJ);
			nextJ--; 
		}
		nextJ = curJ + 2 * prevJ;
		GenJSequence(limit, nextJ, curJ);
	}
	else
	{
		nextJ = limit;
		while(nextJ > curJ)
		{
			Jhall.push_back(nextJ);
			nextJ--; 
		}
		return;
	}
}

std::deque<int>	PMerge::InsertLoser(std::deque<int> ret)
{
	if (deqLosers.empty())
		return (ret);
	if (deqLosers.size() == 1)
		ret.push_front(deqLosers[0]);
	else
	{
		std::deque<int>::iterator pos0 = std::lower_bound(ret.begin(), ret.end(), deqLosers[0]);
		ret.insert(pos0, deqLosers[0]);
		GenJSequence(deqLosers.size(), 1, 1);
		unsigned long j = 0;
		unsigned long idx = 0;;
		while(idx != Jhall.size())
		{
				j = Jhall[idx] - 1;
				std::deque<int>::iterator pos1 = std::lower_bound(ret.begin(), ret.end(), deqWinners[j]);
				if (pos1 != ret.end() && *pos1 == deqWinners[j])
				{
						std::deque<int>::iterator pos2 = std::lower_bound(ret.begin(), pos1, deqLosers[j]);
						ret.insert(pos2, deqLosers[j]);
				}
				else
					std::cout << "matching value not found" << std::endl;
				idx++;		
		}
	}
	return (ret);
}

std::vector<int>	PMerge::InsertLoserVec(std::vector<int> ret) // need to fix
{
	if (vecLosers.empty())
		return (ret);
	std::vector<int>::iterator pos0 = std::lower_bound(ret.begin(), ret.end(), vecLosers[0]);
	if (vecLosers.size() == 1)
		ret.insert(pos0, vecLosers[0]);
	else
	{
		ret.insert(pos0, vecLosers[0]);
		GenJSequence(vecLosers.size(), 1, 1);
		unsigned long j = 0;
		unsigned long idx = 0;;
		while(idx != Jhall.size())
		{
				j = Jhall[idx] - 1;
				std::vector<int>::iterator pos1 = std::lower_bound(ret.begin(), ret.end(), vecWinners[j]);
				if (pos1 != ret.end() && *pos1 == vecWinners[j])
				{
						std::vector<int>::iterator pos2 = std::lower_bound(ret.begin(), pos1, vecLosers[j]);
						ret.insert(pos2, vecLosers[j]);
				}
				else
					std::cout << "matching value not found" << std::endl;
				idx++;		
		}
	}
	return (ret);
}

std::deque<int>	PMerge::FindWinner()
{
	unsigned long i = 0;
	int temp = 0;
	unsigned long limit = 0;
	bool odd = false;
	std::deque<int> ret;
	PMerge Obj;
	if (deqWinners.size() > 1)
	{
		if (this->deqWinners.size() % 2 != 0)
		{
			temp = deqWinners.back();
			limit = deqWinners.size() - 1;
			odd = true;
		}
		else
			limit = deqWinners.size();
		while(i < limit)
		{
			if (i % 2 == 0)
			{
				if(deqWinners[i] > deqWinners[i + 1])
				{
					Obj.deqWinners.push_back(this->deqWinners[i]);
					Obj.deqLosers.push_back(this->deqWinners[i + 1]);
				}
				else
				{
					Obj.deqWinners.push_back(deqWinners[i + 1]);
					Obj.deqLosers.push_back(deqWinners[i]);
				}
			}
			i++;
		}
		ret = Obj.FindWinner();
		ret = Obj.InsertLoser(ret);
		if (odd)
			ret = InsertTemp(ret, temp);
		return (ret);
	}
	else
		return (this->deqWinners);
}

std::vector<int> PMerge::FindWinnerVec()
{
	unsigned long i = 0;
	int temp = 0;
	unsigned long limit = 0;
	bool odd = false;
	std::vector<int> ret;
	PMerge Obj;
	if (vecWinners.size() > 1)
	{
		if (this->vecWinners.size() % 2 != 0)
		{
			temp = vecWinners.back();
			limit = vecWinners.size() - 1;
			odd = true;
		}
		else
			limit = vecWinners.size();
		while(i < limit)
		{
			if (i % 2 == 0)
			{
				if(vecWinners[i] > vecWinners[i + 1])
				{
					Obj.vecWinners.push_back(this->vecWinners[i]);
					Obj.vecLosers.push_back(this->vecWinners[i + 1]);
				}
				else
				{
					Obj.vecWinners.push_back(vecWinners[i + 1]);
					Obj.vecLosers.push_back(vecWinners[i]);
				}
			}
			i++;
		}
		ret = Obj.FindWinnerVec();
		ret = Obj.InsertLoserVec(ret);
		if (odd)
			ret = InsertTempVec(ret, temp);
		return (ret);
	}
	else
		return (this->vecWinners);	
}

void	PMerge::insertDeq(int num)
{
	this->deqWinners.push_back(num);
}

void	PMerge::insertVec(int num)
{
	this->vecWinners.push_back(num);
}
void	PMerge::MeasureandExecVec(int i)
{
		std::vector<int> ret;
		Printvecbef();
		timespec start, end;
		clock_gettime(CLOCK_MONOTONIC, &start);
		ret = FindWinnerVec();
		clock_gettime(CLOCK_MONOTONIC, &end);
		double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + 
                  (end.tv_nsec - start.tv_nsec) / 1e3;
		std::cout << "after: ";
		for (std::vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Time to process a range of " << i - 1 << " elements with std::vector : " << elapsed << " us" << std::endl;
}
void	PMerge::MeasureandExecDeq(int i)
{
		std::deque<int> ret;
		Printdeqbef();
		timespec start, end;
		clock_gettime(CLOCK_MONOTONIC, &start);
		ret = FindWinner();
		clock_gettime(CLOCK_MONOTONIC, &end);
		double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + 
                  (end.tv_nsec - start.tv_nsec) / 1e3;
		std::cout << "after: ";
		for (std::deque<int>::iterator it = ret.begin(); it != ret.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Time to process a range of " << i - 1 << " elements with std::deque : " << elapsed << " us" << std::endl;
}

bool parseArg(const char* str, long& out)
{
    errno = 0;
    char* end;
    long val = std::strtol(str, &end, 10);

    if (end == str || *end != '\0')   
        return false;
    if (errno == ERANGE || val > INT_MAX || val < 0) 
        return false;

    out = val;
    return true;
}