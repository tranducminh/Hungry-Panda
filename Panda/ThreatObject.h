#pragma once

#include "common_function.h"
#include "BaseObject.h"

#define THREAT_WIDTH 36
#define THREAT_HEIGHT 44


class ThreatObject : public BaseObject
{
public:
	ThreatObject();
	~ThreatObject();

	void HandMove(const int& x_border, const int& y_border);
	void HandInputAction(SDL_Event event);
	void Set_y_val(const int y_val) {
		y_val_ = y_val;
	}

private:
	int x_val_;
	int y_val_;
};


