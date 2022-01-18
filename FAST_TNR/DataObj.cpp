#include "StdAfx.h"
#include "DataObj.h"
#include <assert.h>
#include <algorithm>    // std::sort

using namespace std;

extern const int MAX_DIST;

CObj::CObj(void)
{

}


CObj::~CObj(void)
{
}


CQry::CQry(void)
	: CObj()
{

}


CQry::~CQry(void)
{
}



static bool compare_farthest_dist(const pair<int, float>& elem1, const pair<int, float>& elem2)
{
	float maxdist1, maxdist2;
	int obj1_id, obj2_id;

	obj1_id = elem1.first;
	obj2_id = elem2.first;

	maxdist1 = elem1.second;
	maxdist2 = elem2.second;

	assert(obj1_id != obj2_id);

	if (maxdist1 != maxdist2)
	{
		return (maxdist1 > maxdist2);
	}
	else
	{
		return (obj1_id > obj2_id);
	}
}



float CQry::update_result(const int new_obj_id, const float new_obj_dist)
{
	float prundist;

	assert(this->num_of_fns > 0);

	ans_obj_list.push_back(make_pair(new_obj_id, new_obj_dist));
	sort(ans_obj_list.begin(), ans_obj_list.end(), compare_farthest_dist);

	if (ans_obj_list.size() <= num_of_fns)
	{
		prundist = -1; // 확인이 필요함.... hyunju
	}
	else
	{
		vector<pair<int, float>>::const_iterator it_kth_obj = ans_obj_list.begin() + (num_of_fns - 1);
		prundist = it_kth_obj->second;
		ans_obj_list.erase(ans_obj_list.begin() + num_of_fns, ans_obj_list.end());		
	}

	assert(ans_obj_list.size() <= num_of_fns);

	return prundist;
}

void CQry::copy_result(vector<pair<int, float>>& obj_list)
{
	this->ans_obj_list.clear();
	this->ans_obj_list.resize(this->num_of_fns);
	std::copy(obj_list.begin(), obj_list.begin() + this->num_of_fns, this->ans_obj_list.begin());

}

vector<pair<int, float>>& CQry::get_result()
{
	return this->ans_obj_list;
}




MyPoint::MyPoint() : x(-1), y(-1)
{
}

MyPoint::MyPoint(double xx, double yy) : x(xx), y(yy)
{
}



MyPoint::MyPoint(const MyPoint & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
}

MyPoint & MyPoint::operator= (const MyPoint & rhs)\
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}

	return *this;
}

