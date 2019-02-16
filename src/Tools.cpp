#include "Tools.h"
#include <random>
#include <chrono>
#include <cmath>
void ATool::changeType(PType __newType) {
    this->type = __newType;
}
void ToolSinglePoint::onMouseDown(unsigned int x,unsigned int y) {
    if(getType()!=NONE)
        map->add(x,y, getType());
    else {
        map->del(x,y);
    }
}
void ToolSpray::onMouseDown(unsigned int x,unsigned int y) {
    if(getType()!=NONE) {
        unsigned int numberOfPoints = size*0.5;
        std::default_random_engine generator;
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> distribution(0,1);
        for(unsigned int i = 0;i<numberOfPoints;i++) {
            double r = size*sqrt(distribution(generator));
            double angle = distribution(generator)*2*M_PI;
            int pointx = x+r*cos(angle);
            int pointy = y+r*sin(angle);
            map->add(pointx,pointy,getType());
        }
    }
}
void ToolSpray::onMouseMotion(unsigned int x,unsigned int y) {
    this->onMouseDown(x,y);
}
