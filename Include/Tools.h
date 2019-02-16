#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include "APoint.h"
class ATool {
public:
    virtual void onMouseDown(unsigned int x,unsigned int y) {}
    virtual void onMouseUp(unsigned int x,unsigned int y) {}
    virtual void onMouseMotion(unsigned int x,unsigned int y) {}
    void changeType(PType __newType);
    PType getType() {return type;}
    virtual ~ATool() {};
protected:
    ATool(PType __type,ForestMap* __map) :map(__map), type(__type) {}
    ForestMap* map = nullptr;
private:
    PType type;
};

class ToolSinglePoint : public ATool {
    public:
    ToolSinglePoint(PType __type,ForestMap* __map) : ATool(__type,__map) {}
    void onMouseDown(unsigned int x,unsigned int y) override;
};

class ToolPencil : public ToolSinglePoint {
public:
    ToolPencil(PType __type,ForestMap* __map) : ToolSinglePoint(__type,__map) {}
    void onMouseMotion(unsigned int x,unsigned int y) override {this->onMouseDown(x,y);}
};
class ToolSpray : public ATool {
public:
    ToolSpray(PType __type,ForestMap* __map) : ATool(__type,__map) {}
    void onMouseDown(unsigned int x,unsigned int y) override;
    void onMouseMotion(unsigned int x,unsigned int y) override;
private:
    const int size = 10;
    const double numberOfPointsMultiplier = 0.5;
};
#endif // TOOLS_H_INCLUDED
