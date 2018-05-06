#include "ThreatObject.h"

ThreatObject::ThreatObject() {
	rect_.x = Bamboo_Loc[1];
	rect_.y = SCREEN_HEIGHT;
	rect_.w = THREAT_WIDTH;
	rect_.h = THREAT_HEIGHT;

	x_val_ = 0;
	y_val_ = 0;
}

ThreatObject::~ThreatObject() {

}

void ThreatObject::HandMove(const int& x_border, const int& y_border) {

	rect_.y -= y_val_;
	/*if (rect_.y + THREAT_HEIGHT < 0) {
		rect_.x = Bamboo_Loc[randomBamboo()];
		rect_.y = SCREEN_HEIGHT;
	}*/

}